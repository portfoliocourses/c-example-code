/*******************************************************************************
*
* Program: Replace A Substring
* 
* Description: Example of replacing a substring (e.g. a word or phrase) in 
* a string with another substring using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=hLVkrYEwwMM 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace(char *before, char *oldsub, char *newsub);

int main()
{
  // test string
  char string[] = "Hate the sin, love the sinner";
  
  // try to replace "the sin" with "the tin"
  char *result = replace(string, "the sin", "the tin");
  
  // output the before and after strings
  printf("Before: %s\n", string);
  printf("After: %s\n", result);
  
  // free the memory allocated for the after string
  free(result);
  
  return 0;
}

// returns a pointer to a new after string that results from replacing all 
// occurrences of the oldsub string in the before string with the newsub string
char *replace(char *before, char *oldsub, char *newsub)
{
  // get the lengths of the before string, old substring and new substring
  int old_length = strlen(oldsub);
  int new_length = strlen(newsub);
  int before_length = strlen(before);
  
  // keeps track of the occurrences of the old substring in the before string
  int occurrences = 0;
  
  // loop through the before string using i to keep track of the current index
  int i = 0;
  while (i < before_length)
  {
    // if we find the old substring in the before string at index i, then we 
    // increment occurrences and skip over an old substring's worth of chars
    if (strstr(&before[i], oldsub) == &before[i])
    {
      occurrences++;
      i += old_length;
    }
    // otherwise check for the old substring at the next index i
    else i++;
  }
  
  // calculate the difference in size between the new substring and the old 
  // substring... it's possible the old substring is either larger or smaller
  // than the new substring, and this will effect whether we need less or 
  // more space to be allocated
  int sub_diff = new_length - old_length;
  
  // allocate space for the new string... using the before string's length as 
  // a starting point, adjust the size by occurrences multipled by the 
  // difference in length between the new and old substrings as determined above
  char *after;
  after = malloc(before_length + (occurrences * sub_diff));
  
  // build the new after string by using the variable j to keep track of our
  // index in the before string and the variable i to keep track of our index
  // in the new after string
  i = 0;
  int j = 0;

  // keep looping through the before string until we reach the end
  while (j < before_length)
  {
    // if at index j in the before string, we find the old substring, write the 
    // NEW substring to the new after string
    if (strstr(&before[j], oldsub) == &before[j])
    {
      // writes the new substring into the new after string at index i
      strcpy(&after[i], newsub);

      // increment i by the length of the new substring (because we've just put
      // it into the after char array)
      i += new_length;

      // increment j by the length of the old substring (because we can now
      // skip over this many chars in the before string)
      j += old_length;
    }
    else
    {
      // if we didn't find the old substring in the before string at index j, 
      // then we just copy one character from the before to after string
      after[i] = before[j];
      i++;
      j++;
    }
  }
  
  // put a NULL terminator at the end of our after string to end it
  after[i] = '\0';
  
  // return a point to the after string
  return after;
}