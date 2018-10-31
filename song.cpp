//
// Created by Janine Bariuan on 10/29/18.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include "UtPod.h"
#include "song.h"

Song::Song(){}
Song::~Song(){}

Song::Song(string artist1, string title1, int songSize1){
    artist = artist1;
    title = title1;
    songSize = songSize1;

    // DEBUG //
    cout << "\nMADE OBJECT:" << endl;
    cout << "artist: " << artist << endl;
    cout << "title: " << title << endl;
    cout << "song size: " << songSize << "\n" << endl;
    // ****** //
}

string Song::getTitle() const{
    //cout << "getTitle(): " << title << endl;
    return title;
}

string Song::getArtist() const{
    //cout << "getArtist(): " << artist << endl;
    return artist;
}

int Song::getSongSize() const{
    //cout << "getSongSize(): " << songSize << endl;
    return songSize;
}


