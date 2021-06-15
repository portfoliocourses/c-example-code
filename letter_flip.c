/*******************************************************************************
*
* Program: Letter flipper
* 
* Description: Flips lowercase characters to uppercase and uppercase characters
* to lowercase in a C string.
*
* YouTube Lesson: https://www.youtube.com/watch?v=rso22UR1b2I
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void letter_flip(char *s);

int main(void)
{
  // test the function with a couple example strings

  char s1[] = "abcdeABCDE";
  letter_flip(s1);
  printf("s1 after: %s\n", s1);

  char s2[] = "ThiS iS My sTrInG!";
  letter_flip(s2);
  printf("s2 after: %s\n", s2);

  return 0;
}

void letter_flip(char *s)
{
  int length = strlen(s);

  // Examine each character, if it is uppercase make it lowercase and vice versa
  for (int i = 0; i < length; i++)
  {
    if (isupper(s[i]))
      s[i] = tolower(s[i]);
    else if (islower(s[i]))
      s[i] = toupper(s[i]);
  }
}