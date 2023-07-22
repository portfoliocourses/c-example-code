/*******************************************************************************
*
* Program: strnlen() Function (POSIX Library)
* 
* Description: Example of using the strnlen() function in C.  This function is 
* not available in all C compilers as it is not part of standard C, it is 
* available in the POSIX library: https://en.wikipedia.org/wiki/C_POSIX_library
*
* YouTube Lesson: https://www.youtube.com/watch?v=iuA0A9JXIhY
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
  // declare a char array called string of length 5
  char string[5];
  
  // A string in C is a sequence of characters in memory terminated by a 
  // null terminated, so here we have the characters 'a', 'b' and 'c' in 
  // sequence...
  string[0] = 'a';
  string[1] = 'b';
  string[2] = 'c';
  
  // And normally a string is terminated with a null terminated like this to 
  // signify the end of string...
  //  string[3] = '\0';

  // But in C we can have a bug if the null terminator is somehow not present, 
  // e.g. if the data is given to our program by an external source that does 
  // not include the null terminator every time or if we forget to include it.
  // Here to simulate this bug we intentionally leave out the the null 
  // terminator and instead we write 3 'E' characters.  Notably we even write
  // an 'E' character one index beyond the end of the char array, which we 
  // should not do but this is the sort of bug that can occur in C.
  string[3] = 'E';
  string[4] = 'E';
  string[5] = 'E'; 

  // The string length function depends on having a proper null terminated 
  // string to function correctly.  If the null terminator is not present at 
  // the end of the string, the function will keep checking the next character
  // in memory until one is found.  This can lead to the function returning an 
  // incorrect length (as it counts each character read until the null 
  // terminator is found to determine the length).  It can also lead to the 
  // program crashing when the function accesses memory that it should not.
  //         
  // int length = strlen(string);

  // The strnlen() function is a "safer" version of strlen() that is found in 
  // the C POSIX Library.  The strlen() function is part of standard C and so 
  // will be supported by all compilers, but strnlen() will not be.  The 
  // strnlen() function accepts an additional maximum length argument.  The 
  // function will return the length of the string UP TO the maximum length.
  // So if the string has a length less than the maximum length, due to the 
  // null terminator being found in the string at an index less than the 
  // maximum length, then this length will be returned.  Otherwise the  
  // maximum length will be returned.
  //
  // This means if we pass the length of the buffer (i.e. char array) as the 
  // 2nd argument, the strnlen() function is guaranteed to return a length 
  // not exceeded that buffer, and it won't access memory that doesn't belong
  // to the buffer while looking for the null terminator.  This makes the 
  // function "safer" than strlen().
  //
  int length = strnlen(string, 5); 
 
  printf("length: %d\n", length);


  // The strnlen() function actually has the return type size_t and the type
  // of the maximum length 2nd parameter is also size_t, where size_t can 
  // store very large non-negative integers.  We could use %zu to output a 
  // value of type size_t.
  //
  // size_t length = strnlen(string, 5);
  //
  // printf("length: %zu\n", length);

  return 0;
}