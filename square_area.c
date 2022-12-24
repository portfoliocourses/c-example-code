/*******************************************************************************
*
* Program: Area Of A Square
* 
* Description: Example of calculating the area of a square using a user input 
* value for the square side length with C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=EMTrjulX2dU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// declare a function to calculate the area of a square
double square_area(double side);

int main()
{
  // Declare variables for storing the side length and area of the square, type
  // double is used so the variables can store numbers with decimal places.  
  double side = 0;
  double area = 0;
  
  // Prompt the user to enter the square side length
  printf("Side Length: ");

  // Store the side length entered into the side variable.  The "%lf" argument 
  // tells scanf to read a double value from user input, and &side will 
  // pass scanf the memory address of the side variable so that it is able
  // to store the value entered into the side variable.  
  scanf("%lf", &side);
  
  // Calculate the square area and store it into area.  The * operator will 
  // perform a multiplication operation with side and itself and the assignment
  // operator = will store the value into area.
  //
  // area = side * side;

  // We could also call the square_area function declared above and defined 
  // below to calculate the square area.  We provide it with the user input 
  // side length length as an argument and the function will return the square 
  // area which we then store into the area variable. 
  area = square_area(side); 
  
  // Output the square area.  %.2f will tell printf() to expect a double 
  // value to be provided, and to output that value in that place in the string
  // with 2 decimal digits of precision.  We pass area as a 2nd argument to 
  // printf() to supply that double value.
  printf("Area: %.2f\n", area);
  
  return 0;
}

// Function that accepts the area side length as an argument and returns the 
// area of a square.
double square_area(double side)
{
  return side * side;
}
