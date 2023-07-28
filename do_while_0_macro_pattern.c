/*******************************************************************************
*
* Program: do {...} while(0) In Macro Pattern Example
* 
* Description: Example of using the do {...} while (0) pattern in a 
* function-like macro in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=JGqww6ainA8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// We use a do-while loop to allow us to execute multiple statements as part of
// a function-like macro.  Because the loop condition is 0 (which is false) the 
// loop body will only execute once.  There will be no overhead to using a loop
// because the compiler can recognize the loop will execute only once with a 
// constant condition of 0.  Because we have used a do-while loop to group 
// together the statements, we can use foo(10); or similar usages of the 
// function-like macro in an if-statement without breaking it, as alternative 
// approaches would.
//
// See further explanations of this topic here...
//
// Pattern Explanation: https://bruceblinn.com/linuxinfo/DoWhile.html
// Stackoverflow Explanation: https://stackoverflow.com/a/9496007
//
#define foo(x) do {bar(x); bar(x + 1);} while(0)

void bar(int x) { printf("%d\n", x); }
 
int main(void)
{ 
  // Use the function-like macro in an if-statement
  if (1 == 1)
    foo(10);
  else 
    printf("else case\n");
  
  // The macro will be expanded by the preprocessor to this valid C code...
  //
  // if (1 == 1)
  //   do {bar(x); bar(x + 1);} while(0);
  // else 
  //  printf("else case\n");


  // We could try to achieve this with just curly braces by definining the 
  // function-like macro like this...
  //
  // #define foo(x) {bar(x); bar(x + 1); }
  //
  // But then the resulting code after the preprocessor will look like this...
  // 
  // if (1 == 1)
  //   {bar(x); bar(x + 1); };
  // else 
  //  printf("else case\n");
  //
  // Which is not valid, after the close } curly brace we have a semi-colin when
  // an else is expected!

  return 0;
}
