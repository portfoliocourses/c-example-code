/*******************************************************************************
*
* Program: Convert Inches To Feet And Inches
*
* Description: Program to convert a height (or distance) expressed as a total 
* number of inches to an equivalent number of feet and inches using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=f9_RYPjvhr0
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(void)
{
  // If we have a height (or distance) like 66 inches we could express it as 
  // the equivalent number of feet and inches, e.g. 5 feet 6 inches.
  //
  // We can perform this conversion by dividing the total number of inches by
  // 12, e.g. 66 / 12 = 5 feet 6 inches.  Where the quotient if the number of
  // feet and the remainder is the number of inches.
  //
  // When working with int values in C, the division operation \ will give us
  // the quotient and modulus operator % will give us the remainder, e.g.
  //
  // 66 / 12 = 5
  // 6 % 12 = 6 
  //

  // Create variables to store the total inches and equivalent number of 
  // feet and inches
  int total_inches = 0;
  int inches = 0;
  int feet = 0;
   
  // Prompt the user to enter the total number of inches and store the result
  // into the total_inches variable
  printf("Enter Total Inches: ");
  scanf("%d", &total_inches);
  
  // Program will consider negative numbers to be invalid input so we only 
  // perform the conversion if the total inches is >= 0
  if (total_inches >= 0)
  {
    // Perform the conversion as described above
    feet = total_inches / 12;
    inches = total_inches % 12;
    
    // Output the result of the conversion
    printf("%d feet %d inches\n", feet, inches);
  }
  // If the total number of inches is not >= 0 output an error message
  else
  {
    printf("Must enter total inches >= 0");
  }

  return 0;
}