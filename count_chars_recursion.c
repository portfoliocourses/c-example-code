/*******************************************************************************
*
* Program: Count The Occurrences Of A Character In A String Using Recursion
*
* Description: Program to count the occurrences of a character in a string using
* recursion in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=0CyNbF_pcrY
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int count_occurrences(char *string, char c);

int main(void)
{
  // test string with 2 occurrences of the character 'a'
  char test[] = "Some characters in the string.";

  // call the count_occurrences function to return the number of occurrences of
  // the char 'a' in the test string, and output the result
  printf("a count: %d\n", count_occurrences(test, 'a'));

  return 0;
}


// Uses recursion to return the number of occurrences of the char c in the
// string.  Recursion is when we have a function that calls itself to solve
// a problem.
//
// When we pass a string to a function, what we REALLY pass is the memory
// address of the first char in the string.  char *string is a pointer variable
// that will store that memory adress.  We can use the de-reference operator
// *string to get that character (we could also use array syntax like
// string[0]).
//
// string + 1 will give us the memory address of the NEXT character in the
// string.
//
// We use these two operations to implement a recursive solution.  We have
// the function repeatedly call itself with string + 1 as the string
// argument, so that each time the function executes we can look at the NEXT
// char in the string using *string.
//
// We STOP the recursive function calls when *string == '\0', the special
// null terminator that signifies the end of a string.  We call this the base
// step in our recursive solution because it stops the recursion.  We return
// 0 in this case.  The "empty string" has 0 occurrences of the character,
// and the null terminator is not an occurrence of the character.
//
// Otherwise if *string is equal to the character we're looking for (c) we
// return 1 + the remainder of occurrences of the character in the string
// by calling the function with string set to string + 1 (to look at the
// next character in the string in this next function call).
//
// Finally, if this is not the case we return the remainder of occurrences of
// the character in the string by again calling the function with string set
// to string + 1.
//
// This will result in what we can think of as a chain of addition operations
// adding 1 for each occurrence of a character that is found, with the null
// terminator completing this chain with the operand '0'.  This 'chain of
// addition operations' will give us the total occurrences of the character in
// the string.  In reality the additions are done one at a time with each
// function call/return.
//
int count_occurrences(char *string, char c)
{
  if (*string == '\0')
    return 0;
  else if (*string == c)
    return 1 + count_occurrences(string + 1, c);
  else
    return count_occurrences(string + 1, c);
}
