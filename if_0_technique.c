/*******************************************************************************
*
* Program: #if 0 ... #endif Debugging Technique To Temporarily Remove Code 
* 
* Description: Example of temporarily removing code using #if 0 ... #endif in C, 
* an alternative approach to the debugging technique called commenting out code.
*
* YouTube Lesson: https://www.youtube.com/watch?v=45fF11EKvW8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(void)
{
  // do work 1
  printf("work 1\n");
 
  // As an alternative to commenting out code with multiline comments (see 
  // below), we can use #if 0 ... #endif.  This preprocessor directive will 
  // remove the section of source code entirely from the compiled program.  The
  // preprocessor is the first phase of compilation before the source code is
  // turned into executable machine code, and this directive will not include 
  // the code in the compiled code because '0' is considered false.
  //
  
  #if 0        
  /*
     do work 2
  */
  printf("work 2\n");
  #endif 
  
  // We can use multiline comments to temporarily turn sections of code into 
  // comments, allowing us to "turn off" sections of code for debugging 
  // purposes.  This technique is known as 'commenting out code'.
  //
  // We might use #if 0 ... #end if as an alternative technique to multiline
  // comments because we cannot nest multiline comments (the closing of the 
  // inner multiline comment */ will close the outer multiline comment). 
  //

  /*
  // do work 3
  printf("work 3\n");
  */

  return 0;
}