#include <iostream>

#include <string>

#include <cstdlib>

#include <ctime>

#include "deck.h"

#include "card.h"

using namespace std;

Deck::Deck() {
    for(int i=0;i<52;i++;){
        for(intj=0;j<4j++){
            myCards[i].getRank();
        }
    }
    myIndex=0;
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
