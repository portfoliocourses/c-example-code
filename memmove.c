/*******************************************************************************
*
* Program: memmove() Function
* 
* Description: Example of using the memmove() function in C.  The memmove() 
* function allows us to copy a block of data from one location in memory to 
* another. 
*
* YouTube Lesson: https://www.youtube.com/watch?v=DGwdAQauEV4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
  // create a test source array (i.e. a block of memory of 10 ints from 1...10)
  int source[10] = {1,2,3,4,5,6,7,8,9,10};

  // create a test destination array (i.e. a block of memory 10 ints in size)
  int destination[10];
  
  // Use memmove() to copy 10 ints from the source to the destination.  When 
  // we pass 'destination' and 'source' like this, they 'decay to a pointer', 
  // and what we're REALLY passing is the memory addresses of destination 
  // and source (the memory address of the first element in the arrays).  For 
  // the 3rd argument we supply the number of bytes to copy from the source 
  // to the destination... sizeof(int) gives us the size in bytes of an int 
  // value, and we multiply this by 10 to copy all 10 ints from the source to 
  // the destination.
  memmove(destination, source, sizeof(int) * 10);
   
  // Note that memcpy() will ALSO copy a block of memory from source to 
  // destination.  We could comment out the above function call, and uncomment 
  // this function call, and we'll get the same result!
  // memcpy(destination, source, sizeof(int) * 10);
  
  // The behaviour of memcpy() is undefined when the source and destination 
  // blocks of memory overlap, which means it may or may not work.  This is 
  // why we would use memmove() instead of memcpy(), as memmove() will 
  // safely perform the copy even if the blocks of memory overlap.  If we're 
  // not sure if the blocks of memory will overlap or not, we should use 
  // memmove() as it will be safe.  If we're sure they will not overlap we 
  // should use memcpy() as its performance may be higher.  In the below 
  // function call we attempt to copy 8 ints from source (i.e. the 
  // beginning of the array) to 'source+2', i.e. the source array from 
  // index 2 (the 3rd element) onwards. 
  //
  // memmove(source+2, source, sizeof(int) * 8);
  
  // Output the destination array to verify the copy was successful
  for (int i = 0; i < 10; i++)
    printf("destination[%d]=%d\n", i, destination[i]);
  
  // Note that the data is COPIED from source to destination, the data in the 
  // source is not somehow removed (the word 'move' might give this impression).
  // We can print out the source array to verify this. 
  for (int i = 0; i < 10; i++)
    printf("source[%d]=%d\n", i, source[i]);
  
  return 0;
}