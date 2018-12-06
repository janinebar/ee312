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
    void hash(int hashIndex, int file);

    int getHashSize(){
        return HASHSIZE;
    }

    //~eachIndex();


};


/****** FUNCTION DECLARATIONS *******/

void eachIndex::hash(int hashIndex, int file) {

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

    fileNode *insert = new fileNode;

    insert->fileIndex = file;
    insert->next = NULL;

    head = hashtable[hashIndex];
    fileNode *ptr = head;

    cout << "(class) index: " << hashIndex << endl; // DEBUG

    if(head == NULL){
        head = insert;

        // DEBUG //
        cout << "head success" << endl;
        cout << "file " <<  head->fileIndex << endl;
    }
   /* else {
        while(ptr != NULL){

            // add pointers to vector

            cout <<

        }
    } */

};


#endif //CHEATERS_CHEATERS_H
