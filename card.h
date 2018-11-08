//
// Created by asada on 11/7/2018.
//

#ifndef GO_FISH_REAL_CARD_H
#define GO_FISH_REAL_CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card
{
public:


    enum Suit {spades, hearts, diamonds, clubs};

    Card();          // default, ace of spades

    Card(int rank, Suit s);

    string toString()              const;  // return string version e.g. Ac 4h Js
    bool sameSuitAs(const Card& c) const;  // true if suit same as c
    int  getRank()                 const;  // return rank, 1..13
    string suitString(Suit s)      const;  // return "s", "h",...

    string rankString(int r)       const;  // return "A", "2", ..."Q"


    bool operator == (const Card& rhs) const;
    bool operator != (const Card& rhs) const;



private:

    int myRank;
    Suit mySuit;


};

ostream& operator << (ostream& out, const Card& c);



#endif