/*******************************************************************************
*
* Program: Find Sum And Average Of Each Column In A 2D Array
*
* Description: Example of how to find the sum and average of each column in a 2D
* array using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=6A8cM947CEg 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// Define preprocessor constants for the number of rows and columns in our 2D
// array so we can use them when declaring and working with the 2D array.
#define ROWS 5
#define COLUMNS 5

int main()
{
  // Declare and initialize a 2D arrow with ROWS number of rows and COLUMNS
  // number of COLUMNS (i.e. a 5x5 2D array)
  float array[ROWS][COLUMNS] =
  { {1,2,3,4,5},
    {1,2,3,4,5},
    {1,1,1,1,1},
    {2,2,2,2,2},
    {3,3,3,3,3}
  };

  // Declare variables to store the sum and average calculated for each row
  float sum = 0;
  float average = 0;

  // The outer loop will use its counter variable i to go through each column
  // index in our 2D array from 0 up until COLUMNS.  We'll use this counter
  // variable to help us look at the values in each column at each row index.
  for (int i = 0; i < COLUMNS; i++)
  {
    // Reset sum to 0 before adding all the values in the array at the column
    // i to sum in order to calculate the sum of this column
    sum = 0;

    // The inner loop uses its counter variable to go through each row index,
    // and *for* the 'current column index' as given by the counter variable i,
    // we add the element in the array at the column index i and row index j
    // to the sum.  This will give us the sum of all the elements at the
    // column i.
    for (int j = 0; j < ROWS; j++)
      sum += array[j][i];

    // Output the sum of the elements in the column with the index i
    printf("Column %d Sum = %f\n", i, sum);

    // Calculate the average of the elements in this column by dividing their
    // sum by the number of rows (i.e. the number of elements in the column)
    average = sum / ROWS;

    // Ouput the average of the elements in the column with the index i
    printf("Column %d Average = %f\n\n", i, average);
  }

  return 0;
}
