/*******************************************************************************
*
* Program: Find length of the smallest word 
* 
* Description: Find length of the smallest word in a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=AQ_rsjONc7o 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int smallest_word(char *s);

int main()
{
  // test out the function with a test string
  char s[] = "This a, the way. Again...";
  int smallest = smallest_word(s);
  printf("%d\n", smallest);

  return 0;
}

// return the length of the smallest word in the string argument provided
int smallest_word(char *s)
{
  int len = strlen(s);
  int count = 0;
  int min = 100000;  // surely any word will be smaller than this!

  // delimeter characters that separate words
  char nonwords[] = " .,;\t\n";
    
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

    // if we've found a smaller word than the previous smallest word, update 
    // the min value
    if (count < min) min = count;

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
   
  return min;
}

