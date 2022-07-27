/*******************************************************************************
*
* Program: function pointer vs. &function pointer
* 
* Description: In C there is no difference between function and &function in 
* that both will give us a pointer to the function, we demonstrate this in the
* code below.
*
* YouTube Lesson: https://www.youtube.com/watch?v=-41q4ugE8hE  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// A simple function with a void return type and no parameters
void function()
{
  printf("Function!\n");
}

int main()
{
  // Assign to the pointer to a function variable fnc_ptr1 a pointer to 
  // 'function' above, without using the & operator
  void (*fnc_ptr1)() = function;
  
  // We can call the function using the pointer to the function successfully
  (*fnc_ptr1)();
  fnc_ptr1();

  // Assign to the pointer to a function variable fnc_ptr2 a pointer to 
  // 'function' above, this time using the & operator
  void (*fnc_ptr2)() = &function;
  
  // We can again call the function using the pointer to the function 
  (*fnc_ptr2)();
  fnc_ptr2();
  
  // Both fnc_ptr1 and fnc_ptr2 will store the exact same memory address as
  // function and &function both give us the same pointer to the function!
  printf("%p\n", fnc_ptr1);
  printf("%p\n", fnc_ptr2);

  return 0;
}