#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include<limits>
#include <ctime>
#include <cstdlib>
using namespace std;

//PROTOTYPING
void intro();
void generate_back_end(int board[9][9]);
void board_generation(int board[9][9]);
void play(int board[9][9]);
bool validity(int board[9][9], int input, int row, int column);
void update_board(int board[9][9]);
bool full(int board[9][9]);
void shuffle(int arr[], int size);
bool board_stuck(int board[9][9]);


//GLOBAL VARIABLE
int score = 0;
int solution[9][9] = { 0 };

//MAIN FUNCTION
int main() {

	int board[9][9]; //Declaring a 9x9 2D array
	srand(time(0)); //Random seed with time
	int start;

	cout << "PRESS 1, THEN 'ENTER' TO START: ";
	cin >> start;

	if (start == 1) {
		intro();

		board_generation(board);

		//Playing the Sudoku Game
		play(board);
	}

	_getch();
	return 0;
}


void intro() {
	//INTRO TO THE GAME AND RULES
	cout << "WELCOME TO SUDOKU" << endl;
	cout << "There are some rules you must follow: " << endl;
	cout << " - No two numbers must be the same within a row." << endl;
	cout << " - No two numbers must be the same within a column." << endl;
	cout << " - No two numbers must be the same within a row." << endl << endl;

	//Following Line represents and prints out the score details
	cout << "There are +10 points for every correct input, -5 for wrong, -10 for a hint, -20 for a full solve request." << endl << endl;
	cout << "If at any point you need a hint, enter 30. For a full solution at any time, enter 20" << endl << endl;
	//Controls
	cout << "At each point you will be asked what row (1-9) and what column (1-9) you want filled" << endl;
	cout << "LET'S START" << endl;

}
//DEFINITION OF BOARD GENERATING FUNCTION

//To ensure there is a valid solution for every randomly generated board
void generate_back_end(int board[9][9]) {

	int base[9];

	for (int i = 0; i < 9; i++) {
		base[i] = i + 1; //Making a simple 1D array {1, 2,... , 9}
	}

	//Shuffling 1D base array
	shuffle(base, 9);

	//Shuffling the 1D array to make a valid sudoku board
	int shifts[9] = { 3,6,9,1,4,7,2,5,8 };

	for (int row = 0; row < 9; row++) {
		int shift = shifts[row];
		for (int col = 0; col < 9; col++) {
			board[row][col] = base[(col + shift) % 9];
		}
	}
}

//This function reveals some elements of the solved board and hides others as "0"
void board_generation(int board[9][9]) {
	// Generate a complete valid board
	generate_back_end(board);

	// Copy full board to solution
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			solution[i][j] = board[i][j];

	//	Hide random cells in the board
	const int reveal = 10; // percentage of cells to reveal
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (rand() % 100 >= reveal) {
				board[i][j] = 0; // hide this cell
			}
			//If the element is not denoted as zero, it is not hidden
		}
	}
}

//DEFINITION OF FUNCTION THAT ALLOWS USER TO PLAY THE GAME
void play(int board[9][9]) {

	while (true) {

		update_board(board);

		if (full(board)) {
			cout << "YOU WON!" << endl;
			cout << "YOUR FINAL SCORE IS: " << score << endl;
			break;
		}

		//Filling the Board
		int enter_row;
		int enter_column;
		int input;

		cout << "Which Row would you like to fill? ";
		cin >> enter_row;
		cout << "Which Column would you like to fill? ";
		cin >> enter_column;
		cout << "ENTER YOUR VALUE (20 solution, 30 for Hint): ";
		cin >> input;

		if (enter_row < 1 || enter_row > 9 || enter_column < 1 || enter_column >9) {
			cout << "VALUE MUST BE BETWEEN 1 AND 9";
			continue;
		}

		if (input == 30) {

			if (board[enter_row - 1][enter_column - 1] != 0)
				cout << "The Cell seems to be already filled. I can't give you a hint" << endl;
			else {
				board[enter_row - 1][enter_column - 1] = solution[enter_row - 1][enter_column - 1];
				score -= 10;
				cout << "Hint applied at [" << enter_row << "][" << enter_column << "].\n";
			}
			continue; // Move to next cell
		}

		//FULL SOLUTION REQUEST
		else if (input == 20) {
			score -= 20;
			cout << "FULL SOLUTION" << endl;
			update_board(solution);
			cout << "Final score (after penalty): " << score << endl;
			break;
		}

		// Checks if cell is empty
		if (board[enter_row - 1][enter_column - 1] == 0) {

			if (input < 1 || input >9) {
				cout << "Invalid";
				score -= 5;
				continue;
			}
			if (validity(board, input, enter_row - 1, enter_column - 1)) {
				board[enter_row - 1][enter_column - 1] = input; //Value input
				score += 10; //Score Update for a correct answer
			}
			else {
				cout << "ERROR" << endl;
				score -= 5; //Score Update for a wrong answer
			}
		}
		else {
			//If Cell is already filled with a number
			cout << "Cell is already filled.";
			continue;
		}

		// Stuck check
		if (board_stuck(board)) {
			cout << "You are stuck! No valid moves left."<<endl;
			cout << "Solution:"<<endl;
			update_board(solution);
			cout << "Final score: "<<score << endl;
			cout << "GAME OVER";
			exit(0);
		}
		cout << endl;
	}
}

//Checking the validity of an input
bool validity(int board[9][9], int input, int row, int col) {

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

//The following function checks if the board has been properly filled with non-zero numbers
bool full(int board[9][9]) {

	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			if (board[row][col] == 0) //Comparison to see if any spot is still left unfilled.
				return false; //Board Not Full
		}
	}

	return true; //Board Full
}

void shuffle(int arr[], int size) {
	for (int i = size - 1; i > 0; --i) {
		int j = rand() % (i + 1);
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}

// Return true if there's at least one empty cell that has NO possible placements (user stuck)
bool board_stuck(int board[9][9]) {
	for (int r = 0; r < 9; ++r) {
		for (int c = 0; c < 9; ++c) {
			if (board[r][c] != 0) continue;
			bool anyPossible = false;
			for (int v = 1; v <= 9; ++v) {
				if (validity(board, v, r, c)) {
					anyPossible = true;
					break;
				}
			}
			if (!anyPossible) return true; // stuck: this empty cell can't be filled
		}
	}
	return false;
}