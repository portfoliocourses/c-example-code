/*******************************************************************************
*
* Program: Switch statement tutorial
* 
* Description: Examples of using a switch statement control structure.
*
* YouTube Lesson: https://www.youtube.com/watch?v=V7u9rG8-b1U
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  // A basic example of a switch statement, try altering num to see what happens
  int num = 1;
  switch (num)
  {
    case 1:
      printf("Case 1!\n");
      if (1 == 1) printf("if!\n");
      break;

    case 2:
      printf("Case 2!\n");
      break;

    default:
      printf("Default case!\n");
  }
  printf("Below switch statement!\n");

  // "Practical" example of using fall-through logic to count the number of As
  // and vowels in a string (case insensitive)
  char s[] = "aabAdefghIjKlMNoPqRsTU";
  int length = strlen(s);
  int a = 0;
  int vowel = 0;

  // check each character in the string
  for (int i = 0; i < length; i++)
  {
    // check uppercase version of character so we have less cases to check for
    switch (toupper(s[i]))
    {
      // if it is an A, increment the 'a counter', but let execution fall 
      // through (i.e. no break) so that we count vowels
      case 'A':
        a++;
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        vowel++;
      // fall through logic is also used for E,I,O given that the "action" we 
      // want to take (incrementing the count of vowels) is the same for all 
      // of these cases!
    }
  }

  // output the count of a characters and vowels
  printf("a: %d, vowel: %d\n", a, vowel);

  return 0;
}




