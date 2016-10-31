/**
 * arrays.cpp
 *
 * EECS 183, Fall 2015
 * Assignment 3: Array exercises
 *
 * Mackenzie
 * mackfran
 *
 * These functions both modify and check arrays.
 */

#include <iostream>

using namespace std;

/**
 * Requires: size > 0 and size is the number of elements in array
 * Modifies: cout
 * Effects : Prints the elements in the given array, delimited by curly
 *           braces and separated by commas.
 */
void print_array(const int array[], int size);

/**
 * Requires: size > 0 and size is the number of elements in array
 * Modifies: array
 * Effects : Negates each element in array.
 */
void negate_all(int array[], int size);

/**
 * Requires: size > 0 and size is the number of elements in array
 * Modifies: Nothing.
 * Effects : Returns true if the elements in array are in order from
 *           smallest to largest, with duplicates allowed.
 */
bool is_sorted(const int array[], int size);

/**
 * Requires: size > 0 and size is the number of elements in source
 *           and target
 * Modifies: target
 * Effects : Copies the positive elements from source into adjacent
 *           locations in target, starting at index 0. Any remaining
 *           indices in target are left unchanged.
 */
void copy_positive_elements(const int source[], int target[], int size);

int main() {
 
}

void print_array(const int array[], int size) {
    cout << "{ " << array[0];
    for (int i = 1; i < size; i++) {
        cout << ", " << array[i];
    }
    cout << " }" << endl;
}

void negate_all(int array[], int size) {
    if (size > 0) {
        for (int i = 0; i < size; ++i) {
            array[i] = -(array[i]);
        }
    }
}

bool is_sorted(const int array[], int size) {
    bool sorted = true;
    if (size > 0) {
        for (int i = 0; i < size - 1; ++i) {
            if (array[i] > array[i + 1]) {
                sorted = false;
            }
        }
    }
    return sorted;
}

void copy_positive_elements(const int source[], int target[], int size) {
    int posLoc = 0;
    if (size > 0) {
        for (int i = 0; i < size; ++i) {
            if (!target[i]) {
                target[i] = 0;
            }
            if (source[i] > 0) {
                target[posLoc] = source[i];
                posLoc++;
            }
        }
    }
}
