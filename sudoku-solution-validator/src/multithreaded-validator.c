/*
 * multithreaded-validator.c
 */


#include "../inc/multithreaded-validator.h"

/*
 * array that maps to each row/column/3x3-grid of the sudoku solution matrix to each array element
 * sets each element to 1 if the corresponding row/column/3x3-grid is valid
 */
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

            // checks if the elements are unique or a duplicate
            if (validarray[element] != 0)
                pthread_exit(NULL);

            else
                validarray[element] = 1;
        }
    }

    // sets the first 9 indices of the validArray to 1 for each valid 3x3 grid
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

        // checks if the elements are unique or a duplicate
        if (validarray[element] != 0)
            pthread_exit(NULL);

        else
            validarray[element] = 1;
    }

    // sets the first 9 indices of the validArray to 1 for each valid row
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

        // checks if the elements are unique or a duplicate
        if (validarray[element] != 0)
            pthread_exit(NULL);

        else
            validarray[element] = 1;
    }

    // sets the first 9 indices of the validArray to 1 for each valid column
    validArray[18 + col] = 1;
    pthread_exit(NULL);
 }

int multiThreadedValidator(int* matrix[9][9]) {

	pthread_t threads[NUM_THREADS];

	int tCount = 0;

	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLUMNS; c++)
		{
			if (r%3 == 0 && c%3 == 0)
			{
				parameters *grid = (parameters *) malloc(sizeof(parameters));

				// assigns the pointer to the first row and column of the grid
				grid->row = r;
				grid->column = c;
				grid->solution = matrix;

				// spins the threads for each 3x3 grid
				pthread_create(&threads[tCount++], NULL, checkGrids, grid);
			}

			if (c == 0)
			{
				parameters *rows = (parameters *) malloc(sizeof(parameters));

				// assigns the pointer to the first row and column of the row
				rows->row = r;
				rows->column = c;
				rows->solution = matrix;

				// spins the threads for each row
				pthread_create(&threads[tCount++], NULL, checkRowss, rows);
			}

			if (r == 0)
			{
				parameters *cols = (parameters *) malloc(sizeof(parameters));

				// assigns the pointer to the first row and column of the column
				cols->row = r;
				cols->column = c;
				cols->solution = matrix;

				// spins the threads for each column
				pthread_create(&threads[tCount++], NULL, checkColss, cols);
			}
		}
	}

	// waits for all the threads to complete execution
	for (int i = 0; i < NUM_THREADS; i++)
		pthread_join(threads[i], NULL);

	// checks if all the elements of the validArray are 1 (solution is valid)
	for (int i = 0; i < NUM_THREADS; i++)
		if(validArray[i] == 0)		return 0;

	return 1;
}

