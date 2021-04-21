/*
 ============================================================================
 Name        : sudoku-solution-validator.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "..\inc\sudoku-solution-validator.h"
#include "..\inc\single-threaded-validator.h"

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

	if(singleThreadedValidator(matrix)){
		printf("\n\n Valid sudoku");
	}
	else {
		printf("\n\n Invalid sudoku");
	}

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
