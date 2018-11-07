#include <iostream>

#include <string>

#include <cstdlib>

#include <ctime>

#include "deck.h"

#include "card.h"

using namespace std;

Deck::Deck() {
    for(int i=1;i<14;i++;){
        Card object = new Card(i, spades);
        myCards[i-1] = object;
    }
    for(int i=14;i<27;i++;){
        Card object = new Card(i, hearts);
        myCards[i-1] = object;
    }
    for(int i=27;i<40;i++;){
        Card object = new Card(i, clubs);
        myCards[i-1] = object;
    }
    for(int i=40;i<53;i++;){
        Card object = new Card(i, diamonds);
        myCards[i-1] = object;
    }
    myIndex=SIZE-1;
}

void Deck::shuffle() {
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);
    int deck_index1=0;
    int deck_index2=0;
    Card temp[1];
    for(int i=0;i<SIZE;i++) {
        deck_index1 = (rand() % size()) + 1;
        deck_index2 = (rand() % size()) + 1;
        temp[0] = myCards[deck_index2];
        myCards[deck_index2] = myCards[deck_index1];
        myCards[deck_index1] = temp[0];
    }
}

Card Deck::dealCard(){

    SIZE--;
}

int  Deck::size() const{
    return SIZE;
}