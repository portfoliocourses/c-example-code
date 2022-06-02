/*******************************************************************************
*
* Program: Read And Store All Lines Of A File Into An Array Of Strings
* 
* Description: Example of reading and storing all the lines of a file into an 
* array of strings in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=X-1qodkHCHo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// constants for maximum number of lines in the file and max length of a line
#define MAX_LINES 100
#define MAX_LEN 1000

int main(void)
{
  // There are several ways to have an "array of strings" in C, the simplest of 
  // which is to have a 2D char array with each string stored at a row in the 
  // 2D array.  This will result in "unused space" as not all rows may be used 
  // if the file has fewer lines than MAX_LINES or if rows are of less length 
  // than MAX_LEN, so we should think about whether we are OK with this or not.
  // Another more sophisticated technique would be to use dynamic memory 
  // allocation.
  char data[MAX_LINES][MAX_LEN];
  
  // Create a file pointer variable to allow us to access the file
  FILE *file;
  
  // Open the file in reading mode, fopen() will return NULL if it fails to 
  // open the file...
  file = fopen("file.txt", "r");
  
  // If we've failed to open the file, exit with an error message and status, 
  // returning 1 instead of returning 0 is a signal to the shell that something
  // has gone wrong in the execution of our program.
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  
  // line will keep track of the number of lines read so far from the file
  int line = 0;
  
  // So long as we have not reached the end of the file (as detected by feof())
  // and so long as there has not been an error reading from the file (as 
  // detected by ferror()), we continue to read each line of the file with 
  // fgets().  fgets() will store up to a maximum of MEN_LEN chars into the 
  // row 'line' of our 2D char array data, reading from the file we opened 
  // with our file pointer 'file'.  We increment line so that the next time 
  // we call fgets() the line is read into the next row of our 2D char array 
  // data, except when fgets() returns NULL in which case we've reached the 
  // end of the file.
  while (!feof(file) && !ferror(file))
    if (fgets(data[line], MAX_LEN, file) != NULL)
      line++;
  
  // Close the file when we are done working with it.
  fclose(file);
   
  // Print out all the rows of our 2D array that were used to store a line from 
  // the file, as indicated by 'line' which lets us know how many lines we've 
  // read from the file.
  for (int i = 0; i < line; i++)
    printf("%s", data[i]);

  return 0;
}