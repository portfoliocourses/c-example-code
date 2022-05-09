/*******************************************************************************
*
* Program: Why Not To Use gets()
* 
* Description: The function gets() is unsafe to use in C due to buffer overflow
* issues, instead we should use fgets().  This program demonstrates why we 
* should not use gets().
*
* YouTube Lesson: https://www.youtube.com/watch?v=WXnWoRJ7WyU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Dynamically allocate two char arrays on the heap able to store 5 chars.
  // It is not at all guaranteed to be this way, but because all this program
  // does is allocate two char arrays on the heap, on at least some systems
  // (compilers/etc.) the blocks of memory will likely be next to each other 
  // on the heap with 'next' following 'buffer'.
  //
  char *buffer = malloc(sizeof(char) * 5);
  char *next = malloc(sizeof(char) * 5);

  // prompt the user to enter a string 
  printf("Enter: ");

  // We can use gets() to read a string from standard input, chars from 
  // standard input will be read and stored into buffer until the first newline
  // char or EOF is reached.  A newline character will be placed at the end 
  // of the chars to terminate the string as well.  The problem is that gets()
  // can cause a buffer overflow issue if buffer is not large enough to hold 
  // the data read from standard input.  The gets() function will just continue 
  // to write chars in memory adddresses beyond the end of the buffer array's 
  // block of memory.  If we enter a lengthy string, we may even see the chars 
  // when we print out the next char array!  When buffer overflow occurs like 
  // this it makes our program error prone and insecure as the program is 
  // writing to memory that it should not be.
  // 
  gets(buffer);

  // The fgets() function can be used to read data from standard input if we 
  // use stdin as the 3rd argument.  As with gets() chars from standard input 
  // will be read and stored into buffer until the first newline char or EOF 
  // occurs.  But unlike gets() the 2nd argument specifies the maximum length 
  // of the buffer... so a maximum of 4 chars will be read from standard input 
  // in the case of the below function call (because the null terminator also 
  // needs to be placed at the end of buffer to end the string).  This prevents
  // buffer overflow from occuring making fgets() safer to use.  Comment out 
  // the above call to gets() and uncomment the below fgets() function call 
  // to test it out.
  //
  // fgets(buffer, 5, stdin);

  // If we enter a string like "abcdef" when running this program on the 
  // terminal, the above call to fgets() will store 'abcd\0' into the buffer,
  // and the cars "ef\n" will be left in standard input (the \n newline char 
  // occurs after hitting enter).  If we call fgets again we can read these 
  // chars into next... notably the program will not pause for user input in 
  // this case as chars (including a newline to terminate the input) are already
  // waiting to be read from standard input.
  //
  // fgets(next, 5, stdin);
  
  // print out the buffer and next char arrays
  printf("String: %s\n", buffer);
  printf("Next: %s\n", next);
  
  // free the dynamically allocated memory
  free(buffer);
  free(next);

  return 0;
}