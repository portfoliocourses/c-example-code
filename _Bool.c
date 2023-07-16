/*******************************************************************************
*
* Program: _Bool Type
*
* Description: Examples to explain what the _Bool type is in C and why it 
* exists.
*
* YouTube Lesson: https://www.youtube.com/watch?v=I8Y3OKwcmZw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// Older versions of C such as C89 did not include a proper boolean type.  In 
// all versions of C non-zero values are considered true and zero is considered
// false.  

#include <stdio.h>

// In C99 onwards the libary stdbool.h was added, which does include a type 
// bool and true/false...
//
#include <stdbool.h>

// Because older versions of C did not include a proper bool type, developers 
// would make their own using typedef, perhaps with preprocessor macros for 
// true and false...
//
// typedef int bool;
// #define false 0
// #define true 1
//
// Or they might use typedef and enum to create 'true' and 'false' values along
// with a bool type...
//
// typedef enum {false, true} bool;
//
// This was done to improve the readability of the code, as it makes the intent
// of variables and values clearer.  If we have...
//
// int is_raining = 1;
//
// It's unclear if the variable is being used to store ints or a 'booleans', and
// it is unclear if 1 is an integer or 'true'.  But if instead we have...
//
// bool is_raining = true;
//
// The intention is clearer, and the readability of the code is improved.
//

int main(void)
{
  // Because so much old code used custom "bool" types if a new bool type was 
  // included in the language it would break this existing code.  So instead 
  // a type _Bool was added, which is a spelling unlikely to break the 
  // existing code.  At the same time, an stdbool.h library was added that 
  // does have a bool type with true/false, where bool is really just an 
  // alias for _Bool.
  //
  // So we can declare values of type _Bool...
  //
  _Bool is_sunny;
  
  // _Bool variables only store 0 or 1, if we assign a non-zero value to 
  // the variable it will actually store 1.
  _Bool is_raining = 10;
  
  // Incrementing won't do anything in this case, the value will remain 1
  is_raining++;
  
  // Output is_raining to see what value it actually stores
  printf("is_raining: %d\n", is_raining);
  
  // Output whether it is raining or not based on the boolean
  if (is_raining)
  {
    printf("It's raining.\n");
  }
  else
  {
    printf("It's not raining.\n");
  }

  // It is "cleaner" to use bool/true/false, so unless we're using an old 
  // technique to define our own bool type, we should just include stdbool.h
  // even if _Bool exists.
  
  // In C23 bool, true and false are keywords, and including stdbool.h. is 
  // no longer necessary to use bools.  We can say that a proper boolean type
  // has been phased into the language.
  
  return 0;
}