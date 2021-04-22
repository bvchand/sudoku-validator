/*
 =======================================================================================================
 Name        : sudoku-solution-validator.c
 Copyright   : Your copyright notice
 Description : Sudoku solution validation done using both single threaded and multi-threaded validators
 =======================================================================================================
 */

#include "../inc/single-threaded-validator.h"
#include "../inc/multithreaded-validator.h"

int main(void) {
	int *matrix[ROWS][COLUMNS];

	// read the sudoku solution
	readMatrix(matrix);

	// print the matrix solution
	for(int i=0; i<ROWS; i++) {
		for(int j=0; j<COLUMNS; j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}

	clock_t start, end;
    double cpu_time_used;

    printf("\n----------SINGLE THREADED VALIDATOR----------\n");

    //time computation for the single threaded validator
	start = clock();

	// single threaded validator returns 0 if the solution is invalid and 1 if valid
	if(singleThreadedValidator(matrix))
		printf("\nSudoku solution is valid");
	else
		printf("\nSudoku solution is invalid");

	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nSTV took %f seconds to complete the validation\n", cpu_time_used);


	printf("\n----------MULTITHREADED VALIDATOR------------\n\n");

	//time computation for the multi-threaded validator
	start = clock();

	// multi-threaded validator returns 0 if the solution is invalid and 1 if valid
	if(multiThreadedValidator(matrix))
		printf("\nSudoku solution is valid");
	else
		printf("\nSudoku solution is invalid");

	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nMTV took %f seconds to complete the validation\n", cpu_time_used);
}

void readMatrix(int *matrix[ROWS][COLUMNS]) {
	FILE *fp;

	fp = fopen(INPUT_MATRIX, "r");

	if(fp == NULL){
			// if the file name is invalid or if file doesn't exist
			printf("UNABLE TO OPEN THE FILE: %s \n", INPUT_MATRIX);
			exit(1);
		}
	else{
		for(int row=0; row < ROWS; row++){
			for(int col=0; col < COLUMNS; col++){
				fscanf(fp, "%d", &matrix[row][col]);	// scan each element
			}
		}
	}
	fclose(fp);
}
