/*
 ============================================================================
 Name        : sudoku-solution-validator.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "sudoku-solution-validator.h"
#include "single-threaded-validotor.h"

int main(void) {
	int *matrix[ROWS][COLUMNS];

	readMatrix(matrix);

	for(int i=0; i<ROWS; i++) {
		for(int j=0; j<COLUMNS; j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}


<<<<<<< HEAD
	//display sudoku matrix
	printf("\n----------CURRENTLY SOLVING----------\n\n");
	singleThreadedValidator(matrix);
=======
int checkForDuplicate(int nums[]){
    int total = 0;
    for(int i=0;i<9;i++){
        total+=nums[i];
    }
    if(total != 45){
        return 0;
    } 
    return 1;
}

>>>>>>> f0ed10403fdf460fde8e7f84634982bb5678faf8

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

    //Checking rows
    int rows[9];
    for(int col=0; col < COLUMNS; col++){
        if(!checkForDuplicate(matrix[col])){
            printf("invalid sudoku for col:\n");
            for(int x=0;x<9;x++){
                printf("%d ",matrix[col][x]);
            }
            exit(0);
        }
    }

    //Checking columns
    for(int x=0;x<9;x++){
        for(int y = 0;y<9;y++){
            rows[y]=matrix[y][x];
        }
        if(!checkForDuplicate(rows)){
            printf("invalid sudoku loool\n");
            exit(0);
        }
    }

    //Checking for 3X3 grids
    for(int subgridrow = 0;subgridrow<9;subgridrow+=3){
        for(int subgridcol = 0;subgridcol<9;subgridcol+=3){
            int rowsIndex =0;
            for(int row=0;row<3;row++){
                for(int col=0;col<3;col++){
                    rows[rowsIndex++] = matrix[subgridrow + row][subgridcol + col];
                    // printf("%d ",matrix[subgridrow + row][subgridcol + col]);
                }
                // printf("\n");
            }
            // for(int xx=0;xx<9;xx++){
            //     printf("%d ",rows[xx]);
            // }
            // printf("\n\n");
            if(!checkForDuplicate(rows)){
                printf("invalid sudoku who let the dogs otu\n");
                for(int x=0;x<9;x++){
                    printf("%d ",rows[x]);
                }
                exit(0);
            }
        }
    }


	fclose(fp);
}

int checkForDuplicate(int nums[]){

}
