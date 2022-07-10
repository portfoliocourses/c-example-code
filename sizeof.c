/*******************************************************************************
*
* Program: sizeof Operator Demonstration
* 
* Description: Program to demonstrate how the sizeof operator works in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=IWhrWzRI_K4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// We can use extern to access global variables in other files, but in this case
// because bad_array has no dimension we will not be able to use the sizeof 
// operator with it... a compiler error will result if we try.
extern int bad_array[];

// Newer versions of C may support variable length arrays.  Despite the fact 
// that some online sources may describe sizeof as a compile-time operator, in 
// the case of variable length arrays sizeof will operate at run-time to return 
// the length of the array.
//
// In the below function we declare a char array of variable length using the 
// length parameter.  We then output the size of the array using sizeof, and 
// it will work correctly as we supply different lengths as arguments to the 
// function at runtime in our main function below.
void make_array(int length)
{
  char myarray[length];
  printf("sizeof myarray: %zu\n", sizeof myarray);
}

int main()
{
  // sizeof() will return the size in bytes that it takes to store an int value.
  // Note that *technically* sizeof() returns the number of "char-sized units"
  // that it takes to store an int... see the discussion in the comments at the 
  // end of the file as to why we can effectively say that sizeof() "returns the
  // number of bytes" to store a type or expression.
  //
  // sizeof() returns a value of type size_t, so we use %zu to output the value. 
  // We could use %d and it would work, but because size_t has a larger range of
  // integer values than int, we should use %zu to "be safe" (we could get an 
  // integer overflow IF sizeof returns an integer larger than an int can 
  // store).  We should also use size_t type variables when storing the return 
  // value of sizeof instead of int for the same reason.  As a practical matter 
  // it would be very rare for sizeof to return a very large value outside the 
  // range of int, especially if we are just using it to get the size in bytes 
  // of types like int, double, etc, as part of calls to malloc().  As a result
  // much code online will simply use %d and int with sizeof() and it will work
  // fine and is unlikely to result in an error.
  //
  printf("sizeof(int): %zu\n", sizeof(int));
  
  // Where we often see sizeof used is to help dynamically allocate memory.  
  // We pass malloc() the size of the block in memory that we wish to allocate
  // in bytes.  To make our code more portable, if we wish to allocate space 
  // for an array of 10 ints, we can multiply 10 by the sizeof(int).  This way
  // wether the system/compiler uses 2 bytes for ints or 4 bytes for ints, the 
  // correct amount of memory will be allocated.
  //
  // int *array = malloc(10 * sizeof(int));
  
  // The sizeof(char) will *always* be '1' because sizeof(char) is actually 
  // the unit that sizeof returns its results in!
  printf("sizeof(char): %zu\n", sizeof(char));
  
  // sizeof(double) will typically be a larger integer than other common 
  // types, like for example 8
  printf("sizeof(double): %zu\n", sizeof(double));
  
  // We can also get the size in bytes of a variable
  double x = 5;
  printf("sizeof x: %zu\n", sizeof x);
  
  // We can also get the size in bytes of an array... 10 chars (1-9 + the null 
  // terminator) will be 10 byes.
  char string[] = "123456789";
  printf("sizeof string: %zu\n", sizeof string);
  
  // We can get the size in bytes of a double array too... a double will often
  // take up 8 bytes, so 10 doubles should be 10x8 = 80 bytes
  double array[] = {1,2,3,4,5,6,7,8,9,10};
  printf("sizeof(array): %zu\n", sizeof(array));
  
  // We can find the length of an array in terms of the number of elements by 
  // dividing the size of the array in bytes by the size of the first element
  // of the array.  Notice how we use size_t as the variable type given this 
  // is the type of value that sizeof returns.
  size_t array_length = sizeof(array) / sizeof(array[0]);
  
  // We could also divide the size of the array by the size of the array 
  // element type...
  // size_t array_length = sizeof(array) / sizeof(array[0]);
  
  // Output the length of the array
  printf("array_length: %zu\n", array_length);
  
  // We can use sizeof to get the size of literals, like the double literal 1.23
  printf("double literal: %zu\n", sizeof(1.23));
  
  // When we call make_array with 20 and 10, the array 'myarray' will be 
  // declared with different sizes, and yet sizeof will still return the correct
  // size in bytes of 'myarray'.  So contrary to what some online sources may 
  // state, sizeof is not strictly a compile-time operator and may sometimes do
  // work at runtime.
  make_array(20);
  make_array(10);
  
  // You may think that because the arguments above are literals that somehow 
  // the compiler is determining the size at compile-time.  This is not the 
  // case, as even if we have the user supply the length argument to 
  // make_array() at run-time, sizeof will return the correct size of the array.
  int size = 0;
  printf("Size: ");
  scanf("%d", &size);
  make_array(size);
  
  // If we uncomment the below code an error will result, as bad_array is 
  // an incomplete type because it has no dimension, and sizeof cannot find 
  // the size of an incomplete type.
  //
  // printf("sizeof bad_array: %zu\n", sizeof bad_array);
  
  return 0;
}

// sizeof() returns the storage size of a type or an
// expression in char-sized units
//
// i.e. sizeof(char) will always be 1
//
// Technically speaking the size of a char in bits is
// specified by a constant CHAR_BITS and could be
// something other than a byte.
//
// But practically speaking, size of a char is virtually
// always '1 byte' (8 bits).
//
// So we can effectively say that sizeof() returns the
// number of bytes to store the type or expression.
