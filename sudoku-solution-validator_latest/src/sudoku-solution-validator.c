/*
 ============================================================================
 Name        : sudoku-solution-validator.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

<<<<<<< HEAD:sudoku-solution-validator_latest/src/sudoku-solution-validator.c
#include "sudoku-solution-validator.h"
#include "single-threaded-validator.h"
=======
// #include "sudoku-solution-validator.h"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define INPUT_MATRIX "input_matrix.txt"
#define COLUMNS 9
#define ROWS 9
#include "single-threaded-validotor.h"
>>>>>>> d04682c51446fcf7453a938ccc64ce4db97705a4:sudoku-solution-validator/src/sudoku-solution-validator.c

void readMatrix(int *matrix[ROWS][COLUMNS]);

int main(void) {
	int *matrix[ROWS][COLUMNS];

	readMatrix(matrix);

	for(int i=0; i<ROWS; i++) {
		for(int j=0; j<COLUMNS; j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}

	printf("\n----------CURRENTLY SOLVING----------\n\n");
<<<<<<< HEAD:sudoku-solution-validator_latest/src/sudoku-solution-validator.c

	if(singleThreadedValidator(matrix)){
		printf("\n\n Valid sudoku");
	}
	else {
		printf("\n\n Invalid sudoku");
	}
=======
	if(singleThreadedValidator(matrix)){
		printf("\n\n Valid sudoku");
	} else { printf("\n\n Invalid sudoku"); }
>>>>>>> d04682c51446fcf7453a938ccc64ce4db97705a4:sudoku-solution-validator/src/sudoku-solution-validator.c

}

void readMatrix(int *matrix[ROWS][COLUMNS]) {
	FILE *fp;

	fp = fopen(INPUT_MATRIX, "r");

	if(fp == NULL){
			printf("UNABLE TO OPEN THE FILE: %s \n", INPUT_MATRIX);
			exit(1);
		}
	else{
		for(int row=0; row < ROWS; row++){
			for(int col=0; col < COLUMNS; col++){
				fscanf(fp, "%d", &matrix[row][col]);
			}
		}
	}
	fclose(fp);
}
