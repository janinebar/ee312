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
 //   myHand.pop_back();
    myBook.push_back(c2);
 //   myHand.pop_back();
}

Card Player::chooseCardFromHand() const {
    Card ask;
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);
    int player_index=0;
    player_index = (rand() % myHand.size());
    return myHand[player_index];
}

bool Player::cardInHand(Card c) const{
    for(int i=0; i<myHand.size(); i++){
        if(myHand[i].getRank()==c.getRank()){
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c){

}

string Player::showHand() const {
    string current;
    for(int i=0;i<myHand.size();i++){
        current = myHand[i].toString();
        cout<<current <<endl;
    }
}

int Player::getHandSize() const {
    return myHand.size();
}
int Player::getBookSize() const {
    return myBook.size();
}