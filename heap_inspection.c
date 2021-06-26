/*******************************************************************************
*
* Program: Heap inspection vulnerability
* 
* Description: An example demonstrating how the heap inspection vulnerability 
* can occur with dynamic memory allocation in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=hHlE2BpxjKU
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // two pointers for storing memory addresses
  char *password;
  char *other_ptr;
  
  // dynamically allocate space on the heap to store a short password, ask the 
  // user to input a password, and store the password at this space
  password = malloc(10 * sizeof(char));
  printf("\nTrustworthy Program\n\n");
  printf("Enter your password: ");
  scanf("%s", password);

  // have the other_ptr store the memory address where the password is stored
  other_ptr = password;

  // Free the space where the password is stored in memory... but IMPORTANTLY, 
  // this only means that the space is free to be re-allocated and used again, 
  // it does NOT mean the space is made "empty" or "cleared"... i.e the 
  // password we stored is STILL there!
  free(password);

  // print out characters stored at other_ptr and onward & we see our password!
  for (int i = 0; i < 10; i++)
    printf("%c", other_ptr[i]);
  printf("\n");

  return 0;
}