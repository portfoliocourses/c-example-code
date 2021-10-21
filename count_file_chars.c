/*******************************************************************************
*
* Program: Count Characters In A File
* 
* Description: A program to count the number of non-whitespace characters in 
* a file.
*
* YouTube Lesson: https://www.youtube.com/watch?v=FnWBCytmD6w
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <ctype.h>

int main()
{
  FILE *file;
  
  // open file.txt
  file = fopen("file.txt", "r");
  
  // if there was an error opening the file, let the user know
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  int total = 0;
  char c;
  
  // read each character in the file, if it is NOT a whitespace character add 
  // it to the total number of characters
  while ( (c = fgetc(file)) != EOF )
    if (!isspace(c)) total++;
  
  // output the total number of characters in the file
  printf("Total: %d\n", total);

  return 0;
}