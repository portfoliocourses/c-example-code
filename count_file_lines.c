/*******************************************************************************
*
* Program: Count The Lines In A File
* 
* Description: Example of counting the number of lines in a file with C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=kbPEydfeOG4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  // file pointer variable for accessing the file
  FILE *file;

  // open the file called file.txt in "read mode" so we can read from the file
  file = fopen("file.txt", "r");

  // if there was an issue opening the file, notify the user and exit with an 
  // error status
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  
  // c will store each char in the file as we read them in one at a time, lines
  // will store the running tally of how many lines we've encountered
  char c;
  int lines = 0;

  // read in each char one at a time from the file and store it into c, once 
  // fgetc() returns EOF for 'end of file' we stop, but so long as c is not 
  // EOF we check if it is equal to the newline character and increment our 
  // running tally of lines each time
  while ((c = fgetc(file)) != EOF)
    if (c == '\n') lines++;

  // output the number of lines in the file
  printf("Lines: %d\n", lines);

  return 0;
}