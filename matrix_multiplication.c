/*******************************************************************************
*
* Program: Matrix Multiplication 
* 
* Description: Implementation of the matrix multiplication algorithm in C.
* Learn about matrix multiplication here:
* https://en.wikipedia.org/wiki/Matrix_multiplication
*
* YouTube Lesson: https://www.youtube.com/watch?v=G_WjTIBTMhY  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

#define M 3
#define N 4
#define P 3

void matrix_mult(int A[M][N], int B[N][P], int C[M][P]);

int main(void)
{
  // create 2D arrays to store test matrices A, B 
  int A[M][N] =
  { {2,1,0,3},
    {1,0,3,1},
    {2,1,3,0}
  };
  
  int B[N][P] =
  { {2,1,1},
    {1,0,0},
    {3,3,3},
    {0,2,2}
  };
  
  // create 2D array to store resulting matrix of AxB
  int C[M][P];
  
  // multiples matrices AxB and stores result into C
  matrix_mult(A,B,C);
  
  // print out matrix C in a 2D grid
  for (int i = 0; i < M; i++)
  {
    // prints out reach row of the matrix
    for (int j = 0; j < P; j++)
    {
      // print out each element in a 4 char width field to evenly space elements
      printf("%4d ", C[i][j]);
    }

    // print a newline after each row so that the next row begins on a new line
    printf("\n");
  }
  
  return 0;
}

// conducts AxB matrix multiplication, stores result into C
void matrix_mult(int A[M][N], int B[N][P], int C[M][P])
{
  // carries out the standard matrix multiplication algorithm, the outer loops 
  // iterate over all the elements of C
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < P; j++)
    {
      // the inner most loop computes the value of the element of C at the ith 
      // row and jth column, by multiplying the corresponding elements of the 
      // ith row of A and the jth column of B and adding them together
      C[i][j] = 0;
      for (int k = 0; k < N; k++)
      {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

// Example Matrix Multiplication
//
// A = [2 1 0 3]      A is a 3x4 matrix
//     [1 0 3 1]
//     [2 1 3 0]
//
// B = [2 1 1]        B is a 4x3 matrix
//     [1 0 0]
//     [3 3 3]
//     [0 2 2]
//
// C = AB
//
// C[0][0] = (2 * 2) + (1 * 1) + (0 * 3) + (3 * 0)
// C[0][0] = 5
//
// C = [5   8   8 ]   C is a 3x3 matrix
//     [11  12  12]
//     [14  11  11]
//
// A - MxN matrix
// B - NxP matrix
//
// AB will be an MxP matrix
//
