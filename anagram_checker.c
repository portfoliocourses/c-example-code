/*******************************************************************************
*
* Program: Anagram Checker demonstration
* 
* Description: Example of checking if two words are anagrams using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=R0qIYWo8igs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool check_anagram(char *w1, char *w2);

// Anagram example
//   Listen = Silent
int main()
{
  // test the function with two words that are anagrams
  char w1[] = "Listen";
  char w2[] = "Silent";
  if (check_anagram(w1, w2))
    printf("Anagrams!\n");
  else 
    printf("Not anagrams!\n");

  return 0;
}

// returns true if words w1, w2 are anagrams, and false otherwise
//   See: https://en.wikipedia.org/wiki/Anagram
bool check_anagram(char *w1, char *w2)
{
  int len1 = strlen(w1);
  int len2 = strlen(w2);
  
  // keep a count of the number of occurrences of each letter from a-z in w1, w2
  int w1lc[26] = {0};
  int w2lc[26] = {0};
  
  // count the number of occurrences of a-z in w1 (case insensitive)
  for (int i = 0; i < len1; i++)
  { 
    int lower = tolower(w1[i]);
    w1lc[ lower - 'a' ]++;
  }

  // count the number of occurrences of a-z in w2 (case insensitive)
  for (int i = 0; i < len2; i++)
  { 
    int lower = tolower(w2[i]);
    w2lc[ lower - 'a' ]++;
  }
  
  // if the number of occurrences of a letter is different, they're not anagrams
  for (int i = 0; i < 26; i++)
    if (w1lc[i] != w2lc[i]) return false;
  
  // if the number of occurrences of a letter are all the same, they're anagrams
  return true;
}
