/*
 * multithreaded-validator.h
 */

#ifndef SUDOKU_CHECKER_FUNCTIONS_H_
#define SUDOKU_CHECKER_FUNCTIONS_H_

#include "../inc/sudoku-solution-validator.h"

/*
 * Checks if each 3x3-grid of the sudoku solution is valid
 * params: matrix, 9x9 sudoku solution
 * returns: 0 if invalid; 1 if valid
 */
void checkGrids(void *params);

/*
 * Checks if each row of the sudoku solution is valid
 * params: matrix, 9x9 sudoku solution
 * returns: 0 if invalid; 1 if valid
 */
void checkRowss(void *params);

/*
 * Checks if each column of the sudoku solution is valid
 * params: matrix, 9x9 sudoku solution
 * returns: 0 if invalid; 1 if valid
 */
void checkColss(void *params);

/*
 * Checks if each row/column/3x3-grid of the sudoku solution is valid by spawning multiple threads
 * params: matrix, 9x9 sudoku solution
 * returns: 0 if invalid; 1 if valid
 */
int multiThreadedValidator(int* matrix[9][9]);

#endif /* SUDOKU_CHECKER_FUNCTIONS_H_ */
