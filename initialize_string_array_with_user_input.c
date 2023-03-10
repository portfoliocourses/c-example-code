/*******************************************************************************
*
* Program: Initialize An Array Of Strings With User Input
* 
* Description: Initializing an array of strings with user input using C, where 
* the "array of strings" is a 2D char array with a string stored in each row of
* the 2D array.
*
* YouTube Lesson: https://www.youtube.com/watch?v=iXMQs1HBQi8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

#define TOTAL_STRINGS 5
#define STRING_BUFFER_LENGTH 1000

int main(void)
{
  char strings[TOTAL_STRINGS][STRING_BUFFER_LENGTH];
  
  for (int i = 0; i < TOTAL_STRINGS; i++)
  {
    printf("Enter String %d: ", i+1);
    
    fgets(strings[i], STRING_BUFFER_LENGTH, stdin);
    
    int length = strlen(strings[i]);
    if (strings[i][length - 1] == '\n')
    {
      strings[i][length - 1] = '\0';
    }
    else
    {
      int c;
      while ( (c = getchar()) != '\n' && c != EOF) {}
    }
  }
  
  for (int i = 0; i < TOTAL_STRINGS; i++)
  {
    printf("String %d: %s\n", i+1, strings[i]);
  }
  
  
  
  return 0;
}
