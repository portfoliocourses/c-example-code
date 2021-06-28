/*******************************************************************************
*
* Program: Introduction to Pointers
* 
* Description: Examples of using pointers in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=2GDiXG5RfNE  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(void)
{
  // declare an int variable b, and a pointer to an int a, set a to store 
  // the memory address of b using the & operator which returns the 
  // memory address of a variable
  int b = 42;
  int *a = &b;

  // print out the value of b, the memory address of b, and the value of a 
  // (which IS the memory address of b)
  printf("b: %d\n", b);
  printf("&b: %p\n", &b);
  printf("a: %p\n", a);
  
  // dereference the pointer a to modify what a is pointing to (b) via this 
  // assignment statement
  *a = 50;

  // when we print the value of b, notice it is now 50!
  printf("b: %d\n", b);
  printf("&b: %p\n", &b);
  printf("a: %p\n", a);

  // Pointers are used to achieve pass-by-reference (more specifcally called 
  // pass-by-pointer in C), where we can have a function modify the values of 
  // multiple variables in the calling environment by passing the function 
  // the memory address of these variables.  This is how scanf works!

  int m, n, p;
  m = n = p = 0;

  // ask the user for 3 numbers, pass the memory address of m, n and p to scanf
  // and then scanf uses these pointers/addresses to modify the values of m,n,p
  printf("Enter 3 numbers: ");
  scanf("%d %d %d", &m, &n, &p);
  printf("Result: %d\n", m + n + p);

  // let's use pass-by-reference to swap the values of x and y
  int x, y;
  x = 5;
  y = 10;

  // print out x,y and the memory addresses of each before calling swap
  printf("x: %d, y: %d\n", x, y);
  printf("&x: %p\n&y: %p\n", &x, &y);

  // pass swap the memory address of x and memory address of y
  swap(&x, &y);

  // print out the values of x and y afterwards and notice the values have been
  // swapped!
  printf("x: %d, y: %d\n", x, y);


  // pointers are also used to refer to dynamically allocated memory, which 
  // is memory that has been requested at runtime to store data, such as an 
  // array of ints.  In the example below we use malloc to dynamically allocate 
  // space, malloc returns a memory address that we store with the pointer d.
  int *d;
  int length = 0;
  printf("Enter a length: ");
  scanf("%d", &length);

  // malloc requires as an argument the number of bytes to allocate, because we 
  // want to store an array of ints of a given length, we multiply length by 
  // the sizeof space required to store an int.  malloc returns a memory address
  // to this allocated space in memory that we store with d.
  d = malloc(length * sizeof(int));

  // output the memory address that d contains
  printf("d: %p\n", d);

  // store values in this new memory, we can use array index syntax to do this!
  for (int i = 0; i < length; i++) 
    d[i] = i;
  
  // print out these values, again using array index syntax
  for (int i = 0; i < length; i++) 
    printf("d[%d]=%d\n", i, d[i]);

  // free the memory allocated (required so that it can be used again)
  free(d);

  return 0;
}

// swaps the values contained at the memory addresses stored in a and b, an 
// example of pass-by-reference
void swap(int *a, int *b)
{
  // notice that a and b store MEMORY ADDRESSES because they are pointers, 
  // we dereference the pointer with the * operator to get access to what 
  // they are pointing to (in this case, x and y in the main function)
  printf("a: %p\nb: %p\n", a, b);
  printf("*a: %d\n*b: %d\n", *a, *b);

  // swap the values using a temp variable, we use the * pointer dereference 
  // operator again to get access to the values in memory pointed to by a,b
  int temp = 0;
  temp = *a;
  *a = *b;
  *b = temp;
}
