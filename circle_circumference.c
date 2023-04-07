/*******************************************************************************
*
* Program: Calculate Circle Circumference With User Input
* 
* Description: Program to calculate the circumference of a circle with a user
* input value for the radius in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=rHdBxp4oseA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// Define a preprocessor constant for PI
#define PI 3.14159265359

double calculate_circumference(double radius);

int main(void)
{
  // Variable to store the radius entered by the user.  We use type double for
  // variables as circles can have radius and circumferences with decimal 
  // places.
  double radius;
  
  // Variable to store calculated circumference
  double circumference;
  
  // Prompt the user to enter the circle radius
  printf("Enter Radius: ");
  
  // Store the value entered by the user into the radius variable
  scanf("%lf", &radius);
  
  // We could calculate the circumference directly and assign the result to 
  // the variable circumference
  // circumference = 2 * PI * radius;

  // Or we could call the the calculate_circumference() function we have 
  // defined with the entered radius as an argument, and assign the return 
  // value to the circumference variable.
  circumference = calculate_circumference(radius);
     
  // Output the circumference, the .2 will ensure it is output with 2 decimal
  // places of accuracy.
  printf("Circumference: %.2f\n", circumference);
  
  return 0;
}

// Returns the circumference of a circle with the radius provided as an 
// argument.  The advantage of using a function to calculate the circle 
// circumference is that we do not have to reproduce the formula in different
// places in our code to calculate the circumference, we can instead call the
// function where the formula is defined once.
double calculate_circumference(double radius)
{
  return 2 * PI * radius;
}