/*******************************************************************************
*
* Program: Punctuation marks counter demonstration
* 
* Description: Example of counting the punctuation marks in a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=7SRd_gZDqCE 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_punct(char *s);

int main()
{
  // test the function
  char s[] = "apple, pear, orange; something...";
  int total = count_punct(s);
  printf("total: %d\n", total);

  return 0;
}

// returns the number of punctuation marks in the string param s
int count_punct(char *s)
{
  int len = strlen(s);
  int count = 0;

  // examine every char, ispunct lets us know if it is a punctuation mark, 
  // keep a running count
  for (int i = 0; i < len; i++)
    if (ispunct(s[i])) count++;

  return count;
}
