/*******************************************************************************
*
* Program: Word counter
* 
* Description: Counts the occurrences of a word in a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Zydf9p1VOGU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int word_count(char *string, char *word);

int main(void)
{
  // test case 1
  char s1[] = "It is in this string once.";
  char w1[] = "It";
  int result1 = word_count(s1, w1);
  printf("Result 1: %d\n", result1);

  // test case 2
  char s2[] = "This is in in in the word.";
  char w2[] = "in";
  int result2 = word_count(s2, w2);
  printf("Result 2: %d\n", result2);

  return 0;
}

// Returns the number of times the word occurs in the string
int word_count(char *string, char *word)
{
  // obtain the length of the string and word
  int slen = strlen(string);
  int wlen = strlen(word);
  
  // we can stop checking the string for occurrences of the word when we reach 
  // the position in the string where the word could not longer fit, given by:
  int end = slen - wlen + 1;

  // keeps track of the occurrences of the word
  int count = 0;

  // the outer loop ensures we check each position in the string for the word
  for (int i = 0; i < end; i++)
  {
    // start off with the assumption that the word is found at this position
    bool word_found = true;

    // the inner loop checks for the word at this position in the string by 
    // checking if each character in the word matches the corresponding 
    // character in the string (i being the position in the string, and j the 
    // position in the word, by adding i + j we check the corresponding 
    // character in the string).
    for (int j = 0; j < wlen; j++)
    {
      // if we don't have a match, we can stop checking 
      if (word[j] != string[i + j])
      {
        word_found = false;
        break;
      }
    }
    
    // if we never found a char that didn't match, our assumption that a match 
    // was found was true, and we increment the count
    if (word_found) count++;
  }

  return count;
}

