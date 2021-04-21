/*
 * single-threaded-validator.h
 */

#ifndef SINGLE_THREADED_VALIDATOR_H_
#define SINGLE_THREADED_VALIDATOR_H_

#include "sudoku-solution-validator.h"

int checkValid(int* nums);

int checkRows(int* matrix[ROWS][COLUMNS]);
int checkCols(int* matrix[ROWS][COLUMNS]);
int checkGrid(int* board[ROWS][COLUMNS]);

int singleThreadedValidator(int* board[ROWS][COLUMNS]);

#endif /* SINGLE_THREADED_VALIDATOR_H_ */
