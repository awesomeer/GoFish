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



void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    int numCards = 5;
    
    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;
	
	Card c1;
	Card c2;
	
	cout << p1.checkHandForPair(c1, c2) << endl;
	cout << c1.toString() << " " << c2.toString() << endl;
	
	cout << p1.showBooks() << endl;
	cout << p1.showHand() << endl;
	
	// while(1){
		
		// cout << p1.getName() <<" has : " << p1.showHand() << endl;
		// cout << p2.getName() <<" has : " << p2.showHand() << endl;
		
		// // Card play = p1.chooseCardFromHand();
		// // if(p2.cardInHand(play)){
			// // p1.addCard(p2.removeCardFromHand(play));
		// // }
		// // else{
			// // p1.addCard(d.dealCard());
		// // }
		
		// // play = p2.chooseCardFromHand();
		// // if(p1.cardInHand(play)){
			// // p2.addCard(p1.removeCardFromHand(play));
		// // }
		// // else{
			// // p2.addCard(d.dealCard());
		// // }
		
		// Card play = p1.chooseCardFromHand();
		
		// if(p2.rankInHand(play)){
			// for(int i = 0; i < 4; i++){
				// Card test(play.getRank(), (Card::Suit) i);
				// if(p2.cardInHand(test)){
					// p1.addCard(p2.removeCardFromHand(test));
				// }
			// }
		// }
		// else{
			// p1.addCard(d.dealCard());
		// }
		
		// play = p2.chooseCardFromHand();
		
		// if(p1.rankInHand(play)){
			// for(int i = 0; i < 4; i++){
				// Card test(play.getRank(), (Card::Suit) i);
				// if(p1.cardInHand(test)){
					// p2.addCard(p1.removeCardFromHand(test));
				// }
			// }
		// }
		// else{
			// p2.addCard(d.dealCard());
		// }
		
		
		// system("PAUSE");
		
	// }
    
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   


