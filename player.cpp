#include "player.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Player::Player(){
	srand(time(0));
	myName = "";
}

void Player::addCard(Card c){
	myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){
	//pushes c1 and c2 to myBook
	//and removes them from the hand
	myBook.push_back(c1);
	myBook.push_back(c2);
	
	removeCardFromHand(c1);
	removeCardFromHand(c2);
}

bool Player::rankInHand(Card c) const{
	//iterates thorugh myHand comparing the rank with 
	//rank of c
	for(Card i : myHand){
		if(i.getRank() == c.getRank()){
			return true;
		}
	}
	
	return false;
}




Card Player::chooseCardFromHand() const{
	
	if(getHandSize() == 0){
		Card ret((rand() % 13) + 1, Card::spades);
		cout << myName << ": Do you have a " << ret.rankString() << endl;
		return ret;
	}
	
	//selects a random card from myHand and returns it
	int index = rand() % getHandSize();
	Card ret = myHand.at(index);
	cout << myName << ": Do you have a " << ret.rankString() << endl;
	return ret;
}

bool Player::cardInHand(Card c) const{
	//Compares all cards in myHand with c
	//returns true if found; false otherwise
	for(Card i : myHand){
		if(c == i)
			return true;
	}
	
	return false;
}

Card Player::removeCardFromHand(Card c){
	int index = 0;
	//compares all cards from myHand 
	//and erases the card from myHand
	//and returns it
	for(Card i : myHand){
		if(c == i){
			Card re = myHand.at(index);
			myHand.erase(myHand.begin()+index);
			return re;
		}
		index++;
	}
	
	return c;
}

string Player::showHand() const{
	if(getHandSize() == 0)
		return "no cards";
	
	//puts all the cards into one string and returns it
	string s = "";
	for(Card c : myHand){
		s += c.toString() + " ";
	}
	return s;
}

string Player::showBooks() const{
	//puts all the cards into one string and returns it
	string s = "";
	for(Card c : myBook){
		s += c.toString() + " ";
	}
	return s;
}

int Player::getHandSize() const{
	return myHand.size();
}

int Player::getBookSize() const{
	return myBook.size();
}


bool Player::checkHandForPair(Card &c1, Card &c2){
	//iterates thorugh every combination of cards
	//and populates c1 and c2 if the cards rand match
	//return true if match; false otherwise
	for(int i = 0; i < getHandSize()-1; i++){
		for(int j = i+1; j < getHandSize(); j++){
			if(myHand.at(i).getRank() == myHand.at(j).getRank()){
				c1 = myHand.at(i);
				c2 = myHand.at(j);
				return true;
			}
		}
	}
	
	return false;
}
