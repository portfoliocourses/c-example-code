/*******************************************************************************
*
* Program: File Copy demonstration
* 
* Description: Example of how to copy a file with C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=ceODxfZWZIo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// program should be provided with two command line arguments, the name of the 
// file and the name of the copy, e.g. copy_file file.txt copy.txt
int main(int argc, char *argv[])
{
  FILE *file, *copy;
 
  // make sure the correct number of arguments are provided
  if (argc != 3)
  {
    printf("Argument number error.\n");
    return 1;
  }
  
  // open the file for reading, and the copy for writing
  file = fopen(argv[1], "r");
  copy = fopen(argv[2], "w");
  
  // exit if the file(s) could not be opened
  if (file == NULL || copy == NULL)
  {
    printf("Error opening file(s).\n");
    return 1;
  }
  
  // copy the content from the file to the copy one character at a time
  char c;
  while ( (c = fgetc(file)) != EOF )
    fputc(c, copy);
  
  // close the files when we are done with them
  fclose(file);
  fclose(copy);

  return 0;
}
