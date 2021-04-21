/*
 ============================================================================
 Name        : single-threaded-validotor.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "..\inc\single-threaded-validator.h"

int checkValid(int* nums){
    int dupChecker[9] = {0,0,0,0,0,0,0,0,0};
    for(int x=0; x<9;x++) {
    	printf("%d ",nums[x]);
    }
	for(int i=0;i<9;i++){
		int num = nums[i];
		if(nums[i]<1 || nums[i]>9) {
			return 0;
		}
		if(dupChecker[num-1]) {
			return 0;
		}
		dupChecker[num-1] = 1;
	}
	return 1;
}

int checkRows(int* matrix[9][9]) {
	printf("checkRows");
    for(int x=0; x<9;x++) {
    	printf("%d ",matrix[0][x]);
    }
    printf("\n");
	for(int i=0;i<9;i++)
	{
		if (!checkValid(matrix[i]))	return 0;
	}
	return 1;
}

int checkCols(int* matrix[9][9]) {
	int rows[9];
	for(int x=0;x<9;x++){
        for(int y = 0;y<9;y++){
            rows[y]=matrix[y][x];
        }
        if(!checkValid(rows)) return 0;
    }
	return 1;
}

int checkGrid(int* matrix[9][9]) {
	int rows[9];
	for(int subgridrow = 0;subgridrow<9;subgridrow+=3){
        for(int subgridcol = 0;subgridcol<9;subgridcol+=3){
            int rowsIndex =0;
            for(int row=0;row<3;row++){
                for(int col=0;col<3;col++){
                    rows[rowsIndex++] = matrix[subgridrow + row][subgridcol + col];
                }
            }
        if(!checkValid(rows)) return 0;
        }
    }
	return 1;
}


int singleThreadedValidator(int* matrix[9][9]) {
	return checkRows(matrix) && checkCols(matrix) && checkGrid(matrix);
}
