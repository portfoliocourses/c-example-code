/*******************************************************************************
*
* Program: Merge Two Files
* 
* Description: Example of merging two files into a third file in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Vuz-1zNq8hc 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main()
{
  FILE *f1, *f2, *merge;
  
  // open all three files... the two original files for reading, and the third 
  // for writing
  f1 = fopen("f1.txt", "r");
  f2 = fopen("f2.txt", "r");
  merge = fopen("m.txt", "w");

  // if there was an error opening the file(s) inform the user and exit
  if (f1 == NULL || f2 == NULL || merge == NULL)
  {
    printf("Error opening files.\n");
    return 1;
  }
  
  // write the contents of each file one after the other to the third file
  char c;
  while ((c = fgetc(f1)) != EOF) fputc(c, merge);
  while ((c = fgetc(f2)) != EOF) fputc(c, merge);
  
  // close all the files
  fclose(merge);
  fclose(f1);
  fclose(f2);

  return 0;
}