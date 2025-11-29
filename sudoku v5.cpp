#include <iostream>
#include <conio.h>
#include <iomanip>
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
void finish(int board[9][9]);


//GLOBAL VARIABLE
int score = 0;
int solution[9][9];

//MAIN FUNCTION
int main() {

	int board[9][9]; //Declaring a 9x9 2D array
	srand(time(0)); //Random seed with time

	intro();

	board_generation(board);

	//Printing the Board
	update_board(board);

	//Playing the Sudoku Game
	play(board);

	finish(board); //Displays message when all board is filled

	_getch();
	return 0;
}


void intro() {
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

}
//DEFINITION OF BOARD GENERATING FUNCTION

//To ensure there is a valid solution for every ranomly generated board
void generate_back_end(int board[9][9]) {

	int base[9];

	for (int i = 0; i < 9; i++) {
		base[i] = i + 1; //Making a simple 1D array {1, 2,... , 9}
	}

	shuffle(base, 9);

	//Shuffling the 1D array
	for (int j = 0; j < 9; j++) {
		int r = 0 + rand() % 9;
		int temporary = base[j];
		base[j] = base[r];
		base[r] = temporary;
	}

	int shifts[9] = { 0,3,6,1,4,7,2,5,8 };

	//Shifting rows
	for (int row = 0; row < 9; row++) {
		int shift = shifts[row];
		for (int col = 0; col < 9; col++) {
			board[row][col] = base[(col + shift) % 9];
		}
	}
}
void board_generation(int board[9][9]) {
	// Step 1: generate a complete valid board
	generate_back_end(board);

	// Step 2: copy full board to solution
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			solution[i][j] = board[i][j];

	// Step 3: hide random cells in the board
	const int reveal = 10; // percentage of cells to reveal
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (rand() % 100 >= reveal) {
				board[i][j] = 0; // hide this cell
			}
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
				cin >> input; //Takes input from the user

				if (input == 67) {
					board[row][col] = solution[row][col];
					score -= 10;
					cout << "Hint applied at [" << row << "][" << col << "].\n";
					update_board(board);
					continue; // Move to next cell
				}
				else if (input == 20) {
					score -= 20;
					cout << "FULL SOLUTIOM" << endl;
					update_board(solution);
					cout << "Final score (after penalty): " << score << endl;
					exit(0);
				}

				bool check = validity(board, input, row, col); //replace bool everywhere 
				if (check == true && input > 0 && input <= 9) {
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
void finish(int board[9][9]) {

	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			if (board[row][col] == 0) //Comparison to see if any spot is still left unfilled.
				return; //Invalid Input
		}
	}

		cout << "CONGRATULATIONS! YOU WON! YOU SOLVED THE PUZZLE CORRECTLY!"<<endl;
		cout << "YOUR FINAL SCORE IS: " << score;
}

void shuffle(int arr[], int size) {
	for (int i = size - 1; i > 0; --i) {
		int j = rand() % (i + 1);
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}