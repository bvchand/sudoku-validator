/*
 * single-threaded-validotor.h
 */

#ifndef SINGLE_THREADED_VALIDOTOR_H_
#define SINGLE_THREADED_VALIDOTOR_H_

#include "sudoku-solution-validator.h"


void checkRows(int* matrix[ROWS][COLUMNS]);
void checkCols(int* matrix[ROWS][COLUMNS]);
void checkGrid(int* board[ROWS][COLUMNS]);

void singleThreadedValidator(int* board[ROWS][COLUMNS]);

#endif /* SINGLE_THREADED_VALIDOTOR_H_ */
