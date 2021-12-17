/*******************************************************************************
*
* Program: Fill A 2D Array With Random Values
* 
* Description: Example of filling a 2D array with random values between 1 and 
* a max value in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=6xRSNSja1mE   
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 4

void fill_random(int array[ROWS][COLS], int max);

int main(void)
{
  // seed the random number generator with a different value (the current time)
  // each time the program runs to ensure we get different random numbers each
  // time the program runs  
  srand( time(NULL) );
  
  // create a 2D array with ROWS x COLS dimensions
  int A[ROWS][COLS];
  
  // fill the 2D array A with random integers between 1-10
  fill_random(A, 10);
  
  // print out the 2D array
  for (int i = 0; i < ROWS; i++)
  {
    // prints out all the values in a row of the 2D array followed by a newline
    // so that the next row outputs on the next line
    for (int j = 0; j < COLS; j++)
    {
      printf("%3d ", A[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}

// fills the array with random values between 1 - max
void fill_random(int array[ROWS][COLS], int max)
{
  // loops will increment over each column index FOR each row index, giving 
  // us access to all array elements with array[i][j]
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      // assign a random number to each elements of the 2D arraay, where 
      // rand() % max will produce a random number between 0 - (max-1), 
      // and adding 1 will shift it to 1 - max
      array[i][j] = (rand() % max) + 1;
    }
  }
}
