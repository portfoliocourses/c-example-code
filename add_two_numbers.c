/*******************************************************************************
*
* Program: Add Two Numbers From User Input
* 
* Description: A C program to add two numbers from user input.
*
* YouTube Lesson: https://www.youtube.com/watch?v=1F8F4Ma1btM 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main()
{
  // declare 3 variables, 2 store the numbers, and sum to store the sum
  double number1, number2, sum;

  // prompt the user to enter the first number  
  printf("Number 1: ");

  // store the double value entered into the number1 variable
  scanf("%lf", &number1);
  
  // prompt the user to enter the second number
  printf("Number 2: ");

  // store the double value entered into the number2 variable
  scanf("%lf", &number2);

  // sum the two numbers and store the result into sum 
  sum = number1 + number2;
  
  // output the result
  printf("Sum: %f\n", sum);
  
  return 0;
}