//
// Created by Janine Bariuan on 10/26/18.
//


#include <iostream>
#include <string>
#include <cstdlib>
#include "UtPod.h"
#include "song.h"

using namespace std;


//Default constructor
//set the memory size to MAX_MEMORY
UtPod::UtPod(){
    memSize = MAX_MEMORY;
    songs = NULL;
    cout << "\nClass made...... memSize: " << memSize << "\n" << endl;

}


//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UtPod::UtPod(int size){

    if ((size >= MAX_MEMORY) || (size <= 0)){
        size = MAX_MEMORY;
    }

}


UtPod::~UtPod() {}


// argument: object "s" from Song class
int UtPod::addSong(Song const &s){

    SongNode* temp = new SongNode;


    temp->s = s; // creates object "s" from Song class
    temp->next = songs;
    songs = temp;   //newly added song is now on top

    // DEBUG //
    cout << "MADE NODE:" << endl;
    cout << "artist: " << songs->s.getArtist() << endl;
    cout << "title: " << songs->s.getTitle() << endl;
    cout << "song size: " << songs->s.getSongSize() << "\n" << endl;
    // ****** //

    return SUCCESS;

}



// argument: specific object "s" from Song class
// 1. want to go thru linked list to find the Node with that object ?
// 2. replace previous Node-> next before it to temp->next;
int UtPod::removeSong(Song const &s){

    cout << "------------- REMOVE SONG ------------" << endl;

    int result;
    SongNode *before = songs;
    string beforeTitle = before->s.getTitle();
    string beforeArtist = before->s.getArtist();
    int beforeSize = before->s.getSongSize();

    // DEBUG //
    cout << "remove: " << beforeTitle << ", ";
    cout << beforeArtist << ", " << beforeSize << endl;
    // ******* //

    // if head is song want to remove, change head's next to before's next
    if((beforeArtist == s.getArtist()) && (beforeTitle == s.getTitle()) && (beforeSize == s.getSongSize())){

        // DEBUG //
        cout << "Head is song want to remove" << endl;
        cout << "next song: " << songs->next->s.getTitle() << endl;

        songs = before->next;
        songs->next = before->next->next;

        // DEBUG //
        cout << "new head info: " << songs->s.getTitle() << endl;

        result = SUCCESS;
    }
    // otherwise, traverse thru linked list to find song to remove
    else {

        while (before != NULL) {

            // look at the NEXT node
            beforeTitle = before->next->s.getTitle();
            beforeArtist = before->next->s.getArtist();
            beforeSize = before->next->s.getSongSize();

            if((beforeArtist == s.getArtist()) && (beforeTitle == s.getTitle()) && (beforeSize == s.getSongSize())){
                before->next = before->next->next; //removes song node from linked list
                result = SUCCESS;
            }

            before = before->next;  //if haven't found, point to next song node

        }

        if(before == NULL){
            result = NOT_FOUND;
        }

    }

    cout << "removeSong() = " << result << "\n" << endl;
    return result;


}

// swapping done here, comparison done in song.cpp
void shuffle();



/* FUNCTION - void showSongList
     * prints the current list of songs in order from first to last to standard output
     * format - Title, Artist, size in MB (one song per line)
    */
void UtPod::showSongList(){

    cout << "----- UtPod Songs ------\n" << endl;

    SongNode *ptr = songs;

    while(ptr != NULL){

        cout << "'"<< ptr->s.getTitle() << "' by ";
        cout << ptr->s.getArtist() << " (" << ptr->s.getSongSize() << " MB)" << endl;

        ptr = ptr->next;

    }

    cout << endl;

}



// swapping done here, comparison done in song.cpp
void sortSongList();



/* FUNCTION - void clearMemory
     * clears all the songs from memory

       input parms -

       output parms -
    */
void UtPod::clearMemory(){

    SongNode *ptr = songs->next;

    while (songs != NULL){

        free(songs);
        songs = ptr;
        ptr = ptr->next;

    }

}



/* FUNCTION - int getRemainingMemory
    *  returns the amount of memory available for adding new songs

      input parms -

      output parms -
   */
int UtPod::getRemainingMemory(){

    SongNode *ptr = songs;
    int memSum = 0;
    int remaining = 0;

    while(ptr != NULL){

        memSum += ptr->s.getSongSize();
        ptr = ptr->next;

    }

    remaining = MAX_MEMORY - memSum;

    return remaining;

}


