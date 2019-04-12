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
	//concatanates the two strings and returns it
	return rankString(myRank) + suitString(mySuit);
}

bool Card::sameSuitAs(const Card& c) const{
	//compares the two characters true if same; false otherwise
	return (suitString(mySuit)[0]) == (c.toString()[1]);
}

int Card::getRank() const{
	return myRank;
}

string Card::suitString(Suit s) const{
	//Switch for all Suits
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
	//Switch for special ranks
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
	//otherwise return the rank in ascii
	return to_string(r);
}

bool Card::operator == (const Card& rhs) const{
	//Compares the cards to each other true if same; false otherwise
	return toString() == rhs.toString();
}

bool Card::operator != (const Card& rhs) const{
	//just return the opposite of equals
	return !(*this == rhs);
}

ostream& operator << (ostream& out, const Card& c){
	//return outstream with toString
	return out << c.toString();
}
