/*******************************************************************************
*
* Program: Print A Specific Row In A 2D Array
*
* Description: Program to output a specific row in a 2D array using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=fQI9phlnVb8 
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
  { {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
  };
   
  // We'll store the row to print into row_to_print
  int row_to_print = 0;
  
  // Prompt the user for the row to print, we'll start counting rows at "1" even
  // though C array indexes start at 0.
  printf("Enter Row To Print (1,2,3,...): ");
  scanf("%d", &row_to_print);
  
  // Subtract 1 from the row the user entered to account for the fact that 
  // indexes in C begin at 0.  If we have the user enter in a row starting at 
  // 0,1,2,... instead of 1,2,3,... then we can skip this step.
  row_to_print -= 1;
  
  // Check to make sure the supplied row is in range, if it is not exit the 
  // program with an error message and status (exiting the program with return 1
  // instead of return 0 indicates something has gone wrong).
  if (row_to_print < 0 || row_to_print >= ROWS)
  {
    printf("Row out of range.\n");
    return 1;
  }

  // We loop through each column with the counter variable i going from 0 by 1 
  // up until the number of columns, outputting the value at each column in the 
  // row "row_to_print". 
  for (int i = 0; i < COLS; i++)
  {
    printf("%d ", data[row_to_print][i]);
  }

  // Output a couple newlines after outputting the row (just for some space!)
  printf("\n\n");

  return 0;
}