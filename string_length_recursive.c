/*******************************************************************************
*
* Program: String Length Calculator (Recursive)
* 
* Description: Find the length of a string using recursion in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=g_gganqwepw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int string_length(char *string);

int main(void)
{
  // test string
  char string1[] = "abcde";
  
  // call the function with the test string as an argument
  int string1_length = string_length(string1);
  
  // print out the calculated length to verify it is 5
  printf("length: %d\n", string1_length);
  
  return 0;
}

// returns the number of characters in the string (not including the null 
// terminator), using recursion
int string_length(char *string)
{
  // If the string is empty (or we reach the end of the string) return 0, 
  // otherwise we return 1 + the length of the remaining portion of the string!
  // The effect of this will be to calculate and return the correct legnth of 
  // the string, see below for further explanation.
  if (*string == '\0') return 0;
  else return 1 + string_length(string + 1);
}

// Strings in C are char arrays that end with a null terminator, so in memory
// string1 looks like this:
//
//                     special null terminator
//                     |
//           a b c d e \0     - characters
// string1:  0 1 2 3 4 5      - array indexes
//
//
// When we pass arrays to a function in C, what really happens is that the array
// decays to a pointer, so the "string" parameter string above is *really* a
// pointer to a char in the string.  Initially, it will be a pointer to the 
// first char in the string.  The way we solve the problem with recursion is 
// by returning the expression:
//
// 1 + length of remaining portion of the string
//
// we call this the recursive step.  We eventually will stop recursion when 
// the function is called for the null terminator, and we call this the base 
// step.  By calling the function with "string + 1" we are passing a pointer 
// to the next character in the string.  And *string allows us to access the 
// character that string is currently pointing to.
//
// So as the function is called for each char in the string we effectively 
// build an expression of 1 + 1 + 1 + .... + string_length(string +1), with 
// string_length(string + 1) eventually evaluating to 0 when we reach the 
// null terminator.
//
//                 string
//                   |
//           a b c d e \0
// string1:  0 1 2 3 4 5
//
// 1 + 1 + 1 + 1 + 1 + string_length(string + 1)
//