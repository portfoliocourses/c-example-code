/*******************************************************************************
*
* Program: Find Sum And Average Of Each Row In A 2D Array
*
* Description: Example of how to find the sum and average of each row in a 2D
* array using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=oxOsk4kM9EI
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
    {1,1,1,1,1},
    {2,2,2,2,2},
    {1,3,5,7,9},
    {4,5,6,7,8}
  };

  // Declare variables to store the sum and average calculated for each row
  float sum = 0;
  float average = 0;

  // The outer loop will use its counter variable i to go through each row
  // index in our 2D array from 0 up until ROWS.  We'll use this counter
  // variable to help us look at the values in each row at each colum index.
  for (int i = 0; i < ROWS; i++)
  {
    // Reset sum to 0 before adding all the values in the array at the row
    // i to sum in order to calculate the sum of this row
    sum = 0;

    // The inner loop uses its counter variable to go through each column index,
    // and *for* the 'current row index' as given by the counter variable i,
    // we add the element in the array at the row index i and column index j
    // to the sum.  This will give us the sum of all the elements at the row i.
    for (int j = 0; j < COLUMNS; j++)
      sum += array[i][j];

    // Output the sum of the elements in the row with the index i
    printf("Row %d Sum = %f\n", i, sum);

    // Calculate the average of the elements in this row by dividing their sum
    // by the number of columns (i.e. the number of elements in the row)
    average = sum / COLUMNS;

    // Ouput the average of the elements in the row with the index i
    printf("Row %d Average = %f\n\n", i, average);
  }

  return 0;
}