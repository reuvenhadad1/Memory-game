#pragma once
//Assignment: 3
//Author: reuven hadad, ID 312264781:
#include "Pile.h"
#include <stdlib.h>
class Game {
	Pile pile;
	int num_Of_Pairs; // number of pairs that the user has discovered
	void askForCards();
	int SelectCard();
	bool Winner()const;
public:
	Game(int size);
	void Run();
};