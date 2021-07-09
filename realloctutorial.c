/*******************************************************************************
*
* Program: realloc tutorial
* 
* Description: Example of using realloc in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=dTFpT-zuG0Q 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // allocate space for a 5 int array on the heap
  int *a = malloc(sizeof(int) * 5);

  // initialize the array to values 0-5
  for (int i = 0; i < 5; i++) a[i] = i;

  // print out the values to demonstrate they are there
  for (int i = 0; i < 5; i++)
    printf("a[%d] = %d\n", i, a[i]);
  printf("\n");

  // print out the memory address that a stores before realloc
  printf("a before: %p\n", a);

  // run realloc to increase the size of memory allocated to 10 ints
  a = realloc(a, sizeof(int) * 10);

  // print out the memory address that a stores after realloc... we'll find 
  // in this case that a is storing the same memory address, in other words 
  // realloc expanded the space allocated at the *existing* space in memory
  printf("a after: %p\n", a);

  // we can set the 5 additional int values available now...
  for (int i = 5; i < 10; i++) a[i] = i;

  // and we can print out all 10 values too
  for (int i = 0; i < 10; i++)
    printf("a[%d] = %d\n", i, a[i]);
  printf("\n");

  // we should always free memory on the heap after we're done working with it
  free(a);

  // In the above situation, a is the only thing stored on the heap, and so 
  // when realloc is requested to find additional space in memory, it just 
  // has to allocate more space at the existing memory location.
  // 
  // a
  // 0 1 2 3 4 5 _ _ _ _ _ 
  //
  // But what if we have allocated space for two things on the heap?  In this 
  // case if we try to reallocate space for a1, realloc cannot just allocate 
  // more space at the existing memory address, because a2 is stored right 
  // after a1 in memory!  realloc will actually find another new place entirely
  // for the reallocated space, and it will copy the values of a1 into that 
  // new space.  Interestingly, it will leave the data in the original place 
  // in memory that a1 is pointing to... a potential security risk if a1 were 
  // storing sensitive data.
  //
  // a1          a2
  // 0 1 2 3 4 5 9 9 9 9 9
  //

  // allocate space for 5 ints and have a1 point to this space
  int *a1 = malloc(sizeof(int) * 5);

  // same with a2... a2 will be stored directly after a1
  int *a2 = malloc(sizeof(int) * 5);

  // initialize a1 values to 0-4, and a2 values to 9
  for (int i = 0; i < 5; i++) a1[i] = i;
  for (int i = 0; i < 5; i++) a2[i] = 9;

  // when we print out the memory addresses (pointers) that a1 and a2 are 
  // storing we'll find they are "very close" in memory... a2 is stored right 
  // after a1 in memory...
  printf("a1: %p\n", a1);
  printf("a2: %p\n", a2);
  printf("\n");

  // If we print the values of a1 beyond the length of a1, we'll actually find 
  // that we start printing out the values of a2!  This is because a2 is stored
  // right after a1.
  for (int i = 0; i < 14; i++)
    printf("a1[%d] = %d\n", i, a1[i]);
  printf("\n");

  // let's output a1 before we use realloc to increase the size of it
  printf("a1 before: %p\n", a1);

  // and let's save the memory address that a1 contains in save
  int *save = a1;

  // if we free a1 before calling realloc, realloc won't work correctly, you
  // can uncomment the next line to test it out
  // free(a1);
  
  // use realloc to allocate a larger space for the contents of a1 in memory
  a1 = realloc(a1, sizeof(int) * 20);

  // this time we'll find that the memory address a1 is storing is different!
  // realloc couldn't just enlarge the existing space in memory that a1 was 
  // pointing to because a2 was right next to it, instead realloc found another 
  // space in memory altogether and copied the contents of a1 to this space
  printf("a1 after: %p\n", a1);

  // but we've kept a pointer to the original location of a1 in memory at save,
  // notice how it is the same as a1 before the realloc call
  printf("save: %p\n", save);
  printf("\n");

  // we can set 15 more int values at the array in a1 now as it is able to store
  // up to 20 ints now
  for (int i = 5; i < 20; i++) a1[i] = i;

  // and we can print them out... notice how the values for a[0] - a[5] are 
  // the same as before... even though a1 is pointing to a different place 
  // in memory, realloc copied the original data stored in the original place 
  // in memory to this new place in memory
  for (int i = 0; i < 20; i++)
    printf("a1[%d] = %d\n", i, a1[i]);
  printf("\n");

  // If we use our pointer to the old place in memory, save, and print out the 
  // contents at this place in memory, we'll find the data is still there!  This
  // is important... realloc does not clear the original space in memory when 
  // it copies the data to a new place in memory.  This leaves "junk data" in 
  // memory and it potentially a security risk if the "junk data" contains 
  // sensitive data such as passwords.
  for (int i = 0; i < 5; i++)
    printf("save[%d] = %d\n", i, save[i]);
  printf("\n");

  // free the dynamically allocated space for a1, a2
  free(a1);
  free(a2);

  return 0;
}
