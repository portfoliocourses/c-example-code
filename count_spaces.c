/*******************************************************************************
*
* Program: Count The Spaces In A String
* 
* Description: Program to count the number of space characters in a string 
* using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=LML3kmD1CtI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int count_spaces(char *string);

int main(void)
{
  // Test string with 4 spaces
  char string[] = "Live life to the fullest";
  
  // Call function to count spaces, store count into count
  int count = count_spaces(string);

  // Output the count
  printf("Total Space Characters: %d\n", count)
  
  return 0;
}

// Return the number of spaces in the string 'string'
int count_spaces(char *string)
{
  // Find the length of the string (not including the null terminator) using
  // strlen() from the string.h library, store the result into length    
  int length = strlen(string);

  // Stores the count of spaces in the string, initialized to 0 because we 
  // have not counted anything yet  
  int count = 0;
  
  // Loops through each index of the string from 0...length-1 with each loop
  // iteration using the counter variable i.  We use string[i] == ' ' to
  // check if the character is a space and if it is we increment count to 
  // acknowledge we have found another space in the string.  
  for (int i = 0; i < length; i++)
  {
    if (string[i] == ' ')
    {
      count++;
    }
  }

  // Once the loop is done we will have counted all the spaces in the string and
  // we then return that count.    
  return count;
}