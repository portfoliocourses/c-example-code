/*******************************************************************************
*
* Program: strcmp demonstration
* 
* Description: An example of using the strcmp function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Vx3GyTVFcMA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

// strcmp return values
//
// < 0	if the 1st non-matching char has
//      a lower ascii value in s1 than s2
//
// 0    if the strings are equal
//
// > 0  if the 1st non-matching char has 
//      a higher ascii value in s1 than s2
//
int main(void) 
{
  // try altering these strings to test the behaviour of strcmp
  char s1[] = "This is the way.";
  char s2[] = "Thia is the way.";
  
  // check for the different potential return values and output the result
  if (strcmp(s1,s2) == 0) printf("Strings are equal\n");
  else if (strcmp(s1,s2) < 0) printf("s1 < s2\n");
  else if (strcmp(s1,s2) > 0) printf("s1 > s2\n");

  return 0;
}
