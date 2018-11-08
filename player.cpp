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
    removeCardFromHand(c1);
    myBook.push_back(c2);
    removeCardFromHand(c2);
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

Card Player::removeCardFromHand(Card c){        //not 100% sure if this is right, basically cheks if a card in the hand
    Card *object;                               //matches the input and returns that card and deletes it from the hand
    Card *temp;
    for(int i=0;i<myHand.size()-1;i++){
        if(myHand[i]==c){
            *object=myHand[i];
            *temp = myHand[myHand.size()-1];
            myHand[myHand.size()-1]=myHand[i];
            myHand[i]=*temp;
            myHand.pop_back();
            return *object;
        }
    }
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