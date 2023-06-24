/*******************************************************************************
*
* Program: Print A Specific Column In A 2D Array
*
* Description: Program to output a specific column in a 2D array using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=iZLtYIbRRuE 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// Preprocessor constants to define the number of 2D array rows and columns
#define ROWS 4
#define COLS 4

int main(void)
{
  // Declare and initialize a 2D array with this number of ROWS and COLS
  int data[ROWS][COLS] =
  { {1,   2,   3,   4},
    {5,   6,   7,   8},
    {9,  10,  11,  12},
    {13, 14,  15,  16}
  };
    
  // We'll store the column to print into col_to_print
  int col_to_print;
  
  // Prompt the user for the column to print, we'll start counting columns at 
  // "1" even though C array indexes start at 0.  
  printf("Enter Column To Print (1,2,3,...): ");
  scanf("%d", &col_to_print);
  
  // Subtract 1 from the column the user entered to account for the fact that 
  // indexes in C begin at 0.  If we have the user enter in a column starting at
  // 0,1,2,... instead of 1,2,3,... then we can skip this step.  
  col_to_print -= 1;
  
  // Check to make sure the supplied column is in range, if it is not exit the 
  // program with an error message and status (exiting the program with return 1
  // instead of return 0 indicates something has gone wrong).  
  if (col_to_print < 0 || col_to_print >= COLS)
  {
    printf("Column out of range.\n");
    return 1;
  }
  
  // We loop through each row with the counter variable i going from 0 by 1 
  // up until the number of row, outputting the value at each row in the 
  // column "co_to_print".   
  for (int i = 0; i < ROWS; i++)
  {
    printf("%d ", data[i][col_to_print]);
  }

  // Output a couple newlines after outputting the column (just for some space!)
  printf("\n\n");

  return 0;
}