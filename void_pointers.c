/*******************************************************************************
*
* Program: Void Pointers
*
* Description: Examples of using void pointers in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=6BvbLygA6Og
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main()
{
  // Declare test int and double variables.
  int a = 5;
  double b = 3;

  // Declares a pointer variable x and assigns the memory address of 'a' to it,
  // the pointer is associated with the type int, so it's supposed to point to
  // int values like 'a'.  
  int *x = &a;

  // We can use *x to dereference x and get the value 'pointed to' by x, i.e.
  // the value at the memory address that x stores. 
  printf("%d\n", *x);
   
  // An advantage of having pointers with an associated type is that the
  // compiler can warn us if we're potentially making a mistake.  For example
  // if above we tried to assign the memory address of the double variable 'b'
  // to x the compiler will produce a warning, because x is supposed to point
  // to int values and 'b' is a double value.
  //
  // int *x = &b;

  
  // Here we declare a void pointer p, a 'generic pointer' that can store 
  // memory addresses of any type of value without a warning.
  void *p;

  // p can store the memory address of 'a' OR 'b' without a compiler warning! 
  p = &a;
  p = &b;

  // We cannot dereference void pointers.  When we dereference a pointer we 
  // get an 'object' of the type associated with the pointer, but with a void 
  // pointer the type 'void' is an incomplete type and we can't use it such 
  // as an argument to printf() below...
  // 
  // printf("%d\n", *p);

  
  
  //  Void pointers can be used to make data structures and functions which are
  //  "more generic" in terms of the types of data they can work with.
  //
  //  For example the malloc() function returns a void pointer to a block of 
  //  allocated memory, allowing us to use the function to allocate blocks of 
  //  memory for "anything", e.g. arrays of ints, or doubles or structs.
  //
  //  malloc() prototype: void *malloc(size_t size);
  //
  //  We can use malloc to declare space for an array of 10 ints...
  //
  //  int *a = malloc(sizeof(int) * 10);
  //
  //  Or we can use malloc to allocate space for a double...
  //
  //  double * a = malloc(sizeof(double));
  //
  //  And it's OK too!


  //  The qsort() function in the C standard library which performs quicksort 
  //  also uses void pointers to make the function "more generic" in terms of
  //  what types of data the function can work with.  The qsort() function 
  //  accepts a void pointer to an array of elements of "any type" as the first
  //  argument to the function.  The 4th argument to the function is a function
  //  pointer to a function that accepts two void pointers as arguments, this 
  //  function is used by qsort() to carry out the quicksort algorithm by 
  //  comparing elements.  The usage of void pointers allows this function 
  //  to work with "any type" of data, e.g. we can supply functions to compare
  //  ints or functions to compar some type of struct.
  //
  //  void qsort(void *base,
  //             size_t nitems,
  //             size_t size,
  //             int (*compar)(const void *, const void*))

  
  // Non-void pointers support what's called pointer arithmetic, where we can
  // manipulate what a pointer is pointing to using arithmetic operations.
  char string[] = "String";
  
  // The char pointer variable c will point to the 2nd character 't' in the
  // string
  char *c = &string[1];
  
  // We can dereference c to output 't'
  printf("%c\n", *c);
  
  // We can use pointer arithmetic to "increment" the pointer and have it point
  // to the next character (+ 1) in the string.  This is not adding the value 
  // 1 to the pointer, it is incrementing the pointer by one char-sized unit 
  // to point to the next char in memory.
  c = c + 1;
  
  // We can dereference c and now output 'r'
  printf("%c\n", *c);

  // We can set our void pointer to point to the 2nd character 't' in the 
  // string as well.  
  p = &string[1];
   
  // In the official C standard we are not allowed to use pointer arithmetic 
  // with void pointers, but GNU C and other C compilers allow it.  In GNU C 
  // the pointer will be incremented by one char-sized unit (i.e. a byte in 
  // practice), so p will point to 'r'
  p = p + 1;
   
  // We cannot directly dereference void pointers, but we could cost this void
  // point to a char pointer (knowing that it is pointing to a char), and then 
  // dereference THAT pointer to output the character 'r'. 
  printf("%c\n", *((char *) p));
 
  return 0;
}
