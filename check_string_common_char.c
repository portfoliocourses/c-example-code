/*******************************************************************************
*
* Program: Check If Two Strings Have Any Character In Common
*
* Description: Program to check if two strings have a character in common 
* using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=h9ZbdhQnre4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool check_common(char *str1, int len1, char *str2, int len2);

int main(void)
{
  // Two test strings with the characters 'o' and 'r' in common
  char str1[] = "Portfolio";
  char str2[] = "Courses";
  
  // Check if the strings have a character in common.  Note that strlen() 
  // returns the length of the strings (not including the null terminator),
  // though we could have just passed in the lengths directly if we 
  // already know them.
  //
  if (check_common(str1, strlen(str1), str2, strlen(str2)))
  {
    printf("Strings have a character in common.\n");
  }
  else
  {
    printf("Strings do not have a character in common.\n");
  }
  
  return 0;
}

// Returns true if the strings str1 and str2 have any character in common,
// where str1 has the length len1 and str2 has the length len2.  The function
// assumes the string are encoded using ASCII.
bool check_common(char *str1, int len1, char *str2, int len2)
{
  // If either str1 or str2 are a 'pointer to nothing', return false
  if (str1 == NULL || str2 == NULL) 
  {
    return false;
  }
  
  // In ASCII characters are encoded as integers from 0...255, see the table:
  // https://www.ascii-code.com/
  //
  // So for example 'A' is really the integer 65.  So we create an array of 
  // bool elements, one for each integer/character from 0....255.  Now some 
  // of the 'characters' in ASCII are things like unprintable control 
  // characters that we won't see in actual strings but that's OK.
  //
  // A value of false will mean that we have not encountered the character
  // with that integer/index in str1.  So 'A' -> 65 means that the index
  // 65 keeps track of whether we found the character 'A' in str1.
  //
  bool exists_in_str1[256] = {false};

  // Loop through each index in str1, set the index in exists_in_str1 for each
  // character found in str1 to true.  
  for (int i = 0; i < len1; i++)
  {
    exists_in_str1[ str1[i] ] = true;
  }
  
  // Loop through each index in str2 now, and IF the index for a character in 
  // exists_in_str2 has been set to true that means we ALSO found the character
  // in str1 and can return true as the strings have a character in common.
  for (int i = 0; i < len2; i++)
  {
    if (exists_in_str1[ str2[i] ])
    {
      return true;
    }
  }
  
  // If we find no character in common between the strings we return false
  return false;
}