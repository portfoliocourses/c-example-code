/*******************************************************************************
*
* Program: Find The Characters Common To Two Strings
*
* Description: Program to find the characters that two strings have in common 
* using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=namRJaE8ZqA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *find_common(char *str1, int len1, char *str2, int len2);

int main(void)
{
  // Two test strings with the characters 'o' and 'r' in common
  char str1[] = "Portfolio";
  char str2[] = "Courses";
   
  // Find the characters the two strings have in common, the function returns
  // a dynamically allocated string of these characters
  char *common_string = find_common(str1, strlen(str1), str2, strlen(str2));
  
  // Output the characters
  printf("Common characters: %s\n", common_string);
  
  // Free the dynamically allocated space the characters were stored in
  free(common_string);
  
  return 0;
}

// Returns a dynamically allocated string of the characters that the strings 
// pointed to by str1 and str2 have in common, where str1 and str2 have 
// the lengths len1 and len2 respectively.
char *find_common(char *str1, int len1, char *str2, int len2)
{
  // Check if str1 and str2 are NULL pointers and return NULL as an error if so
  // as we can't find the common characters if we don't have two strings.
  if (str1 == NULL || str2 == NULL)
  {
    return NULL;
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
  // the characters that are common to both strings.  We initially set all 
  // indexes to 0.
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
  
  // We know that the two strings have count number characters in common, so 
  // to return a string with this many characters we allocate space for a 
  // block of memory of count + 1 bytes.  As it takes one byte to store an
  // int value and we need one more byte/character to store the null 
  // terminator to terminate the string.  We store the pointer (memory address)
  // for this block of memory into common_string.
  char *common_string = malloc(count + 1);
  
  // As each index in exists_in_string represents a character, and if the 
  // index is set to 2 we know that character exists in both strings, we 
  // loop through each index of exists_in_string.  And if that index is 
  // set to 2, we add that character to our common_string.  Note that 
  // even though we are assigning an 'int value' stored in i to the 
  // common_string, because those int values like 65 represent characters
  // like 'A', it's as if we are assigning those characters to the string.
  // We use count to go through the indexes of the common_string, 
  // starting it off at 0 and incrementing each time we add a character
  // common to both strings to common_string.
  count = 0;
  for (int i = 0; i < 256; i++)
  {
    if (exists_in_strings[i] == 2)
    {
      common_string[count] = i; 
      count++;
    }
  }
  
  // We add the null terminator on to the end of common_string to terminate
  // the string.
  common_string[count] = '\0';
  
  // We return the pointer to our string
  return common_string;
}