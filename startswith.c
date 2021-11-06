/*******************************************************************************
*
* Program: Check If A String Starts With Another String
* 
* Description: Example of a substring function implementation in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=vWuxWxGVMC8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool startswith(char *string, char *start);

int main()
{
  // the test string
  char test[] = "Roses are red";
  
  // the string DOES start with Roses
  char startOK[] = "Roses";
  if (startswith(test, startOK))
    printf("Yes string does start with Roses.\n");
  else
    printf("No string doesn't start with Roses.\n");

  // the string DOES NOT start with Violets
  char startBad[] = "Violets";
  if (startswith(test, startBad))
    printf("Yes string does start with Violets.\n");
  else
    printf("No string doesn't start with Violets.\n");
  
  // check the 'error handling code' in the case that a potential starting 
  // string is actually longer than the string itself (we expect back false)
  char tooLong[] = "Roses are red Violets are Blue";
  if (startswith(test, tooLong))
    printf("This should not occur!\n");
  else
    printf("Test successful!\n");
  
  return 0;
}

// returns true if string starts with start
bool startswith(char *string, char *start)
{
  // get the length of both strings
  int string_length = strlen(string);
  int start_length = strlen(start);
  
  // handling what is essentially an 'error case' where the start string is 
  // longer than the actual string itself... we must return false in this case
  // because it's just not possible for a string to start with a string longer
  // than itself!
  if (start_length > string_length) return false;
  
  // if any character at the same index in start and string does not match, we 
  // know the string does not start with the start string and return false
  for (int i = 0; i < start_length; i++)
    if (string[i] != start[i]) return false;
  
  // if all characters DID match we can say the string DOES start with the 
  // start string and return true
  return true;
}