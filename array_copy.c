/*******************************************************************************
*
* Program: Array copy
* 
* Description: Demonstration of creating a copy of an array on the heap using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=aCR3SlfZTwg
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int *array_copy(int *array, int length);

int main(void)
{
  // two test arrays
  int a1[] = {1,2,3,4,5};
  int a2[] = {99,50,30,70,80,90,100,50};

  // create copies of the array, have a1_copy and a2_copy point to these copies
  int *a1_copy = array_copy(a1, 5);
  int *a2_copy = array_copy(a2, 8);

  // notice how we can modify a1, and it doesn't effect the copy!
  a1[0] = 10;
  for (int i = 0; i < 5; i++)
    printf("a1_copy[%d]=%d\n", i, a1_copy[i]);

  // same with a2, we can modify it, and the copy will not be effected
  a2[0] = 0;
  printf("\n");
  for (int i = 0; i < 8; i++)
    printf("a2_copy[%d]=%d\n", i, a2_copy[i]);

  // notice how the copy is stored at a different location in memory!
  printf("\n");
  printf("a1: %p\na1_copy: %p\n", a1, a1_copy);

  // free the dynamically allocated memory when we are done using it
  free(a1_copy);
  free(a2_copy);

  return 0;
}

// creates a copy of the array of the given length on the heap
int *array_copy(int *array, int length)
{
  // creates space in memory to store the copy
  int *c = malloc(length * sizeof(int));

  // copy the values of the original array into the copy
  for (int i = 0; i < length; i++)
    c[i] = array[i];

  // returns the pointer to the copy
  return c;
}




