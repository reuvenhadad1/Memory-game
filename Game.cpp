//Assignment: 3
//Author: reuven hadad, ID 312264781:
#include "Game.h"
void Game::askForCards(){
	int choice = 1, index1, index2;
	//TO DO : not work good need to fix thr gat state sitoian 
	while (choice == 1) { //while the user wants continue to play
		cout << "Choose the first card by entering the row and col number" << endl;
		index1 = SelectCard(); //first card
		pile.returnLetter(index1);
		if ((pile.GetState(index1) == true))
		{
			cout << "The card you chose is already open, try the round again" << endl;
		}
		cout << "Choose the second card by entering the row and col number" << endl;
		index2 = SelectCard(); //second card
		if ((pile.GetState(index2) == true))
		{
			cout << "The card you chose is already open, try the round again"<<endl;

		}
		if (index1 == index2)
		{
			cout << "you cant open the same card twice the game wil exit now" << endl;
			exit(1);
		}
		if (pile.returnLetter(index1) == pile.returnLetter(index2)) {
			cout << "Match!!!!! ";
			num_Of_Pairs++;
			pile.ChangeState(index1);
			pile.ChangeState(index2);

		}
		else {
			cout << "No match!!!!! ";
		}
		pile.PrintPile();
		if (Winner()==true) {
			cout << endl << endl << "You Won!!!!!!! BYE BYE" << endl;
			break; //exit the game
		}
		cout << "Do you want to continue? Press 1 to continue, otherwise press 0" << endl;
		cin >> choice;
	}
}
// user selact card by row and col and return index
int Game::SelectCard(){
	pile.PrintPile();
	int index;
	int row, col;
	cout << "  row: ";
	cin >> row;
	cout << "  col: ";
	cin >> col;
	index = (--row) * 5 + (--col);
	return index;
}
// user win the game 
bool Game::Winner() const {
	if (num_Of_Pairs == pile.getSize() / 2)
		return true;
	return false;
}
// num of paris thet the user found 
Game::Game(int size) : pile(size), num_Of_Pairs(0){ //ctor
}
void Game::Run() {
	pile.PrintDiscoveredPile();
	// TO DO : change to 30 sec waiting
	int sec = 5;
	clock_t start_time = clock();
	clock_t end_time = sec * 1000 + start_time;
	while (clock() != end_time)
		;	system("cls");
	askForCards();

}

