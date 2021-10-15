/*******************************************************************************
*
* Program: Append User Input To File 
* 
* Description: Example of appending user input to a file in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=ABYpwVjuDN0 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE 1024

int main()
{
  FILE *file;
  char buffer[MAX_LINE];
  
  // open up file.txt in APPEND mode, any data we write to the file will be 
  // appended to the existing content of the file
  file = fopen("file.txt", "a");
  
  // exit if there is an error opening the file
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  
  // continually accept lines of user input until the user enters quit
  printf("Enter 'quit' to exit.\n");
  do 
  {
    // read a line of input from the terminal (stdin) and store it into buffer
    fgets(buffer, MAX_LINE, stdin);

    // when the user enters quit, stop
    if (strcmp(buffer, "quit\n") == 0)
      break;

    // write the buffer to the file
    fputs(buffer, file);

  // accept input indefinitely
  } while (true);

  // close the file handle when we are done with it
  fclose(file);

  return 0;
}