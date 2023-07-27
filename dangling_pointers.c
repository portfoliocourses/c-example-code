/*******************************************************************************
*
* Program: Dangling Pointer Demonstration
*
* Description: Examples related to dangling pointers in C.  Dangling pointers 
* Wikipedia article: https://en.wikipedia.org/wiki/Dangling_pointer.
*
* YouTube Lesson: https://www.youtube.com/watch?v=HhJyLX6hM9M 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// Turns off the assert()
#define NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// A function-like macro that makes it easier to call safe_free_mem(), we 
// can just supply the pointer variable as we do with free() this way.
#define safe_free(ptr) safe_free_mem((void **) &(ptr))

// Increments the value pointed to by ptr by 1.  Returns 0 if successful, -1 
// otherwise in the case ptr is NULL.
int do_work(int *ptr)
{
  // if ptr is NULL it points to nothing so we cannot de-reference it and the 
  // function returns an error code -1, "defensively" handling a NULL pointer
  if (ptr == NULL) return -1;
  
  // Increments the value pointed to by ptr 
  *ptr = *ptr + 1;
  
  // Returns 0 if successful
  return 0;
}

// A safe version of the free function that accesses the pointer that pointer
// to a pointer parameter ptr points to and 1) frees the block of memory the 
// pointer points to, 2) sets the pointer to NULL to prevent and dangling 
// pointer.  
void safe_free_mem(void **ptr)
{
  // It does not make sense for ptr to be set to NULL and it is undefined 
  // behaviour to try to de-reference NULL so we use an assert() to 
  // ensure ptr is not set to NULL.
  assert(ptr);
  
  // Free the memory pointed to by the pointer that ptr points to
  free(*ptr);
  
  // Set the pointer that ptr points to to NULL so it points to nothing
  *ptr = NULL;
}

int main(void)
{
  // Allocate a block of memory to store a single int value and have ptr 
  // store the memory address of this block of memory (i.e. point to it)
  int *ptr = malloc(sizeof(int));
  
  // We can set the value of this space in memory to 4 by de-referencing
  // ptr.
  *ptr = 5;
  
  // Output the memory address ptr stores, and the value stored at that 
  // memory adress.
  printf("  ptr before: %p\n", ptr);
  printf(" *ptr before: %d\n", *ptr);
  

  // We need to the free block of dynamically allocated memory when we are
  // done working wit hit.  If we JUST call free() and pass it the pointer 
  // the block of memory will be free...
  // 
  // free(ptr);
  //
  // BUT ptr will still store the memory address for this block of memory.
  // The free() function does not set it to NULL so that it points to 
  // nothing.  As a result, our program can still access this memory and 
  // modify it.  We call this situation a "dangling pointer":
  // https://en.wikipedia.org/wiki/Dangling_pointer
  //
  // *ptr = 99;
  // printf("   ptr after: %p\n", ptr);
  // printf("  *ptr after: %d\n", *ptr);
  //
  // This can cause serious bugs that can be difficult to trace and can be a 
  // security issue as well!
  // 


  // We could instead set ptr to NULL after calling free()...
  //
  // free(ptr);
  // ptr = NULL;
  //
  // This is considered a best practice to eliminate the dangling pointer,
  // our program can no longer use ptr to access the block of memory.


  // We could also create a "safe" version of the free function as we have done
  // so above that sets the pointer variable to NULL for us. 
  //
  // safe_free_mem((void **) &ptr);

  // If we want to be able to call our safe free function by just passing the 
  // pointer varible as we do with free(), we could use a function-like macro
  // safe_free defined above to achieve this effect:
  //
  safe_free(ptr);
  
  // One advantage of setting pointers to NULL after free() is that often 
  // functions will defensively check if pointer parameters are NULL before 
  // using them.  Here are do_work() function will recognize that ptr has 
  // been set to NULL and return an error status allowing our program to 
  // handle the issue gracefully.
  if (do_work(ptr) != 0)
  {
    printf("Error doing work.\n");
    return -1;
  }
  
  return 0;
}
