/*
 * single-threaded-validotor.c
 */

#include "../inc/single-threaded-validator.h"

int checkValid(int* nums){
    int dupChecker[9] = {0,0,0,0,0,0,0,0,0};

	for(int i=0; i<9; i++){
		int num = nums[i];
		if(nums[i]<1 || nums[i]>9) {
			return 0;	// sudoku solution is invalid if the value isn't between 1-9.
		}
		if(dupChecker[num-1]) {
			return 0;	// sudoku solution is invalid if the value is a duplicate.
		}
		dupChecker[num-1] = 1;	// sets the element to 1 if the value is unique.
    }
	return 1;
}

int checkRows(int* matrix[9][9]) {

	// checks for all the rows
	for(int i=0;i<9;i++)	{
		if (!checkValid(matrix[i]))	return 0;
	}
	return 1;
}

int checkCols(int* matrix[9][9]) {
	int rows[9];

	// checks for all the columns
	for(int x=0;x<9;x++) {
        for(int y = 0;y<9;y++){
            rows[y]=matrix[y][x];
        }
        if(!checkValid(rows)) return 0;
    }
	return 1;
}

int checkGrid(int* matrix[9][9]) {
	int rows[9];

	//checks for all the 3x3 grids
	for(int subgridrow = 0;subgridrow<9;subgridrow+=3)	{
        for(int subgridcol = 0;subgridcol<9;subgridcol+=3)	{
            int rowsIndex =0;
            for(int row=0;row<3;row++)	{
                for(int col=0;col<3;col++)	{
                	// gathers the elements of the grid
                    rows[rowsIndex++] = matrix[subgridrow + row][subgridcol + col];
                }
            }

            // checks if the values are valid.
        if(!checkValid(rows)) return 0;
        }
    }
	return 1;
}


int singleThreadedValidator(int* matrix[9][9]) {

	// returns 1 if rows/columns/grids are all valid; 0 if invalid
	return checkRows(matrix) && checkCols(matrix) && checkGrid(matrix);
}
