//
// Created by Janine Bariuan on 10/26/18.
//

#ifndef SONG_H
#define SONG_H
#include <string>
#include <cstdlib>

using namespace std;

//SONG class declaration
class Song {

    private:
        string artist;
        string title;
        int songSize;


    public:
    Song();
    Song(string artist1, string title1, int songSize1);

    string getTitle() const;
    string getArtist() const;
    int getSongSize() const;
    int compareSongs(Song const &s1, Song const &s2);

    ~Song();

};

#endif //SONG_H
