/*******************************************************************************
*
* Program: Count The Lowercase Letters In A String
* 
* Description: Program to count the lowercase letters in a string using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=0xk-Xbiv5oE 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_lowercase(char *string);

int main(void)
{
  // Test string with 11 lowercase letters
  char string[] = "Read Only Memory";
  
  // Call function to count lowercase letters, store count into count
  int count = count_lowercase(string);
   
  // Output the count
  printf("Total lowercase letters: %d\n", count);
  
  return 0;
}

// Return the number of lowercase letters in the string 'string'
int count_lowercase(char *string)
{
  // Find the length of the string (not including the null terminator) using
  // strlen() from the string.h library, store the result into length
  int length = strlen(string);
  
  // Stores the count of lowercase letters in the string, initialized to 0
  // because we have not counted anything yet
  int count = 0;
  
  // Loops through each index of the string from 0...length-1 with each loop
  // iteration using the counter variable i.  We use the islower() function to
  // check if the character is a lowercase letter and if it is we increment 
  // count to acknowledge we have found another lowercase letter in the string.
  for (int i = 0; i < length; i++)
  {
    if (islower(string[i]))
    {
      count++;
    }
  }

  // Once the loop is done we will have counted all lowercase letters in the 
  // string and we then return that count.  
  return count;
}