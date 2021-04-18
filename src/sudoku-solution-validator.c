/*
 ============================================================================
 Name        : sudoku-solution-validator.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define INPUT_MATRIX "input_matrix.txt"
#define COLUMNS 9
#define ROWS 9

typedef struct {
	int row;
	int column;
	int (*matrix)[ROWS];
}parameters;


int main(void) {
	FILE *fp;
	int matrix[COLUMNS][ROWS];

	fp = fopen(INPUT_MATRIX, "r");

	if(fp == NULL){
			printf("UNABLE TO OPEN THE FILE: %s \n", INPUT_MATRIX);
			exit(1);
		}
	else{
		for(int col=0; col < COLUMNS; col++){
			for(int row=0; row < ROWS; row++){
				fscanf(fp, "%d", &matrix[col][row]);
			}
			printf("\n");
		}
	}
	fclose(fp);

	for(int i=0; i<ROWS; i++) {
		for(int j=0; j<COLUMNS; j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}


	//display sudoku matrix
	printf("CURRENTLY SOLVING --\n");


}
