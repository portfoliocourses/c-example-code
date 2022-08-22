/*******************************************************************************
*
* Program: Convert A For Loop To A While Loop Demonstration
* 
* Description: Example of how to convert a for loop to a while loop in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=q7vdQJ3Y0CE  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main()
{
  // for loop to output the numbers from 1 to 10
  //
  // Notice the different parts of the for-loop...
  //
  // Initialization statement: int i = 1;
  // Condition (test expression): i <= 10
  // Update statement: i++
  // Body: 
  // {
  //   printf("%d\n", i); 
  // }
  //   
  for (int i = 1; i <= 10; i++)
  {
    printf("%d\n", i);
  }
  
  // We can follow the below template to convert a for loop to a while loop,
  // replacing the different parts of the template with the associated parts
  // of the for loop.
  //
  //    /* initialization statement */
  //    while ( /* condition (test expression) */ )
  //    {
  //       /* body */
  //  
  //      /* update statement */
  //    }
  //
  // This will work for any for loop, as the initialization statement will 
  // execute before anything else in the loop, the condition will be checked 
  // before each time the loop body executes, and the update statement will 
  // always execute after the body.  We reproduce the exact same behaviour 
  // and control-flow of the for-loop by respecting this order/behaviour in 
  // the for loop!
  //


  // The while loop that results from applying the template:
  //
  int i = 1;
  while (i <= 10)
  {
    printf("%d\n", i);
    i++;
  }

  return 0;
}