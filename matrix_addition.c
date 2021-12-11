/*******************************************************************************
*
* Program: Matrix Addition
* 
* Description: Implementation of matrix addition in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Jtn_NXLvbAQ 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// number of rows and columns in our matrices
#define ROWS 3
#define COLS 4

void matrix_addition(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS]);

int main(void)
{
  // test matrices
  int A[ROWS][COLS] =
  { {1,1,1,1},
    {1,1,1,1},
    {1,1,1,1}
  };
 
  int B[ROWS][COLS] =
  { {2,2,2,2},
    {2,2,2,2},
    {2,2,2,2}
  };
  
  // We'll add together A and B and store the result into C
  int C[ROWS][COLS];
  
  matrix_addition(A,B,C);
  
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

// adds matrices A and B and stores the result into C
void matrix_addition(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS])
{
  // add together each corresponding value in A and B and store the result into 
  // the corresponding value in C
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
}