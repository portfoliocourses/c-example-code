/*******************************************************************************
*
* Program: Swap 2D Array Rows
* 
* Description: Swap two rows in a 2D array using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=WK2VR6Br2AU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// use constants to define our array dimensions
#define ROWS 5
#define COLS 4

void swap_rows(int array[ROWS][COLS], int rowA, int rowB);

int main(void)
{
  // create an array
  int A[ROWS][COLS] =
  { {1,1,1,1},
    {2,2,2,2},
    {3,3,3,3},
    {4,4,4,4},
    {5,5,5,5}
  };
  
  // swap the 2nd and 4th rows (remember arrays are zero-indexed in C!)
  swap_rows(A, 1, 3);

  // print out A after swapping the rows
  for (int i = 0; i < ROWS; i++)
  {
    // prints out each row of values
    for (int j = 0; j < COLS; j++)
    {
      printf("%d ", A[i][j]);
    }
    // prints out a new line so the next row starts on the next line
    printf("\n");
  }
  
  return 0;
}

// swaps the rows in array at rowA and rowB indexes
void swap_rows(int array[ROWS][COLS], int rowA, int rowB)
{
  // temp variable for helping to perform the row swap
  int temp = 0;

  // increment through each column index with i
  for (int i = 0; i < COLS; i++)
  {
    // use the temp variable to swap the value at rowA and rowB at column i
    temp = array[rowA][i];
    array[rowA][i] = array[rowB][i];
    array[rowB][i] = temp;
  }
}