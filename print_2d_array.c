/*******************************************************************************
*
* Program: Print A 2D Array
*
* Description: Program to print out a 2D array in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=kU-_WPIA3ys 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// Define preprocessor constants for the number of ROWS and COLS in the 2D 
// array, preventing us from having to repeat the dimensions everywhere they are
// needed or altering them everywhere if we need to change them.
#define ROWS 4
#define COLS 5

// Performs the same algorithm below in the main function to output the 2D array
void print2Darray(int array[ROWS][COLS])
{
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      printf("%3d ", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main()
{
  // Declare and initialize the 2D array
  int array[ROWS][COLS] =
  { {1,2,3,4,5},    
    {6,7,8,9,10},     
    {11,12,13,14,15}, 
    {16,17,18,19,20}  
  };
    
  // The outer loop with its counter variable i loops over each row index.  
  // Then *for* reach row index, we use the inner loop and counter variable j 
  // to loop over each column index.  We can then print out the element at 
  // each row and column index in the inner loop.  We use the width field 
  // "3" with "%3d" so that each integer outputs into a field of width 3 
  // characters.  This will give the table / 2D grid of output fixed width 
  // columns and neatly align the data.  We also output a newline after 
  // outputting each row of values so that the next row of values outputs 
  // on the next line of the terminal.
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      printf("%3d ", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  // We could also call the function to print out the 2D array as done below:
  // print2Darray(array);

  return 0;
}