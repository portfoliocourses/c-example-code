/*******************************************************************************
*
* Program: Delete A Substring
* 
* Description: Deletes all occurrences of a substring from a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=p6uqGop26es
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

void delete(char string[], char substr[]);

int main()
{
  // test string
  char string[] = "Hate the sin, love the sinner";
  
  // print the string before removing the substring
  printf("Before: %s\n", string);
  
  // remove the substring "the "
  delete(string, "the ");
  
  // print the string after removing the substring
  printf("After: %s\n", string);
  
  return 0;
}

// deletes all occurrences of substr that occur in string
void delete(char string[], char substr[])
{
  // i is used to loop through the string
  int i = 0;

  // store the lengths of the string and substr
  int string_length = strlen(string);
  int substr_length = strlen(substr);
  
  // loop through the string keeping track of our current index with i, 
  // starting at the first index
  while (i < string_length)
  {
    // if we find the substr at the current index, delete it
    if (strstr(&string[i], substr) == &string[i])
    {
      // determine the string's new length after removing the substr occurrence
      string_length -= substr_length;
      
      // shift forward the remaining characters in the string after the substr 
      // occurrence by the length of substr, effectively removing it!
      for (int j = i; j < string_length; j++)
        string[j] = string[j + substr_length];
    }
    else i++;
  }
  
  // put a null terminator at the end of the string 
  string[i] = '\0';
  
}