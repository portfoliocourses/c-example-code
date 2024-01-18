/*******************************************************************************
*
* Program: Count The Uppercase Letters In A String
* 
* Description: Program to count the uppercase letters in a string using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=VT5jaa_-oMQ 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_uppercase(char *string);

int main(void)
{
  // Test string with 3 uppercase letters
  char string[] = "Let's go to New York!";
  
  // Call function to count uppercase letters, store count into count
  int count = count_uppercase(string);
   
  // Output the count
  printf("Total uppercase letters: %d\n", count);
  
  return 0;
}

// Return the number of uppercase letters in the string 'string'
int count_uppercase(char *string)
{
  // Find the length of the string (not including the null terminator) using
  // strlen() from the string.h library, store the result into length
  int length = strlen(string);
  
  // Stores the count of uppercase letters in the string, initialized to 0
  // because we have not counted anything yet
  int count = 0;
  
  // Loops through each index of the string from 0...length-1 with each loop
  // iteration using the counter variable i.  We use the isupper() function to
  // check if the character is an uppercase letter and if it is we increment 
  // count to acknowledge we have found another uppercase letter in the string.
  for (int i = 0; i < length; i++)
  {
    if (isupper(string[i]))
    {
      count++;
    }
  }

  // Once the loop is done we will have counted all uppercase letters in the 
  // string and we then return that count.  
  return count;
}