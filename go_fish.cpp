// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>	   // Provides EXIT_SUCCESS

#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:


// int main(){
	// Deck t;
	// Player p("Mithilesh");
	// p.addCard(t.dealCard());
	// p.chooseCardFromHand();
	
// }

Deck d;

void dealHand(Deck &d, Player &p, int numCards);
bool turn(Player &p1, Player &p2);
void checkForBooks(Player &p1);

int main( )
{
    int numCards = 5;
    
    Player p1("Joe");
    Player p2("Jane");
    
      //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
	
	while(1){
		
		while(turn(p1, p2)){}
		system("PAUSE");
		while(turn(p2, p1)){}
		system("PAUSE");
		
	}
    
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   
bool turn(Player &p1, Player &p2){
	Card play;
	bool success;
	cout << p2.getName() <<" has " << p2.showHand() << endl;
	
	play = p1.chooseCardFromHand();
		
	if(p2.rankInHand(play)){
		cout << p2.getName() << ": Yes I have a " << play.rankString() << endl;
		for(int i = 0; i < 4; i++){
			Card test(play.getRank(), (Card::Suit) i);
			if(p2.cardInHand(test)){
				p1.addCard(p2.removeCardFromHand(test));
			}
		}
		success = true;
	}
	else{
		cout << p2.getName() << ": Go Fish" << endl;
		Card add = d.dealCard();
		p1.addCard(add);
		cout << p1.getName() << " Draws a " << add.toString() << endl;
		success = false;
	}
	checkForBooks(p1);
	cout << endl;
	return success;
}

void checkForBooks(Player &p1){
	Card check1, check2;
	while(p1.checkHandForPair(check1, check2)){
			p1.bookCards(check1, check2);
			cout << p1.getName() << " books cards " << check1.toString() << " " << check2.toString() << endl;
	}
}