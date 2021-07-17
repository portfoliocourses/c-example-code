/*******************************************************************************
*
* Program: Variable scope
* 
* Description: Examples of variable scope in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=qwM_c3gF2lw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

void func(int a);

// global variables aka "file scope", these variables have the scope of the file
int y = 3;
int x = 2;

int main(void)
{
  // x is a local variable, aka "function scope", it has the scope of the main 
  // function
  int x = 5;

  // the local variable x will take precedence over the global variable x and 
  // we will print x: 5 and not x: 2 
  printf("x: %d\n", x);

  // we can access global variable y inside the main function, to use it or 
  // modify it too
  printf("y: %d\n", y);
  y++;

  func(10);

  // x will have "block scope", the scope in-between the curly braces below
  {
    int z = 2;
    printf("z: %d\n", z);
  }
  
  // we see block scope used for for-loop counter variables like i very often
  for (int i = 0; i < 10; i++)
  {
    printf("i: %d\n", i);
  }

  // we cannot access i outside of the above block
  // printf("i: %d\n", i);

  return 0;
}

void func(int a)
{
  // functions besides main can have their own local variables
  int x = 8;
 
  // functions besides main can access global variables
  y++;

  // again because we have a local variable x it takes precedence over the 
  // global variable x and we print out x: 8 instead of x: 2
  printf("x: %d\n", x);

  // we can access the global variable y in our functions as well
  printf("y: %d\n", y);

  // a function parameter a is effectively a local variable!
  a++;
  printf("a: %d\n", a);
}


