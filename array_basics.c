/*******************************************************************************
*
* Program: Array basics tutorial
* 
* Description: Examples illustrating the basics of using arrays in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=SqOphaInWOs
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// grade array...
//
// Index:   0     1     2     3     4
//
// Value:   91    82    73    64    55
//
// This is what the grade array looks like in memory, with each value (element)
// accessible via an index starting from 0 up until 4.
//

int main(void)
{
  // we can declare and initialize an array like this 
  int grade[] = {91, 82, 73, 64, 55};

  // ...or like this...
  // int grade[5] = {91, 82, 73, 64, 55};

  // we could also set individual values like this...
  // grade[0] = 91;
  // grade[1] = 82;
  // grade[2] = 73;
  // grade[3] = 64;
  // grade[4] = 55;

  // We can use variables to access array elements, allowing for concise clear 
  // code such as the below to print all array elements... this would scale to 
  // any number of array elements simply by modifying the value 5 (which itself
  // could be a variable or constant value).  
  for (int i = 0; i < 5; i++)
    printf("grade[%d] = %d\n", i, grade[i]);

  // compute the array average print it out
  int total = 0;
  for (int i = 0; i < 5; i++)
    total = total + grade[i];
  int average = total / 5;

  printf("average: %d\n", average);

  return 0;
}
