/**
 * test.cpp
 *
 * EECS 183, Fall 2015
 * Project 3: 0h h1 Test Suite
 *
 * Pratik Joshi
 * Mackenzie Francisco
 *
 * prjoshi
 * mackfran
 *
 * This test suite includes a main() function that runs all of our test functions. This can be used for catching bugs in ohhi.cpp.
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();

void test_row_has_no_threes_of_color();
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();
void test_rows_are_different();
void test_cols_are_different();
void test_board_has_no_duplicates();

void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_solve_balance_row();
void test_solve_balance_column();

void test_board_is_solved();
void test_check_valid_input();
void test_check_valid_move();

int main() {
    
    cout << "UTILITY FUNCTIONS" << endl;
    
    cout << "Testing count_unknown_squares():" << endl;
    test_count_unknown_squares();
    cout << endl;
    
    cout << "VALIDITY CHECKS" << endl;
    
    cout << "Testing row_has_no_threes_of_color():" << endl;
    test_row_has_no_threes_of_color();
    cout << endl;
    
    cout << "Testing col_has_no_threes_of_color():" << endl;
    test_col_has_no_threes_of_color();
    cout << endl;
    
    cout << "Testing board_has_no_threes():" << endl;
    test_board_has_no_threes();
    cout << endl;
    
    cout << "Testing rows_are_different():" << endl;
    test_rows_are_different();
    cout << endl;
    
    cout << "Testing cols_are_different():" << endl;
    test_cols_are_different();
    cout << endl;
    
    cout << "Testing board_has_no_duplicates():" << endl;
    test_board_has_no_duplicates();
    cout << endl;
    
    cout << "SOLVING FUNCTIONS" << endl;
    
    cout << "Testing solve_three_in_a_row():" << endl;
    test_solve_three_in_a_row();
    cout << endl;
    
    cout << "Testing solve_three_in_a_column():" << endl;
    test_solve_three_in_a_column();
    cout << endl;
    
    cout << "Testing solve_balance_row():" << endl;
    test_solve_balance_row();
    cout << endl;
    
    cout << "Testing solve_balance_column():" << endl;
    test_solve_balance_column();
    cout << endl;
    
    cout << "GAMEPLAY FUNCTIONS" << endl;
    
    cout << "Testing board_is_solved():" << endl;
    test_board_is_solved();
    cout << endl;
    
    cout << "Testing check_valid_input():" << endl;
    test_check_valid_input();
    cout << endl;
    
    cout << "Testing check_valid_move():" << endl;
    test_check_valid_move();
    cout << endl;

    return 0;
}


void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"O-OX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << count_unknown_squares(board, size_1) << endl;

    // test case 2
    string test_board_2[] = {"OXOX",
                             "OOXX",
                             "XOXO",
                             "XXOO"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << count_unknown_squares(board, size_2) << endl;
    
    // test case 3
    string test_board_3[] = {"----",
                             "----",
                             "----",
                             "----"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << count_unknown_squares(board, size_3) << endl;
}

void test_row_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"O-OX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    int row_1 = 0;
    int color_1 = BLUE;
    read_board_from_string(board, test_board_1, size_1);
    cout << row_has_no_threes_of_color(board, size_1, row_1, color_1) << endl;
    
    // test case 2
    string test_board_2[] = {"OOOX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_2 = 4;
    int row_2 = 0;
    int color_2 = BLUE;
    read_board_from_string(board, test_board_2, size_2);
    cout << row_has_no_threes_of_color(board, size_2, row_2, color_2) << endl;
    
    // test case 3
    string test_board_3[] = {"OX-X",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_3 = 4;
    int row_3 = 0;
    int color_3 = RED;
    read_board_from_string(board, test_board_3, size_3);
    cout << row_has_no_threes_of_color(board, size_3, row_3, color_3) << endl;
    
    // test case 4
    string test_board_4[] = {"OXXX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_4 = 4;
    int row_4 = 0;
    int color_4 = RED;
    read_board_from_string(board, test_board_4, size_4);
    cout << row_has_no_threes_of_color(board, size_4, row_4, color_4) << endl;
    
    // test case 5
    string test_board_5[] = {"XX",
                             "OO"};
    int size_5 = 2;
    int row_5 = 0;
    int color_5 = RED;
    read_board_from_string(board, test_board_5, size_5);
    cout << row_has_no_threes_of_color(board, size_5, row_5, color_5) << endl;
    
    // test case 6
    string test_board_6[] = {"OO",
                             "XX"};
    int size_6 = 2;
    int row_6 = 0;
    int color_6 = BLUE;
    read_board_from_string(board, test_board_6, size_6);
    cout << row_has_no_threes_of_color(board, size_6, row_6, color_6) << endl;
    
    // test case 7
    string test_board_7[] = {"X"};
    
    int size_7 = 1;
    int row_7 = 0;
    int color_7 = RED;
    read_board_from_string(board, test_board_7, size_7);
    cout << row_has_no_threes_of_color(board, size_7, row_7, color_7) << endl;
    
    // test case 8
    string test_board_8[] = {"O"};
    
    int size_8 = 1;
    int row_8 = 0;
    int color_8 = BLUE;
    read_board_from_string(board, test_board_8, size_8);
    cout << row_has_no_threes_of_color(board, size_8, row_8, color_8) << endl;
}

void test_col_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"O-OX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    int col_1 = 0;
    int color_1 = BLUE;
    read_board_from_string(board, test_board_1, size_1);
    cout << col_has_no_threes_of_color(board, size_1, col_1, color_1) << endl;
    
    // test case 2
    string test_board_2[] = {"O-OX",
                             "OO--",
                             "O---",
                             "-O--"};
    int size_2 = 4;
    int col_2 = 0;
    int color_2 = BLUE;
    read_board_from_string(board, test_board_2, size_2);
    cout << col_has_no_threes_of_color(board, size_2, col_2, color_2) << endl;
    
    // test case 3
    string test_board_3[] = {"OX-X",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_3 = 4;
    int col_3 = 0;
    int color_3 = RED;
    read_board_from_string(board, test_board_3, size_3);
    cout << col_has_no_threes_of_color(board, size_3, col_3, color_3) << endl;
    
    // test case 4
    string test_board_4[] = {"OX-X",
                             "OX--",
                             "XX--",
                             "-O--"};
    int size_4 = 4;
    int col_4 = 1;
    int color_4 = RED;
    read_board_from_string(board, test_board_4, size_4);
    cout << col_has_no_threes_of_color(board, size_4, col_4, color_4) << endl;
    
    // test case 5
    string test_board_5[] = {"XO",
                             "XO"};
    int size_5 = 2;
    int col_5 = 0;
    int color_5 = RED;
    read_board_from_string(board, test_board_5, size_5);
    cout << col_has_no_threes_of_color(board, size_5, col_5, color_5) << endl;
    
    // test case 6
    string test_board_6[] = {"OX",
                             "OX"};
    int size_6 = 2;
    int col_6 = 0;
    int color_6 = BLUE;
    read_board_from_string(board, test_board_6, size_6);
    cout << col_has_no_threes_of_color(board, size_6, col_6, color_6) << endl;
    
    // test case 7
    string test_board_7[] = {"X"};
    
    int size_7 = 1;
    int col_7 = 0;
    int color_7 = RED;
    read_board_from_string(board, test_board_7, size_7);
    cout << col_has_no_threes_of_color(board, size_7, col_7, color_7) << endl;
    
    // test case 8
    string test_board_8[] = {"O"};
    
    int size_8 = 1;
    int col_8 = 0;
    int color_8 = BLUE;
    read_board_from_string(board, test_board_8, size_8);
    cout << col_has_no_threes_of_color(board, size_8, col_8, color_8) << endl;
}

void test_board_has_no_threes() {
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"O-OX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_threes(board, size_1) << endl;
    
    // test case 2
    string test_board_2[] = {"OOOX",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_has_no_threes(board, size_2) << endl;
    
    // test case 3
    string test_board_3[] = {"O-OX",
                             "OO--",
                             "XXX-",
                             "-O--"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_has_no_threes(board, size_3) << endl;
    
    // test case 4
    string test_board_4[] = {"O-OX",
                             "OO--",
                             "O---",
                             "-O--"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << board_has_no_threes(board, size_4) << endl;
    
    // test case 5
    string test_board_5[] = {"O-OX",
                             "OO-X",
                             "X--X",
                             "-O--"};
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << board_has_no_threes(board, size_5) << endl;
}

void test_rows_are_different() {
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"XOOX",
                             "XOOX",
                             "----",
                             "----"};
    int size_1 = 4;
    int row_1 = 0;
    int row_2 = 1;
    read_board_from_string(board, test_board_1, size_1);
    cout << rows_are_different(board, size_1, row_1, row_2) << endl;
    
    // test case 2
    string test_board_2[] = {"XOOX",
                             "XXOO",
                             "----",
                             "----"};
    int size_2 = 4;
    int row_3 = 0;
    int row_4 = 1;
    read_board_from_string(board, test_board_2, size_2);
    cout << rows_are_different(board, size_2, row_3, row_4) << endl;
    
    // test case 3
    string test_board_3[] = {"XO-X",
                             "XOOX",
                             "----",
                             "----"};
    int size_3 = 4;
    int row_5 = 0;
    int row_6 = 1;
    read_board_from_string(board, test_board_3, size_3);
    cout << rows_are_different(board, size_3, row_5, row_6) << endl;
    
    // test case 4
    string test_board_4[] = {"XO-X",
                             "XOOX",
                             "----",
                             "----"};
    int size_4 = 4;
    int row_7 = 3;
    int row_8 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << rows_are_different(board, size_4, row_7, row_8) << endl;
    
    // test case 5
    string test_board_5[] = {"XO-X",
                             "XO-X",
                             "----",
                             "----"};
    int size_5 = 4;
    int row_9 = 0;
    int row_10 = 1;
    read_board_from_string(board, test_board_5, size_5);
    cout << rows_are_different(board, size_5, row_9, row_10) << endl;
    
    // test case 6
    string test_board_6[] = {"XO",
                             "OX"};
    int size_6 = 2;
    int row_11 = 0;
    int row_12 = 1;
    read_board_from_string(board, test_board_6, size_6);
    cout << rows_are_different(board, size_6, row_11, row_12) << endl;
    
    // test case 7
    string test_board_7[] = {"XO",
                             "XO"};
    int size_7 = 2;
    int row_13 = 0;
    int row_14 = 1;
    read_board_from_string(board, test_board_7, size_7);
    cout << rows_are_different(board, size_7, row_13, row_14) << endl;
}

void test_cols_are_different() {
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"XX--",
                             "OO--",
                             "OO--",
                             "XX--"};
    int size_1 = 4;
    int col_1 = 0;
    int col_2 = 1;
    read_board_from_string(board, test_board_1, size_1);
    cout << cols_are_different(board, size_1, col_1, col_2) << endl;
    
    // test case 2
    string test_board_2[] = {"XX--",
                             "OX--",
                             "OO--",
                             "XO--"};
    int size_2 = 4;
    int col_3 = 0;
    int col_4 = 1;
    read_board_from_string(board, test_board_2, size_2);
    cout << cols_are_different(board, size_2, col_3, col_4) << endl;
    
    // test case 3
    string test_board_3[] = {"XX--",
                             "OO--",
                             "-O--",
                             "XX--"};
    int size_3 = 4;
    int col_5 = 0;
    int col_6 = 1;
    read_board_from_string(board, test_board_3, size_3);
    cout << cols_are_different(board, size_3, col_5, col_6) << endl;
    
    // test case 4
    string test_board_4[] = {"XX--",
                             "OO--",
                             "-O--",
                             "XX--"};
    int size_4 = 4;
    int col_7 = 3;
    int col_8 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << cols_are_different(board, size_4, col_7, col_8) << endl;
    
    // test case 5
    string test_board_5[] = {"XX--",
                             "OO--",
                             "----",
                             "XX--"};
    int size_5 = 4;
    int col_9 = 0;
    int col_10 = 1;
    read_board_from_string(board, test_board_5, size_5);
    cout << cols_are_different(board, size_5, col_9, col_10) << endl;
    
    // test case 6
    string test_board_6[] = {"XO",
                             "OX"};
    int size_6 = 2;
    int col_11 = 0;
    int col_12 = 1;
    read_board_from_string(board, test_board_6, size_6);
    cout << cols_are_different(board, size_6, col_11, col_12) << endl;
    
    // test case 7
    string test_board_7[] = {"OO",
                             "XX"};
    int size_7 = 2;
    int col_13 = 0;
    int col_14 = 1;
    read_board_from_string(board, test_board_7, size_7);
    cout << cols_are_different(board, size_7, col_13, col_14) << endl;
    
}

void test_board_has_no_duplicates() {
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"OXOX",
                             "OOXX",
                             "XXOO",
                             "XOXO"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_duplicates(board, size_1) << endl;
    
    // test case 2
    string test_board_2[] = {"OXOX",
                             "OXOX",
                             "X-XO",
                             "XO--"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_has_no_duplicates(board, size_2) << endl;
    
    // test case 3
    string test_board_3[] = {"OOX-",
                             "OO-X",
                             "XX--",
                             "XX--"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_has_no_duplicates(board, size_3) << endl;
    
}

void test_solve_three_in_a_row() {
    int board[MAX_SIZE][MAX_SIZE];
    bool announce;
    
    // test case 1
    string test_board_1[] = {"X-XOOX",
                             "OO----",
                             "X-----",
                             "------",
                             "------",
                             "-O----"};
    int size_1 = 6;
    int row_1 = 0;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_row(board, size_1, row_1, announce);
    print_board(board, size_1);
    
    // test case 2
    string test_board_2[] = {"OXOX-X",
                             "OO----",
                             "O-----",
                             "------",
                             "------",
                             "-O----"};
    int size_2 = 6;
    int row_2 = 0;
    read_board_from_string(board, test_board_2, size_2);
    solve_three_in_a_row(board, size_2, row_2, announce);
    print_board(board, size_2);
    
    // test case 3
    string test_board_3[] = {"OX-XOX",
                             "OO----",
                             "O-----",
                             "------",
                             "------",
                             "-O----"};
    int size_3 = 6;
    int row_3 = 0;
    read_board_from_string(board, test_board_3, size_3);
    solve_three_in_a_row(board, size_3, row_3, announce);
    print_board(board, size_3);

}

void test_solve_three_in_a_column() {
    int board[MAX_SIZE][MAX_SIZE];
    bool announce;
    
    // test case 1
    string test_board_1[] = {"X-XOOX",
                             "-O----",
                             "X-----",
                             "O-----",
                             "O-----",
                             "XO----"};
    int size_1 = 6;
    int col_1 = 0;
    read_board_from_string(board, test_board_1, size_1);
    solve_three_in_a_column(board, size_1, col_1, announce);
    print_board(board, size_1);
    
    // test case 2
    string test_board_2[] = {"OXOX-X",
                             "XO----",
                             "O-----",
                             "X-----",
                             "------",
                             "XO----"};
    int size_2 = 6;
    int col_2 = 0;
    read_board_from_string(board, test_board_2, size_2);
    solve_three_in_a_column(board, size_2, col_2, announce);
    print_board(board, size_2);
    
    // test case 3
    string test_board_3[] = {"OX-XOX",
                             "XO----",
                             "------",
                             "X-----",
                             "O-----",
                             "XO----"};
    int size_3 = 6;
    int col_3 = 0;
    read_board_from_string(board, test_board_3, size_3);
    solve_three_in_a_column(board, size_3, col_3, announce);
    print_board(board, size_3);
    
    // test case 4
    string test_board_4[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_4 = 4;
    int col_4 = 1;
    read_board_from_string(board, test_board_4, size_4);
    solve_three_in_a_column(board, size_4, col_4, announce);
    print_board(board, size_4);
    
    // test case 5
    string test_board_5[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_5 = 4;
    int col_5 = 2;
    read_board_from_string(board, test_board_5, size_5);
    solve_three_in_a_column(board, size_5, col_5, announce);
    print_board(board, size_5);
    
    // test case 6
    string test_board_6[] = {"----",
                             "X-X-",
                             "----",
                             "--X-"};
    int size_6 = 4;
    int col_6 = 2;
    read_board_from_string(board, test_board_6, size_6);
    solve_three_in_a_column(board, size_6, col_6, announce);
    print_board(board, size_6);
}

void test_solve_balance_row() {
    int board[MAX_SIZE][MAX_SIZE];
    bool announce;
    
    // test case 1
    string test_board_1[] = {"X-XO",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    int row_1 = 0;
    read_board_from_string(board, test_board_1, size_1);
    solve_balance_row(board, size_1, row_1, announce);
    print_board(board, size_1);
    
    // test case 2
    string test_board_2[] = {"O-OX",
                             "OO--",
                             "O---",
                             "-O--"};
    int size_2 = 4;
    int row_2 = 0;
    read_board_from_string(board, test_board_2, size_2);
    solve_balance_row(board, size_2, row_2, announce);
    print_board(board, size_2);
    
    // test case 3
    string test_board_3[] = {"X-",
                             "--"};
    int size_3 = 2;
    int row_3 = 0;
    read_board_from_string(board, test_board_3, size_3);
    solve_balance_row(board, size_3, row_3, announce);
    print_board(board, size_3);
    
    // test case 4
    string test_board_4[] = {"O-",
                             "--"};
    int size_4 = 2;
    int row_4 = 0;
    read_board_from_string(board, test_board_4, size_4);
    solve_balance_row(board, size_4, row_4, announce);
    print_board(board, size_4);
    
    // test case 5
    string test_board_5[] = {"X"};
    
    int size_5 = 1;
    int row_5 = 0;
    read_board_from_string(board, test_board_5, size_5);
    solve_balance_row(board, size_5, row_5, announce);
    print_board(board, size_5);
    
    // test case 6
    string test_board_6[] = {"O"};
    
    int size_6 = 1;
    int row_6 = 0;
    read_board_from_string(board, test_board_6, size_6);
    solve_balance_row(board, size_6, row_6, announce);
    print_board(board, size_6);
    
    // test case 7
    string test_board_7[] = {"XX--",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_7 = 4;
    int row_7 = 0;
    read_board_from_string(board, test_board_7, size_7);
    solve_balance_row(board, size_7, row_7, announce);
    print_board(board, size_7);
    
    // test case 8
    string test_board_8[] = {"OO--",
                             "OO--",
                             "O---",
                             "-O--"};
    int size_8 = 4;
    int row_8 = 0;
    read_board_from_string(board, test_board_8, size_8);
    solve_balance_row(board, size_8, row_8, announce);
    print_board(board, size_8);
    
    // test case 9
    string test_board_9[] = {"X---",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_9 = 4;
    int row_9 = 0;
    read_board_from_string(board, test_board_9, size_9);
    solve_balance_row(board, size_9, row_9, announce);
    print_board(board, size_9);
    
    // test case 10
    string test_board_10[] = {"O---",
                              "OO--",
                              "O---",
                              "-O--"};
    int size_10 = 4;
    int row_10 = 0;
    read_board_from_string(board, test_board_10, size_10);
    solve_balance_row(board, size_10, row_10, announce);
    print_board(board, size_10);
    
    // test case 11
    string test_board_11[] = {"X-XX--",
                              "OO----",
                              "X-----",
                              "OO----",
                              "X-----",
                              "-O----"};
    int size_11 = 6;
    int row_11 = 0;
    read_board_from_string(board, test_board_11, size_11);
    solve_balance_row(board, size_11, row_11, announce);
    print_board(board, size_11);
    
    // test case 12
    string test_board_12[] = {"O-OO--",
                              "OO----",
                              "O-----",
                              "OO----",
                              "O-----",
                              "-O----"};
    int size_12 = 6;
    int row_12 = 0;
    read_board_from_string(board, test_board_12, size_12);
    solve_balance_row(board, size_12, row_12, announce);
    print_board(board, size_12);
    
    // test case 13
    string test_board_13[] = {"XXOO",
                              "OO--",
                              "X---",
                              "-O--"};
    int size_13 = 4;
    int row_13 = 0;
    read_board_from_string(board, test_board_13, size_13);
    solve_balance_row(board, size_13, row_13, announce);
    print_board(board, size_13);
    
    // test case 14
    string test_board_14[] = {"OOXX",
                              "OO--",
                              "O---",
                              "-O--"};
    int size_14 = 4;
    int row_14 = 0;
    read_board_from_string(board, test_board_14, size_14);
    solve_balance_row(board, size_14, row_14, announce);
    print_board(board, size_14);
    
    // test case 15
    string test_board_15[] = {"----",
                              "OO--",
                              "O---",
                              "-O--"};
    int size_15 = 4;
    int row_15 = 0;
    read_board_from_string(board, test_board_15, size_15);
    solve_balance_row(board, size_15, row_15, announce);
    print_board(board, size_15);
    
    // test case 16
    string test_board_16[] = {"----",
                              "----",
                              "----",
                              "----"};
    int size_16 = 4;
    int row_16 = 0;
    read_board_from_string(board, test_board_16, size_16);
    solve_balance_row(board, size_16, row_16, announce);
    print_board(board, size_16);
    
}

void test_solve_balance_column() {
    int board[MAX_SIZE][MAX_SIZE];
    bool announce;
    
    // test case 1
    string test_board_1[] = {"X-XO",
                             "OO--",
                             "X---",
                             "-O--"};
    int size_1 = 4;
    int col_1 = 0;
    read_board_from_string(board, test_board_1, size_1);
    solve_balance_column(board, size_1, col_1, announce);
    print_board(board, size_1);
    
    // test case 2
    string test_board_2[] = {"O-OX",
                             "OO--",
                             "----",
                             "XO--"};
    int size_2 = 4;
    int col_2 = 0;
    read_board_from_string(board, test_board_2, size_2);
    solve_balance_column(board, size_2, col_2, announce);
    print_board(board, size_2);
    
    // test case 3
    string test_board_3[] = {"X-",
                             "--"};
    int size_3 = 2;
    int col_3 = 0;
    read_board_from_string(board, test_board_3, size_3);
    solve_balance_column(board, size_3, col_3, announce);
    print_board(board, size_3);
    
    // test case 4
    string test_board_4[] = {"O-",
                             "--"};
    int size_4 = 2;
    int col_4 = 0;
    read_board_from_string(board, test_board_4, size_4);
    solve_balance_column(board, size_4, col_4, announce);
    print_board(board, size_4);
    
    // test case 5
    string test_board_5[] = {"X"};
    
    int size_5 = 1;
    int col_5 = 0;
    read_board_from_string(board, test_board_5, size_5);
    solve_balance_column(board, size_5, col_5, announce);
    print_board(board, size_5);
    
    // test case 6
    string test_board_6[] = {"O"};
    
    int size_6 = 1;
    int col_6 = 0;
    read_board_from_string(board, test_board_6, size_6);
    solve_balance_column(board, size_6, col_6, announce);
    print_board(board, size_6);
    
}

void test_board_is_solved() {
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"XOXO",
                             "OXOX",
                             "XXOO",
                             "OOXX"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_is_solved(board, size_1) << endl;
    
    // test case 2
    string test_board_2[] = {"OOOX",
                             "OXOX",
                             "XXOO",
                             "OOXX"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_is_solved(board, size_2) << endl;
    
    // test case 3
    string test_board_3[] = {"XOXO",
                             "XOXO",
                             "XXOO",
                             "OOXX"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_is_solved(board, size_3) << endl;
    
    // test case 4
    string test_board_4[] = {"O-OX",
                             "OO--",
                             "----",
                             "XO--"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << board_is_solved(board, size_4) << endl;
}

void test_check_valid_input() {
    
    // test case 1
    int size1 = 4;
    int row_input1 = 1;
    char col_input1 = 'B';
    char color_char1 = RED_LETTER;
    int row1 = 1;
    int col1 = 1;
    
    cout << check_valid_input(size1, row_input1, col_input1, color_char1, row1, col1) << endl;
    
    // test case 2
    int size2 = 4;
    int row_input2 = 0;
    char col_input2 = 'B';
    char color_char2 = RED_LETTER;
    int row2 = 1;
    int col2 = 1;
    
    cout << check_valid_input(size2, row_input2, col_input2, color_char2, row2, col2) << endl;
    
    // test case 3
    int size3 = 4;
    int row_input3 = 5;
    char col_input3 = 'B';
    char color_char3 = RED_LETTER;
    int row3 = 1;
    int col3 = 1;
    
    cout << check_valid_input(size3, row_input3, col_input3, color_char3, row3, col3) << endl;
    
    // test case 4
    int size4 = 4;
    int row_input4 = 1;
    char col_input4 = '@';
    char color_char4 = RED_LETTER;
    int row4 = 1;
    int col4 = 1;
    
    cout << check_valid_input(size4, row_input4, col_input4, color_char4, row4, col4) << endl;
    
    // test case 5
    int size5 = 4;
    int row_input5 = 1;
    char col_input5 = 'E' + size5;
    char color_char5 = RED_LETTER;
    int row5 = 1;
    int col5 = 1;
    
    cout << check_valid_input(size5, row_input5, col_input5, color_char5, row5, col5) << endl;
    
    // test case 6
    int size6 = 4;
    int row_input6 = 1;
    char col_input6 = 'B';
    char color_char6 = 'Z';
    int row6 = 1;
    int col6 = 1;
    
    cout << check_valid_input(size6, row_input6, col_input6, color_char6, row6, col6) << endl;
}

void test_check_valid_move() {
    
    // test case 1
    int test_board_1[MAX_SIZE][MAX_SIZE] = { {RED, UNKNOWN, RED, BLUE},
                             {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN},
                             {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN},
                             {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN} };
    int size_1 = 4;
    int test_board_2[MAX_SIZE][MAX_SIZE] = { {RED, BLUE, RED, BLUE},
                               {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN},
                               {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN},
                               {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN} };
    int row1 = 0;
    int col1 = 1;
    int color1 = BLUE;
    
    cout << check_valid_move(test_board_1, test_board_2, size_1, row1, col1, color1) << endl;
    
    // test case 2
    int test_board_3[MAX_SIZE][MAX_SIZE] = { {RED, UNKNOWN, RED, BLUE},
                                             {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN},
                                             {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN},
                                             {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN} };
    int size_2 = 4;
    int test_board_4[MAX_SIZE][MAX_SIZE] = { {BLUE, UNKNOWN, RED, BLUE},
                                             {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN},
                                             {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN},
                                             {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN} };
    int row2 = 0;
    int col2 = 0;
    int color2 = BLUE;
    
    cout << check_valid_move(test_board_3, test_board_4, size_2, row2, col2, color2) << endl;
    
    // test case 3
    int test_board_5[MAX_SIZE][MAX_SIZE] = { {RED, UNKNOWN, RED, BLUE},
                                             {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN},
                                             {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN},
                                             {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN} };
    int size_3 = 4;
    int test_board_6[MAX_SIZE][MAX_SIZE] = { {RED, RED, RED, BLUE},
                                             {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN},
                                             {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN},
                                             {UNKNOWN, UNKNOWN, UNKNOWN, UNKNOWN} };
    int row3 = 0;
    int col3 = 1;
    int color3 = RED;
    
    cout << check_valid_move(test_board_5, test_board_6, size_3, row3, col3, color3) << endl;
    
}
