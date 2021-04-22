/*
 ============================================================================
 Name        : sudoku-solution-validator.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "../inc/single-threaded-validator.h"
#include "../inc/multithreaded-validator.h"

int main(void) {
	int *matrix[ROWS][COLUMNS];

	readMatrix(matrix);

	for(int i=0; i<ROWS; i++) {
		for(int j=0; j<COLUMNS; j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}

	printf("\n----------SINGLE THREADED VALIDATOR----------\n\n");

	if(singleThreadedValidator(matrix))
		printf("\n\nSudoku solution is valid");
	else
		printf("\n\nSudoku solution is invalid");

	printf("\n----------MULTITHREADED VALIDATOR----------\n\n");

	if(multiThreadedValidator(matrix))
		printf("\n\nSudoku solution is valid");
	else
		printf("\n\nSudoku solution is invalid");
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
