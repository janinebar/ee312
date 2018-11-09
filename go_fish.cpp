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

    outputfile << p1.getName() << endl;
    outputfile << p2.getName() << endl;

    Deck d;  //create a deck of cards
    //d.shuffle();

    dealHand(d, p1, numCards);

    cout << "deck size " << d.size() << endl;

    dealHand(d, p2, numCards);

    cout << "deck size " << d.size() << endl;


    outputfile << p1.getName() <<" has : " << p1.showHand() << endl;
    outputfile << p2.getName() <<" has : " << p2.showHand() << endl;

    outputfile << "P1 hand size " << p1.getHandSize() << endl;
    outputfile << "P2 hand size " << p2.getHandSize() << endl;


      while((d.size() > 0) && (p1.getHandSize() > 0) && (p2.getHandSize() > 0)){

          Card cardChosenFromHand = p1.chooseCardFromHand();
          outputfile << p1.getName() << " asks: Do you have a " << cardChosenFromHand << "?" <<endl;


      }

    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}




