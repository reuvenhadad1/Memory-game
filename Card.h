#pragma once 
//Assignment: 3
//Author: reuven hadad, ID 312264781:
#include <iostream>
#include <ctime>
using namespace std;
class Card {
	bool state; // true - the card is open, false - the card is closed
	char letter;
public:
	Card();
	void ChangeState();
	bool CompareCards(const Card & other)const;
	void PrintCard()const;
	void SetLetter(char letter) { this->letter = letter; } //set letter
	char GetLetter()const { return letter; } //get letter
	void SetState(bool state) { this->state = state; } //set state
	bool GetState()const { return state; } //get state

};