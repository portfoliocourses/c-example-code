/*******************************************************************************
*
* Program: Reverse Words demonstration
* 
* Description: Example of reversing the words in a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Jy5QILbHKVA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

void reverse_words(char *s);

int main() 
{
  char s[] = "This is the way.";

  // print the string before reversing the words
  printf("%s\n", s);
  
  // reverse the words in the string
  reverse_words(s);
  
  // print the string after reversing the words
  printf("%s\n", s);

  return 0;
}

// accepts a string as an argument and reverses the words in the string
void reverse_words(char *s)
{
  int len = strlen(s);
  int i = 0, j = 0;

  // used to store each word temporarily 
  char temp[100];
  
  // the outer loop checks to see whether we have reached the end of the string,
  // the counter variable i keeps track of the index we have stepped through so
  // far in the string s
  for (i = 0; i < len; i++)
  {
    // this loop uses j as a counter variable to keep track of the length of 
    // and store the next word into temp, we stop the loop either when we 
    // reach the end of the string or the end of the next word
    for (j = 0; i < len; j++, i++)
    {
      // stop the loop if we reach the end of the next word
      if (s[i] == ' ' || s[i] == '.')
        break;
      temp[j] = s[i];
    }
    
    // Overwrite the word in s by writing the word into s at its current 
    // position, but reversed.  The word is stored in temp, and we use j in 
    // this loop to step backwards through the word one index at a time when 
    // we access the word in temp below.  In the case of s we subtract j 
    // from i to overwrite the word in its current position in s.
    while (j > 0)
    {
      j--;
      s[i - j - 1] = temp[j];
    }
  }
}
