//Assignment: 3
//Author: reuven hadad, ID 312264781:
#include "Pile.h"
Pile::Pile(int size) {
	if (size < 2 || size>52) { //if size is not valid
		pileSize = 20;
	}
	else if (size % 2 == 1) { //if size is odd
		pileSize = --size; //prefix
	}
	else { //if size is valid
		pileSize = size;
	}
	cards = new Card[pileSize];
	fill();
	mix();
}
Pile::~Pile() { //free memory allocation
	if (cards != NULL)
		delete[] cards;
}
void Pile::fill() { //filling the pile
	char ch = 'A';
	for (int i = 0 ; i < pileSize ; i++) {
		cards[i].SetLetter(ch);
		i = i + 1;
		cards[i].SetLetter(ch);
		ch = ch + 1;
	}
}
void Pile::ChangeState(int index) {
	cards[index].ChangeState();
}
void Pile::mix() { //mixing the pile
	int index1, index2;
	char temp;
	srand(time(NULL));
	for (int i = 0;i < pileSize;i++) {
		index1 = rand() % pileSize;
		index2 = rand() % pileSize;
		if (cards[index1].GetLetter() != cards[index2].GetLetter()) {
			temp = cards[index1].GetLetter();
			cards[index1].SetLetter(cards[index2].GetLetter());
			cards[index2].SetLetter(temp);
		}
	}
}
void Pile::PrintPile() const {
	int col = 1, row = 1;
	// printing the columns numbers
	while (col <= 5) {
		cout << "\t" << col;
		col++;
		if (col >= pileSize)
			break;
	}
	cout << endl << row << "\t";
	col = 0;
	for (int i = 0 ; i < pileSize ; i++) {
		cards[i].PrintCard();
		col++;
		if (col == 5 && i < pileSize - 1) {			
			col = 0;
			cout << endl << ++row << "\t";
		}
	}
	cout << endl << endl;
}
void Pile::PrintDiscoveredPile() const { // prints the pile visibly
	int col = 1, row = 1;
	// printing the columns numbers
	while (col <= 5) {
		cout << "\t" << col;
		col++;
		if (col >= pileSize)
			break;
	}
	cout << endl << row << "\t";
	col = 0;
	for (int i = 0; i < pileSize; i++) {
		cout << "[ " << cards[i].GetLetter() << " ]  ";
		col++;
		if (col == 5 && i < pileSize - 1) {
			col = 0;
			cout << endl << ++row << "\t";
		}
	}
	cout << endl << endl;

}
bool Pile::GetState(int index)
{
	if (cards[index].GetState())
	{
		return true;
	}
		return false;
}
// return the latter
char Pile::returnLetter(int index) const {
	if (index >= pileSize || index < 0) {
		cout << "The index is invalid, your game is over!!!!" << endl;
		exit(1);
	}
	char a;
	a = cards[index].GetLetter();
	return a;
}
