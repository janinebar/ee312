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

int Player::getHandSize() const {
   return myHand.size();
}
int Player::getBookSize() const {
    return myBook.size();
}