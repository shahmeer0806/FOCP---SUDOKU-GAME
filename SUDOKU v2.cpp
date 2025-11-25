#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
using namespace std;

//PROTOTYPING
void board_generation(int board[9][9]);
void play(int board[9][9]);
bool validity(int board[9][9], int input);

//MAIN FUNCTION
int main() {

	int board[9][9];

	board_generation(board);

	//Printing the Board
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl << endl;

	}

	play(board);

    _getch();
	return 0;
}

//DEFINITION OF BOARD GENERATING FUNCTION
void board_generation(int board[9][9]) {

	srand(time(0));

	cout << endl;
	//Filling random cells
	for (int row = 0; row < 9; row++) {
		int seed = 0 + rand() % 8;

		for (int col = 0; col < 9; col++) {
			if (col == seed) {
				board[row][col] = 1 + rand() % 9;
			}
			else
				board[row][col] = 0;
		}
	}
}

//DEFINITION OF FUNCTION THAT ALLOWS USER TO PLAY THE GAME
void play(int board[9][9]) {

	int input; 

	//Filling the Board
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			if (board[row][col] == 0) {
				cout << "ENTER ELEMENT [" << row << "][" << col << "]: ";
				cin >> input;
				
				int check = validity(board, input);
				if (check == 0) {
					input = board[row][col];
				}
				else {
					cout << "ERROR" << endl;
					col--;
				}

			}
		}
		cout << endl;
	}

}

bool validity(int board[9][9], int input) {

	//For smaller board
	int mini_check = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			
			//For Row Index 0 to 2
			if (i >= 0 || i <= 2) {
				for (int k = 0; k < 3; k++) {
					//For Column Index 0 to 2
					for (int l = 0; l < 3; l++) {
						if (board[i][j] == input) {
							mini_check = 1;
						}
						else
							mini_check = 0;
					}
					//For Column Index 3 to 5
					for (int l = 3; l < 6; l++) {
						if (board[i][j] == input) {
							mini_check = 1;
						}
						else
							mini_check = 0;
					}
					//For Column Index 6 to 8
					for (int l = 6; l < 9; l++) {
						if (board[i][j] == input) {
							mini_check = 1;
						}
						else
							mini_check = 0;
					}
				}
			}

			// For Row Index 3-5
			if (i >= 3 || i <= 5) {
				for (int k = 3; k < 6; k++) {
					//For Column Index 0 to 2
					for (int l = 0; l < 3; l++) {
						if (board[i][j] == input) {
							mini_check = 1;
						}
						else
							mini_check = 0;
					}
					//For Column Index 3 to 5
					for (int l = 3; l < 6; l++) {
						if (board[i][j] == input) {
							mini_check = 1;
						}
						else
							mini_check = 0;
					}
					//For Column Index 6 to 8
					for (int l = 6; l < 9; l++) {
						if (board[i][j] == input) {
							mini_check = 1;
						}
						else
							mini_check = 0;
					}
				}
			}

			//For Row index 6 to 8
			if (i >= 6 || i <= 8) {
				for (int k = 6; k < 9; k++) {
					//For Column Index 0 to 2
					for (int l = 0; l < 3; l++) {
						if (board[i][j] == input) {
							mini_check = 1;
						}
						else
							mini_check = 0;
					}
					//For Column Index 3 to 5
					for (int l = 3; l < 6; l++) {
						if (board[i][j] == input) {
							mini_check = 1;
						}
						else
							mini_check = 0;
					}
					//For Column Index 6 to 8
					for (int l = 6; l < 9; l++) {
						if (board[i][j] == input) {
							mini_check = 1;
						}
						else
							mini_check = 0;
					}
				}
			}
			
		}
	}
	//End Of Smaller Board Checking
}
