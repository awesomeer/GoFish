#include "card.h"
#include <iostream>
#include <string>

using namespace std;

Card::Card(){
	myRank = 1;
	mySuit = spades;
}

Card::Card(int rank, Suit s){
	myRank = rank;
	mySuit = s;
}

string Card::toString() const{
	return rankString(myRank) + suitString(mySuit);
}

bool Card::sameSuitAs(const Card& c) const{
	return (suitString(mySuit)[0]) == (c.toString()[1]);
}

int Card::getRank() const{
	return myRank;
}

string Card::suitString(Suit s) const{
	switch(s){
		case spades:
			return "s";
		case hearts:
			return "h";
		case diamonds:
			return "d";
		case clubs:
			return "c";
		default:		//Dont know what to return for default
			return "s";
	}
}

string Card::rankString() const{
	return rankString(myRank);
}

string Card::rankString(int r) const{
	switch(r){
		case 1:
			return "A";
		case 11:
			return "J";
		case 12:
			return "Q";
		case 13:
			return "K";
	}
	return to_string(r);
}

bool Card::operator == (const Card& rhs) const{
	return toString() == rhs.toString();
}

bool Card::operator != (const Card& rhs) const{
	return !(*this == rhs);
}

ostream& operator << (ostream& out, const Card& c){
	return out << c.toString();
}
