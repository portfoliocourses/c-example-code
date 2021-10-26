/*******************************************************************************
*
* Program: Initialize Array With #include
* 
* Description: Example of how to initialize an array with #include in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=_rr2AgzB8RI
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main()
{
  // initializes the array with the contents of data.txt, which for testing 
  // purposes was exactly the text:
  // 1,2,3,4,5,6,7,8,9,10
  int a[2][5] = {
    #include "data.txt"
  };

  // verify array 'a' has been initialized with the values from data.txt
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 5; j++)
      printf("a[%d][%d]=%d\n",i,j,a[i][j]);

  return 0;
}