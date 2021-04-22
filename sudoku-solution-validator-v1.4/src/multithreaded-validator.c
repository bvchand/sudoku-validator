/*
 * multithreaded-validator.c
 */


#include "../inc/multithreaded-validator.h"

int validArray[NUM_THREADS] = {0};

void checkGrids(void *params)
{
    parameters *data = (parameters *) params;
    int startRow = data->row;
    int startCol = data->column;
    int validarray[10] = {0};
    for (int i = startRow; i < startRow + 3; ++i)
    {
        for (int j = startCol; j < startCol + 3; ++j)
        {
            int element = data->solution[i][j];
            if (validarray[element] != 0)
                pthread_exit(NULL);
            else
                validarray[element] = 1;
        }
    }

    validArray[startRow + startCol/3] = 1;
    pthread_exit(NULL);
}

void checkRowss(void *params)
{
    parameters *data = (parameters *) params;
    int row = data->row;

    int validarray[10] = {0};
    for (int j = 0; j < 9; j++)
    {
        int element = data->solution[row][j];
        if (validarray[element] != 0)
            pthread_exit(NULL);
        else
            validarray[element] = 1;
    }

    validArray[9 + row] = 1;
    pthread_exit(NULL);
}

void checkColss(void *params)
{
    parameters *data = (parameters *) params;

    int col = data->column;

    int validarray[10] = {0};
    for (int i = 0; i < 9; i++)
    {
        int element = data->solution[i][col];
        if (validarray[element] != 0)
            pthread_exit(NULL);
        else
            validarray[element] = 1;
    }

    validArray[18 + col] = 1;
    pthread_exit(NULL);
 }

int multiThreadedValidator(int* matrix[9][9]) {

	pthread_t threads[NUM_THREADS];

	int tCount = 0;

	for (int r = 0; r < ROWS; r++)
	{
//		printf("test\n");
		for (int c = 0; c < COLUMNS; c++)
		{
//			printf("***\n");
//			printf("%d ", matrix[r][c]);
			if (r%3 == 0 && c%3 == 0)
			{
//				printf("entered grid\n");
				parameters *grid = (parameters *) malloc(sizeof(parameters));
				grid->row = r;
				grid->column = c;
				grid->solution = matrix;
				pthread_create(&threads[tCount++], NULL, checkGrids, grid);
//				printf("\ngrid %d done\n",r);
			}

			if (c == 0)
			{
//				printf("entered row\n");
				parameters *rows = (parameters *) malloc(sizeof(parameters));
				rows->row = r;
				rows->column = c;
				rows->solution = matrix;
				pthread_create(&threads[tCount++], NULL, checkRowss, rows);
//				printf("\nrows %d done\n",r);
			}

			if (r == 0)
			{
//				printf("entered col\n");
				parameters *cols = (parameters *) malloc(sizeof(parameters));
				cols->row = r;
				cols->column = c;
				cols->solution = matrix;
				pthread_create(&threads[tCount++], NULL, checkColss, cols);
//				printf("\ncols %d done\n",c);
			}
//			printf("%d ", matrix[r][c]);
		}
//		printf("\n");
	}

	for (int i = 0; i < NUM_THREADS; i++)
		pthread_join(threads[i], NULL);

	for (int i = 0; i < NUM_THREADS; i++)
		if(validArray[i] == 0)		return 0;

	return 1;
}

