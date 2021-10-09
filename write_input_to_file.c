/*******************************************************************************
*
* Program: Write Input To File
* 
* Description: Example of writing lines of user input to a file in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=HEEzZ7fA9Oo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

int main()
{
  char buffer[BUFFER_SIZE];
  bool keep_going = true;
  FILE *fh;
  
  // open the file
  fh = fopen("output.txt", "w");

  // if the file didn't open successfully, exit with an error message
  if (fh == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  
  // keep reading lines of input until the user enters 'quit'
  while (keep_going)
  {
    // read a line of input into the buffer
    fgets(buffer, BUFFER_SIZE, stdin);
    
    // if the user entered quit, stop, otherwise output the line to the file
    if (strcmp(buffer, "quit\n") == 0)
      keep_going = false;
    else fputs(buffer, fh);
  }

  // close the file
  fclose(fh);

  return 0;
}
