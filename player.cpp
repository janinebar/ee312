//
// Created by asada on 11/6/2018.
//

#include <iostream>
#include <string>
#include <vector>


#include "card.h"
#include "deck.h"
#include "player.h"

Player::Player() {}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myHand.pop_back(c1);
    myBook.push_back(c2);
    myHand.pop_back(c2);
}

string Player::showHand() const {
/*    for(int i=0;i<myHand.size();i++){
        cout<<myHand[i] <<endl;
    }*/
}

int Player::getHandSize() const {
   return myHand.size();
}
int Player::getBookSize() const {
    return myBook.size();
}