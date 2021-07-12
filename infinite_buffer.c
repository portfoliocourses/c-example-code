/*******************************************************************************
*
* Program: Infinite buffer
* 
* Description: An example of an "infinite input buffer" in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=qwM_c3gF2lw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 5

int main(void)
{
  // A traditional input buffer with a fixed length.
  // But what if we don't know the size of the input in advance?  We could 
  // either make a very large buffer to accommodate large inputs, or we could
  // use dynamic memory allocation and realloc to increase the size of our
  // buffer (see below).
  /*
  int buffer[BUFFER_SIZE];

  for (int i = 0; i < BUFFER_SIZE; i++)
  {
    printf("Enter: ");
    scanf("%d", &buffer[i]);
  }

  // compute the average, print out the data in the buffer
  int total = 0;
  for (int i = 0; i < BUFFER_SIZE; i++)
  {
    printf("buffer[%d]=%d\n", i, buffer[i]);
    total += buffer[i];
  }
  printf("Average: %d\n", total / BUFFER_SIZE);
  */

  // Infinite buffer will grow as required to store an unknown amount of input!
  // Of course the buffer is not truly "infinite" as eventually our computer 
  // will run out of memory, but we'll call it infinite because it's more fun.

  // start with a small buffer size of 2 and allocate space for it on the heap
  int size = 2;
  int *buffer = malloc(sizeof(int) * size);

  // accept input indefinitely from the user (i.e. input of unknown length)
  int input = 0;
  int num_data = 0;
  while (true)
  {
    // if the number of data inputs equals the size of the buffer, use realloc
    // to increase the size of the buffer (double it each time)
    if (num_data == size)
    {
      size *= 2;
      buffer = realloc(buffer, sizeof(int) * size);
      printf("Buffer size: %d\n", size);
    }
    
    // ask the user for input, store it in the buffer or break if time to quit
    printf("Enter (-1 to quit): ");
    scanf("%d", &input);
    if (input == -1) break;
    else buffer[num_data] = input;
    
    // num_data keeps track of how much actual data is in the buffer
    num_data++;
  }

  // compute the average, output the data in the buffer
  int total = 0;
  for (int i = 0; i < num_data; i++)
  {
    printf("buffer[%d]=%d\n", i, buffer[i]);
    total += buffer[i];
  }
  printf("Average: %d\n", total / num_data);

  // notice how the buffer size increases depending on how many numbers we 
  // input, with num_data keeping track of the actual amount of data in the 
  // buffer
  printf("Num data: %d\n", num_data);
  printf("Buffer size: %d\n", size);

  return 0;
}
