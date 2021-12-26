/*******************************************************************************
*
* Program: Read Specific Line
* 
* Description: Example of reading a specific line from a file in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=w0mgn6OLKUs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

// constants for size of char arrays to store filename, the line from the file
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

int main()
{
  // file pointer will be used to open/read the file
  FILE *file;

  // used to store the filename and each line from the file
  char filename[FILENAME_SIZE];
  char buffer[MAX_LINE];

  // stores the line number of the line the user wants to read from the file
  int read_line = 0;

  // prompt the user for the filename, store it into filename
  printf("File: ");
  scanf("%s", filename);

  // prompt the user for the line to read, store it into read_line
  printf("Read Line: ");
  scanf("%d", &read_line);

  // open the the file in read mode
  file = fopen(filename, "r");

  // if the file failed to open, exit with an error message and status
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  // we'll keep reading the file so long as keep_reading is true, and we'll 
  // keep track of the current line of the file using current_line
  bool keep_reading = true;
  int current_line = 1;
  do 
  {
    // read the next line from the file, store it into buffer
    fgets(buffer, MAX_LINE, file);

    // if we've reached the end of the file, we didn't find the line
    if (feof(file))
    {
      // stop reading from the file, and tell the user the number of lines in 
      // the file as well as the line number they were trying to read as the 
      // file is not large enough
      keep_reading = false;
      printf("File %d lines.\n", current_line-1);
      printf("Couldn't find line %d.\n", read_line);
    }
    // if we've found the line the user is looking for, print it out
    else if (current_line == read_line)
    {
      keep_reading = false;
      printf("Line:\n%s", buffer);
    }

    // continue to keep track of the current line we are reading
    current_line++;

  } while (keep_reading);

  // close our access to the file
  fclose(file);

  // notably at this point in the code, buffer will contain the line of the 
  // file we were looking for if it was found successfully, so it could be 
  // used for other purposes at this point as well...

  return 0;
}
