//
// Created by asada on 11/7/2018.
//

#ifndef GO_FISH_REAL_DECK_H
#define GO_FISH_REAL_DECK_H

#include "card.h"


class Deck
{
    static const int SIZE = 52;

public:


    Deck();           // pristine, sorted deck

    void shuffle();   // shuffle the cards in the current deck
    Card dealCard();   // get a card, after 52 are dealt, fail

    int  size() const; // # cards left in the deck

private:

    Card myCards[SIZE];
    int myIndex;  // current card to deal
};

#endif
