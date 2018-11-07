//
// Created by asada on 11/6/2018.
//
#include <iostream>
#include <string>
#include <cstdlib>
#include "card.h'


Card::Card(){}
Card::~Card(){}



Card(int rank, Suit s);{
    myRank = rank;
    mySuit = s;
}


// return string version e.g. Ac 4h Js
string Card::toString(){

}

// true if suit same as c
bool Card::sameSuitAs(const Card& c) const{
    if ()
}

// return rank, 1..13
int  Card::getRank() const{
    return myRank;
}

// return "s", "h",...
string Card::suitString(Suit s) const{
    if (s==spades){
        return "s";
    }
    if (s==hearts){
        return "h";
    }
    if (s==diamonds){
        return "d";
    }
    if (s==clubs){
        return "c";
    }
}

// return "A", "2", ..."Q"
string rankString(int r) const{
    if(r==1){
        return "A";
    }
    if(r>1&&r<11){
        string number = to_string r;
        return number;
    }
    if(r==11){
        return "J";
    }
    if(r==12){
        return "Q";
    }
    if(r==13){
        return "K";
    }
}