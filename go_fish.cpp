//Mithilesh Konakanchi mk38328

// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>	   // Provides EXIT_SUCCESS
#include <fstream>

#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:

void dealHand(Deck &d, Player &p, int numCards);
bool turn(Player &p1, Player &p2, Deck &d, ofstream &outFile);
void checkForBooks(Player &p1, ofstream &outFile);
void checkWinPlayer(Player &p1, Player &p2, ofstream &outFile);
void checkTie(Player &p1, Player &p2 ,Deck &d, ofstream &outFile);



int main( )
{
	
	ofstream out;
	out.open("gofish_results.txt");
	
    int numCards = 7;
	
    
    Player p1("Joe");
    Player p2("Jane");
    
    //create a deck of cards
	Deck d;
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
	
	while(1){
		
		//if turn returns true player1 goes again
		while(turn(p1, p2, d, out)){}
		//system("PAUSE");
		
		
		
		while(turn(p2, p1, d, out)){}
		//system("PAUSE");
		
	}
    
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
	//deals numCards to the player from the deck
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}
   
bool turn(Player &p1, Player &p2, Deck &d, ofstream &outFile){
	Card play;
	//success is true if player1 guessed right; false otherwise
	bool success;
	
	//Shows the players hands before the turn starts
	outFile << p1.getName() <<" has " << p1.showHand() << endl;
	outFile << p2.getName() <<" has " << p2.showHand() << endl;
	
	cout << p1.getName() <<" has " << p1.showHand() << endl;
	cout << p2.getName() <<" has " << p2.showHand() << endl;
	
	//If the players hand is empty they automatically draw a card from the deck
	if(p1.getHandSize() != 0){
		play = p1.chooseCardFromHand();
		outFile << p1.getName() << ": Do you have a " << play.rankString() << endl;
		cout << p1.getName() << ": Do you have a " << play.rankString() << endl;
		
		//If the player2 has the rank in hand they give all cards with the same rank to
		//the other player
		if(p2.rankInHand(play)){
			outFile << p2.getName() << ": Yes I have a " << play.rankString() << endl;
			cout << p2.getName() << ": Yes I have a " << play.rankString() << endl;
			//For loop checks for the same rank with all suits
			//and adds it to the player1's hand
			for(int i = 0; i < 4; i++){
				Card test(play.getRank(), (Card::Suit) i);
				if(p2.cardInHand(test)){
					p1.addCard(p2.removeCardFromHand(test));
				}
			}
			success = true;
		}
		else{
			//if the rank is not in hand player1 draws a card from the deck
			outFile << p2.getName() << ": Go Fish" << endl;
			cout << p2.getName() << ": Go Fish" << endl;
			if(d.size()){
				Card add = d.dealCard();
				p1.addCard(add);
				outFile << p1.getName() << " draws a " << add.toString() << endl;
				cout << p1.getName() << " draws a " << add.toString() << endl;
			}
			else{
				outFile << p1.getName() << " draws no cards" << endl;
				cout << p1.getName() << " draws no cards" << endl;
			}
			success = false;
		}
	}
	else{
		outFile << p1.getName() << " has no cards" << endl;
		outFile << p2.getName() << ": Go Fish" << endl;
		
		cout << p1.getName() << " has no cards" << endl;
		cout << p2.getName() << ": Go Fish" << endl;
		if(d.size()){
			Card add = d.dealCard();
			p1.addCard(add);
			
			outFile << p1.getName() << " draws a " << add.toString() << endl;
			cout << p1.getName() << " draws a " << add.toString() << endl;
		}
		else{
			outFile << p1.getName() << " draws no cards" << endl;
			cout << p1.getName() << " draws no cards" << endl;
		}
		success = false;
	}
	//checks for books and pairs when the turn is over
	checkForBooks(p1, outFile);
	outFile << endl;
	cout << endl;
	//checks for victory conditions and tie condition
	checkWinPlayer(p1, p2, outFile);
	checkTie(p1, p2, d, outFile);
	
	return success;
}

void checkForBooks(Player &p1, ofstream &outFile){
	Card check1, check2;
	//While there are pairs in the players hands it keeps on booking cards
	while(p1.checkHandForPair(check1, check2)){
			p1.bookCards(check1, check2);
			outFile << p1.getName() << " books cards " << check1.toString() << " " << check2.toString() << endl;
			cout << p1.getName() << " books cards " << check1.toString() << " " << check2.toString() << endl;
	}
}

void checkWinPlayer(Player &p1, Player &p2, ofstream &outFile){
	//If the amount of pairs a player is greater than 13 than he/she won and the players books are outputed
	//also exits the game
	if(p1.getBookSize()/2 > 13){
		outFile << "Player " << p1.getName() << " won with " << p1.getBookSize()/2 << " books" << endl;
		outFile << p1.getName() << ": " << p1.showBooks() << endl << endl;
		outFile << p2.getName() << ": " << p2.showBooks() << endl;
		
		cout << "Player " << p1.getName() << " won with " << p1.getBookSize()/2 << " books" << endl;
		cout << p1.getName() << ": " << p1.showBooks() << endl << endl;
		cout << p2.getName() << ": " << p2.showBooks() << endl;
		//cout << "Deck Size: " << d.size() << endl;
		outFile.close();
		exit(0);
	}
}

void checkTie(Player &p1, Player &p2, Deck &d, ofstream &outFile){
	//Checks if the deck has 0 cards and all the players have 0 cards in their hands
	//therefore all the cards are booked equally and the game is a tie
	//Outputs the player's books
	if(d.size() == 0 && p1.getHandSize() == 0 && p2.getHandSize() == 0){
		outFile << "Game ended in a tie" << endl;
		outFile << p1.getName() << ": " << p1.showBooks() << endl << endl;
		outFile << p2.getName() << ": " << p2.showBooks() << endl;
		
		cout << "Game ended in a tie" << endl;
		cout << p1.getName() << ": " << p1.showBooks() << endl << endl;
		cout << p2.getName() << ": " << p2.showBooks() << endl;
		
		outFile.close();
		exit(0);
	}
}