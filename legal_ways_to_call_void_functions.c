/*******************************************************************************
*
* Program: Legal Ways To Call Void Functions
*
* Description: Examples of different ways void functions can be called using C,
* even though these techniques are either not useful or generally considered 
* bad practice!  :-)
*
* YouTube Lesson: https://www.youtube.com/watch?v=fmD636e4ZsI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// A global variable 
int number;

// A void function which sets the global variable number to 0. Void functions
// by definition do not return a value.
void setup()
{
  number = 0;
}

// Increments global variable number by 1
void increment()
{
  number++;
}

// Outputs a simple string: Output 1
void function1()
{
  printf("Output 1\n");
}

// Outputs a simple string: Output 2
void function2a()
{
  printf("Output 2\n");
}

// Void functions can actually contain return statements that will stop the 
// execution of the function.  So this function here will stop execution 
// before the printf() call is executed.  Notably we can actually call a
// void function in the return statement of a void function!
void function2b()
{
  return function1();
  printf("Output 2\n");
}

int main(void)
{
  // Typically we would call a void function like this as just a statement on
  // its own as there is no return value to do anything with, but there are 
  // other legal ways of calling void functions.
  function1();
  
  // We can wrap the function call in brackets, which practically does nothing
  (function1());
   
  // We can typecase the result of the function call to void, which again 
  // practically will do nothing
  (void) function1();
  
  // We can call void functions in a ternary operator, though because the 
  // void function calls do not produce a value we can't use the result of 
  // the ternary operator in a larger expression as we might if the expressions
  // did return values.
  1 == 2 ? function1() : function2a();

  // A return statement inside a void function can call a void function as 
  // is done by function2b()
  function2b();
  
  // We can call void functions using the comma operator, where each expression
  // is evaluated from left to right and the result of the entire expression is
  // the result of the rightmost expression.  In this case setup() will set 
  // the global variable number to 0, increment() will increment it twice by 
  // 1 to 2, and the result of the expression is number (which is 2) which is
  // then assigned to value.
  int value = (setup(), increment(), increment(), number);
  
  // Output the resulting value
  printf("value: %d\n", value);

  // We can also call void functions in the "update statement" and "update 
  // statement" of a for loop as we do below, having the global variable 
  // go from 0 to 4 by 1 with each loop iteration as a result.
  for (setup(); number < 5; increment())
  {
    printf("number: %d\n", number);
  }
  
  return 0;
}