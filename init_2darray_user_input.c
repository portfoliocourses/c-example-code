/*******************************************************************************
*
* Program: Initialize 2D Array With User Input
* 
* Description: Example of how to initialize a 2D array with user input in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=p8-DGGL1Rk0 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// constants for defining and working with the 2d array
#define ROWS 3
#define COLS 5

// ultimately we can visualize our 2d array as follows: 
//
//            array =
//
// 1st row:   [ 0,  0,  0,  0,  0 ]
//
// 2nd row:   [ 0,  0,  0,  0,  0 ]
//
// 3rd row:   [ 0,  0,  0,  0,  0 ]
//
int main(void)
{
  // declares a 2d array of ints with 3 rows and 5 columns
  int array[ROWS][COLS];
  
  // the outer loop iterates over each row with counter variable i
  for (int i = 0; i < ROWS; i++)
  {
    // the inner loop iterates over each column within each row with counter 
    // variable j
    for (int j = 0; j < COLS; j++)
    {
      // ask the user to enter the value for the ith row and jth column
      printf("array[%d][%d]=", i, j);

      // set the value in the 2d array at the ith row and jth column
      scanf("%d", &array[i][j]);
    }
  }
  
  // output each element in the 2d array by iterating over each row and 
  // column with the same structure as above 
  printf("\n");
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      // out the element at the ith row and jth column
      printf("%d ", array[i][j]);
    }
    
    // after the values for a row have been output, output a newline so that 
    // the next row of values starts on a new line
    printf("\n");
  }
  
  return 0;
}
