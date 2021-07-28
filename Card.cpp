//Assignment: 3
//Author: reuven hadad, ID 312264781:
#include "Card.h"
Card::Card() :state(false) {

}
void Card::ChangeState() { // method which changes the state of the card
	if (state == false)
		state = true;
	else
		state = false;
}
bool Card::CompareCards(const Card & other) const { //method which gets a Card object and compares with 'this' object
	if (this->letter != other.letter)
		return false;
	return true;
}
void Card::PrintCard() const {
	if (this->state == true) //it means that the card is open
		cout << "[ " << letter << " ]  ";
	else //the card is closed
		cout << "[ ? ]  ";
}
