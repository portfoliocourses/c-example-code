/*******************************************************************************
*
* Program: Delete All Lines From A File Containing A Char From A String
* 
* Description: A C program that deletes all lines from a file that contain one 
* or more chars from a group of chars.
*
* YouTube Lesson: https://www.youtube.com/watch?v=tDAxTQFZB28 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// constants for defining char array related to file size, reading file content
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

int main()
{
  // char arrays for storing the filename of the file to open, and a temporary
  // file the program will create
  char filename[FILENAME_SIZE];
  char temp_filename[FILENAME_SIZE];
  
  // delete_chars will store a string containing our special group of chars... 
  // any line containing one or more of these chars will be removed from the 
  // file
  char delete_chars[MAX_LINE];
  
  // char array used to read each line from the file
  char buffer[MAX_LINE];
  
  // file pointers for opening file and temporary file
  FILE *file, *temp;
  
  // Prompt the user for the file name, store it into the filename char array,
  // and then move forward the null terminator a single char so that the newline
  // char that ends the string (after the user hits enter) is replaced with the 
  // null terminator (ending the string one char earlier).
  printf("File: ");
  fgets(filename, FILENAME_SIZE, stdin);
  filename[strlen(filename) - 1] = '\0';
  
  // Construct the temporary file name as temp___filename.txt where filename.txt
  // is the name of the file entered by the user above.  First copy the string 
  // temp___ into the temp_filename char array, and then concatenate on the 
  // filename the user entered, in order to construct this temporary file name.
  strcpy(temp_filename, "temp____");
  strcat(temp_filename, filename);
  
  // Prompt the user for the group of chars for which we will delete the lines 
  // of the file if they contain one or more of these chars.  Store it into 
  // delete_chars, as with filename we remove the newline char at the end of 
  // the user input (after storing it into delete_chars char array) so that the 
  // newline character is not included in the group of chars.
  printf("Delete Chars: ");
  fgets(delete_chars, MAX_LINE, stdin);
  delete_chars[strlen(delete_chars) - 1] = '\0';
  
  // Open up the file for reading, and the temporary file for writing
  file = fopen(filename, "r");
  temp = fopen(temp_filename, "w");

  // If either file failed to open, exit with an error message and status.
  if (file == NULL || temp == NULL)
  {
    printf("Error opening file(s).\n");
    return 1;
  }
  
  // We solve this problem by writing every line from the original file to the 
  // temporary file EXCEPT lines that contain one or more chars from the group
  // of chars stored in delete_chars.  We'll then delete the original file and
  // rename the temporary file to the original file's name.  This loop will 
  // continue until we reach the end of the file (or an error occurs).
  bool keep_reading = true;
  do 
  {
    // Read in the next line of the file, store it into buffer.
    fgets(buffer, MAX_LINE, file);
    
    // If an error occurs reading the file, exit with an error message and 
    // status, and also delete the temporary file as well
    if (ferror(file))
    {
      printf("Error reading file.\n");
      fclose(temp);
      remove(temp_filename);
      return 1;
    }
    // If we reach the end of the file, stop the iterations of the loop
    else if (feof(file)) keep_reading = false;
    // The function strpbrk searches buffer for any char contained in 
    // delete_chars and returns a pointer to the first instance of any char 
    // contained in delete_chars that it encounters in buffer.  IF it can't find
    // any chars from delete_chars in buffer, it will return NULL.  So we ONLY 
    // write the line we've read in from the file into the temporary file IF 
    // strpbrk() returns NULL, as this means not one char from delete_chars has 
    // been found in this line from the file!  This effectively turns the 
    // temporary file into a version of the original file with the lines we 
    // wanted to delete "removed" because we never write them to the temporary
    // file! 
    else if (strpbrk(buffer, delete_chars) == NULL)
      fputs(buffer, temp);

  } while (keep_reading);
  
  // close the original file and temporary file
  fclose(file);
  fclose(temp);
  
  // delete the original file
  remove(filename);

  // rename the temporary file to the original file's filename, replacing it
  rename(temp_filename, filename);

  return 0;
}