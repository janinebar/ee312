#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <cstdlib>
#include "cheaters.h"



using namespace std;

/*function... might want it in some class?*/ // <<<------ Why put in class? Why do we need a class?
int getdir (string dir, vector<string> &files)
{

    DIR *dp;   // type DIR pointer
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

/***** function: simplify string. removes special characters, leaves only lowercase and numbers *****/
string simplify(string simplifyString){

    string simplified = "";

    for(int i = 0; i < simplifyString.length(); i++){
        // checks if number
        char currentChar = simplifyString.c_str()[i];
        if(isdigit(currentChar)){
            //cout << "number: " << currentChar << endl;
            simplified += currentChar;
        }
        // checks if alpha
        if(isalpha(currentChar)){
            int ifCaps = currentChar;
            //cout << "alpha: " << currentChar << endl;
            if( ((ifCaps%64) > 0) && ((ifCaps%64) < 33) ) {
                //cout << "capital" << endl;
                currentChar = currentChar + 32;
                simplified += currentChar;
            }
            else {
                simplified += currentChar;
            }
        }
    }

    return simplified;

}


/***** function: hashKey. returns key to hash to. *****/
int hashKey(string inputstring, int hashsize){
    int sum=0;
    char *digit;
    int value = 0;

    cout << "==== hashKey ====" << endl;
    inputstring = "abclkjhgklfjlhjgfkjlkjhklfgjhklgjflkjghkljfgklhjfkgljhlkfgjlkhjd";

    for(int i=0; i < inputstring.length();i++){
        int j = i;
        int multiplier = 31;
        while (j>0){
            multiplier*=multiplier;
            j--;
        }
        char test = inputstring.c_str()[inputstring.size()-i-1];
        value = test - 97;
        //cout << value << endl;

        value*=multiplier;
        sum+=value;
        cout << "value " << value << endl;
    }

    cout << "return: " << sum%hashsize << endl;
    cout << "========" << endl;

    return sum%hashsize;
}



/*
 * Plan
 *
 * 1. Reads files ? - DONE
 * 2. Puts file names into vector - DONE
 *
 * 3. Milestone 1
 *  a. Open file
 *  b. Read certain number of letters (argv[2]) from one file
 *   i. check: print out n-word sequences from one file.
 *
 * 4. Milestone 2
 *  a. Create hashing function (produces key)
 *   i. Create word sequence simplifier (removes uppercase, punctuation, spaces)
 *  b. Create hash table (what kind of data structure???)
 *  c.
 *
 * NEED TO:
 * - make queue
 * - make hashing function
 * - make hash table
 * - make linked list stuff of hashing table
 * - make classes to create linked lists?????? (so each index
 * - make struct for nodes (has vector file index)
 *
 */

// Arguments: [1] path to files, [2] n-word sequence, [3] min. number of matches
int main(int argc, char *argv[])
{
    string folder = argv[1];
    cout << folder << endl;
    string dir = string(folder); // dir = directory name
    vector<string> files = vector<string>(); // files = string vector

    getdir(dir,files);

    // prints out files vector
    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << " " << files[i] << endl;
    }


    /*** Hash table ***/
    const int HASHSIZE = 1000000;
    eachIndex hashtable[HASHSIZE];

    /*** OPENS FILE ***/
    ifstream txtFile;

    for(int goThru = 2; goThru < files.size(); goThru++) {

        cout << " ------ NEW FILE -------" << endl;

        string openFile = files[goThru];
        string wholeDir = dir + "/" + openFile;
        cout << wholeDir << endl; // DEBUG
        txtFile.open(wholeDir);

        // DEBUG //
        if (txtFile) {
            cout << "open" << endl;
        }

        string word;
        int numWords = atoi(argv[2]);
        cout << "n-word seq: " << numWords << endl; // DEBUG
        int l = 5;
        int counter = 0;
        string nwordSeq = "";

        // DEBUG - counts total number of words //
        int totalWords = 0;

        for (totalWords = 0; !txtFile.eof(); totalWords++) {
            txtFile >> word;
            //cout << word << endl;

            // DEBUG //
            if (txtFile.eof()) {
                cout << "endof " << txtFile.eof() << endl;
            }

        }
        cout << "num words = " << totalWords << endl; // DEBUG
        // ------------------ //



        txtFile.close();
        txtFile.open(wholeDir);

        if (txtFile) {
            cout << "open" << endl;
        }

        bool reachedEof = false;

        vector<string> chunks = vector<string>();

        /*** Read n-word sequence from file ***/
        while (!reachedEof) {
            //while(counter < 5){

            nwordSeq = "";

            // creates n-word sequence string
            for (int i = 0; i < numWords; i++) {
                txtFile >> word;
                if (txtFile.eof()) {
                    reachedEof = true;
                    cout << "reached eof" << endl; // DEBUG
                }
                nwordSeq += word;
            }


            // puts chunks into vector except for last one
            // simplifies each string
            string simplified;
            if(!reachedEof){
                simplified = simplify(nwordSeq);
                chunks.push_back(simplified);
            }

            for(int m = 0; m < chunks.size(); m++){
                int key = hashKey(simplified, HASHSIZE);
                // hash(hashtable, key(index), HASHSIZE, goThru)
            }


            // DEBUG //
            if(reachedEof) {
                cout << nwordSeq << endl;
            }
            //cout << endl;
            //cout << counter << endl;
            // ---- //

            txtFile.close();
            txtFile.open(wholeDir);

            // sets where to begin next n-word seq
            for (int j = -1; j < counter; j++) {
                txtFile >> word;
                //cout << "skipping: " << word << endl; // DEBUG
            }

            counter++;
            //cout << endl; // DEBUG

        }

        // DEBUG --- printing out data of each file //
       /* cout << counter << endl;
        cout << "vector size: " << chunks.size() << endl;
        cout << chunks[chunks.size()-1] << endl; */

        txtFile.close();

        for(int m = 0; m < chunks.size(); m++){
            cout << chunks[m] << endl;
        }

        cout << "goThru: " << goThru << endl;
    }




   return 0;
}