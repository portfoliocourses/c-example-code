/*******************************************************************************
*
* Program: Create Your Own strspn() Function
* 
* Description: Example of how to create your own strspn() function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=oMXhxEpznoc 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

size_t _strspn(const char *str1, const char *str2);

int main()
{
  // Test strings
  char *string = "12363acdef";
  char *digits = "0123456789";
  
  // The official strspn() function is defined in the string.h library and 
  // returns the length of the initial substring of its first string argument 
  // made up of entirely characters found in its second string argument.  So 
  // in the case of 'string' and 'digits' the length of the initial substring 
  // of 'string' made up of entirely characters found in 'digits' is 5, and we 
  // expect our function _strspn() to also return 5. 
  size_t length = _strspn(string, digits);
  
  // Print out the returned value to confirm it is 5
  printf("Initial Substring Length: %zu\n", length);
  
  return 0;
}

// return the length of the initial substring of str1 made up of entirely 
// characters found in str2
size_t _strspn(const char *str1, const char *str2)
{
  // variable to keep count of the initial substring length
  size_t initial_length = 0;
  
  // get the lengths of each string in order to know when to stop a counter 
  // variable used to loop through each character in each string
  size_t len1 = strlen(str1);
  size_t len2 = strlen(str2);
  
  // The outer loop will go through each character in str1 using counter 
  // variable 'i', 'i' will be the character we are currently looking at in str1
  for (size_t i = 0; i < len1; i++)
  {
    // The inner loop will attempt to find a matching character in str2 for the 
    // character we are currently looking at in str1.  We start off with the 
    // assumption there is no matching character with found_match = false, and 
    // then we loop through each character in str2 with counter variable j 
    // identifying the character we are currently looking at in str2.  When 
    // we find a match with the character we are currently looking at in in str1
    // as given by counter variable 'i', we then set found_match to true and 
    // stop looking for a match.
    bool found_match = false;
    for (size_t j = 0; j < len2; j++)
      if (str2[j] == str1[i])
      {
        found_match = true;
        break;
      }
    
    // If we go through all of str2 in the above inner loop without finding a 
    // match then found_match will still be false, and in this case we want to 
    // 'break' and terminate the outer loop as we have reached the end of the 
    // initial substring of str1 made up of entirely characters found in str2.
    // If we did find a match we increment initial_length because we have 
    // identified one more character in the initial substring of str1 that is 
    // made up of characters found in str2.
    if (!found_match) break;
    else initial_length++;
  }
  
  // return the initial substring length
  return initial_length;
}