/*
 * sudoku-solution-validator.h
 */

#ifndef SUDOKU_SOLUTION_VALIDATOR_H_
#define SUDOKU_SOLUTION_VALIDATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
// #include <chrono>
#include <time.h>

#define INPUT_MATRIX "input_matrix.txt"
#define COLUMNS 9
#define ROWS 9
#define NUM_THREADS 27

typedef struct {
	int row;
	int column;
	int (*solution)[ROWS];
}parameters;

void readMatrix(int *matrix[ROWS][COLUMNS]);
int main(void);

#endif /* SUDOKU_SOLUTION_VALIDATOR_H_ */
