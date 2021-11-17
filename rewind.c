/*******************************************************************************
*
* Program: rewind() function
* 
* Description: Examples of arithmetic operations in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=btq2nirO6f8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main()
{
  FILE *file;

  // open the file data.txt for reading
  file = fopen("data.txt", "r");
  
  // if there was a problem opening the file, tell the user and exit 
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  // read and output all file content until the file pointer reaches the 
  // end of the file
  char c;
  while ( (c = fgetc(file)) != EOF)
    printf("%c", c);
  printf("\n");

  // rewind the file pointer back to the beginning of the file!
  rewind(file);
  
  // we can now read and output the file contents again
  while ( (c = fgetc(file)) != EOF)
    printf("%c", c);
  printf("\n");
  
  // close the file pointer
  fclose(file);
 
  return 0;
}