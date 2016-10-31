/**
 * ohhi.cpp
 *
 * EECS 183, Fall 2015
 * Project 3: 0h h1
 *
 * Pratik Joshi
 * Mackenzie Francisco
 *
 * prjoshi
 * mackfran
 *
 * In ohhi.cpp, the functions declared in ohhi.h are implemented. 
 * The first few functions make sure that partially-completed 0h h1 boards 
 * follow the rules of the puzzle: equal representation, runs of three or more 
 * are not allowed, and no duplicates. The next few functions use algorithms to 
 * solve 0h h1 puzzles. The last few functions allow a user to play 0h h1.
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

///////////////////////////////////////
// UTILITY FUNCTIONS //////////////////
///////////////////////////////////////

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    
    //goes through the array and if there is a "-", you add 1 countUnknown
    int countUnknown = 0;
    for (int row = 0; row < size; row++) {
        for (int column = 0; column < size; column++){
            if (board[row][column] == UNKNOWN){
                countUnknown += 1;
            }
        }
    }
    return countUnknown;
}


///////////////////////////////////////
// VALIDITY CHECKS ////////////////////
///////////////////////////////////////

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color){
    for (int element = 1; element < size - 1; element++){
        /** looks at the element to the left and right of desired
         * element and if both are the same as the desired element,
         * you return false. Otherwise you return true.
         */
        if (board[row][element] == board[row][element - 1]
            && board[row][element] == board[row][element + 1]){
            if (board[row][element] == color){
               return false;
            }
        }
    }
    return true;
}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    for (int element = 1; element < size - 1; element++){
        /** Looks at the element to the top and bottom of the desired element
         * and if both are the same as the desired element, you return false.
         * Otherwise you return true
         */
        if (board[element][col] == board[element - 1][col] &&
            board[element][col] == board[element + 1][col]){
            if (board[element][col] == color){
            return false;
            }
        }
    }
    return true;
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    /** Checks that the board has no threes of any kind and returns true if none
     *of the conditions are false
     */
    for (int i = 0; i < size; i++){
        if (row_has_no_threes_of_color(board, size, i, BLUE) == false){
            return false;
        }
        if ((row_has_no_threes_of_color(board, size, i, RED)) == false) {
            return false;
        }
        if ((col_has_no_threes_of_color(board, size, i, BLUE)) == false) {
            return false;
        }
        if ((col_has_no_threes_of_color(board, size, i, RED)) == false) {
            return false;
        }
    }
    return true;
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
    // Checks that there are no duplicate rows
    for (int i = 0; i < size; i++){
        if (board[row1][i] != board[row2][i]){
            return true;
        }
        if (board[row1][i] == UNKNOWN){
            return true;
        }
    }
    return false;
}

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    //Checks that there are no duplicate columns
    for (int i = 0; i < size; i++){
        if (board[i][col1] != board[i][col2]){
            return true;
        }
        if (board[i][col1] == UNKNOWN){
            return true;
        }
    }
    return false;
}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    //checks that there are no duplicate rows and column in the entire board
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            if ((rows_are_different(board, size, i, j)) == false){
                return false;
            }
            if ((cols_are_different(board, size, i, j)) == false){
                return false;
            }
        }
    }
    return true;
}


///////////////////////////////////////
// SOLVING FUNCTIONS //////////////////
///////////////////////////////////////

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    /** If the entire array is bigger than a 2x2, Enters in the opposite color
     * if 2 elements in a row are the same or if there is a "-" between two
     * elements of the same color
     */
    if (size > 2){
        for (int rowElement = 0; rowElement < size; rowElement++){
            //Checks if the element is 0 and changes colors accordingly
            if (rowElement == 0) {
                if (board[row][rowElement] == board[row][rowElement + 1]
                    && board[row][rowElement] != UNKNOWN) {
                    if (board[row][rowElement + 2] == UNKNOWN) {
                        mark_square_as(board, size, row, rowElement + 2,
                                       opposite_color(board[row][rowElement]),
                                       announce);
                    }
                }
                else if (board[row][rowElement] == board[row][rowElement + 2]
                         && board[row][rowElement] != UNKNOWN){
                    if (board[row][rowElement + 1] == UNKNOWN){
                    mark_square_as(board, size, row, rowElement + 1,
                                   opposite_color(board[row][rowElement]),
                                   announce);
                    }
                }
            }
            /** checks if the element is equal to the last spot in the array and
             * changes colors accordingly
             */
            else if (rowElement == size - 1) {
                if (board[row][rowElement] == board[row][rowElement - 1] &&
                    board[row][rowElement] != UNKNOWN) {
                    if (board[row][rowElement - 2] == UNKNOWN) {
                        mark_square_as(board, size, row, rowElement - 2,
                                       opposite_color(board[row][rowElement]),
                                       announce);
                    }
                }
                else if (board[row][rowElement] == board[row][rowElement - 2]
                         && board[row][rowElement] != UNKNOWN) {
                    if (board[row][rowElement - 1] == UNKNOWN) {
                        mark_square_as(board, size, row, rowElement - 1,
                                       opposite_color(board[row][rowElement]),
                                       announce);
                    }
                }
            }
            /** checks if rowElement is greater than to the first element and
             * if it is less than the second to last one and changes the color
             * always fill that spot in
             */
            else if (rowElement > 0 && rowElement < size - 2){
                if (board[row][rowElement] == board[row][rowElement + 1]
                    && board[row][rowElement] != UNKNOWN) {
                    if (board[row][rowElement - 1] == UNKNOWN) {
                    mark_square_as(board, size, row, rowElement - 1,
                                   opposite_color(board[row][rowElement]),
                                   announce);
                    }
                    if (board[row][rowElement + 2] == UNKNOWN){
                        mark_square_as(board, size, row, rowElement + 2,
                                       opposite_color(board[row][rowElement]),
                                       announce);
                    }
                }
                else if (board[row][rowElement] == board[row][rowElement + 2]
                         && board[row][rowElement] != UNKNOWN){
                    if (board[row][rowElement + 1] == UNKNOWN){
                    mark_square_as(board, size, row, rowElement + 1,
                                   opposite_color(board[row][rowElement]),
                                   announce);
                    }
                }
            }
        }
    }
}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    /** If the entire array is bigger than a 2x2, Enters in the opposite color
     * if 2 elements in a column are the same or if there is a "-" between two
     * elements of the same color
     */
    if (size > 2){
        for (int colElement = 0; colElement < size; colElement++){
            //Checks if the element is 0 and changes colors accordingly
            if (colElement == 0) {
                if (board[colElement][col] == board[colElement + 1][col]
                    && board[colElement][col] != UNKNOWN) {
                    if (board[colElement + 2][col] == UNKNOWN) {
                        mark_square_as(board, size, colElement + 2, col,
                                       opposite_color(board[colElement][col]),
                                       announce);
                    }
                }
                else if (board[colElement][col] == board[colElement + 2][col]
                         && board[colElement][col] != UNKNOWN){
                    if (board[colElement + 1][col] == UNKNOWN){
                        mark_square_as(board, size, colElement + 1, col,
                                       opposite_color(board[colElement][col]),
                                       announce);
                    }
                }
            }
            /** checks if the element is equal to the last spot in the array and
             * changes colors accordingly
             */
            else if (colElement == size - 1) {
                if (board[colElement][col] == board[colElement - 1][col]
                    && board[colElement][col] != UNKNOWN) {
                    if (board[colElement - 2][col] == UNKNOWN) {
                        mark_square_as(board, size, colElement - 2, col,
                                       opposite_color(board[colElement][col]),
                                       announce);
                    }
                }
                else if (board[colElement][col] == board[colElement - 2][col]
                         && board[colElement][col] != UNKNOWN) {
                    if (board[colElement - 1][col] == UNKNOWN) {
                        mark_square_as(board, size, colElement - 1, col,
                                       opposite_color(board[colElement][col]),
                                       announce);
                    }
                }
            }
            /** checks if rowElement is greater than to the first element and
             * if it is less than the second to last one and changes the color
             * always fill that spot in
             */
            else if (colElement > 0 && colElement < size - 2){
                if (board[colElement][col] == board[colElement + 1][col]
                    && board[colElement][col] != UNKNOWN) {
                    if (board[colElement - 1][col] == UNKNOWN) {
                        mark_square_as(board, size, colElement - 1, col,
                                       opposite_color(board[colElement][col]),
                                       announce);
                    }
                    if (board[colElement + 2][col] == UNKNOWN){
                        mark_square_as(board, size, colElement + 2, col,
                                       opposite_color(board[colElement][col]),
                                       announce);
                    }
                }
                else if (board[colElement][col] == board[colElement + 2][col]
                         && board[colElement][col] != UNKNOWN){
                    if (board[colElement + 1][col] == UNKNOWN){
                        mark_square_as(board, size, colElement + 1, col,
                                       opposite_color(board[colElement][col]),
                                       announce);
                    }
                }
            }
        }
    }
}


void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    /* If the number of red or blue tiles in a row is equal to half of the board
     *  size, you fill the rest of the "-" spaces with the opposite color
     */
    int numOfRed = 0;
    int numOfBlue = 0;
    for (int i = 0; i < size; i++){
        if (board[row][i] == RED){
            numOfRed += 1;
        }
        if (board[row][i] == BLUE){
            numOfBlue += 1;
        }
        
        if (numOfRed == size / 2){
            for(int l = 0; l < size; l++){
                if (board[row][l] == UNKNOWN) {
                    mark_square_as(board, size, row, l, BLUE, announce);
                }
            }
        }
        else if (numOfBlue == size / 2){
            for (int j = 0; j < size; j++){
                if (board[row][j] == UNKNOWN) {
                    mark_square_as(board, size, row, j, RED, announce);
                }
            }
        }
    }
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    /* If the number of red or blue tiles in a column is equal to half of the
     * board size, you fill the rest of the "-" spaces with the opposite color
     */
    int numOfRed = 0;
    int numOfBlue = 0;
    for (int i = 0; i < size; i++){
        if (board[i][col] == RED){
            numOfRed += 1;
        }
        else if (board[i][col] == BLUE){
            numOfBlue += 1;
        }
    }
    if (numOfRed == size / 2){
        for (int j = 0; j < size; j++) {
            if (board[j][col] == UNKNOWN){
                mark_square_as(board, size, j, col, BLUE, announce);
            }
        }
    }
    else if (numOfBlue == size / 2){
        for (int k = 0; k < size; k++){
            if (board[k][col] == UNKNOWN){
                mark_square_as(board, size, k, col, RED, announce);
            }
        }
    }
}


///////////////////////////////////////
// GAMEPLAY FUNCTIONS /////////////////
///////////////////////////////////////

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    /* Makes sure that the board has every square filled and has no threes,
     * duplicates and no unknown spaces 
     */
    if (board_has_no_threes(board, size) == true && board_has_no_duplicates
        (board, size) == true && count_unknown_squares(board, size) == 0){
        return true;
    }
    return false;
}

bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    // checks that the imput is something that will give blue or red
    if (row_input >= 1 && row_input <= size
        && toupper(col_input) >= 'A' && toupper(col_input) <= 'A' + size
        && (color_char == 'X' || color_char == 'x' || color_char == 'O' ||
            color_char == 'o' || color_char == '-')){
        return true;
    }
    else{
        cout << "Sorry, that's not a valid input." << endl;
        return false;
    }
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    
    /*checks that the move made by the user is valid and does not modify
     * the original board or violate any rules
     */
    int board[MAX_SIZE][MAX_SIZE];
    
    if (original_board[row][col] != UNKNOWN){
        cout << "Sorry, original squares cannot be changed." << endl;
        return false;
    }
    else{
        copy_board(current_board, board, size);
        mark_square_as(board, size, row, col, color, false);
        if (board_has_no_duplicates(board, size)
            && board_has_no_threes(board, size)) {
            return true;
        }
        else{
            cout << "Sorry, that violates a rule." << endl;
        }
    }
    return false;
}


///////////////////////////////////////
// S'MORE FUNCTIONS ///////////////////
///////////////////////////////////////


void solve_lookahead_row(int board[MAX_SIZE][MAX_SIZE],
                         int size,
                         int row,
                         bool announce) {
    // your code here
}

void solve_lookahead_column(int board[MAX_SIZE][MAX_SIZE],
                            int size,
                            int col,
                            bool announce) {
    // your code here
}
