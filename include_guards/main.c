/*******************************************************************************
*
* Program: Includ Guards Demonstration
* 
* Description: Example of how to use include guards in C.  Include guards 
* prevent the double inclusion problem from occuring, see this for more 
* details: https://en.wikipedia.org/wiki/Include_guard
*
* YouTube Lesson: https://www.youtube.com/watch?v=pF1_fXz5zN0 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// We include both course.h and student.h headers because let's say we want to 
// work with both Students and Courses.  This would be a natural thing for a 
// programmer to do.  The issue is that course.h includes student.h already, so
// if we include student.h here too, without using include guards, the Student
// struct type will be declared twice and a compiler error will occur. 
//
// Using include guards prevents this from occurring.

#include "course.h"
#include "student.h"
   
int main(void)
{  

  return 0;
}
