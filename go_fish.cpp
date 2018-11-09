// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <fstream>

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{

    ofstream outputfile;

    outputfile.open("gofish.txt");
    int numCards = 5;

    Player p1("Asad");
    Player p2("Janine");

    string p1name = p1.getName();
    string p2name = p2.getName();
    outputfile << p1.getName() << endl;
    outputfile << p2.getName() << endl;

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);

    cout << "deck size " << d.size() << endl;

    dealHand(d, p2, numCards);

    cout << "deck size " << d.size() << endl;


    outputfile << p1.getName() <<" has : " << p1.showHand() << endl;
    outputfile << p2.getName() <<" has : " << p2.showHand() << endl;

    outputfile << "P1 hand size " << p1.getHandSize() << endl;
    outputfile << "P2 hand size " << p2.getHandSize() << endl;

    // put cards of same rank in book
    //for(int i = 0; i < p1.getHandSize(); i++)
    Card *card1 = new Card();
    Card *card2 = new Card();
   /* bool checker = true;

    for(int i = 0; i < p1.getHandSize(); i++) {
        //while(checker) {
        while (p1.checkHandForBook(*card1, *card2)) {
            cout << card1->getRank() << " " << card2->getRank() << endl;
            cout << "true" << endl;
            p1.bookCards(*card1, *card2);
        }
    } */
           /* else{
                cout << "false" << endl;
                checker = false;
            } */
       // }


        Player currentAsker = p1;
        Player currentAnswerer = p2;

        // gameplay begins
        for(int i = 0; i < 2; i++) {
            //while((d.size() > 0) && (p1.getHandSize() > 0) && (p2.getHandSize() > 0)){

            string askerName = currentAsker.getName();
            string answererName = currentAnswerer.getName();

            Card askercardChosen = currentAsker.chooseCardFromHand();
            int askerrankChosen = askercardChosen.getRank();
            outputfile << askerName << " asks: Do you have a " << askerrankChosen << "?" << endl;

            /* Go thru p2 deck and see if have same rank as p1's card
             * IF MATCH
             *    put p1 card and p2 card -> p1 book
             *
             * ELSE
             *    p2 says Go Fish
             *    p1 draws from deck (print card drawn)
             *
             * Player 2's turn
             */

            // checking through P2's hand to see if matches
            if (currentAnswerer.sameRankInHand(askercardChosen)) {
                cout << "same rank true" << endl;
                outputfile << answererName << ": Yes, I have a " << askerrankChosen << "." << endl;
            } else {
                cout << "same rank false" << endl;
                outputfile << answererName << ": Go Fish" << endl;
            }

            outputfile << "\n" << endl;

            // if asker is p1, switch asker to p2
            if (currentAsker.getName() == p1.getName()) {
                currentAsker = p2;
                currentAnswerer = p1;
            }
                // if asker is p2, switch asker to p1
            else {
                currentAsker = p1;
                currentAnswerer = p2;
            }

        }







     // }

    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}




