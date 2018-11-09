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

    outputfile.open("gofish_results.txt");
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

   // cout << "deck size " << d.size() << endl;

    dealHand(d, p2, numCards);

   // cout << "deck size " << d.size() << endl;


    outputfile << p1.getName() <<" has : " << p1.showHand() << endl;
    outputfile << p2.getName() <<" has : " << p2.showHand() << endl;

    outputfile << "P1 hand size " << p1.getHandSize() << endl;
    outputfile << "P2 hand size " << p2.getHandSize() << endl;


    Card *card1 = new Card();
    Card *card2 = new Card();
    bool checker = true;


    // checks hand for book right after cards dealt
    // player 1
    for(int i = 0; i < 2; i++) {
        if (p1.checkHandForBook(*card1, *card2)) {
         /*   cout << card1->toString() << " " << card2->toString() << endl;
            cout << "true" << endl; */
            p1.bookCards(*card1, *card2);
            p1.removeCardFromHand(*card1);

          //  outputfile << "p1 new hand: " << p1.showHand() << endl;

            p1.removeCardFromHand(*card2);

          //  outputfile << "p1 new hand: " << p1.showHand() << endl;
        }
    }

    // player 2
    for(int i = 0; i < 2; i++) {
        if (p2.checkHandForBook(*card1, *card2)) {
           /* cout << card1->toString() << " " << card2->toString() << endl;
            cout << "true" << endl; */
            p2.bookCards(*card1, *card2);
           // outputfile << "p2 books " << p2.showBooks() << endl;

            p2.removeCardFromHand(*card1);

          //  outputfile << " p2 new hand: " << p2.showHand() << endl;

         //   outputfile << "p2 remove card " << card2->toString() << endl;
            p2.removeCardFromHand(*card2);

         //   outputfile << "p2 new hand: " << p2.showHand() << endl;
        }
    }


        Player currentAsker = p1;
        Player currentAnswerer = p2;

    int askerbooksize = currentAsker.getBookSize();
    int answererbooksize = currentAnswerer.getBookSize();

        // gameplay begins
       // for(int i = 0; i < 4; i++) {
       while( (askerbooksize < 28) && (answererbooksize < 28) ){

            outputfile << "\n" << endl;

         /*   outputfile << "decksize " << d.size() << endl;
           outputfile << "asker booksize " << currentAsker.getBookSize() << endl;
           outputfile << "answerer booksize " << currentAnswerer.getBookSize() << endl; */

            if(currentAsker.getHandSize() == 0){
                outputfile << currentAsker.getName() << "'s hand is empty." << endl;
                if(d.size() > 0) {
                    Card dealt = d.dealCard();
                    currentAsker.addCard(dealt);
                    outputfile << currentAsker.getName() << " draws " << dealt.toString() << endl;
                    Card *book1 = new Card();
                    Card *book2 = new Card();
                    if(currentAsker.checkHandForBook(*book1, *book2)){
                        currentAsker.bookCards(*book1, *book2);
                        currentAsker.removeCardFromHand(*book1);
                        currentAsker.removeCardFromHand(*book2);

                    }
                }
            }

            if(currentAnswerer.getHandSize() == 0){
                outputfile << currentAnswerer.getName() << "'s hand is empty." << endl;
                if(d.size() > 0) {
                    Card dealt = d.dealCard();
                    currentAnswerer.addCard(dealt);
                    outputfile << currentAnswerer.getName() << " draws " << dealt.toString() << endl;
                    Card *book1 = new Card();
                    Card *book2 = new Card();
                    if(currentAnswerer.checkHandForBook(*book1, *book2)){
                        currentAnswerer.bookCards(*book1, *book2);
                        currentAnswerer.removeCardFromHand(*book1);
                        currentAnswerer.removeCardFromHand(*book2);

                    }
                }
            }

          /*  outputfile << currentAsker.getName() << "'s hand -- " << currentAsker.showHand() << endl;
            outputfile << currentAnswerer.getName() << "'s hand -- " << currentAnswerer.showHand() << endl; */

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
               // cout << "same rank true" << endl;
                outputfile << answererName << ": Yes, I have a " << askerrankChosen << "." << endl;

                //answerer's hand now changes below
                Card answererCardMatched = currentAnswerer.removeCardFromHand(askercardChosen);
                //Book cards into asker's hand
                // ---> figure out how to get the card found from sameRankinHand to book
                currentAsker.addCard(answererCardMatched);

               // outputfile << "after added -- " <<  currentAsker.getName() << " hand now: " << currentAsker.showHand() << endl ;
               // outputfile << currentAnswerer.getName() << "'s hand now: " << currentAnswerer.showHand() << endl;

                currentAsker.removeCardFromHand(askercardChosen);
                currentAsker.removeCardFromHand(answererCardMatched);
                //currentAnswerer.removeCardFromHand(answererCardMatched);

                currentAsker.bookCards(askercardChosen, answererCardMatched);
               // outputfile << currentAsker.getName() <<"book : " << currentAsker.showBooks() << endl;

                // DEBUG //
              //  outputfile << "after removed -- " <<  currentAsker.getName() << " hand now: " << currentAsker.showHand() << endl ;
              //  outputfile << currentAnswerer.getName() << "'s hand now: " << currentAnswerer.showHand() << endl;

              outputfile << currentAsker.getName() << " books the " << askercardChosen.getRank() << endl;

            // go fish
            } else {
              //  cout << "same rank false" << endl;
                outputfile << answererName << ": Go Fish" << endl;

                if(d.size() > 0) {
                    Card dealt = d.dealCard();
                    currentAsker.addCard(dealt);      //currentAsker draws from deck
                    outputfile << currentAsker.getName() << " draws " << dealt.toString() << endl;
                    Card *book1 = new Card();
                    Card *book2 = new Card();
                    if(currentAsker.checkHandForBook(*book1, *book2)){
                        currentAsker.bookCards(*book1, *book2);
                        currentAsker.removeCardFromHand(*book1);
                        currentAsker.removeCardFromHand(*book2);
                    }
                }

              //  outputfile << "askers hand -- " << currentAsker.showHand() << endl;


                //checksHandforBook
            }


            // if asker is p1, switch asker to p2
            if (currentAsker.getName() == p1.getName()) {

                Player holdAsker = currentAsker;
                currentAsker = currentAnswerer;
                currentAnswerer = holdAsker;

                askerbooksize = currentAsker.getBookSize();
                answererbooksize = currentAnswerer.getBookSize();

            }
                // if asker is p2, switch asker to p1
            else {

                Player holdAsker = currentAsker;
                currentAsker = currentAnswerer;
                currentAnswerer = holdAsker;

                askerbooksize = currentAsker.getBookSize();
                answererbooksize = currentAnswerer.getBookSize();

            }

     //   }

         /*  outputfile << "decksize " << d.size() << endl;
           outputfile << "asker booksize " << currentAsker.getBookSize() << endl;
           outputfile << "answerer booksize " << currentAnswerer.getBookSize() << endl; */

           if((askerbooksize==26) && (answererbooksize==26)){
               askerbooksize = 29;
               answererbooksize = 29;
           }

     } // end of gameplay while loop



    outputfile << "\n" << endl;

    // determines winner
    if(currentAnswerer.getBookSize() > currentAsker.getBookSize()){
        outputfile << currentAnswerer.getName() << "'s book size: " << currentAnswerer.getBookSize() << endl;
        outputfile << currentAsker.getName() << "'s book size: " << currentAsker.getBookSize() << endl;
        outputfile << "\n" << endl;
        outputfile << currentAnswerer.getName() << " wins!" << endl;
    }
    else if (currentAnswerer.getBookSize() == currentAsker.getBookSize()){
        outputfile << currentAnswerer.getName() << "'s book size: " << currentAnswerer.getBookSize() << endl;
        outputfile << currentAsker.getName() << "'s book size: " << currentAsker.getBookSize() << endl;
        outputfile << "\n" << endl;
        outputfile << "It's a tie!" << endl;
    }
    else {
        outputfile << currentAnswerer.getName() << "'s book size: " << currentAnswerer.getBookSize() << endl;
        outputfile << currentAsker.getName() << "'s book size: " << currentAsker.getBookSize() << endl;
        outputfile << "\n" << endl;
        outputfile << currentAsker.getName() << " wins!" << endl;
    }



    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}




