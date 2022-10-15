/*******************************************************************************
*
* Program: Convert The Vowels In A String To Uppercase Letters
*
* Description: Example of converting the vowels in a string to uppercase letters
* using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=v7r9LD6oIYA
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convert_vowels(char *s);

int main(int argc, char *argv[])
{
  // declare and initialize a test string
  char test[] = "Let's make a test string.";

  // call convert_vowels to convert the vowels in the string to uppercase
  // letters
  convert_vowels(test);

  // output the test string after performing the converison
  printf("test: %s\n\n", test);

  return 0;
}

// Converts the vowels in the string s to uppercase letters
void convert_vowels(char *s)
{
  // Find the length of the string using strlen() and store it into length
  int length = strlen(s);

  // Loop with counter variable i going from 0 up to the length of the string,
  // so that we can check each index in the string to see if it is a lowercase
  // vowel and conver it to an uppercase vowel if so
  for (int i = 0; i < length; i++)
  {
    // Pass the islower() function the character at the index i that we are
    // currently checking, it will return true if the character is a lowercase
    // letter and false otherwise.
    if (islower(s[i]))
    {
      // If the character is lowercase, check to see if it is a vowel
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
          s[i] == 'o' || s[i] == 'u')
      {
        // If the character is a vowel, use the toupper() function to convert
        // it to an uppercase letter and replace the vowel currently at
        // this index with its uppercase equivalent
        s[i] = toupper(s[i]);
      }
    }
  }
}