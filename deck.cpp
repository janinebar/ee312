
#include <iostream>

#include <string>

#include <cstdlib>

#include <ctime>

#include "deck.h"

#include "card.h"

using namespace std;

Deck::Deck() {
    for(int i=1;i<14;i++){
        Card *object = new Card(i, Card::spades);
        myCards[i-1] = *object;
    }
    for(int i=14;i<27;i++){
        Card *object = new Card(i-13, Card::hearts);
        myCards[i-1] = *object;
    }
    for(int i=27;i<40;i++){
        Card *object = new Card(i-26, Card::clubs);
        myCards[i-1] = *object;
    }
    for(int i=40;i<53;i++){
        Card *object = new Card(i-39, Card::diamonds);
        myCards[i-1] = *object;
    }
    myIndex=0;

  /*  // DEBUG //
   for(int j = 0; j < 52; j++){
        cout << myCards[j].toString() << endl;
    }

    cout << "\n" << endl; */

}

void Deck::shuffle() {
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);
    int deck_index1 = 0;
    int deck_index2 = 0;

    Card temp[1];  // holds card to be swapped
    for(int i=0;i<SIZE;i++) {
        deck_index1 = (rand() % size());
        deck_index2 = (rand() % size());

        //cout << "indexes: " << deck_index1 << " " << deck_index2 << endl;
        //cout << "swap: " << myCards[deck_index1].toString() << " " << myCards[deck_index2].toString() << endl;

        temp[0] = myCards[deck_index2];
        myCards[deck_index2] = myCards[deck_index1];
        myCards[deck_index1] = temp[0];
    }

    // DEBUG //
    for(int j = 0; j < 52; j++){
         cout << myCards[j].toString() << endl;
     }
}

Card Deck::dealCard(){
    if(size() > 0) {
        Card dealt;
        dealt = myCards[myIndex];
        cout << "index " << myIndex << endl;
        myIndex++;
        return dealt;
    }
}

int  Deck::size() const{

    int testSize = SIZE-myIndex;

    // DEBUG //
   /* for(int j = 0; j < testSize; j++){
        cout << myCards[j].toString() << endl;
    }
    // */

    return SIZE-myIndex;
}