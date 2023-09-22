/*******************************************************************************
*
* Program: Find The Factors Of A Positive Integer
*
* Description: Program to find and display the factors of a positive integer 
* using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=mCfACbalIvc
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(void)
{
  // Stores the positive integer
  int number = 0;
  
  // Prompt the user to enter a positive integer, store the integer entered 
  // into the variable number
  printf("Enter Positive Integer: ");
  scanf("%d", &number);
  
  // If the number is not a positive integer, output an error message
  if (number <= 0)
  {
    printf("Number must be a positive integer.\n");
  }
  // Otherwise find the factors of the positive integer
  else
  {
    // The possible factors of the positive integer number are integers 
    // between 1...number, including 1 and number.  A number is a 
    // factor if it evenly divides the positive integer, i.e. if the 
    // positive integer divided by the number has a remainder of 0.  
    // 
    // So we use a loop with a counter variable i that goes from 1 
    // to the positive integer number by 1 with each loop iteration,
    // allowing us to check all possible factors.  We use the modulus
    // operator % which returns the remainder of a division operation 
    // to find the remainder of the positive integer number divided 
    // by the possible factor i.  And if that remainder is equal to 
    // 0, as checked with ==, then we know it's a factor and output
    // the the factor i.
    //
    for (int i = 1; i <= number; i++)
    {
      if (number % i == 0)
      {
        printf("%d ", i);
      }
    }

    // Output a newline after outputting the factors so any further 
    // output from the program appears on the next line of the
    // terminal.
    printf("\n");
  }
  
  return 0;
}
