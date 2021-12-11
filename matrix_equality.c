/*******************************************************************************
*
* Program: Matrix Equality 
* 
* Description: Example of how to check if two matrices of equal dimension are 
* equal in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=c8-Bl50vjHk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

// matrix dimensions
#define ROWS 3
#define COLS 4

bool matrix_equality(int A[ROWS][COLS], int B[ROWS][COLS]);

int main(void)
{
  // test matrices
  int A[ROWS][COLS] =
  { {1,2,3,4},
    {1,2,3,4},
    {1,2,3,4}
  };
 
  int B[ROWS][COLS] =
  { {1,2,3,4},
    {1,2,5,4},
    {1,2,3,4}
  };
  
  // use the function to check for matrix equality and report the result
  if (matrix_equality(A,B))
    printf("A=B\n");
  else
    printf("A!=B\n");
  
  return 0;
}

// returns true if matrices A and B are equal, and false otherwise
bool matrix_equality(int A[ROWS][COLS], int B[ROWS][COLS])
{
  // check every position in A and B, and if at the same position in each 
  // matrix the element is not equal, the matrices are not equal, and 
  // we should return false
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      if (A[i][j] != B[i][j]) return false;
    }
  }
  
  // if we check all possible positions in the matrices and never find an 
  // element that is not equal, they must all be equal, and we return true
  return true;
}