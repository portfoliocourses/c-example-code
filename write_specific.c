/*******************************************************************************
*
* Program: Write To A Specific Line In A File
* 
* Description: Write to a specific line in a file and shift down the remaining
* lines of the file using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=CskiW4kd6Kk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// set some generous maximum lengths for filename size and each line in a file
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

// Our program works by writing all the lines of the original file to a temp 
// file, except at the line where we wish to write a new line of text we first 
// write this new line of text to the temp file.  We then delete the original 
// file and rename the temp file to the name of the original file.
int main()
{
  // file pointers for the original file and temp file
  FILE *file, *temp;

  // store the filename and temp filename
  char filename[FILENAME_SIZE];
  char temp_filename[FILENAME_SIZE];

  // buffer will store each line from the original file
  char buffer[MAX_LINE];

  // newline will store the new line of text to be written to the file
  char newline[MAX_LINE];

  // write_line will store the line number where the new text is to be written
  int write_line = 0;

  // ask the user to enter the filename, store it into filename
  printf("File: ");
  scanf("%s", filename);
  
  // we'll make a temp file with "temp__filename" format
  strcpy(temp_filename, "temp____");
  strcat(temp_filename, filename);

  // ask the user for the line number to replace, store it into write_line
  printf("Line Number: ");
  scanf("%d", &write_line);

  // flush stdin to get the \n char from the last scanf out, otherwise the 
  // below fgets will 'fail' as it will immediately encounter a newline
  fflush(stdin);

  // ask the user for the new line of text, store it into newline
  printf("New Line: ");
  fgets(newline, MAX_LINE, stdin);

  // open the original file for reading, and the temp file for writing
  file = fopen(filename, "r");
  temp = fopen(temp_filename, "w");

  // check if either file failed to open, if either did exit with error status
  if (file == NULL || temp == NULL)
  {
    printf("Error opening file(s).\n");
    return 1;
  }

  // we'll keep reading the file so long as keep_reading is true
  bool keep_reading = true;

  // will keep track of the current line number we are reading from the file  
  int current_line = 1;

  do 
  {
    // read the next line of the file into the buffer    
    fgets(buffer, MAX_LINE, file);

    // if we've reached the end of the file, stop reading
    if (feof(file)) keep_reading = false;
    // if we've reached the line to write the new line of text, write the line 
    // of text to the temp file, followed by the line of text currently in the
    // original file at this line
    else if (current_line == write_line)
    {
      fputs(newline, temp);
      fputs(buffer, temp);
    }
    // otherwise write this line to the temp file    
    else fputs(buffer, temp);

    // increment the current line as we will now be reading the next line
    current_line++;

  } while (keep_reading);

  // close our access to both files as we are done with them
  fclose(file);
  fclose(temp);

  // delete the original file, rename temp file to the original file's name
  remove(filename);
  rename(temp_filename, filename);

  return 0;
}