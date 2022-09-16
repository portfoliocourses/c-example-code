/*******************************************************************************
*
* Program: Area Of A Rectangle
* 
* Description: Example of calculating the area of a rectangle using user input 
* values for length and width with C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=6FaWbQAwpDY 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
  // Declare variables for storing the length, width and area of the rectangle,
  // type double is used so the variables can store numbers with decimal places.
  double length, width, area;
  
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
  
  // Calculate the rectangle area and store it into area.  The * operator will 
  // perform a multiplication operation with length and width and the assignment
  // operator = will store the value into area.
  area = length * width;
  
  // Output the rectangle area.  %.2f will tell printf() to expect a double 
  // value to be provided, and to output that value in that place in the string
  // with 2 decimal digits of precision.  We pass area as a 2nd argument to 
  // printf() to supply that double value.
  printf("Area: %.2f\n", area);
  
  return 0;
}