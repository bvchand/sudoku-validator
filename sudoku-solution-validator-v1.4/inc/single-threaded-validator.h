/*
 * single-threaded-validator.h
 */

#ifndef SINGLE_THREADED_VALIDATOR_H_
#define SINGLE_THREADED_VALIDATOR_H_

#include "../inc/sudoku-solution-validator.h"

int checkValid(int* nums);

int checkRows(int* matrix[9][9]);
int checkCols(int* matrix[9][9]);
int checkGrid(int* matrix[9][9]);

int singleThreadedValidator(int* matrix[9][9]);

#endif /* SINGLE_THREADED_VALIDATOR_H_ */
