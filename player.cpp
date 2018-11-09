//
// Created by Asad Ahmed and Janine Bariuan on 11/6/2018.
//

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "card.h"
#include "deck.h"
#include "player.h"

Player::Player() {}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);

    // DEBUG //
   /* cout << "book: " << endl;
    for(int i = 0; i < myBook.size(); i++){
        cout << myBook[i].getRank() << endl;
    } */
}

bool Player::checkHandForBook(Card &c1, Card &c2){

    //cout << "reached checkHand " << endl;

    int numMatches = 0;
    bool bookFound = false;

    for(int i = 0; i < getHandSize(); i++){

       // cout << "reached c1 " << endl;
        //cout << myHand[i].getRank() << endl;
        c1 = myHand[i];
        int c1Rank = c1.getRank();
        //cout << "c1 rank " << c1Rank << endl;

        for(int j = i + 1; j < getHandSize(); j++){

            //cout << "reached c2 " << endl;
            c2 = myHand[j];
            int c2Rank = c2.getRank();
           // cout << "c2 rank " << c2Rank << endl;

            if(c1Rank == c2Rank){
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }

        }

      //  cout << "i = " << i << endl;

    }

    return false;

}

Card Player::chooseCardFromHand() const {

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

    Card *object = new Card();                               //matches the input and returns that card and deletes it from the hand
    Card *temp = new Card();

    for(int i=0; i < myHand.size() ; i++){         // desired card = want to remove
        if(myHand[i].getRank() == c.getRank()){

            // DEBUG //
         //   cout << "remove card find rank: " << c.getRank() << " myHand: " << myHand[i].getRank() << endl;

            *object=myHand[i];                      // if found desired card, then put in object
            *temp = myHand[myHand.size()-1];        // temp has end card in vector
            myHand[myHand.size()-1] = myHand[i];    //puts desired card at end
            myHand[i] = *temp;                        // end card now replaced desired cards location
            myHand.pop_back();                      // removes desired card from hand

         //   cout << "removed: " << object->toString() << endl;

            return *object;                         // returns desired card
        }
    }




}

string Player::showHand() const {
    string current;
    string outHand;
    for(int i=0;i<myHand.size();i++){
        current = myHand[i].toString();
        //cout << "current card " << current << endl;
        outHand = outHand + " " + current;
        //cout << "outhand " << outHand << endl;
    }

    return outHand;
}


string Player::showBooks() const{

    string current;
    string outBook;
    for(int i=0;i < myBook.size() ;i++){
        current = myBook[i].toString();
        //cout << "current card " << current << endl;
        outBook = outBook + " " + current;
        //cout << "outhand " << outHand << endl;
    }

    return outBook;

}

//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

// checking answerer's hand
bool Player::sameRankInHand(Card c) const{

    //c = asker's card
    int answererRank;
    bool checker = false;

    for(int i = 0; i < myHand.size(); i++){

        answererRank = myHand[i].getRank();
        if(answererRank == c.getRank()){
            checker = true;
        }

    }

    return checker;

}


int Player::getHandSize() const {
    return myHand.size();
}


int Player::getBookSize() const {
    return myBook.size();
}