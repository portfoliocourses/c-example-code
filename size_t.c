/*******************************************************************************
*
* Program: size_t Type Example
* 
* Description: Example of using the size_t type in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=nBJuP_un20M 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main()
{
  // Create a string literal
  char *string = "abcdef";
  
  // When we use strlen() to find the length of the string literal we'll store 
  // the return value into an int variable, and it will work perfectly fine. BUT
  // technically strlen() is returning a value of type size_t.  The size_t type
  // can represent a greater range of positive integers than an int variable,
  // and so this could be a problem in the case of very large numbers.  Many 
  // standard library functions in C actually use size_t type and not int!
  int length = strlen(string);
  
  // We'll be able to use the length variable find to print out each character 
  // in the string individually...
  for (int i = 0; i < length; i++)
    printf("string[%d] = %c\n", i, string[i]);
  
  // The maximum value that an int variable can typically store is 2147483647, 
  // as on most systems/compilers 4 bytes are used to represent an int (it's 
  // possible that only 2 bytes are used in which cause the range is lower).  
  // IF we try to store the number 2147483648, one more than the max, into the 
  // int variable, it's not going to work.  We'll get an int overflow error 
  // as a result, and a negative number will actually be stored into _int!
  int _int = 2147483648;
  
  // Output _int to verify 2147483648 is not stored correctly into the variable
  printf("_int: %d\n", _int);
  
  // A size_t type variable IS able to store a number this large
  size_t _size_t = 2147483648;
  
  // verify _size_t has successfully stored the number
  printf("_size_t: %zu\n", _size_t);
  
  // We can output the preprocessor constant SIZE_MAX to determine the maximum
  // value a size_t type variable can store with the given system/compiler.
  printf("SIZE_MAX: %zu\n", SIZE_MAX);
  
  return 0;
}

// size_t is defined in multiple header files such as
// string.h, stdio.h, etc.
//
// size_t must be large enough to represent the size of
// any 'object' in C, i.e. things in memory like strings
//
// size_t is defined as of C99 to be an unsigned int
// stored using at least 4 bytes of memory
//
// unsigned int means size_t values CANNOT be negative
//
// size_t MINIMUM range is therefore...
//
//         0 to 4,294,967,295
//
// int range minimum is...
//
//         −32,767 to 32,767
//
// BUT on most modern systems the int range will be...
//
//          -2,147,483,648 to 2,147,483,647

