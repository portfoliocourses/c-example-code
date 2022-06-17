/*******************************************************************************
*
* Program: Constant Pointer VS. Pointer To A Const
*
* Description: The difference between a constant pointer and a pointer to a
* constant in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=egvGq3WSF9Y
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main()
{
  // Declare two char variables so we have something to point our pointers to
  char a = 'a';
  char b = 'b';

  // Declares a constant pointer called 'constant_pointer' and sets it to
  // point to the variable a, i.e. we assign it a's memory adddress.  We
  // CAN change the value of what a constant pointer is pointing to, we CAN'T
  // change what the constant pointer is pointing to (i.e. the memory address
  // that it stores).
  char *const constant_pointer = &a;

  // De-reference the constant pointer to access what it is pointing to with
  // the de-reference operator '*'.  In this case, we CAN assign the value 'x'
  // to a, changing the value of what the pointer is pointing to.
  *constant_pointer = 'x';

  // We CAN'T change what a constant pointer is pointing to, this will cause
  // a compilation error.
  // constant_pointer = &b;

  // If we output the variable a we'll find it has been changed to the value 'x'
  printf("a: %c\n", a);

  // Either of the below statements will declare a pointer to a constant
  // called 'pointer_to_const' and set it to point to the variable a.
  //
  // char const *pointer_to_const = &a;
  const char *pointer_to_const = &a;

  // We'll get 'x' if we output the de-referenced pointer as it points to
  // the variable 'a' which now stores the char 'x'
  printf("*pointer_to_const: %c\n", *pointer_to_const);

  // We CAN change what a pointer to a const is pointing to, in this case
  // we have the pointer point to the variable 'b'.
  pointer_to_const = &b;

  // If we output the de-referenced pointer we'll now find we output 'b'
  // as the pointer now points to the variable 'b' which stores the char 'b'.
  printf("*pointer_to_const: %c\n", *pointer_to_const);

  // We CAN'T change the value of what a pointer to a constant is pointing to,
  // in this case if we try to de-reference the pointer to set the variable
  // 'b' to the value 'z' we will get a compilation error.
  // *pointer_to_const = 'z';

  // We can also create a constant pointer to a constant, using either of
  // the below syntaxes.  In this case we cannot change what the pointer is
  // pointing to OR the value of what the pointer is pointing to!
  //
  // const char *const constant_pointer_to_constant = &a;
  char const *const constant_pointer_to_constant = &a;

  // Attempting to change the value of what the pointer is pointing to will
  // cause a compilation error.
  // *constant_pointer_to_constant = 'z';

  // Attempting to change what the pointer is pointing to will casue a
  // compilation error.
  // constant_pointer_to_constant = &b;

  return 0;
}


//  A summary of the different types of pointers we can create and what
// is mutable/immutable (i.e. changable vs. unchangable).
//
//
//                         Pointer      Value
//
//  Non-Const Pointer      Mutable      Mutable
//  To Non-Const
//
//  Non-Const Pointer      Mutable      Immutable
//  To Const
//
//  Const Pointer          Immutable    Mutable
//  To Non-Const
//
//  Const Pointer          Immutable    Immutable
//  To Const
