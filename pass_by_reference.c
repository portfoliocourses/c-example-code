/*******************************************************************************
*
* Program: Pass by reference tutorial
* 
* Description: An overview of pass by reference in C, also called call by 
* reference, and more accurately described as pass by pointer.
*
* YouTube Lesson: https://www.youtube.com/watch?v=RecxQUUEOn4
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// swap uses pass by value, swap2 uses pass by reference
void swap(int a, int b);
void swap2(int *a, int *b);

int main(void)
{
  int x = 5;
  int y = 10;
  
  // when we call swap with x and y, the VALUES of x and y are passed to the 
  // function as arguments
  swap(x, y);
  printf("x: %d\ny: %d\n", x, y);

  // when we call swap2 with &x and &y, the memory addresses, i.e. the pointers,
  // are passed to the function as arguments... this allows the function to 
  // effectively access the variables x and y in the calling environment (main)
  swap2(&x, &y);
  printf("x: %d\ny: %d\n", x, y);

  return 0;
}

// swapping a and b will not effect the values of x and y in the main function
// because swap only has access to the value of x and value of y via them being
// passed to the function as arguments (i.e. "pass by value")
void swap(int a, int b)
{
  // a classic swap algorithm using a temp variable to swap two variables
  int temp;
  temp = a;
  a = b;
  b = temp;
}

// swap2 is given a pointer to an int in the case of a and b... so this means 
// swap2 has a memory address a and a memory address b, and given how we've 
// called the function above, a will store the memory address of x, and b 
// will store the memory address of y.  We can then use * operator to 
// "dereference the pointer", which means "give us access to the memory address
// (i.e. variable) that a and b are pointing to".  In other words, we can use 
// * to manipulate and use the variables x and y in the main function because 
// those are what a and b are pointing to!
void swap2(int *a, int *b)
{
  // perform the swap with a temp variable, use * to manipulate what a and b
  // are pointing to (i.e. x and y)
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}