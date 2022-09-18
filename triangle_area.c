/*******************************************************************************
*
* Program: Area Of A Triangle
*
* Description: Example of how to calculating the area of a triangle in C using
* user input values for the triangle base and height.
*
* YouTube Lesson: https://www.youtube.com/watch?v=0JMObBs9xWQ
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
  // Declare variables to store the base, height, and area of the triangle,
  // type double is used so numbers with decimal places such as 2.5 can be
  // stored into the variables.
  double base, height, area;

  // Prompt the user to enter the triangle base... by passing the string
  // "Base: " to printf() the text "Base: " will be printed to the terminal
  // (technically, what we call standard output).
  printf("Base: ");

  // Store the value the user enters into the variable base using scanf.  The
  // %lf placeholder will have scanf read a double vale from user input, and
  // &base will pass the memory address of the variable base (i.e. a pointer to
  // base) to scanf so it can store the value in this variable.
  scanf("%lf", &base);

  // The same as above, but now the user is prompted for the triangle height
  // and what they enter is stored into the height variable.
  printf("Height: ");
  scanf("%lf", &height);

  // Calculate the triangle area, 1/2 * base * height.  The * operator will
  // perform multiplication, and the = assigment operator will assign the
  // resulting value to the area variable.
  area = 0.5 * base * height;

  // Output the triangle area, by outputting the text "Area: " followed by
  // the comptued area.  The %.2f placeholder will have printf() output a
  // double value after the text "Area: ", and the double value will be output
  // with 2 decimal digits of precession due to the .2 precession field.  The
  // double value to be output, area, is supplied as the 2nd argument to the
  // call to printf().
  printf("Area: %.2f\n", area);

  return 0;
}