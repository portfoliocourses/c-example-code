/*******************************************************************************
*
* Program: Parameters vs. Arguments
*
* Description: An explanation of the difference between function parameters and
* function arguments in C, as the terms are often used informally and 
* interchangeably in practice though there is a difference.
*
* YouTube Lesson: https://www.youtube.com/watch?v=_ztGoCKDLHs
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// 'a' and 'b' are the *parameters* of the function, they are effectively 
// special local variables of the function that will be assigned the arguments 
// provided when the function is called before the function body executes
int sum(int a, int b)
{
  return a + b;
}

int main()
{
  // '10' and '5' are the function *arguments*, the parameter 'a' will be 
  // assigned the value '10' and the parameter 'b' will be assigned the value 
  // '5' before the sum function body executes
  sum(10,5);
  
  // Declare two variables x and y and assign them the values of 2 and 4 
  // respectively
  int x = 2;
  int y = 4;
  
  // We sometimes say that we are "passing a variable" to a function, e.g. that 
  // we are "passing y to the sum function".  This language is not incorrect, 
  // but it's important to remember what's really happening is that the VALUE 
  // of the variable y will be passed to the function.  So in the below example
  // the 2nd argument to the function will really be the value '4' that y is 
  // currently set to.  What's really happening is that the expression 'y' 
  // is evaluating to '4'.  In the case of the first argument, the expression 
  // 'x+2' will evaluate to '4' as x=2 and 2+2=4, and the value '4' will be 
  // passed to the sum function!
  sum(x+2,y);
    
  return 0;
}