/*******************************************************************************
*
* Program: 2D array examples
* 
* Description: Examples of working with 2D arrays in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=ZUPfWzTlPbE
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// we can use constants to define the size of 2D arrays, this can help us to 
// write code (e.g. loops) that will still work if we need to change the size 
// of the 2D array later
#define ROWS 3
#define COLS 3

// dimensions of our matrices
#define M 3
#define N 4
#define P 5

// We specify the dimensions of the 2D arrays in our parameters... in this case
// we specify BOTH the row and column, there are a few other ways we can pass 
// 2D arrays to functions but this is a common way.
void matrix_mult(int c[M][P], int a[M][N], int b[N][P]);

int main(void)
{
  // delcare the array
  int a[ROWS][COLS];

  // use scanf to accept user input to initialize the array elements
  for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
    {
      printf("Enter a[%d][%d]=",i,j);
      scanf("%d", &a[i][j]);
    }

  // print out all elements of the array
  for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
      printf("a[%d][%d]=%d\n",i,j,a[i][j]);

  // initialize 2D arrays representing matrices to be multiplied
  int A[M][N] = { {1,2,3,4},
                  {4,5,6,7},
                  {8,9,10,11} };

  int B[N][P] = { {1,1,1,1,1},
                  {1,1,1,1,1},
                  {1,1,1,1,1},
                  {1,1,1,1,1} };

  int C[M][P] = { {0,0,0,0,0},
                  {0,0,0,0,0},
                  {0,0,0,0,0} };

  // perform the matrix multiplication
  matrix_mult(C,A,B);

  // print out the result matrix C
  printf("\n\n\n");
  for (int i = 0; i < M; i++)
    for (int j = 0; j < P; j++)
      printf("C[%d][%d]=%d\n",i,j,C[i][j]);

  return 0;
}

// Performs a matrix multiplication of a and b, stores result into c
void matrix_mult(int c[M][P], int a[M][N], int b[N][P])
{
  // Our code below depends on c[i][j] being 0, so initialize it to 0 
  // just to be sure (this could actually be done *in* the below loops too, 
  // which would be more efficient!)
  for (int i = 0; i < M; i++)
    for (int j = 0; j < P; j++)
      c[i][j] = 0;
  
  // perform the matrix multiplication
  for (int i = 0; i < M; i++)
    for (int j = 0; j < P; j++)
      for (int k = 0; k < N; k++)
        c[i][j] += a[i][k] * b[k][j];
}
