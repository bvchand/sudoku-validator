/*
 * sudoku-solution-validator.h
 */

#ifndef SUDOKU_SOLUTION_VALIDATOR_H_
#define SUDOKU_SOLUTION_VALIDATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

// file containing the sudoku solution
#define INPUT_MATRIX "input_matrix.txt"


#define COLUMNS 9	// number of columns in the sudoku solution
#define ROWS 9		// number of rows in the sudoku solution

#define NUM_THREADS 27	// maximum number of threads

// parameters of each element in the sudoku solution matrix.
typedef struct {
	int row;
	int column;
	int (*solution)[9];
}parameters;

/*
 * reads the sudoku matrix from the input file
 * params: matrix, 9x9 sudoku solution
 */
void readMatrix(int *matrix[ROWS][COLUMNS]);

/*
 * the main
 */
int main(void);

#endif /* SUDOKU_SOLUTION_VALIDATOR_H_ */
