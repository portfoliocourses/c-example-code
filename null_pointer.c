/*******************************************************************************
*
* Program: NULL Pointer Demonstration
*
* Description: A explanation of what is a NULL pointer, including some common
* use cases of the NULL pointer.
*
* YouTube Lesson: https://www.youtube.com/watch?v=n_e0y4a8IMg
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// The value NULL is used to represent a "pointer to nothing", i.e. a pointer
// that does not point to any actual valid memory address.
//
// In C99 onwards NULL is defined as ((void *) 0)
//
// i.e. 0 converted to a void pointer
//
// NULL == 0 must evaluate to true
//
// BUT NULL can technically be represented with any bit pattern, it doesn't
// have to be all zeros!

#include <stdio.h>
#include <stdlib.h>

// Declare a struct which can be used to create a linked list data structure:
//   https://en.wikipedia.org/wiki/Linked_list
//
// Each node in the linked list will store a value and a pointer to the next
// node in the list.  The last node in the chain will store the NULL value
// instead of a pointer to the next node... this is a common use case for
// NULL within data structures such as linked lists (i.e. indicating an
// 'end point').
//
struct node
{
  int value;
  struct node *next;
};

int main(void)
{

  // BEST PRACTICE: Initialize a pointer to NULL

  // If we declare a pointer variable like this, it will store whatever value
  // happens to be in memory at the time it is declared.  This is a problem
  // because the pointer could be pointing to memory that our program doesn't
  // actually "own".
  //
  // int *ptr;

  // If we're not going to initialize the pointer variable right away to a valid
  // memory address, we should initialize it to NULL as NULL means that the
  // pointer "points to nothing".  It's an explicit way of setting the pointer
  // to point to nothing initially.  We can check for NULL before working
  // with a pointer value to understand whether it points to nothing or a valid
  // memory address instead (i.e. is the pointer ready to be worked with, or
  // do we perhaps need to allocate memory or something).
  int *ptr = NULL;

  // If we output the pointer value we'll most likely see it is set to 0x0
  // once we have set it to NULL.  NULL is virtually always "0" but as
  // noted above it's possible to represent it with a non-zero bit pattern.
  printf("ptr: %p\n", ptr);

  // One common use case of the value NULL is for it to be returned when a
  // function cannot allocate memory.  For example malloc() will attempt to
  // allocate a block of memory and return the memory address of that block
  // of memory, but if it fails it will return NULL.
  ptr = malloc(sizeof(int));

  // If instead of the above attempt to allocate space for one int we try
  // to allocate space for many, many ints it is possible malloc() will
  // fail and return NULL instead of a valid memory address.
  //
  // ptr = malloc(sizeof(int) * 1000000000000000);

  // We can CHECK the pointer variable to see if it doesn't equal NULL before
  // working with it as if it is a valid memory address!
  if (ptr != NULL)
  {
    // Dereference the pointer to set a value and output the value
    *ptr = 5;
    printf("*ptr: %d\n", *ptr);
  }
  // if the pointer DOES equal NULL we can then handle it however we like...
  else
   printf("Error: ptr is NULL!\n");



  // BEST PRACTICE: set a free'd pointer variable to NULL

  // Notably calling free() does not set a pointer to NULL, let's output
  // ptr before calling free()
  printf("\nbefore free:\n%p\n", ptr);

  // Calling free() will only free the block of memory that was allocated,
  // it will not modify the memory address that is stored by ptr.  This is a
  // problem because then ptr would be pointing to memory that our program
  // does not "own" anymore.  We call this situation a dangling pointer:
  // https://en.wikipedia.org/wiki/Dangling_pointer
  free(ptr);

  // As a best practice if we intend to re-use a pointer variable after calling
  // free we should set the pointer variable to NULL to make it clear that the
  // pointer no longer points to valid memory.
  ptr = NULL;

  // If we were to comment out the line above, we would notice that ptr still
  // stores the same memory address as it did BEFORE calling free(), i.e. we
  // we would have a dangling pointer.
  printf("\nafter free:\n%p\n", ptr);



  // COMMON USE CASE: Data Struture "End Points"

  // Let's use our struct node above to create a basic linked list data
  // structure, with node n1 linked to node n2 which is linked to the last
  // node in the chain n3.
  //
  // n1 -> n2 -> n3

  // Declare the 3 struct node variables
  struct node n1, n2, n3;

  // Set n1's value to 5 and link it to n1 by having its next member store
  // the memory address of n2.
  n1.value = 5;
  n1.next = &n2;

  // Set n2's value to 6 and link it to n3 by having its next member store
  // the memory address of n3.
  n2.value = 6;
  n2.next = &n3;

  // Set n3's value to 7 and set it to be the LAST node in the chain by
  // settings its next member to NULL.
  n3.value = 7;
  n3.next = NULL;

  // We can traverse the linked list by using a pointer variable, we'll set
  // the struct node pointer variable traverse to initially point to the
  // first node in the above chain.
  struct node *traverse = &n1;

  // Now we can output the linked list...
  printf("\n\nLinked List: ");

  // So long as traverse is not yet equal to NULL we'll know we haven't yet
  // reached the end of the chain of nodes.
  while (traverse != NULL)
  {
    // Output the value stored in node that travserse is currently pointing to
    printf("%d ", traverse->value);

    // Set traverse to point to the NEXT node in the chain using the next
    // member of the node that traverse is currently pointing to.  When
    // traverse reaches the LAST node of the chain, its next member will be
    // set to NULL and the loop will stop!
    traverse = traverse->next;
  }

  // Output a newline
  printf("\n");



  // COMMON USE CASE: Special Function Behaviour When Passed As Argument

  // Some functions that expect a pointer as an argument when NULL is
  // passed to the function instead of a valid memory address.  For example
  // realloc() will dynamically allocate space for an all new block of
  // memory rather than try to reallocate space for an existing block of
  // memory when it is passed NULL as the first argument rather than a valid
  // memory address.

  // Dynamically allocate space for a block of memory to store 10 ints using
  // malloc()
  int *array = malloc(sizeof(int) * 10);

  // Output the value of array
  printf("\nbefore array:\n%p\n", array);

  // If we were to pass the memory address stored in array as the first
  // argument to realloc() it will attempt to enlarge the block of memory by
  // 1 int to store 11 ints.  It will attempt to enlarge the block of memory
  // at its existing location, meaning that the memory address returned by
  // realloc() will almost certainly be the same in the case of this
  // program (as a general rule, realloc may move the block of memory being
  // reallocated somewhere else entirely if for example it can't find more
  // space at the existing location in memory).
  //
  // array = realloc(array, sizeof(int) * 11);

  // If instad we pass realloc() NULL as its first argument it will allocate
  // space for a new block of memory entirely, the behaviour of the function
  // changes almost entirely as a result.
  array = realloc(NULL, sizeof(int) * 11);

  // Output the pointer after calling realloc() and we'll find it's set to
  // a new location in memory entirely.
  printf("\nafter array:\n%p\n", array);



  // The size in bytes that NULL takes up in memory will be equal to the size
  // of a pointer variable.  This can vary from one system and compiler to
  // the next, but something like 8 bytes would be typical.
  printf("sizeof(NULL): %zu\n", sizeof(NULL));
  printf("sizeof(int*): %zu\n", sizeof(int*));



  // NULL also has the property that if it is stored in pointer variables of
  // different types a check for equality between these variales will
  // return true.

  // Here we set char and int pointer variables to NULL
  char *char_pointer = NULL;
  int *int_pointer = NULL;

  // When we compare them for equality we will find out they ARE equal
  if (char_pointer == int_pointer)
    printf("NULL pointers equal\n");

  return 0;
}
