# FOCP - ASSIGNMENT 2: SUDOKU GAME

![Sample Sudoku Board](https://github.com/shahmeer0806/FOCP---SUDOKU-GAME/blob/main/RefPics/1.png)

## ***OVERVIEW:***

Sudoku is a grid-based, logic-based number placement puzzle. The word finds its origin in the Japanese language, where it means “single number”. The basic rules of Sudoku are that for any number in a certain cell in  9x9 grid:

* The same number must not be present elsewhere in that row.
* The same number must not be present elsewhere in that column.
* The same number must not be present elsewhere in that 3x3 matrix.

The game starts with some cells of the grid already filled with valid numbers, eliminating the possibility of infinite solutions, and only allowing one certain solution to be thought of and become the goal to reach.

Sudoku could very well be considered a good brain exercise which improves the player’s cognitive ability, and helps them improve their logic-based decision making skills. It challenges the players to think deeply and critically, analyzing all possible combinations of solutions and constraints in them before jumping to conclusions for answers. Moreover, it can help one improve his focus. Since the game requires utmost attention to detail, the player has no choice but to focus on the board. This is the opposite effect to the modern day “dopamine rush” social media provides, which has the effect of shortening the attention spans of present-day youth.

Overall, we’ve established that Sudoku is a mind-bending puzzle. Some people might find it easy, some might find it peaceful, the rest might very well find it an impossibly difficult game; it all depends on what stage you’re on in your Sudoku journey.


## ***Team Information:***

Unfortunately, due to unforeseen circumstances, my teammate from the last assignment was unable to work with me on this project. Therefore, I had to go on and do this assignment alone. Therefore, I inevitably took on all the roles, ranging from main programmer/developer to ReadMe/Repository manager and code tester.


## ***Design & Logic:***

1.	Functions used:
* For one, I used a void introduction function, which basically displays a message when the user runs the program. It is displayed before the game prompt the player to enter the first element. The introduction also familiarizes the user with the rules of Sudoku that need to be followed.
* I used another void function to generate a fully solved Sudoku board in the back end of the game. From that generated back-end board, the void function “generate board” randomly reveals a few blocks, each with correct inputs, displaying the other blocks as 0.
* The bool validity function basically enforces the rules of Sudoku. It pairs up with the “play” function to take a user’s input for a certain cell, checks the row and column repetition rule. It also makes sure the 3x3 matrix repetition rule is followed.
* The update board void function basically prints an “updated” version of the Sudoku board every time the user enters a valid input. 
* The finish function essentially checks if a board is filled with non-zero numbers. If that is indeed the case, the system prints a “Game Over” or “Congratulations” message and displays the final score of the user (+10 for every correct input, -5 for every wrong input, -10 for each hint requested, -20 for asking to solve the whole board).

2. Grid Handling:
I basically initialized the board as a 9x9 element 2D array. I later went on to “split” that grid into smaller 3x3 matrices, not with the help of variables, but through printing lines of horizontal and vertical dashes between the smaller grids. I made the user input row-wise (and by row wise I mean horizontally, or row-by-row). As far as printing the numbers is concerned, I traverse the 2D array and print it using nested loops. 




3. Hint/Solver approach:
If the user inputs “20”, the full Sudoku board is solved and shown, and 20 points are deducted from the total score. If he enters “30”, a hint is given on the cell he’s at.


## ***Execution Instructions:***

When the program is run (either with or without debugging), it asks the user to input 1 to start the game:
![](https://github.com/shahmeer0806/FOCP---SUDOKU-GAME/blob/main/RefPics/2.png)

Upon entering “1”, the game window opens up and the introduction to the game is seen:
![](https://github.com/shahmeer0806/FOCP---SUDOKU-GAME/blob/main/RefPics/3.png)

Then, the game starts, so the user is asked to enter the row and column identity of the cell he wants to fill, and the value (1-9) he wants to fill it with. If the value is a valid input (after checks), the input is printed onto the board. If not, the input is wrong and score is subtracted by 5:
![](https://github.com/shahmeer0806/FOCP---SUDOKU-GAME/blob/main/RefPics/4.png)

If, after pressing which row and column he’d like to fill, the user enters “30”, a hint is given for that certain cell. The correct value is printed onto the board:
![](https://github.com/shahmeer0806/FOCP---SUDOKU-GAME/blob/main/RefPics/5.png)

If, however, after entering the row and column value, the user enters “20”, the full solution is printed, the game is over, and the score is printed:
![](https://github.com/shahmeer0806/FOCP---SUDOKU-GAME/blob/main/RefPics/6.png)

The good thing (or some might say “bad thing”, depending on their interpretation) about this game is that as long as the user is fulfilling the validity checks, the board keeps filling up. If at some point he reaches an unsolvable state, a “GAME OVER” message displays and his score can be seen. Also, the actual solution for that board is printed. Getting stuck is solely the result of the user’s poor decision making. 


## ***AI Tool Reflection (if any):***

Considering I was a first time programmer heading into this assignment/project alone, I surely had reservations about how accurate, bug-free and clean my code would be. Therefore, I did resort to AI Tools like ChatGPT and Gemini to help me out in the following scenarios:
* For the checking of 3x3 matrices, my code was almost a hundred lines of for loops. Though I do believe my logic was more likely accurate than not, I do acknowledge the fact that it would have taken more processing power for the compiler to run all that code efficiently. Therefore, I turned to ChatGPT to help me optimize the 3x3 matrix validity checks. 
* At times, it was hard to keep track of any syntax error or logical error, be most of them occurring by accident (e.g me writing a break statement where it was unnecessary or flipping an equation or missing a semi colon or line break). Thus, I resorted to AI Tools to help me get rid of these minor errors that could have major impacts on the program.
* Also, I took help from ChatGPT to help make the game more presentable. Before, it used to be just a series for numbers separated by spaces (not presentable in the least). So, to make sure the game looked more like a real-life Sudoku board, or at least something as close to it as possible.


## ***Future Enhancements:***

* I believe I could introduce the numbers, whether they’re already displayed at the start of the game or entered by the user, to be colored, so it’s easier to track the non-zero numbers and be more distinguishable from all the zeros in the grid. 
* I think having the option to select the difficulty level would be a good feature. We could either increase the grid size or decrease the number of hints as the levels get harder.
* We could also allow a more randomized, yet still solvable, Sudoku backend board. For example, the back end board right now is just a shuffle of numbers with a gap of 3 integers. 
