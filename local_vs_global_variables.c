/*******************************************************************************
*
* Program: Local vs. Global Variables
* 
* Description: Examples of using local and global variables in C, as well as a 
* block-scope variable.
*
* YouTube Lesson: https://www.youtube.com/watch?v=qXVIMX2GlK8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// Declares a global variable which will have the scope of all functions (i.e.
// the variable can be accessed by ALL functions).  The variable will have the 
// lifetime of the entire program's execution... i.e. it will take up space in
// memory for the entire execution of the program (in the 'data section of 
// memory).  The variable is initialized to 50.  Global variables are declared
// outside the definition of a function.
//
int global = 50;

// Declare another global variable x and initialize it to 1
int x = 1;

// We're not required to initialize global variables, but if we do we need to 
// initialize them to a constant value.  So for example the below statement will
// cause a compiler error because we are attempting to initialize x using 
// a variable and not a constant.
//
// int x = global;

// A void function (which returns no value) to test out local/global variables
void function1()
{
  // Declared inside the definition of function1(), 'local' will be a local 
  // variable of function1, i.e. it will 'belong' to function1.  The variable 
  // will have the scope of function1 which means it can only be accessed 
  // within function1, it cannot be accessed in other functions such as the 
  // main function.  It will have the lifetime of the execution of the function,
  // so it will only exist as the function is executing and will cease to 
  // exist in memory when the execution of the function is complete.  Local 
  // variables exist in a place in memory called the stack.  Local variables
  // are sometimes called "function-scope" variables.  We initialize the 
  // variable 'local' to the value 10.  
  int local = 10;
  
  // We can access the local variable inside the function it belongs to OK
  printf("local: %d\n", local);
  
  // We can access a global variable in ANY function, here we increment it and 
  // then print out its value
  global++;
  printf("global: %d\n", global);
  
  // Here we declare a local variable x with the same name as the global 
  // variable x
  int x = 10;
  
  // When a local variable has the same name as a global variable, the local 
  // variable will take precedence, so here we will output that x is 10.
  printf("x: %d\n", x);
}

int main(void)
{
  // Call function1() to test out local vs global variables
  function1();
  
  // We can access the global variable in the main function too
  global++;
  printf("global: %d\n", global);
  
  // We can declare a variable inside a block defined with { }, like an 
  // if statement block or loop block.  We say that these variables are 
  // 'block scope' variables, and they will have the scope of the block
  // they are declared in.
  if (x == 1)
  {
    int block = 2000;
    printf("block: %d\n", block);
  }
  
  // We cannot access the block scope variable outside the above block, it 
  // does not exist here...
  //
  // block = 5000;
  
  return 0;
}