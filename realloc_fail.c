/*******************************************************************************
*
* Program: Safely Handle realloc() Failure
* 
* Description: Example of how to safely handle the failure of the realloc()
* function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=skqCnhhA0ZY  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // allocate space for 3 int values
  int *array = malloc(sizeof(int) * 3);
  
  // set the values of the dynamically allocated array
  array[0] = 2;
  array[1] = 3;
  array[2] = 8;
  
  // print out the memory address of the dynamically allocated array BEFORE 
  // we attempt reallocation
  printf("array before: %p\n", array);
  
  // create a temp variable to store the return value of realloc()
  int *temp;
  
  // Often in C example code online, you'll find that realloc() is setup to 
  // assign its return variable to the same variable that was given as a first 
  // argument, i.e.  array = realloc(array, ... some value .... );
  //
  // The issue with this is that IF realloc fails, it returns NULL.  If it 
  // returns NULL and the value is assigned to 'array', the memory address that 
  // was stored there previously will be overwritten.  If we no longer have the 
  // memory address of the block of memory, we can no longer call free() to free
  // that block of memory.  So we have an allocated block of many memory that 
  // we can no longer free... i.e. a memory leak has resulted!!!
  //
  // So what we do instead is FIRST save the result of calling realloc() to a 
  // temp variable, and then ONLY once we've verified that temp is not NULL 
  // do we assign the temp value to array, so that we can continue to use 
  // array (or whatever the variable is called) to refer to this data.
  //
  temp = realloc(array, sizeof(int) * 999999999999999);
  
  // ONLY if temp is NOT NULL do we assign the temp value to array
  if (temp != NULL) array = temp;
  else
  {
    // if the temp value IS NULL we can detect this and "fail gracefully", but
    // the important thing is we have not overwritten array... we still have 
    // the memory address and can still free the memory, so we've prevented a
    // memory leak
    printf("array after: %p\n", array);
  }
  
  free(array);
  
  return 0;
}