/*******************************************************************************
*
* Program: Print A String Until The First Newline demonstration
* 
* Description: Example of printing a string until the first newline character
* with putchar() in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=nixt_K8kgos 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

void print_until_newline(char *s);

int main()
{
  // test the function with this string
  char s[] = "This is the way. Again!";
  print_until_newline(s);
  printf("\n");

  return 0;
}

// prints the string s until the first newline char is encountered
void print_until_newline(char *s)
{
  // loop through each char in the string, using putchar() to print the char,
  // up until we encounter either the first newline char OR each the end of 
  // the string (the null terminator)
  int i = 0;
  while (s[i] != '\n' && s[i] != '\0')
  {
    putchar(s[i]);
    i++;
  }
}
