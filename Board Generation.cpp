#include <iostream>
#include <conio.h>
using namespace std;

void board_generation();

int main() {
	
	board_generation();

	_getch();
	return 0;
}

void board_generation() {

	//Initializing the board
	int board[9][9] = { 0 };
	srand(time(0));

	cout << endl;
	//Filling random cells
	for (int row = 0; row < 9; row++) {
		int seed = 0 + rand() % 8;

		for (int col = 0; col < 9; col++) {
			if (col == seed) {
				board[row][col] = rand() % 9;
			}
			else
				board[row][col] = 0;
		}
	}

	//Printing the Board
	cout << "\t";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j]<<" ";
		}
		cout << endl<<endl;
		cout << "\t";
	}
}


