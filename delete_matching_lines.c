/*******************************************************************************
*
* Program: Delete All File Lines That Match A String 
* 
* Description: Example of deleting all lines from a file that match a string 
* using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Zn_YyKpE2AE 
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

// our program will work by writing all of the original file content to a 
// temp file EXCEPT for lines that match the string we want to delete, and 
// then we'll delete the original file and rename the temp file to the original 
// file name
int main()
{
  // store the filename and temp filename
  char filename[FILENAME_SIZE];
  char temp_filename[FILENAME_SIZE];

  // will store each line in the file, and the string of lines to delete
  char delete_line[MAX_LINE];
  char buffer[MAX_LINE];

  // file handles for the original file and temp file
  FILE *file, *temp;

  // have the user enter the filename, store it into the filename char array
  // the string will contain a newline character at the end, replace it with
  // the null terminator to end the filename one character earlier as files 
  // do not end with newlines
  printf("File: ");
  fgets(filename, FILENAME_SIZE, stdin);
  filename[strlen(filename) - 1] = '\0';

  // creates a temp filename "temp___filename.txt" where filename.txt is the 
  // name of the file entered by the user by first copying the prefix temp____
  // to temp_filename and then appending the original filename
  strcpy(temp_filename, "temp____");
  strcat(temp_filename, filename);

  // have the user enter the string for which lines should be deleted, and store
  // it into delete_line
  printf("Delete Line: ");
  fgets(delete_line, MAX_LINE, stdin);

  // open the original file for reading and the temp file for writing
  file = fopen(filename, "r");
  temp = fopen(temp_filename, "w");

  // if there was a problem opening either file let the user know what the error
  // was and exit with a non-zero error status
  if (file == NULL || temp == NULL)
  {
    printf("Error opening file(s).\n");
    return 1;
  }

  bool keep_reading = true;
  do {

    // stores the next line from the file into the buffer    
    fgets(buffer, MAX_LINE, file);

    // if we've reached the end of the file, stop reading from the file, 
    // otherwise so long as the current line does NOT match the string 
    // we want to delete, write the line to the temp file
    if (feof(file)) keep_reading = false;
    else if (strcmp(buffer, delete_line) != 0)
      fputs(buffer, temp);

  } while (keep_reading);

  // close our access to the files
  fclose(file);
  fclose(temp);

  // delete the original file, give the temp file the name of the original file
  remove(filename);
  rename(temp_filename, filename);

  return 0;
}