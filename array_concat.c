/*******************************************************************************
*
* Program: Concatenate Two Arrays
*
* Description: Example of how to concatenate two arrays into a new third array
* using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=2zH5TDg3LUo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *concat(int *a1, size_t len1, int *a2, size_t len2);

int main(int argc, char *argv[])
{
  // Declare and initialize two test arrays to concatenate
  int array1[] = {0,1,2,3,4};
  int array2[] = {5,6,7,8,9};

  // Call the concatenate function with the above arrays and their lengths as
  // argumenets, store the pointer to the dynamically allocated array that the
  // function returns into array3.
  int *array3 = concat(array1, 5, array2, 5);

  // Loop through the indexes of the new array from 0 to the array length (10)
  // and output the values at each index to confirm the array concatenation
  // was succesful.
  for (int i = 0; i < 10; i++)
    printf("array3[%d] = %d\n", i, array3[i]);
  printf("\n");

  // Free the dynamically allocated third array once we are done working with
  // it to prevent a memory leak.
  free(array3);

  return 0;
}

// Concatenates array a1 with length len1 with array a2 with length l2, storing
// the new array in dynamically allocated memory, and returns a pointer to it
int *concat(int *a1, size_t len1, int *a2, size_t len2)
{
  // Allocate space for a block of memory able to store an array of ints with
  // the combined length of both a1 (len1) and a2 (len2).  The sizeof(int)
  // operator will return the size in bytes that it takes to store an int and
  // by multiping this by len1 + len2 malloc() will return a pointer to a block
  // of memory (i.e. an array) able to store this many int values/elements, and
  // we store that pointer (memory address) into new_array.
  int *new_array = malloc(sizeof(int) * (len1 + len2));

  // Copy the data from a1 into new_array, sizeof(int) * len1 specifies how many
  // bytes to copy (the size in bytes that it takes to store an int multipled
  // by the number number of ints in a1 aas given be len1).
  memcpy(new_array, a1, sizeof(int) * len1);

  // Copy the data from a2 into new_array, but this time we copy the data into
  // the destination memory address as given by the pointer arithmetic
  // "new_array + len1".  What this operation will do is give us a memory
  // address offset from the new_array memory address by the sizeof(int) * len1,
  // as we need to copy the values from a2 AFTER the values from a1 to perform
  // the concatenation.
  memcpy(new_array + len1, a2, sizeof(int) * len2);

  // Return the pointer to the third array
  return new_array;
}