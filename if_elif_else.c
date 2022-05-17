/*******************************************************************************
*
* Program: #if #elif #else Demonstration
* 
* Description: Examples of using the #if #elif and #else preprocessor directives
* for conditional compilation in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Wky4R426yuM 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// The preprocessor is the first phase in the compilation of a C program, it 
// will operator on preprocessor directives and mostly performs text insertion
// and replacement type operations using these directives.  It will transform 
// our source code with these operations into a version of the code that is 
// then compiled into an executable program.

// We can define 'constants' (object-like macros) with the preprocessor,  where 
// any occurrence of BUFFER_SIZE will then be replaced with the text 100 and 
// any occurrence of TOTAL_BUFFERS will then be replaced with the text 10
#define BUFFER_SIZE 100
#define TOTAL_BUFFERS 10

// If we don't define a macro called PLATFORM_CODE, then in the below code where
// we attempt to use the macro PLATFORM_CODE in an #if directive the
// preprocessor will replace it with 0.  Try uncomment the below line and 
// changing the PLATFORM_CODE to values like 1,2,5, etc. to see what happens 
// with the #if #elif #else directives in the main function.
//
// #define PLATFORM_CODE 4

// The macro VERSION_CODE is set to a char, and we can use this in the condition
// expression of an #if directive
#define VERSION_CODE 'a'

// Define a macro OS to test the define() keyword
#define OS

// Create a function-like macro called func with a parameter x, it will replace
// x with the expression x - 100
#define FUNC(x) x - 100

// The #if directive will include the code beneath it (but before #else) into 
// the compiled source code IF the condition is true (i.e. if the condition is 
// any value but 0 which is considered false).  Here we use our function-like 
// macro defined above... with an argument of 200, the macro will be replaced 
// with the text 200 - 100 which evaluates to 100 which is greater than 0!  So
// the VALUE macro will be set to 500.  Try another argument to the 
// function-like macro such as 50 to see what happens.
//
#if FUNC(200) > 0 
  #define VALUE 500
#else 
  #define VALUE 1000
#endif

int main()
{
  // The #if #elif and #else directives work together to insert code into the 
  // compiled source code.  First the #if directive expression will be 
  // evaluated, if it is true the idented printf() beneath it will be inserted
  // into the compile source code, otherwise the first #elif condition will 
  // be checked next.  Notably, if the PLATFORM_CODE macro is NOT defined the 
  // preprocessor will replace the macro with the value of 0, which will make 
  // the first condition true.  We would need to uncomment the PLATFORM_CODE 
  // macro #define directive above to define the PLATFORM_CODE macro to 
  // something.  If after evaluating the #if and all #elif directives no 
  // condition expressions are true, then the indented printf() following #else 
  // will be inserted into the compiled source code.
  #if PLATFORM_CODE == 0
    printf("Platform 0\n");
  #elif PLATFORM_CODE == 2
    printf("Platform 2\n");
  #elif PLATFORM_CODE == 3
    printf("Platform 3\n");
  #else 
    printf("Unknown Platform\n");
  #endif
  
  // Any expression that evaluates to 0 will be considered false, so in the 
  // below example '0 is false' will always be output.
  #if 0
    printf("will not print\n");
  #else 
    printf("0 is false\n");
  #endif
  
  // Any expression that does NOT evaluate to 0 will be considered true, so in 
  // the below example 'non-zero is true' will always be output.
  #if -1 
    printf("non-zero is true!\n");
  #endif
  
  // We can use char constants in our condition expressions as well, here the 
  // VERSION_CODE macro is set to 'a' so we expect this printf() to execute
  #if VERSION_CODE == 'a'
    printf("VERSION_CODE == a\n");
  #endif
  
  // We can use operators like multiplication, division, addition and 
  // subtraction (and some others) in our condition expressions, here we 
  // multiply the BUFFER_SIZE by the TOTAL_BUFFERS (100 * 10 = 1000).  We can 
  // also use and, or and not operators in our condition expressions as well, 
  // so here even though the left operand evaluates to false, we have "or 1" 
  // (where 1 being a non-zero value is true), and so "false or true" evaluates
  // to try and we will print out the BUFFER_SIZE value.
  #if BUFFER_SIZE * TOTAL_BUFFERS > 5000 || 1
    printf("%d\n", BUFFER_SIZE);
  #endif
  
  // We can use defined() to check whether a macro has been defined, this is 
  // the same as using the #ifdef directive 
  #if defined(OS)
    printf("OS is defined\n");
  #endif

  // Print out VALUE, it will be set based on the #if #else directives above 
  // the main function.
  printf("Value: %d\n", VALUE);

  return 0;
}