/*******************************************************************************
*
* Program: Count The Lines In A File
* 
* Description: Example of counting the number of lines in a file with C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=AAF207cxbXk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main()
{
  // file pointer variable for accessing the file
  FILE *file;

  // stores the filename the user enters
  char filename[1024];

  // prompt the user to enter a filename, store it into filename
  printf("Enter File: ");
  scanf("%s", filename);
  
  // open the file with the given filename in read mode
  file = fopen(filename, "r");

  // if there was an issue opening the file, notify the user and exit with an 
  // error status
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  // c will store each char in the file as we read them in one at a time, 
  // current_line will store the running tally of how many lines we've found
  int current_line = 1;
  char c;
  do 
  {
    // read the next character from the file
    c = fgetc(file);

    // if it's a newline, we've found another line
    if (c == '\n') current_line++;
  
  // continue until the special end of file value is returned from fgetc
  } while (c != EOF);
  
  // close the file since we are done with it
  fclose(file);
  
  // print out the number of lines found
  printf("lines: %d\n", current_line);

  return 0;
}
