#include "player.h"
#include <string>
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

Player::Player(){
	myName = "";
}

void Player::addCard(Card c){
	myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){
	myBook.push_back(c1);
	myBook.push_back(c2);
	
	removeCardFromHand(c1);
	removeCardFromHand(c2);
}

bool Player::rankInHand(Card c) const{
	for(Card i : myHand){
		if(i.getRank() == c.getRank()){
			return true;
		}
	}
	
	return false;
}




Card Player::chooseCardFromHand() const{
	srand(time(NULL));
	
	int index = rand() % getHandSize();
	Card ret = myHand.at(index);
	cout << myName << ": Do you have a " << ret.rankString(ret.getRank()) << endl;
	return ret;
}

bool Player::cardInHand(Card c) const{
	for(Card i : myHand){
		if(c == i)
			return true;
	}
	
	return false;
}

Card Player::removeCardFromHand(Card c){
	int index = 0;
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
	string s = "";
	for(Card c : myHand){
		s += c.toString() + " ";
	}
	return s;
}

string Player::showBooks() const{
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
