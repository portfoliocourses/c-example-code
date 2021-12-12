/*******************************************************************************
*
* Program: Matrix Subtraction
* 
* Description: Implementation of matrix substraction in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=rPxe7t3fmeo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// number of rows and columns in our matrices
#define ROWS 3
#define COLS 4

void matrix_subtraction(int A[ROWS][COLS],
                        int B[ROWS][COLS],
                        int C[ROWS][COLS]);

int main(void)
{
  // test matrices
  int A[ROWS][COLS] =
  { {2,2,2,2},
    {2,2,2,2},
    {2,2,2,2}
  };
  
  int B[ROWS][COLS] =
  { {1,1,1,1},
    {1,1,1,1},
    {1,1,1,1}
  };
  
  int C[ROWS][COLS];
  
  // We'll perform A - B and store the result into C
  matrix_subtraction(A,B,C);
  
  // output C so we can see if the result is correct
  for (int i = 0; i < ROWS; i++)
  {
    // outputs a row of values in C, followed by a newline to put the next row 
    // on the next line    
    for (int j = 0; j < COLS; j++)
    {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}

// subtracts matrices A and B and stores the result into C
void matrix_subtraction(int A[ROWS][COLS],
                        int B[ROWS][COLS],
                        int C[ROWS][COLS])
{
  // subtract each corresponding value in A and B and store the result into 
  // the corresponding value in C
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      C[i][j] = A[i][j] - B[i][j];
    }
  }
}
