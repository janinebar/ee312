//
// Created by Janine Bariuan on 12/5/18.
//

#ifndef CHEATERS_CHEATERS_H
#define CHEATERS_CHEATERS_H

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

    if(head == NULL){
        head = insert;
    }
    else {
        while(ptr != NULL){

        }
    }

};


#endif //CHEATERS_CHEATERS_H
