/*******************************************************************************
*
* Program: Remove All The Characters In A String That Occur In Another String
*
* Description: Program to remove all the characters from the first string that
* are present in the second string using C
*
* YouTube Lesson: https://www.youtube.com/watch?v=25BeWHutGs0 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int remove_chars(char string[], char remove[]);

int main(void)
{
  char string[] = "Let's try this out today!";
  char remove[] = "aeiou";

  int removed = remove_chars(string, remove);

  printf("String: %s\n", string);
  printf("Removed: %d\n", removed);

  return 0;
}

int remove_chars(char string[], char remove[])
{
  int string_length = strlen(string);
  int remove_length = strlen(remove);
  int removed = 0;

  int j = 0;
  for (int i = 0; i < string_length; i++)
  {
    bool in_string = false;

    for (int k = 0; k < remove_length; k++)
      if (string[i] == remove[k]) in_string = true;

    if (!in_string)
    {
      string[j] = string[i];
      j++;
    }
    else removed++;
  }
  string[j] = '\0';

  return removed;
}