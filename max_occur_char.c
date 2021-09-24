/*******************************************************************************
*
* Program: Find Maximum Occurring Character demonstration
* 
* Description: Example of finding and printing the maximum occurring character 
* in a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=KFl8iyx66fI
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void print_max_char(char *s);

int main()
{
  // test the function with this string where c is the maximum occurring char
  char s[] = "abcdefghabcdefghabccccdefgh";
  print_max_char(s);

  return 0;
}

// find and print the maximum occurring character in the string s
void print_max_char(char *s)
{
  // the unique array will store the characters that have already been counted
  int length = strlen(s);
  char unique[length];
  int counted = 0;
  int max_count;
  char max_char;

  // check each char in the string
  for (int i = 0; i < length; i++)
  {
    // check to see if the char has already been counted
    bool already_counted = false;
    for (int j = 0; j < counted; j++)
      if (s[i] == unique[j])
        already_counted = true;

    // if the char has already been counted, skip the remainder of the loop
    if (already_counted) continue;

    // count how many times the char occurs in the string
    int count = 0;
    for (int j = 0; j < length; j++)
      if (s[i] == s[j]) count++;

    // add the char to the array of already counted characters
    unique[counted] = s[i];
    counted++;

    // determine if this is the new maximum occurring char... if it is the 
    // first char we've counted it is the maximum by default, otherwise 
    // we update the max count/char if this char occurs a higher number of times
    if (counted == 1)
    {
      max_count = count; 
      max_char = s[i];
    }
    else if (count > max_count)
    {
      max_count = count; 
      max_char = s[i];
    }

  }

  // output the maximum occurring char and number of occurrences, output an 
  // error message if the string contained no characters at all
  if (length > 0)
    printf("%c:%d\n", max_char, max_count);
  else 
    printf("error: string has 0 length\n");

}

