/*******************************************************************************
*
* Program: Resize An Array
* 
* Description: Example of resizing a dynamically allocated array with realloc()
* using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=tz0-w62wOoU  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // A statically allocated array (i.e. static array) like this cannot be 
  // resized, it will always have the length of 1000.  If we have a program 
  // that needs some varying number of int values as determined at runtime, 
  // one thing we could do is declare the array to have the maximum possible 
  // length required for this problem.  We could refer to this as the "capacity"
  // of the array, while maintaining a separate concept of the "length" or 
  // "size" of the array (i.e. how much of the array are we actually using).
  //
  // We could then have logic which ensures that we do not exceed the array 
  // capacity, while other logic could depend on the length of the array 
  // to do things like access the elements in the portion of the array 
  // that we are actually using.  So while the array's max capacity could be 
  // 1000, maybe at runtime we determine that we only need 200 elements, and 
  // so we have loops that depend on this length of 200.  This length could 
  // change as the program executes and we need to use more or less int values.
  //
  // This would be one workaround solution to the fact that we cannot resize 
  // a statically allocated array.  It would mean that we have unused memory, 
  // but maybe we are OK with this.  Note that a statically allocated array 
  // is stored in a place in memory called the stack.
  //
  // int array[1000];
  // int capacity = 1000;  <--- keeps track of the capacity of the array
  // int length = ...;     <--- tracks the length used, determined at runtime
  //
  // if (exceed capacity)  <--- code to ensure we do not exceed array capacity
  // {
  //   error message
  // }
  //
  // for (int i = 0; i < length; i++)  <-- logic to work with the portion of the
  // {                                     array which is practically used, e.g.
  //   ... array[i] ...                    accessing all the elements in this 
  // }                                     portion and doing some work with them
  //
  

  // We CAN resize a dynamically allocated array, which is stored in a different
  // place in memory called the heap.  We have to use a function like malloc() 
  // or calloc() to allocate a block of space in memory.  Here we call malloc() 
  // and pass it 3 x the size in bytes that it takes to store an int [as provided 
  // by size()], so that it allocates a block of memory with enough bytes to 
  // store 3 int values.  We keep track of the size of the array using length.
  // The call to malloc() returns a pointer, i.e. a memory address for this 
  // block of memory, which we store into data.
  //
  int length = 3;
  int *data = malloc(length * sizeof(int));
  
  // We can use array notation with data to set the elements of the array.
  data[0] = 4;
  data[1] = 5;
  data[2] = 6;
  
  // If later on the program determines it needs a larger array, we can increase
  // length which tracks the array size, and then call realloc().  The call to 
  // realloc() will reallocate the block of memory, we pass it the memory 
  // address of the existing block of memory as well as the size in bytes needed
  // for the reallocated block of memory.  realloc() will return the pointer 
  // (memory address) for the reallocated block of memory.
  // 
  // If there is enough unused space in memory next to the existing block of 
  // memory then realloc() can just increase the size of this block of memory 
  // and return the same pointer (memory address) as before.  But if there 
  // isn't realloc() will find another place in memory and return a pointer 
  // for that new address in memory.  In this case, realloc() will also copy 
  // the existing data from the old location in memory to the new location 
  // in memory.
  //
  // In the below solution to keep things simple we just store the returned 
  // pointer back into data, so that before and after the call to realloc(),
  // even if the block is moved, data will point to the block of memory.  But
  // note that realloc() could fail and if it does it will return NULL (i.e. 
  // a pointer to nothing).  This would then cause a memory leak when we 
  // overwrite the original memory address stored in data with NULL, and we 
  // lose access to the original block of memory.  So really we should use 
  // a temporary pointer variable in this situation to safely handle realloc()
  // failure as covered here: https://www.youtube.com/watch?v=skqCnhhA0ZY
  //
  length += 2;
  data = realloc(data, length * sizeof(int));
 
  // Set the additional two elements in the array to these values
  data[3] = 7;
  data[4] = 8;

  // Loop through and output the data in the array
  for (int i = 0; i < length; i++)
  {
    printf("data[%d] = %d\n", i, data[i]);
  }
  
  // Free the dynamically allocated memory.  We do this to avoid a memory leak
  // and so our program could potentially use this memory again.
  free(data);
  
  return 0;
}