/*******************************************************************************
*
* Program: Replace A Specific Line In A File
* 
* Description: Replaces a specific line of text in a file in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=JKR0S84xLJ4 
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

// our program works by writing all the lines of the original file to a temp 
// file EXCEPT the line we want to replace, which we instead write a 
// replacement line for in its place, and then we delete the original file 
// and rename the temp file to the original file's name
int main()
{
  // file pointers for the original file and temp file
  FILE *file, *temp;

  // store the filename and temp filename
  char filename[FILENAME_SIZE];
  char temp_filename[FILENAME_SIZE];
  
  // buffer will store each line from the original file
  char buffer[MAX_LINE];

  // replace will store the line of replacement text
  char replace[MAX_LINE];

  // replace_line will store the line number we wish to replace
  int replace_line = 0;
  
  // ask the user to enter the filename, store it into filename
  printf("File: ");
  scanf("%s", filename);

  // we'll make a temp file with "temp__filename" format
  strcpy(temp_filename, "temp____");
  strcat(temp_filename, filename);
  
  // ask the user for the line number to replace, store it into replace_line
  printf("Replace Line Number: ");
  scanf("%d", &replace_line);
  
  // flush stdin to get the \n char from the last scanf out, otherwise the 
  // below fgets will 'fail' as it will immediately encounter a newline
  fflush(stdin);
  
  // ask the user for the replacement line of text, store it into replace
  printf("New Line: ");
  fgets(replace, MAX_LINE, stdin);
  
  // open the original file for reading, and the temp file for writing
  file = fopen(filename, "r");
  temp = fopen(temp_filename, "w");
  
  // check if either file failed to open, if either did exit with error status
  if (file == NULL || temp == NULL)
  {
    printf("Error opening files(s).\n");
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
    // if the line we've reached is the one we wish to replace, write the 
    // replacement text to this line of the temp file
    else if (current_line == replace_line)
      fputs(replace, temp);
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