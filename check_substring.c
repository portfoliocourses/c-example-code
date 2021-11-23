/*******************************************************************************
*
* Program: Check If A String Is A Substring Of Another String
* 
* Description: Function to check if a string is a substring of another string 
* in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=tx37dJZTfMM 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_substring(char *check, char *string);

int main(void)
{
  // test strings
  char s1[] = "This is my test string.";
  char c1[] = "test";
  
  // check if c1 is a substring of s1, report the results
  if (is_substring(c1,s1))
    printf("'%s' IS a substring of '%s'\n", c1, s1);
  else
    printf("'%s' IS NOT a substring of '%s'\n", c1, s1);
  
  return 0;
}

// returns true if check is a substring of strign, and false otherwise
bool is_substring(char *check, char *string)
{
  // get the length of both strings
  int slen = strlen(string);
  int clen = strlen(check);
  
  // we can stop checking for check in string at the position it will no longer
  // possibly fit into the string
  int end = slen - clen + 1;
  
  // check each position in string for check
  for (int i = 0; i < end; i++)
  {
    // assume the check string is found at this position
    bool check_found = true;
    
    // check each index of the check string to see if it matches with the 
    // corresponding character in string at index i onwards
    for (int j = 0; j < clen; j++)
    {
      // if we find a non-matching character, we know that check is not 
      // found here and we can stop checking now
      if (check[j] != string[i + j])
      {
        check_found = false;
        break;
      }
    }
    
    // if we found no non-matching characters, we found that check IS a 
    // substring of string (at position i) and we can stop checking
    if (check_found) return true;
  }
  
  // if at no position in string did we find check it is NOT a substring
  return false;
}
