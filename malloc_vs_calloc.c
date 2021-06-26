/*******************************************************************************
*
* Program: malloc vs calloc
* 
* Description: Examples demonstrating the difference between malloc and calloc 
* in C.  When using malloc, unlike calloc the memory is not all set to zero, 
* and so the memory allocated may include "garbage data".  Calloc is however 
* slower than malloc, as the memory needs to be set to 0 which takes extra time.
*
* YouTube Lesson: https://www.youtube.com/watch?v=SKBnxCq3HvM
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  // malloc vs calloc difference example

  int size = 0;
  int *junk = 0;
  srand( time(0) );

  // this code will fill the heap with random junk data
  for (int i = 0; i < 1000; i++)
  {
    size = rand() % 16000;
    junk = malloc( size * sizeof(int) );
    for (int j = 0; j < size; j++)
    {
      junk[j] = rand();
    }
    free(junk);
  }

  // In the below code we now try to allocate space for an array using malloc, 
  // and when we print out the current contents we'll find it is occupied with 
  // junk data.  If however we comment out the statement which calls malloc to 
  // allocate the space, and remove the comment on the previous line to use 
  // calloc instead, we'll find the space is all 0s instead! 
  int *array;
  // array = calloc( 1000, sizeof(int) );
  array = malloc( 1000 * sizeof(int) );
  for (int i = 0; i < 1000; i++)
    printf("%d", array[i]);
  free(array);
  printf("\n");


  // PERFORMANCE TEST
  //
  // Do a performance test comparison of malloc vs calloc.  We use tic and toc 
  // to record before and after times when running malloc and calloc with 
  // large numbers, and we diff them to get the performance time.
  //
  // Example output from the below code...
  //
  // malloc: 0.000009s
  // calloc: 0.001784s
  //
  // Showing malloc is orders of magnitude faster than calloc!
  //
  clock_t tic, toc;

  // test malloc
  tic = clock();
  array = malloc( 1000000 * sizeof(int) );
  toc = clock();
  printf("malloc: %fs\n", (double) (toc - tic) / CLOCKS_PER_SEC );
  free(array);

  // test calloc
  tic = clock();
  array = calloc( 1000000, sizeof(int) );
  toc = clock();
  printf("calloc: %fs\n", (double) (toc - tic) / CLOCKS_PER_SEC );
  free(array);

  return 0;
}
