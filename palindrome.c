/*******************************************************************************
*
* Program: Check if a string is a palindrome
* 
* Description: An example of a function for checking whether a string is a 
* palindrome or not.
*
* YouTube Lesson: https://www.youtube.com/watch?v=XMMmvv4wZtQ 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char string[]);

int main(void)
{
  // some example strings
  char string1[] = "not a palindrome!";
  char string2[] = "abccba";
  char string3[] = "abcdcba";

  // check if each string is a palindrome and report the results
  if (is_palindrome(string1)) printf("%s\n- is a palindrome\n", string1);
  else printf("%s\n- is not a palindrome\n", string1);
  printf("\n");

  if (is_palindrome(string2)) printf("%s\n- is a palindrome\n", string2);
  else printf("%s\n- is not a palindrome\n", string2);
  printf("\n");

  if (is_palindrome(string3)) printf("%s\n- is a palindrome\n", string3);
  else printf("%s\n- is not a palindrome\n", string3);

  return 0;
}

// returns true if the string is a palindrome and false otherwise
bool is_palindrome(char string[])
{
  // find the middle of the string as we'll need to check up until here 
  int len = strlen(string);
  int middle = len / 2;

  // check the corresponding characters on the left and right sides of the 
  // string to see if they match, until we reach the middle, if they ever do 
  // not match then return false as the string is not a palindrome
  for (int i = 0; i < middle; i++)
    if (string[i] != string[len - i - 1]) return false;

  // if all corresponding characters on the left and right sides of the string 
  // have matched, the string must be a palindrome and so return true
  return true;
}