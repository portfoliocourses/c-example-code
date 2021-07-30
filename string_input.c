/*******************************************************************************
*
* Program: Reading user input strings with spaces
* 
* Description: Examples of how to accept user input strings with spaces in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=f8589Y9LHHg 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  // buffer will store our string
  char buffer[100];

  printf("Enter: ");
  
  // Approach #1 utilizes pattern matching to accept a string
  //
  // scanf("%[^\n]%*c", buffer);
  // printf("Buffer: %s\n", buffer);

  // Approach #2 utilizes fgets to accept a string, but instead of a file as 
  // "normal", we use stdin to read in the data (standard input, which is 
  // normally going to be the terminal).
  //
  // fgets(buffer, 100, stdin);

  // Approach #3 reads in one character at a time with getchar() until a 
  // newline character is encountered
  //
  char c;
  int i = 0;
  while (  (c = getchar()) != '\n' ) buffer[i++] = c;
  buffer[i] = '\0';

  // Output the string stored in the buffer
  printf("Buffer: %s\n", buffer);

  return 0;
}


