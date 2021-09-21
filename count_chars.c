/*******************************************************************************
*
* Program: Print Occurrences Of Characters demonstration
* 
* Description: Example of printing the number of occurrences of all unique
* characters in a string.
*
* YouTube Lesson: https://www.youtube.com/watch?v=PdiLIj943NY 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void print_occurrences(char *s);

int main()
{
  // test the function out with a test string
  char s[] = "abcdefghijklmnopabcdefabcab";
  print_occurrences(s);

  return 0;
}

// prints the number of occurrences of each unique character in the string s
void print_occurrences(char *s)
{
  // unique will keep track of the unique characters found so far, counted 
  // will keep track of how many unique characters we've already counted
  int length = strlen(s);
  char unique[length];
  int counted = 0;
  
  // check each character in the string
  for (int i = 0; i < length; i++)
  {
    // check to see if the character at index i has already been counted
    bool already_counted = false;
    for (int j = 0; j < counted; j++)
      if (s[i] == unique[j])
        already_counted = true;
    
    // if the character has already been counted, skip ahead to the next 
    // iteration of the loop as we do not need to count it again
    if (already_counted) continue;
    
    // if we haven't already counted the character, count it now
    int count = 0;
    for (int j = 0; j < length; j++)
      if (s[i] == s[j]) count++;
    
    // output the count
    printf("%c - %d\n", s[i], count);
    
    // add the character to the array of unique characters we've found so far
    unique[counted] = s[i];
    counted++;
  }
}
