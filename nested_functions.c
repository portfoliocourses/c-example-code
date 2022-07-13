/*******************************************************************************
*
* Program: Nested Functions Demonstration
*
* Description: Examples of using nested functions in C.  Note that nested
* functions are not part of ANSI C (i.e. Standard C) but are supported as an
* extension by GNU C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=U_T8b9tf63s
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// the outer function is the "containing function"
void outer()
{
  // variable is a local variable of our containing function outer
  int variable = 5;

  // If we declare a nested function we can call it before we define it, but
  // in order to declare a nested function we must explicitly use the auto
  // storage class.  This is unusual as the auto storage class is the default
  // storage class when no other storage class (e.g. static, extern) is
  // provided, but in this case the auto keyword explicitly being present
  // is required.
  auto void nested();

  // call the nested function... we can call it before it is defined because
  // we declared it above...
  nested();

  // Define the nested function called nested
  void nested()
  {
    // A nested function can access a local variable of the containing
    // function so long as it is visible before the nested function is defined
    //
    // Accessing local variables of the containing function can save us from
    // having to pass them to the nested function, which saves space on the
    // stack as we have one less parameter...  this may be useful in
    // some embedded systems.
    printf("variable: %d\n", variable);
  }

  // Call the nested function
  nested();
}

// Making a function a nested function makes it explicitly local to its
// containing function, making it clear that the function is "owned" by
// its containing function.  In this case below we define a rectangle_area
// nested function that helps the max_rectangle_area function find the
// largest of two rectangle's areas.
int max_rectangle_area(int width1, int length1, int width2, int length2)
{
  // A nested function to find a rectangle area
  int rectangle_area(int width, int length)
  {
    return width * length;
  }

  // use the nested function to compute the two areas
  int area1 = rectangle_area(width1, length1);
  int area2 = rectangle_area(width2, length2);

  // return the larger of the two areas
  if (area1 > area2) return area1;
  else return area2;
}

int main()
{
  // call our outer() function which used its own nested() function
  outer();

  // call the max_rectangle_area() function which uses its own rectangle_area()
  // nested function
  printf("max area: %d\n", max_rectangle_area(4,5,9,8));

  return 0;
}