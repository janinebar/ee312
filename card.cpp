//
// Created by Asad Ahmed and Janine Bariuan on 11/6/2018.
//
#include <iostream>
#include <string>
#include <cstdlib>
#include "card.h"


Card::Card(){}
//Card::~Card(){}



Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}


// return string version e.g. Ac 4h Js
string Card::toString() const{

    // turn rank int to string
    string printSuit;
    string printRank;
    if(myRank==1){
        printRank = "A";
    }
    if(myRank == 1){

        printRank = "1";
    }
    if(myRank == 2){

        printRank = "2";
    }
    if(myRank == 3){

        printRank = "3";
    }
    if(myRank == 4){

        printRank = "4";
    }
    if(myRank == 5){

        printRank = "5";
    }
    if(myRank == 6){

        printRank = "6";
    }
    if(myRank == 7){

        printRank = "7";
    }
    if(myRank == 8){

        printRank = "8";
    }
    if(myRank == 9){

        printRank = "9";
    }
    if(myRank == 10){

        printRank = "10";
    }
    if(myRank==11){
       printRank = "J";
    }
    if(myRank==12){
        printRank = "Q";
    }
    if(myRank==13){
        printRank = "K";
    }
    if (mySuit == spades){
        printSuit = "s";
    }
    if (mySuit == hearts){
        printSuit = "h";
    }
    if (mySuit == clubs){
        printSuit = "c";
    }
    if (mySuit == diamonds){
        printSuit = "d";
    }
    string result = printRank + printSuit;
    //cout << result << endl;
    return result;

}

// true if suit same as c
/*bool Card::sameSuitAs(const Card& c) const{
 //   if (mySuit==c)
}*/

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
string Card::rankString(int r) const{
    if(r==1){
        return "A";
    }
    if(r==2){
        return "2";
    }
    if(r==3){
        return "3";
    }
    if(r==4){
        return "4";
    }
    if(r==5){
        return "5";
    }
    if(r==6){
        return "6";
    }
    if(r==7){
        return "7";
    }
    if(r==8){
        return "8";
    }
    if(r==9){
        return "9";
    }
    if(r==10){
        return "10";
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


/*bool Card::operator == (const Card& rhs) const;
bool Card::operator != (const Card& rhs) const; */
