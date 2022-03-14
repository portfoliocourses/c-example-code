/*******************************************************************************
*
* Program: Build Your Own strcpy() String Copy Function
* 
* Description: Demonstration of how to build our own strcpy() function for 
* copying a string in C, using two different approaches: one based on using a 
* loop and counter variable, and another using a loop and pointer arithemetic.
*
* YouTube Lesson: https://www.youtube.com/watch?v=ct5J8pm_33g 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

char *str_cpy1(char *destination, const char *source);
char *str_cpy2(char *destination, const char *source);

int main()
{
  // create a test source string and test destination char array
  char src[] = "copy this";
  char dest[100];
  
  // test the 2nd version of our str_cpy function, we could replace 2 with 1 
  // in the below statement to test the 1st version
  char *dest_ptr = str_cpy2(dest, src);
  
  // check that the dest char array contains the string in src, dest_ptr should
  // also be a pointer to this same dest char array and should therefore 
  // output the same string and have the same memory address as dest
  printf("     src: %s\n", src);
  printf("    dest: %s\n", dest);
  printf("dest_ptr: %s\n", dest_ptr);
  printf("    dest: %p\n", dest);
  printf("dest_ptr: %p\n", dest);
  
  return 0;
}

// Copy the string contained in source to destination, and return a pointer to 
// destination.  In this version of the function we use a loop and counter 
// variable to help copy each character.
char *str_cpy1(char *destination, const char *source)
{
  // if destination is NULL we can't copy to the address, likely something has 
  // gone wrong perhaps in allocating space for destination, so we just retunr
  // NULL in this case
  if (destination == NULL) return NULL;
  
  // use counter variable i to keep track of our index into the destination
  // and source character arrays, start at first index
  int i = 0;

  // copy characters until we encounter the null terminator in the source string
  // which signifies the end of the string
  while (source[i] != '\0')
  {
    // copy the character at index i from the source string to index i in the 
    // destination character array
    destination[i] = source[i];

    // increment i so that the next iteration of the loop looks at and 
    // potentially copies the next character in the source
    i++;
  }
  
  // append a null terminator onto the destination char array to properly 
  // end the string
  destination[i] = '\0';
  
  // return the pointer to the destination string.

  return destination;
}

// Copy the string contained in source to destination, and return a pointer to 
// destination.  In this version of the function we de-reference the pointers to
// the string and use pointer arithemetic to perform the copy.
char *str_cpy2(char *destination, const char *source)
{
  // again if the destination is NULL, we can't make the copy and so return NULL
  if (destination == NULL) return NULL;

  // We're going to manipulate the destination pointer, which right now, points 
  // to the first char in the char array in memory.  We want to return a pointer
  // to this first char in memory, and therefore we need to store it to return
  // it later given destination itself will be modified.
  char *return_ptr = destination;
  
  // when the char that source points at is the null terminator, stop copying
  // characters from source to destination
  while (*source != '\0')
  {
    // copy the char source is currently pointing to to the index in the 
    // destination char array that destination is currently pointing to
    *destination = *source;

    // Use pointer arithemetic to advance the destination and source pointers
    // to the next char in memory.  At the start of the function's execution 
    // destination and source are both pointers to the first element in char 
    // arrays in memory, by advancing the pointer one position, we have them 
    // point to the *next* char in each char array in memory, allowing us 
    // to perform a copy of the next char in the next iteration of the loop.
    destination++;
    source++;
  }

  // add the null terminator on to the end of the destination char array in 
  // order to make it a proper string
  *destination = '\0';
  
  // return the original destination pointer that we stored into return_ptr 
  // before modifying destination, that way we return a pointer to the complete
  // destination string (right now, destination is pointing to the null 
  // terminator that terminates the string)
  return return_ptr;
}