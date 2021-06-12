/*******************************************************************************
*
* Program: Vowel counter
* 
* Description: An example of how to count the number of vowels in a string.
*
* YouTube Lesson: https://www.youtube.com/watch?v=heJ56FVFrZ4
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int vowel_count(char *s);

int main(void)
{
  // sample strings
  char s1[] = "It's a wonderful life!";
  char s2[] = "Luke I am your Father";
  char s3[] = "AaEeIiOoUu";

  // try to get the vowel counts
  int s1count = vowel_count(s1);
  int s2count = vowel_count(s2);
  int s3count = vowel_count(s3);

  // output the vowel counts
  printf("s1 vowel count: %d\n", s1count);
  printf("s2 vowel count: %d\n", s2count);
  printf("s3 vowel count: %d\n", s3count);

  return 0;
}

// Returns the number of vowels in the provided string
int vowel_count(char *s)
{
  int count = 0;
  for (int i = 0; i < strlen(s); i++)
  {
    // convert each character to upper case, use fall-through logic to handle
    // each vowel case: https://w.wiki/3UTm
    switch (toupper(s[i]))
    {
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        count++;
    }
  }
  return count;
}

