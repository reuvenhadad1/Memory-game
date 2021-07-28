#pragma once
//Assignment: 3
//Author: reuven hadad, ID 312264781:
#include "Card.h"
class Pile {
	Card* cards;
	int pileSize;
public:
	Pile(int size);
	~Pile();
	void mix();
	void fill();
	void ChangeState(int index);
	void PrintPile()const;
	void PrintDiscoveredPile()const;
	bool GetState(int);
	int getSize()const { return pileSize; }
	char returnLetter(int index)const;
};