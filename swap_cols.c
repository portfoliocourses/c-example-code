/*******************************************************************************
*
* Program: Swap Columns In A 2D Array 
* 
* Description: Swaps two columns in a 2D array in C.s
*
* YouTube Lesson: https://www.youtube.com/watch?v=-8esr14bCCI  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// use constants to define the dimensions of our 2D array
#define ROWS 3
#define COLS 5

void col_swap(int array[ROWS][COLS], int colA, int colB);

int main(void)
{
  // create a test 2d array
  int A[ROWS][COLS] =
  { {1,2,3,4,5},
    {1,2,3,4,5},
    {1,2,3,4,5}
  };
  
  // call the function to swap he 2nd and 4th columns in the 2d array
  col_swap(A, 1, 3);
  
  // print out the 2d array
  for (int i = 0; i < ROWS; i++)
  {
    // prints out all the values in a row of the 2d array
    for (int j = 0; j < COLS; j++)
    {
      printf("%d ", A[i][j]);
    }

    // prints out a newline so the next row starts on another line
    printf("\n");
  }
  
  return 0;
}

// swaps the columns in the array at colA index and colB index
void col_swap(int array[ROWS][COLS], int colA, int colB)
{
  // temporary variable used to help perform the swaps
  int temp = 0;

  // increment i over all of the row indexes of the 2d array
  for (int i = 0; i < ROWS; i++)
  {
    // swap the values in colA and colB indexes at row index i
    temp = array[i][colA];
    array[i][colA] = array[i][colB];
    array[i][colB] = temp;
  }
}