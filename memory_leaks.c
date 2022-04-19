/*******************************************************************************
*
* Program: Memory Leak Examples
* 
* Description: Examples of memory leaks occurring in C.  For an explanation of 
* what a memory leak is as a general concept see the Wikpedia article:
* https://en.wikipedia.org/wiki/Memory_leak.  In general a memory leak occurs 
* when our program does not free dynamically allocated memory after it is done 
* working with the memory.
*
* YouTube Lesson: https://www.youtube.com/watch?v=lQCLAKfcYI4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

// Function allocates memory and returns a pointer to the block of memory
int *allocate()
{
  // malloc will return a memory address for the block memory that is stored 
  // into pointer
  int *pointer = malloc(sizeof(int) * 10000);

  // When the function returns, the pointer variable that stores the memory
  // address will no longer exist, but the intention is the return value is 
  // assigned somewhere so that the memory can be released/freed later
  return pointer;
}

int main()
{
  
  // We call allocate but we do not store the memory address (pointer) that is 
  // returned... as a result, our program has "lost" the memory address for the 
  // dynamically allocated block of memory and the program CANNOT free the 
  // memory now.  This is one way that a memory leak can occur, when our 
  // program "loses" the pointer to the dynamically allocated memory.  
  allocate();


  // Another way a memory leak can occur is if our program never frees memory 
  // that has been allocated despite the fact that it has the pointer to the 
  // memory available.

  // pointer to store dynamically allocated memory address
  int *data;

  // define a very large size of memory to allocate
  size_t data_size = sizeof(int) * 1000000000000;

  // used to count iterations of the loop
  int iterations = 0;
  
  // keep allocating memory without freeing it
  while (true)
  {
    // allocate the memory using malloc
    data = malloc(data_size);

    // eventually malloc will fail to allocate memory because no more memory 
    // is available, it will return NULL when this is the case and we stop 
    // the loop at this point
    if (data == NULL) break;

    // otherwise count and output the iterations of the loop so far
    iterations++;
    printf("iterations: %d\n", iterations);
     
    // If we did free the dynamically allocated memory using free() then we 
    // should not run out of memory (it is still possible malloc will fail on
    // the first call).
    // free(data);
  }
  
  // notify the user that malloc has now failed
  printf("malloc failed.\n");

  return 0;
}