/*******************************************************************************
*
* Program: Check If A String Is A Palindrome Using Recursion
* 
* Description: Check if a string is a palindrome using recursion in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=zQbX6r8MagM 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool check_palindrome(char *string, int left, int right);
bool is_palindrome(char *string);

int main()
{
  // Create a test string
  char *test = "racecar";
  
  // Check if the string is a palindrome and output the result
  if (is_palindrome(test)) 
    printf("'%s' is a palindrome.\n", test);
  else
    printf("'%s' is not a palindrome.\n", test);
  
  return 0;
}

// Returns true if the string provided as an argument is a palindrome, and false
// otherwise.  The function is a wrapper for the recursive check_palindrome() 
// function, which simplifies how check_palindrome() is called by finding the 
// length of the string and using this when calling check_palindrome().
bool is_palindrome(char *string)
{
  // The strlen() function from the string.h library returns the length of the 
  // string it is passed as an argument, we store the length into the variable
  // length.
  int length = strlen(string);
  
  // A string of length 0 or 1 is automatically considered a palindrome so we 
  // just return true for these cases.
  if (length == 0 || length == 1)
    return true;
  
  // Call check_palindrome(), providing the initial left index of 0 and the 
  // initial right index as the last index in the string which will be one 
  // less than the length of the string.
  return check_palindrome(string, 0, length - 1);
}

// Returns true if the string provided as an argument is a palindrome and false
// otherwise.  The function should be called with left and right initially set 
// to the first and last index of the string.
//
// The function works by continually checking the corresponding characters on 
// either sides of the string to see if they are equal, until the middle of the
// string is reached.
//
// So for example if we have the string:
//
//     left     right
//        |     |
//       "racecar"
//
// The function uses the indexes left and right, checking to see if the 
// characters at these indexes are equal.  If they are not the string is not a 
// palindrome and the function returns false.  If they are equal, the string may
// be a palindrome, and the function calls itself with left incremented by 1 
// and right decremented by 1, so that the next pair of corresponding characters
// is checked to see if they are equal:
//
//      left   right
//         |   |
//       "racecar"
//
// Once left >= right then we will have verified the string is a palindrome, 
// and we can return true.
//
bool check_palindrome(char *string, int left, int right)
{
  if (left >= right)
    return true;
  else if (string[left] == string[right])
    return check_palindrome(string, left + 1, right - 1);
  else
    return false;
}