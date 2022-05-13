/*******************************************************************************
*
* Program: #ifdef #ifndef Conditional Compilation Directive Examples
* 
* Description: Example of using the #ifdef and #ifndef preprocessor directives 
* for conditional compilation in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=BevPV5DrIxE 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// Define a macro with #define
#define DEBUG_MODE

// Undefine a macro using #undef, add and remove this below line of code to 
// see the effect it has on the program
#undef DEBUG_MODE

// Define a macro WINDOWS
#define WINDOWS

// Set BUFFER_SIZE to 100 based on whether or not LINUX macro is defined
#ifdef LINUX
  #define BUFFER_SIZE 100
#endif 

// Set BUFFER_SIZE to 200 based on whether or not MAC macro is defined
#ifdef MAC 
  #define BUFFER_SIZE 200
#endif 

// Set BUFFER_SIZE to 300 based on whether or not WINDOWS macro is defined
#ifdef WINDOWS 
  #define BUFFER_SIZE 300
#endif

int main()
{
  // If the DEBUG_MODE macro is defined the preprocessor will insert the code 
  // printf("Debug mode!\n"); into the source code before it is compiled, 
  // otherwise the preprocessor will insert the code 
  // printf("Not debug mode 2!\n"); into the source code before it is compiled.
  #ifdef DEBUG_MODE
    printf("Debug mode!\n");
  #else 
    printf("Not debug mode 2!\n");
  #endif
  
  // Insert the printf() statement if the DEBUG_MODE macros is NOT defined
  #ifndef DEBUG_MODE
    printf("Not debug mode!\n");
  #endif
  
  // Output the size of the buffer char array which will be determined based on
  // which MAC, LINUX or WINDOWS macro has been defined.
  char buffer[BUFFER_SIZE];
  printf("sizeof(buffer): %lu\n", sizeof(buffer));
  
  return 0;
}