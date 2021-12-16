/*******************************************************************************
*
* Program: Matrix Transpose 
* 
* Description: Finds the transpose of a matrix in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=5OpitQe0o5k 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

#define M 3
#define N 4

void transpose(int A[M][N], int T[N][M]);

int main(void)
{
  // test matrix stored as MXN 2darray
  int A[M][N] =
  { {1,2,3,4},
    {5,6,7,8},
    {9,8,7,6}
  };
  
  // NxM 2d array to store transpose
  int T[N][M];
  
  // create the transpose
  transpose(A, T);
  
  // print out the transpose
  for (int i = 0; i < N; i++)
  {
    // prints out each row of values in the transpose, follwoed by a newline 
    // so the next row prints out on the next line
    for (int j = 0; j < M; j++)
    {
      printf("%d ", T[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}

// stores the transpose of A in T
void transpose(int A[M][N], int T[N][M])
{
  // store the value at the ith row and jth column of A into the jth row and 
  // ith column of T to create the transpose
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      T[j][i] = A[i][j];
    }
  }
}

// The transpose of a matrix is a new matrix whose rows
// are the columns of the original matrix.
//
// [1 2 3 4]   transpose   [1 5 9]
// [5 6 7 8]       ->      [2 6 8]
// [9 8 7 6]               [3 7 7]
//                         [4 8 6]
