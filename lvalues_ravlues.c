/*******************************************************************************
*
* Program: lvalues and rvalue errors
* 
* Description: Examples of lvalue and rvalue related errors in C.  
*
* YouTube Lesson: https://www.youtube.com/watch?v=Ha-v53xIYXc
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// The terms lvalue and rvalue will come up in compiler error messages in C.
//
// lvalues are also known as locator values, and they have an identifiable 
// memory address.  e.g. a double variable
//
// rvalues are values that are not lvalues and have no identifiable memory 
// address, so we can't assign to them.  e.g. a double literal
//
// Knowing what lvalues and ravlues are can help us to better understand 
// compiler error messages, which helps us to debug!
//
int main()
{
  // x is an lvalue, it has an identifiable memory address, where as 
  // 20 is not an lvalue but is instead an rvalue (it is a literal value
  // with no identifiable memory address)
  int x = 20;
  
  // we can't assign to 20, and compilers may give us an error making note
  // of the fact that the left-side of the assignment operator is not an lvaue
  20 = x;

  // Just because something is an lvalue doesn't mean we can assign to it... y
  // is an lvalue because it has an indentifiable memory address, but we can't
  // assign to y because it is const... we would say that y is not a modifiable
  // lvalue.  Originally the terms lvalue and rvalue came out of the fact that 
  // lvalues were on the left side of an assignment... we now use the term 
  // locator values to describe lvalues.
  const y = 20;
  y = 10;
  
  // we can't assign to the memory address of x because that's ultimately just
  // a value (the pointer / memory address)
  &x = 5;
  
  // while we could say ptr = &(x) when we add 4 to x we treat x like an int
  // and we can't get the memory address of 24 i.e. &(20 + 4), this will give 
  // us an error referencing "rvalues" on some compilers
  int *ptr1 = &(x + 4);
  
  // here is a common situation where a compiler may give a difficult to 
  // understand lvalue error message... we mean to do a comparison but 
  // forget the second = and accidentally attempt to do an assignment, which 
  // causes an lvalue error becuase we can't assign to the result of a modulus 2
  int a = 20;
  if (a % 2 = 0)
    printf("a is even\n");

  // we actually CAN apply the & operator to string literals (but not any other
  // type of literal) because string literals are stored as arrays at a memory
  // addres and therefore have an identifiable memory address
  void *newptr = &"abc";

  return 0;
}
