//Assignment: 3
//Author: reuven hadad, ID 312264781:
#include "Game.h"
int main() {
	int no;
	cout << "Enter number of cards you want to play with" << endl;
	cin >> no;
	Game m(no);
	m.Run();
	return 0;
}