/*******************************************************************************
*
* Program: Count The Characters Common To Two Strings
*
* Description: Program to count the number of characters that are common to two
* strings using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Vnvzsb5wFg4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int count_common(char *str1, int len1, char *str2, int len2);

int main(void)
{
  // Two test strings with the characters 'o' and 'r' common to both
  char str1[] = "Portfolio";
  char str2[] = "Courses";
    
  // Find the number of characters common to both strings (2)
  int common_count = count_common(str1, strlen(str1), str2, strlen(str2));
  
  // Output the result
  printf("Common character count: %d\n", common_count);
  
  return 0;
}

// Returns the number of characters common to the strings str1 and str2 of 
// length len1 and len2.  The function assumes the characters in the string
// are encoded using ASCII.
int count_common(char *str1, int len1, char *str2, int len2)
{
  // Check if str1 and str2 are NULL pointers and return -1 as an error if so 
  // as we can't count the number of common characters if we don't have two 
  // strings.
  if (str1 == NULL || str2 == NULL)
  {
    return -1;
  }
  
  // In ASCII characters are encoded as integers from 0...255, see the table:
  // https://www.ascii-code.com/
  //
  // So for example 'A' is really the integer 65.  So we create an array of 
  // int elements, one for each integer/character from 0....255.  Now some 
  // of the 'characters' in ASCII are things like unprintable control 
  // characters that we won't see in actual strings but that's OK.
  //
  // If we find a character like 'A' in str1 we will set the index 'A'/65 to 1 
  // to acknowledge this, and if we find the character in str2 we will set the
  // index 2 to acknowledge this.  In this way we're able to keep track of 
  // the characters that are common to both strings (and we're able to count 
  // them).  We initially set all indexes to 0.
  //
  int exists_in_strings[256] = {0};
  
  // Loop through each character in str1 and set the index for that character
  // in exists_in_strings equal to 1 to acknowledge that character was found in
  // str1.
  for (int i = 0; i < len1; i++)
  {
    exists_in_strings[ str1[i] ] = 1;
  }
  
  // Keeps track of how many characters are common to both strings
  int count = 0;

  // Loop through each character in str2, check to see if that character was
  // found in str1 by checking the index for that character in exists_in_strings
  // to see if it's set to 1.  If it is, we've found a character that's in 
  // both strings, and we set exist_in_strings at the index of this character
  // to 2 now to acknowledge this.  We also increment count as we have found
  // another character common to both strings.  Notably on subsequent iterations
  // of the loop when a character common to both strings is found again the 
  // if-statement condition will be false, as we have now set that index to 2,
  // and that's OK as we've already acknowledged that the character occurs 
  // in both strings.
  for (int i = 0; i < len2; i++)
  {
    if (exists_in_strings[ str2[i] ] == 1)
    {
      exists_in_strings[ str2[i] ] = 2;
      count++;
    }
  }
  
  // Return the count of the number of characters common to both strings
  return count;
}
