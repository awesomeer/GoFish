#include "deck.h"
#include <ctime>
#include <cstdlib>

Deck::Deck(){
	srand(time(0));
	
	myIndex = 0;
	for(int i = 1; i <= 13; i++){
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
	}
	myIndex = 0;
}

void Deck::shuffle(){
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
	if(size() != 0){
		return myCards[myIndex++];
	}
}

int Deck::size() const{
	return SIZE - myIndex;
}