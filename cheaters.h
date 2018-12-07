//
// Created by Janine Bariuan on 12/5/18.
//

#ifndef CHEATERS_CHEATERS_H
#define CHEATERS_CHEATERS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctype.h>

using namespace std;

class eachIndex{

private:

    /*** Linked List ***/
    struct fileNode{
        int fileIndex;
        fileNode *next;
    };

    fileNode *head;

    /*** Hash table ***/
    static const int HASHSIZE = 1000000;
    fileNode *hashtable[HASHSIZE];



public:
    eachIndex(){

        // makes every hashtable elem NULL
        for(int i = 0; i < HASHSIZE; i++){
            hashtable[i] = NULL;
        }

    }


    /**** Hashing Function ****/
    vector<int> hash(int hashIndex, int file, vector<int> matchesVec);

    int getHashSize(){
        return HASHSIZE;
    }

    //~eachIndex();


};


/****** FUNCTION DECLARATIONS *******/

vector<int> eachIndex::hash(int hashIndex, int file, vector<int> matchesVec) {

    /*
     * create temp node with file index
     *
     * go to hashIndex
     *
     *  if head NULL
     *  - head = node
     *  - head->next = NULL
     *
     *  else
     *  - traverse list, adding matches to vector
     *  - add node at end
     *  - node->next = NULL;
     *
     *  need to return that array of matches
     */
    fileNode *temp = new fileNode;
    fileNode *insert = new fileNode;

    temp->fileIndex = file;
    temp->next = NULL;
    insert = temp;

    fileNode *ptr = new fileNode;
    ptr = hashtable[hashIndex];

    cout << "hash tabling.." << endl;

    if(hashtable[hashIndex] == NULL) {
        hashtable[hashIndex] = insert;
    }
    else {
        while(ptr != NULL){
            matchesVec.push_back(ptr->fileIndex);
            //cout << "pushed: " << matchesVec[matchesVec.size()-1] << endl;
            ptr = ptr->next;

        }
        ptr = insert;
       /* cout << "head: " << hashtable[hashIndex]->fileIndex << endl;
        cout << "inserted: " << ptr->fileIndex << endl; */
    }


    return matchesVec;

};

class matchValues{

private:
    int row;
    int col;
    int numMatches;

public:

    matchValues();
    matchValues(int i, int j, int matches){

        row = i;
        col = j;
        numMatches = matches;

    }

    int getRow(){

        return row;
    }

    int getCol(){
        return col;
    }

    int getMatches(){
        return numMatches;
    }

    //~matchValues();

};

#endif //CHEATERS_CHEATERS_H
