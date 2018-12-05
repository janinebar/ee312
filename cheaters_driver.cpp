#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


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
 *
 *
 */

// Arguments: [1] path to files, [2] n-word sequence, [3] min. number of matches
int main(int argc, char *argv[])
{
    string dir = string("sample_set"); // dir = directory name
    vector<string> files = vector<string>(); // files = string vector

    getdir(dir,files);

    // prints out files vector
    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << " " << files[i] << endl;
    }

    // Open one file //

    ifstream txtFile;

   // while (loop going thru all files){

        string openFile = files[2];
        string wholeDir = dir + "/" + openFile;
        cout << wholeDir << endl; // DEBUG
        txtFile.open(wholeDir);

        // DEBUG //
        if(txtFile){
            cout << "open" << endl;
        }

        string word;
        int n = 6;
        int l = 5;
        int counter = 0;
        string nwordSeq = "";

        // Read n-word sequence from file
        while(counter < 6) {

            nwordSeq = "";

            for (int i = 0; i < n; i++) {
                txtFile >> word;
                nwordSeq += word;
            }

            // DEBUG //
            cout << nwordSeq << " ";
            cout << endl;
            cout << endl;
            cout << counter << endl;
            // ---- //

            txtFile.close();
            txtFile.open(wholeDir);

            // DEBUG - PRINTS OUT N-WORD SEQ //
            for(int j = 0; j < counter; j++) {
                txtFile >> word;
                cout << "skipping: " << word << endl;
            }

            counter++;
            cout << endl; // DEBUG

        }




   return 0;
}