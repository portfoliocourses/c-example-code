/*******************************************************************************
*
* Program: Find Minimum Occurring Character demonstration
* 
* Description: Example of finding and printing the minimum occurring character 
* in a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=euzKnNGLs8U 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void print_min_char(char *s);

int main()
{
  // test the function with this string where h is the minimum occurring char
  char s[] = "abcdefghabcdefghabcdefg";
  print_min_char(s);

  return 0;
}

// find and print the minimum occurring character in the string s
void print_min_char(char *s)
{
  // the unique array will store the characters that have already 
  int length = strlen(s);
  char unique[length];
  int counted = 0;
  int min_count;
  char min_char;
  
  // check each character in the string
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
    
    // determine if this is the new minimum occurring char... if it is the 
    // first char we've counted it is the minimum by default, otherwise 
    // we update the min count/char if this char occurs a lower number of times
    if (counted == 1)
    {
      min_count = count;
      min_char = s[i];
    }
    else if (count < min_count)
    {
      min_count = count;
      min_char = s[i];
    }
  }

  // output the minimum occurring char and number of occurrences, output an 
  // error message if the string contained no characters at all
  if (length > 0)
    printf("%c:%d\n", min_char, min_count);
  else 
    printf("error: string has 0 length\n");
}
