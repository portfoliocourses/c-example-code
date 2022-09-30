/*******************************************************************************
*
* Program: Perimeter Of A Rectangle
* 
* Description: Find the perimeter of a rectangle using C, where the rectangle 
* length and width values have been supplied via user input.
*
* YouTube Lesson: https://www.youtube.com/watch?v=50qJ3bNm_S0 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
  // Declare 3 variables for storing the rectangle length, width and perimeter 
  // values.  The variables have type double as double allows us to store 
  // numbers with decimal places such as 3.5.
  double length, width, perimeter;
   
  // Prompt the user to enter the rectangle length
  printf("Length: ");

  // Store the length entered into the length variable.  The "%lf" argument 
  // tells scanf to read a double value from user input, and &length will 
  // pass scanf the memory address of the length variable so that it is able
  // to store the value entered into the length variable.
  scanf("%lf", &length);
  
  // In the same way, prompt the user for the rectangle width and store it 
  // into the width variable
  printf("Width: ");
  scanf("%lf", &width);
  
  // Calculate the rectangle perimeter and store the result into the perimeter
  // variable.  The + operator will add together the length and width, and the
  // ( ) brackets will ensure the addition operation occurs first, before the 
  // result is multiplied by 2.  The = assignment operator will store the 
  // value into the perimeter variable.
  perimeter = 2 * (length + width);
  
  // Output the rectangle perimeter.  %.2f will tell printf() to expect a double
  // value to be provided, and to output that value in that place in the string
  // with 2 decimal digits of precision.  We pass perimeter as a 2nd argument to 
  // printf() to supply that double value.
  printf("Perimeter: %.2f\n", perimeter); 

  return 0;
}
