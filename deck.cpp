#include "deck.h"
#include <ctime>
#include <cstdlib>

Deck::Deck(){
	srand(time(0));
	
	myIndex = 0;
	Card::Suit s;
	for(int s = Card::spades; s <= Card::clubs; s++){
		for(int i = 1; i <= 13; i++){
			Card add(i, (Card::Suit)s);
			myCards[myIndex] = add;
		}
	}
	myIndex = 0;
}

void Deck::shuffle(){
	srand(time(NULL));
	for(int i = 0; i < 200; i++){
		Card temp;
		int beg = rand() % 52;
		int end = rand() % 52;
		
		temp = myCards[beg];
		myCards[beg] = myCards[end];
		myCards[end] = temp;
	}
}

Card Deck::dealCard(){
	if(size() != 0)
		return myCards[myIndex++];
}

int Deck::size() const{
	return SIZE - myIndex;
}