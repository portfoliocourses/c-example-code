/*******************************************************************************
*
* Program: Static Functions
* 
* Description: An example of a static function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=zgbTMwZkoOk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include "lib.h"

// If we DIDN'T use the static keyword in lib.c when defining print() we could
// actually make print() accessible in main.c by including a function 
// declaration.  If you remove the static keyword in lib.c and uncomment this 
// line below and the call to print() in main, you will see that it works!
//
// void print(double value, int times);

int main(int argc, char *argv[])
{
  // Use the library's interface to report the value
  report_value(10.3333);
  
  // If print() is not defined using the static keyword, and we declare 
  // the function above (see the commented declaration), then we could actually
  // call the print() function from this file!
  //
  // print(10.3333, 3);

  return 0;
}
