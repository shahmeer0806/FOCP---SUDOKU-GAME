#include <iostream>
#include <conio.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

//PROTOTYPING
void board_generation(int board[9][9]);
void play(int board[9][9]);
bool validity(int board[9][9], int input, int row, int column);
void update_board(int board[9][9]);
void shuffle(int arr[], int size);

//GLOBAL VARIABLE
int score = 0;

//MAIN FUNCTION
int main() {

	int board[9][9];

	int nums[9] = { 1,2,3,4,5,6,7,8,9 };
	shuffle(nums, 9);

	board_generation(board);

	//Printing the Board
	update_board(board);

	//Playing the Sudoku Game
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
	//PRINTING BOARD
}

//DEFINITION OF FUNCTION THAT ALLOWS USER TO PLAY THE GAME
void play(int board[9][9]) {
	int input;

	//INTRO TO THE GAME
	cout << "WELCOME TO SUDOKU" << endl;
	cout << "There are some rules you must follow: " << endl;
	cout << " - No two numbers must be the same within a row." << endl;
	cout << " - No two numbers must be the same within a column." << endl;
	cout << " - No two numbers must be the same within a row." << endl << endl;
	//Following Line represents and prints out the score details
	cout << "There are +10 points for every correct input, -5 for wrong, -10 for a hint, -20 for a full solve request." << endl << endl;
	cout << "If at any point you need a hint, enter 67. For a full solution at any time, enter 20" << endl << endl;
	cout << setw(15) << right << "LET'S START" << endl;
	//END OF INTRO

	//Filling the Board
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			if (board[row][col] == 0) {
				cout << "ENTER ELEMENT [" << row << "][" << col << "]: ";
				cin >> input; //Takes input from the user

				if (input == 67) {
					
					score -= 10;
				}
				else if (input == 20) {
					
					score -= 20;
				}

				bool check = validity(board, input, row, col); //replace bool everywhere 
				if (check == true && input >= 0 && input <= 9) {
					board[row][col] = input; //Value input
					score += 10; //Score Update for a correct answer
					update_board(board); //Prints updated board
				}
				else {
					cout << "ERROR" << endl;
					col--; //To ensure it doesn't move on after an error
					score -= 5; //Score Update for a wrong answer
				}
			}
		}
		cout << endl;


	}

}

//Checking the validity of an input
bool validity(int board[][9], int input, int row, int col) {

	//For smaller board
	int starting_row = row - (row % 3);
	int starting_col = col - (col % 3);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			if (board[starting_row + i][starting_col + j] == input) {
				return false;
				break;
			}
		}
	}

	//Linear Search for same elements in a column
	int col_check = 0;

	for (int x = 0; x < 9; x++) {
		if (board[row][x] == input) {
			return false; //Invalid Input
			break;
		}
	}

	//Linear Check for same elements in a row
	int row_check = 0;

	for (int y = 0; y < 9; y++) {
		if (board[y][col] == input) {
			return false; //Invalid input
			break;
		}
	}
	return true; //Valid input
}

//TO PRINT THE BOARD AFTER EVERY INPUT SO THE USER IS IN TOUCH WITH THE GAME
void update_board(int board[9][9]) {

	cout << endl;

	for (int i = 0; i < 9; i++) {

		//Horizontal Divider for 3x3 matrices
		if (i % 3 == 0 && i != 0) {
			cout << "-------+--------+-------";
			cout << endl;
		}
		for (int j = 0; j < 9; j++) {

			//Vertical Divider for 3x3 matrices
			if (j % 3 == 0 && j != 0) {
				cout << " | ";
			}
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void shuffle(int arr[], int size) {
	for (int a = 8; a <= 0; a--) {
		int b = 1 + rand() & 9;
		// Swapping arr[i] and arr[j]
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
}

//To ensure there is a valid solution for every ranomly generated board
bool solve(int board[9][9], int row, int col) {
	if (row == 9)
		return true;
	if (col == 9)
		return solve(board, row +1, 0);
	if (board[row][col] != 0)
		return solve(board, row, col + 1);

	//Randomizing an array of numbers
	int n[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	shuffle (n, 9);

	//CODE FOR AUTHENTICATION IS MISSING CURRENTLY
}

//The following function checks if the board has been properly filled with non-zero numbers
void finish(int board[9][9]) {

	int final_check = 1; //Using this as a flag value
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			if (board[row][col] == 0) //Comparison to see if any spot is still left unfilled.
				final_check = 0; //Invalid Input
		}
	}

	if (final_check == 1) {
		cout << "CONGRATULATIONS! YOU WON! YOU SOLVED THE PUZZLE CORRECTLY!";
		cout << "YOUR FINAL SCORE IS: " << score;
	}
}
