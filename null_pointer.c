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

struct node
{
  int value;
  struct node *next;
};

int main(void)
{
  int *ptr = NULL;

  printf("ptr: %p\n", ptr);

  ptr = malloc(sizeof(int));

  if (ptr != NULL)
  {
    *ptr = 5;
    printf("*ptr: %d\n", *ptr);
  }
  else
   printf("Error: ptr is NULL!\n");

  printf("\nbefore free:\n%p\n", ptr);

  free(ptr);

  ptr = NULL;

  printf("\nafter free:\n%p\n", ptr);

  // n1 -> n2 -> n3
  struct node n1, n2, n3;

  n1.value = 5;
  n1.next = &n2;

  n2.value = 6;
  n2.next = &n3;

  n3.value = 7;
  n3.next = NULL;

  struct node *traverse = &n1;

  printf("\n\nLinked List: ");

  while (traverse != NULL)
  {
    printf("%d ", traverse->value);
    traverse = traverse->next;
  }

  printf("\n");

  int *array = malloc(sizeof(int) * 10);

  printf("\nbefore array:\n%p\n", array);

  array = realloc(NULL, sizeof(int) * 11);

  printf("\nafter array:\n%p\n", array);

  printf("sizeof(NULL): %zu\n", sizeof(NULL));
  printf("sizeof(int*): %zu\n", sizeof(int*));

  char *char_pointer = NULL;
  int *int_pointer = NULL;

  if (char_pointer == int_pointer)
    printf("NULL pointers equal\n");

  return 0;
}