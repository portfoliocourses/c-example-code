/*******************************************************************************
*
* Program: Dynamic memory allocation tutorial
* 
* Description: Examples of dynamic memory allocation in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=R0qIYWo8igs
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void memory_hog(int size);

int main(void)
{
  // ask the user for the size of the dynamically allocated array to create
  int size = 0;
  printf("Enter size: ");
  scanf("%d", &size);
  
  // create the array based on the size using either malloc or calloc, calloc 
  // will set the memory to all 0s, malloc will not, so there may be 'junk data'
  // in the space that has been allocated with malloc
  // int *a = malloc(sizeof(int) * size);
  int *a = calloc(size, sizeof(int));

  // initialize the array with some values
  for (int i = 0; i < size; i++) a[i] = size - i;

  // print out the array values
  for (int i = 0; i < size; i++)
    printf("a[%d] = %d\n", i, a[i]);
  printf("\n");

  // the variable 'a' itself is just a pointer... it stores a memory address of 
  // this dynamically allocated array/space on the heap that we are accessing
  printf("a: %p\n", a);

  // unlike the stack, blocks of data on the heap can be re-sized using realloc 
  // to allocate more space for the data... in this case we increase the size
  // by 5 ints
  a = realloc(a, sizeof(int) * (size + 5));

  // set the additional 5 int values in the array to 9
  for (int i = size; i < (size+5); i++) a[i] = 9;

  // print out the entire array so we can see the last 5 values have been set 
  // to 9s
  for (int i = 0; i < (size+5); i++)
    printf("a[%d] = %d\n", i, a[i]);
  printf("\n");

  // save the memory address stored in a, i.e. the memory address of the 
  // dynamically allocated array
  int *save = a;

  // free the block of memory on the heap, this allows the memory to be used 
  // again by future calls to calloc/malloc/realloc
  free(a);

  // we've maintained the pointer to the original block of memory with save...
  printf("save: %p\n", save);

  // If we print out the data located at this memory, we'll see the data that 
  // we set previously... what this tells us is that even though free() makes
  // the memory available again to be used it does not "blank" the memory by 
  // say setting it all to 0... whatever data was in there before will still 
  // be there.  This could be a security risk if sensitive data was stored 
  // in that memory!
  for (int i = 0; i < 10; i++)
    printf("save[%d] = %d\n", i, save[i]);
  printf("\n");  

  // if we uncomment the below code, we call memory_hog forever again and again
  // which will use malloc to allocate space but never free it... the heap will
  // eventually run out of memory to allocate and our program will crash!
  // while (1) memory_hog(128000);

  return 0;
}

// will use malloc to allocate space, but it is never free'd and so never made 
// available again
void memory_hog(int size)
{
  int *a = malloc(size);
}
