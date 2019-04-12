#include "deck.h"
#include <ctime>
#include <cstdlib>

Deck::Deck(){
	srand(time(0));
	
	myIndex = 0;
	//iterates through the suits
	for(int i = 0; i < 4; i++){
		//iterates through the ranks
		for(int j = 1; j <= 13; j++){
			//Creates card with rank j and suit i
			//and adds it to myCardss
			Card add(j, Card::Suit(i));
			myCards[i*13+j-1] = add;
			
		}
	}
	
	/* for(int i = 1; i <= 13; i++){
		Card add(i, Card::spades);
		myCards[myIndex] = add;
		myIndex++;
	}
	for(int i = 1; i <= 13; i++){
		Card add(i, Card::hearts);
		myCards[myIndex] = add;
		myIndex++;
	}
	for(int i = 1; i <= 13; i++){
		Card add(i, Card::diamonds);
		myCards[myIndex] = add;
		myIndex++;
	}
	for(int i = 1; i <= 13; i++){
		Card add(i, Card::clubs);
		myCards[myIndex] = add;
		myIndex++;
	} */
	myIndex = 0;
}

void Deck::shuffle(){
	//Swaps the cards 200
	for(int i = 0; i < 200; i++){
		Card temp;
		//brg and end are the rwo indeices to swap
		int beg = rand() % 52;
		int end = rand() % 52;
		
		//swap the two cards
		temp = myCards[beg];
		myCards[beg] = myCards[end];
		myCards[end] = temp;
	}
}

Card Deck::dealCard(){
	if(size() != 0){
		//return card at myIndex and increment myIndex
		return myCards[myIndex++];
	}
}

int Deck::size() const{
	return SIZE - myIndex;
}