
/*******************************************************************************
*
* Program: Initialize An Array With User Input
* 
* Description: Example of how to initialize an array with user input in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=5nyMb7hJ7Xs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main()
{
  int length;
  
  // ask the user for the length of the array, store it into length
  printf("Length: ");
  scanf("%d", &length);
  
  // declare an array using the entered length
  int array[length];
  
  // ask the user to enter a value for array indexes from 0 ... (length-1), and 
  // store what is entered into the array at each index
  for (int i = 0; i < length; i++)
  {
    printf("array[%d]=", i);
    scanf("%d", &array[i]);
  }
  
  // output the array contents to verify elements were set correctly
  printf("\n");
  for (int i = 0; i < length; i++)
    printf("array[%d] = %d\n", i, array[i]);

  return 0;
}