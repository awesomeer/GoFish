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
}

Card Player::chooseCardFromHand() const{
	srand(time(NULL));
	
	int index = rand() % getHandSize();
	Card ret = myHand.at(index);
	cout << "Do you have a " << ret.rankString(ret.getRank()) << endl;
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
			myHand.erase(myHand.begin()+index);
			return c;
		}
		index++;
	}
	return c;
}

string Player::showHand() const{
	return "";
}

string Player::showBooks() const{
	return "";
}

int Player::getHandSize() const{
	return myHand.size();
}

int Player::getBookSize() const{
	return myBook.size();
}
