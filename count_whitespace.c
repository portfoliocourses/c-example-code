/*******************************************************************************
*
* Program: Count The Whitespace Characters In A String
* 
* Description: Count the whitespace characters in a string using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=IesFHiWbs7M 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_whitespace(char *string);

int main(void)
{
  // A test string.  Whitespace characters include characters such as ' ' and 
  // '\n' (newline) and '\t' (tab), so this string has 6 whitespace characters.
  char string[] = "Line 1\nLine 2\n\tLine 3";
  
  // Call the function, pass it the string, store the return value into count
  int count = count_whitespace(string);
  
  // Output the returned count of whitespace characters
  printf("Total Whitespace Characters: %d\n", count);
  
  return 0;
}

// Returns the total whitespace characters in the string passed as an argument
int count_whitespace(char *string)
{
  // Find the length of the string (not including the null terminator)
  int length = strlen(string);

  // Keeps track of the running count of the number of whitespace characters,
  // initialized to zero because before we go through the string we haven't 
  // counted any characters yet
  int count = 0;
  
  // The loop will take the counter variable i from 0, 1, 2, ... length-1
  // with each iteration, which are the indexes of each char in the string.
  // We then use the isspace() function which returns true if the char it 
  // is passed is a whitespace character and false otherwise, and we pass 
  // it the character at the 'current index' i to check if it is a whitespace
  // character or not.  If it is, we increment the running count of 
  // whitespace characters.
  for (int i = 0; i < length; i++)
  {
    if (isspace(string[i]))
    {
      count++;
    }
  }

  // Return the count of the number of whitespace characters 
  return count;
}