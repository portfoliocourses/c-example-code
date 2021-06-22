/*******************************************************************************
*
* Program: Function basics tutorial
* 
* Description: Examples illustrating the basics of using functions in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=NGQoKF2Ggt8
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// function declarations that tell the compiler these functions will be defined
int add(int a, int b);
int mult(int x, int y);
void print_int(int a);

int main(void)
{
  // using printf is a type of function call!
  printf("Hello, World!\n");
  printf("Another printf statements!\n");

  /// we call the add function with arguments 4 and 5, it returns an int value
  // that we initialize output to... it's as if the return value of add(4, 5)
  // (in this case 9) takes the place of add(4, 5)
  int output = add(4, 5);
  printf("Output: %d\n", output);

  // we call the mult function with arguments 9 and 7, it returns an int value
  int multoutput = mult(9,7);
  printf("Mult output: %d\n", multoutput);

  // we can call a function with no return value (a void function)
  print_int(5);

  return 0;
}

// the add function accepts two int parameters a and b, adds them together, and 
// returns the resulting int 
int add(int a, int b)
{
  int result = a + b;
  return result;
}

// the mult function accepts two int parameters x and y, and uses the add 
// function defined above repeatedly to perform multiplication.
int mult(int x, int y)
{
  int result = 0;
  for (int i = 0; i < x; i++)
    result = add(result, y);
  return result;
}

// An example of a void function which has no return value!
void print_int(int a)
{
  printf("INT: %d\n", a);
}





