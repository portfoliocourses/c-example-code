/*******************************************************************************
*
* Program: Print An Array
*
* Description: Examples of different ways of printing out the elements of an 
* array in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=4sIdcbHbIbQ 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main()
{
  // Declare and initialize an array to store int values with the name 'array' 
  // containing 8 elements set to the values 1-8.  
  //
  // The array indexes start at 0 and go up until 7...
  //
  //             0 1 2 3 4 5 6 7
  int array[] = {1,2,3,4,5,6,7,8};

  // Declare and initialize a variable length, set it to the length of the array
  int length = 8;
  
  // We could output each array element individually like this using 8 almost 
  // identical statements.  But the only difference between each statement is
  // the index in the array being accessed, we could instead use a loop instead
  // of repeating the same statement again and again...
  //
  /*
    printf("%d\n", array[0]);
    printf("%d\n", array[1]);
    printf("%d\n", array[2]);
    printf("%d\n", array[3]);
    printf("%d\n", array[4]);
    printf("%d\n", array[5]);
    printf("%d\n", array[6]);
    printf("%d\n", array[7]);
  */

  // We could create a loop with a counter variable (i) that will go from 0 
  // up until the length of the array, incrementing by 1 with each loop 
  // iteration.  Note that the loop will STOP when i == length, as we keep 
  // the loop going so long as i < length... this means the last element output
  // will be the element at the index length - 1, which is the index of the 
  // last element in the array.
  for (int i = 0; i < length; i++)
  {
    // Output the array element at the index i followed by a new line
    printf("%d\n", array[i]);
  }
  // Output a newline after outputting the array elements
  printf("\n");
  
  // In this version the array elements are output separated by spaces
  for (int i = 0; i < length; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
  
  // In this version the array name and index are output along with the value 
  // at that index
  for (int i = 0; i < length; i++)
  { 
    printf("array[%d] = %d\n", i, array[i]);
  }
  printf("\n");
  
  // In this version the array elements are output separated by commas
  for (int i = 0; i < length; i++)
  {
    // Output the array element
    printf("%d", array[i]);
    
    // Output a comma only if the index i is not the last index in the array 
    // (as given by length - 1) so that way the last element does not have a 
    // comma output after it...
    if (i != (length - 1)) printf(",");
  }
  printf("\n");

  return 0;
}