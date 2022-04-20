/*******************************************************************************
*
* Program: Count The Vowels In A String Using Recursion Demonstration
* 
* Description: Example of how to count the vowels in a string using recursion 
* in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=0dXJKOeqGGA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <ctype.h>

int count_vowels(char *string);

int main(void)
{
  // a test string with 7 vowels
  char test_string[] = "Maybe let's try this string out!";
  
  // call function to count vowels, store result into vowles
  int vowels = count_vowels(test_string);
  
  // output the total vowels to confirm the correct result of 7
  printf("total vowels: %d\n", vowels);
  
  return 0;
}

// Returns the number of vowels in the provided string using recursion.
int count_vowels(char *string)
{
  // When a string is passed to a function, what is really passed is a pointer 
  // to the first char in a string.  This function works by continually calling
  // itself with a pointer to the next char in the string, until it reached 
  // the null terminator that ends a string.  When it reaches the null 
  // terminator it returns 0, for all other chars it checks to see if they are 
  // a vowel... if they are it returns 1 + the count of the remaining vowels 
  // in the string, otherwise it just returns the remaining vowels in the 
  // string.  This will result in counting all the vowels in the string!

  // If the current character is the null terminator, we have reached the end
  // of the string and we return 0.  We call this the base case or base step as 
  // it ends the recursive function calls.
  if (*string == '\0') return 0;
  
  // Otherwise we want to look at the current character to see if it is a vowel,
  // to account for both uppercase and lowercase vowels more easily we'll use 
  // tolower() which will convert an uppercase char to its lowercase equivalent
  // (returning all other chars unchanged).
  char c = tolower(*string);
  
  // If the character is a vowel, return 1 + any vowels in the remaining string
  // as determined by count_vowels.  The expression "string + 1" uses pointer 
  // arithmetic to give us a pointer to the next char in the string so we can 
  // examine it on the next function call.  If the current char is NOT a vowel
  // then the count of vowels is given by the number of vowels in the remaining 
  // portion of the string so we again call count_vowels with string + 1 but do
  // not add 1 this time.
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return 1 + count_vowels(string + 1);
  else
    return count_vowels(string + 1);
  
}