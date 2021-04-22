/*
 * multithreaded-validator.h
 */

#ifndef SUDOKU_CHECKER_FUNCTIONS_H_
#define SUDOKU_CHECKER_FUNCTIONS_H_

#include "../inc/sudoku-solution-validator.h"

void checkGrids(void *params);
void checkRowss(void *params);
void checkColss(void *params);

int multiThreadedValidator(int* matrix[9][9]);

#endif /* SUDOKU_CHECKER_FUNCTIONS_H_ */
