/*******************************************************************************
*
* Program: Find The Length Of An Array Using sizeof()
*
* Description: Example of using the abort() function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=ZCzXhRkiBu4
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// We can create a function-like preprocessor macro to help calculate the
// length of an array using the size of operator.  The preprocessor macro
// will do a text replacement during the preprocessor phase of the compilation
// of the program, so that if it is used with LENGTH(array) the text
// will be replaced with sizeof(array) / sizeof(array[0]).  The sizeof()
// operator will return the size in bytes of its operand.  Dividing the
// total size of the array in bytes by the size of the first element in bytes
// will result in the total length of the array.
#define LENGTH(a) sizeof(a) / sizeof(a[0])

// Instead of using sizeof() to help find the length of the array, we could
// use a preprocessor constant to keep track of the size of the array.  The
// preprocessor phase of compilation will replace any occurrences of 'SIZE'
// with '9'.
#define SIZE 9

// A function that attemps to print the length (aka size) of the array, but
// fails.  When an array is passed to a function in C what is actually
// passed to the function is a pointer to the array.  So when we use the
// sizeof() operator to find the sizeof(array) what we *actually* get is the
// size of the pointer, not the size of the array itself.  This will cause
// the length calculation in the below function to 'fail' in that we will
// not get the array length as desired.
void print_size(int array[])
{
  int length = sizeof(array) / sizeof(array[0]);

  // Note that even though when an array is passed to a function what is really
  // passed is a pointer to the array, we can still use array notation to access
  // the array elements.
  array[0] = 5;

  printf("LENGTH: %d\n", length);
}

int main(int argc, char *argv[])
{
  // Instead of using sizeof() to help find the length of an array, we could
  // instead declare a const variable and set it to the length of the array
  // in order to keep track of the array size.  The const keyword will make
  // it so that variable cannot be modified after it is first initialized,
  // which would make sense given that an array will not change size (at least,
  // an array on the stack).  Unlike a preprocessor constant, a const variable
  // will be local to the function in which it is declared, and it will take
  // up space in memory as any other variable will.
  const int size = 9;

  // Declare an array of length 9 and initialize it with int values
  int array[] = {1,2,3,4,5,6,7,8,9};

  // We can use a function-like macro to calcualte the length of the array
  int length = LENGTH(array);

  // We could also use sizeof() directly wherever we want to get the length
  // of an array, for example:
  //
  // int length = sizeof(array) / sizeof(array[0]);

  // We could also divide the size of the array by the size of an int value,
  // and we would get the same result as above.  The issue is if we were to
  // change our array to have type double, the calculation would no longer
  // result in the correct length, because a double takes more bytes to
  // store than an int.  If we instead divide the size of the array by the
  // size of the first element in the array, the calculation will automatically
  // adjust as the size of the first element in the array will be the same
  // size as the type of the array (double, int, etc.).
  //
  // int length = sizeof(array) / sizeof(int);


  // We could use the function-like macro multiple times, and with different
  // array names, and it will work.  Notably, the after the text LENGTH(array)
  // is replaced with sizeof(array) / sizeof(array[0]), the calculation of
  // the array length will occur at COMPILE-TIME.  It may be concerning that
  // if we use LENGTH(array) all over our source code it will result in many
  // calculations occurring at run-time, as our program is executing, resulting
  // in a performance cost for this work to be done.  But the compiler knows
  // all that is needed to perform the sizeof(array) / sizeof(array[0])
  // calculation at compile-time, and it will perform the calculation then.  So
  // when our program actually runs as an executable LENGTH(array) will actually
  // be replaced with 9 already.
  //
  // Here we use the function-like macro to get the length of the array in
  // order to help us print out the array elements, using a loop with a counter
  // variable and condition that will stop the loop when the counter variable
  // reaches the array length.
  //
  for (int i = 0; i < LENGTH(array); i++)
    printf("array[%d] = %d\n", i, array[i]);

  // Output the computed array length
  printf("length: %d\n", length);

  // Output the size in bytes of the array, an int, a double, and the first
  // element of the array, to help understand how the sizeof operator and
  // array length calculation work.
  printf("sizeof(array): %d\n", sizeof(array));
  printf("sizeof(int): %d\n", sizeof(int));
  printf("sizeof(double): %d\n", sizeof(double));
  printf("sizeof(array[0]): %d\n", sizeof(array[0]));

  // Dynamically allocate an array of 100 ints using malloc(), dynamic_array
  // will be a pointer to this block of memory on the heap.
  int *dynamic_array = malloc(sizeof(int) * 100);

  // sizeof(dynamic_array) will NOT give us the size of the block of memory
  // on the heap, it will actually give us the size of the pointer, i.e. the
  // size of a pointer to an int.
  printf("sizeof(dynamic_array): %d\n", sizeof(dynamic_array));

  // So if we try to use the LENGTH function-like macro to get the size of
  // this dynamically allocated array, it's not going to work, because it
  // will try to use sizeof(dynamically_array) to get the size in bytes of the
  // array (and this will not work, instead it will result in the size in
  // bytes of the pointer).
  int dynamic_length = LENGTH(dynamic_array);

  // Output the incorrect dynamic_length value
  printf("dynamic_length: %d\n", dynamic_length);

  // Free the dynamically allocated array to prevent a memory leak
  free(dynamic_array);

  // If we call print_size and pass it array, what will actually be passed
  // to the array is a pointer to the array, i.e. the memory address of
  // the first element in the array.
  print_size(array);

  return 0;
}