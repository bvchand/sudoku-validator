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
	clock_t start, end;
    double cpu_time_used;
	printf("\n----------SINGLE THREADED VALIDATOR----------\n\n");
	start = clock();
	if(singleThreadedValidator(matrix))
		printf("\n\nSingle thread Sudoku solution is valid");
	else
		printf("\n\nSingle thread Sudoku solution is invalid");
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nSTV took %f seconds to execute \n", cpu_time_used);

	printf("\n----------MULTITHREADED VALIDATOR----------\n\n");

	start = clock();
	if(multiThreadedValidator(matrix))
		printf("\n\nMulti thread Sudoku solution is valid");
	else
		printf("\n\nMulti thread Sudoku solution is invalid");
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nMTV took %f seconds to execute \n", cpu_time_used);
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
