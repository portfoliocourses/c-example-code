/*******************************************************************************
*
* Program: Simple Calculator Using Switch Statement
*
* Description: Example of creating a simple calculator program in C using a 
* switch statement.
*
* YouTube Lesson: https://www.youtube.com/watch?v=8-NGTIExdKQ 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(void)
{
  // Stores the operation to perform as a single character.
  char operator;

  // Stores the operands (i.e. the numbers involved in the operation), type 
  // double is used so the calculator can handle numbers with decimal places.
  double operand1, operand2;
  
  // Prompt the user to enter the operator for either addition, subtraction, 
  // multiplication or division and store the entered operator into the 
  // operator variable.
  printf("Enter operator (+, -, *, /): ");
  scanf("%c", &operator);
  
  // Prompt the user to enter the two operands and store the values into the 
  // operand variables.
  printf("Enter two operands (numbers): ");
  scanf("%lf %lf", &operand1, &operand2);
  
  // Perform the operation that the user has entered
  switch (operator)
  {
    // Addition
    case '+':
      // We output the operands and the result of the addition.
      printf("%f + %f = %f\n", operand1, operand2, operand1 + operand2);
      break;
      
    // Subtraction
    case '-':
      printf("%f - %f = %f\n", operand1, operand2, operand1 - operand2);
      break;
      
    // Multiplication
    case '*':
      printf("%f * %f = %f\n", operand1, operand2, operand1 * operand2);
      break;
      
    // Division
    case '/':
      printf("%f / %f = %f\n", operand1, operand2, operand1 / operand2);
      break;
      
    // The default case will execute if the char stored in operator does not 
    // match one of the above.  Note that we use a break after the end of each
    // case above to prevent execution of statements in the switch from 
    // continuing ("fall through").  But with default we don't really need 
    // a break statement because there are no statements left in the switch.
    default:
      printf("Invalid operator entered.\n");
      
  }
  
  return 0;
}