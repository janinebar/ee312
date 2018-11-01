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

  /*  // DEBUG //
    cout << "\nMADE OBJECT:" << endl;
    cout << "artist: " << artist << endl;
    cout << "title: " << title << endl;
    cout << "song size: " << songSize << "\n" << endl; */
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

int Song::compareSongs(Song const &s1, Song const &s2){

   // cout << "title:  " << s1.getTitle() << " " << s2.getTitle() << endl;

    if(s1.getArtist() > s2.getArtist()){
        //cout << "swap artists:  " << s1.getArtist() << " " << s2.getArtist() << endl;
        return 0;
    }
    else if (s1.getTitle() > s2.getTitle()){
        //cout << "swap title:  " << s1.getTitle() << " " << s2.getTitle() << endl;
        return 0;
    }
    else if(s1.getSongSize() > s2.getSongSize()){
        //cout << "swap size:  " << s1.getSongSize() << " " << s2.getSongSize() << endl;
        return 0;
    }
    else{
        return -2;
    }


}

