/*
 * single-threaded-validator.h
 */

#ifndef SINGLE_THREADED_VALIDATOR_H_
#define SINGLE_THREADED_VALIDATOR_H_

#include "../inc/sudoku-solution-validator.h"

/*
 * Checks if the elements of the row/column/3x3-grid are valid
 * params: nums, an array containing the elements of the row/column/3x3-grid
 * returns: 0 if invalid; 1 if valid
 */
int checkValid(int* nums);

/*
 * Checks if each row of the sudoku solution is valid
 * params: matrix, 9x9 sudoku solution
 * returns: 0 if invalid; 1 if valid
 */
int checkRows(int* matrix[9][9]);

/*
 * Checks if each column of the sudoku solution is valid
 * params: matrix, 9x9 sudoku solution
 * returns: 0 if invalid; 1 if valid
 */
int checkCols(int* matrix[9][9]);

/*
 * Checks if each 3x3-grid of the sudoku solution is valid
 * params: matrix, 9x9 sudoku solution
 * returns: 0 if invalid; 1 if valid
 */
int checkGrid(int* matrix[9][9]);

/*
 * Single threaded validator that checks if each row/column/3x3-grid of the sudoku solution is valid
 * params: matrix, 9x9 sudoku solution
 * returns: 0 if invalid; 1 if valid
 */
int singleThreadedValidator(int* matrix[9][9]);

#endif /* SINGLE_THREADED_VALIDATOR_H_ */
