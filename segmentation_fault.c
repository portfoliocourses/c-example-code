/*******************************************************************************
*
* Program: Segmentation Faults And Common Causes
*
* Description: Examples of common causes of segmentation faults in C.  See the
* Wikipedia article on segmentation faults:
*   https://en.wikipedia.org/wiki/Segmentation_fault
*
* YouTube Lesson: https://www.youtube.com/watch?v=T91q6ZngBk4  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// A function which calls itself 'forever', i.e. infinite recursion
void function()
{
  function();
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // A segmentation fault error occurs at runtime when a program accesses or 
  // tries to modify memory that it is not allowed to access or modify.  The 
  // fault is detected by hardware with memory protection and reported to the
  // operating system.  Examples of some common causes of segmentation faults 
  // are provided below, but notably these issues will not necessarily cause 
  // a segmentation fault and there are other issues which may cause 
  // segmentation faults.
  //

  // Declare an array of length 4 and initialize it with 4 int values
  int data[4] = {1,2,3,4};

  // We can safely access values in the range of indexes of the array
  printf("%d\n", data[2];)

  // But accessing values far outside this range may cause a segmentation fault
  //
  // printf("%d\n", data[1000000]);
  
  // A compiler would warn us about the above issue because it can be detected
  // at compilation time, but what if the index accessed was determined at 
  // runtime from user input as below?  In this case we may need to use a 
  // debugger or logging or another technique to identify the line of code 
  // where the segmentation fault occurs.  
  //
  int index = 0;
  printf("Index: ");
  scanf("%d", &index);
  printf("%d\n", data[index]);

  
  // A function which calls itself 'forever', i.e. infinite recursion, can also
  // cause a segmentation fault due to stack overflow.  Each time the function
  // calls itself information is added to a data structure called a call stack,
  // and once this data structure fills beyond capacity it can result in 
  // a segmentation fault.
  //
  // function();

  // An uninitialized pointer variable is called a wild pointer, this can also 
  // be a source of segmentation fault errors if we try to de-reference the 
  // pointer.
  //
  // int *p;
   
  // NULL is a special value which essentially means "pointer to nothing", if we
  // de-reference a pointer variable that is set to NULL we can also have a
  // segmentation fault.
  //
  // int *p = NULL;
  

  // When we free a pointer variable that points to dynamically allocated memory
  // the pointer variable will still contain the memory address of the
  // previously allocated and valid memory.  This is called a dangling pointer.
  // If we try to de-reference a dangling pointer this can also cause a 
  // segmentation fault.  
  //
  // Here malloc() allocates a block of memory large enough to store one int 
  // value, and the memory address for that block of memory is returned and 
  // stored into p.  When we free p, the block of memory is freed so it can 
  // potentially be used again, but p still stores the memory address that 
  // malloc() returned originally even though this block of memory is not 
  // allocated and valid to use anymore!
  //
  int x = 5;
  int *p = malloc(sizeof(int));
  // do some work with the block of memory 
  free(p);  

  // De-referencing the pointer p to access/use 'what it points to'.
  //
  // printf("%d\n", *p);  

  return 0;
}