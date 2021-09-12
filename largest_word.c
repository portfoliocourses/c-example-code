/*******************************************************************************
*
* Program: Find length of the largest word 
* 
* Description: Find length of the largest word in a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=6o8aZzU7TGs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int largest_word(char *s);

int main()
{
  // test out the function with a test string
  char s[] = "This is, theres way Again...";
  int largest_length = largest_word(s);
  printf("%d\n", largest_length);

  return 0;
}

// return the length of the largest word in the string argument provided
int largest_word(char *s)
{
  int len = strlen(s);
  int count = 0;
  int max = -1;

  // delimeter characters that separate words
  char nonwords[] = " .,;\n\t";
  
  // the outer loop stops when we reach the end of the string, it has a loop 
  // that steps through the next word, followed by a loop that steps through 
  // any delimeter characters that separate words
  int i = 0;
  while (i < len)
  {
    // this loop steps through a word and keeps a count of the characters
    count = 0;
    while (i < len)
    {
      // we know we've reached the end of a word when strchr() no longer 
      // returns NULL as it means that it found a match for s[i] in nonwords, 
      // the function returns NULL if it cannot find the char and a pointer 
      // to the matching character if it can
      if (strchr(nonwords, s[i]) != NULL)
        break;
      i++;
      count++;
    }
    
    // if we've found a larger word than the previous largest word, update 
    // the max value
    if (count > max) max = count;
    
    // step through any delimeter characters until we reach the next word
    while (i < len)
    {
      // once strchr() returns NULL, we know that s[i] is NOT one of the 
      // delimeter characters that separates words, and we have reached the 
      // next word
      if (strchr(nonwords, s[i]) == NULL)
        break;
      i++;
    }
  } 
 
  return max;
}

