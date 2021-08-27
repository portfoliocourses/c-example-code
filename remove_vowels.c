/*******************************************************************************
*
* Program: Remove vowels from a string demonstration
* 
* Description: Removes all vowels from a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=40XRhfcUtaU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(void) 
{
  // we will remove the vowels from this string by modifying it in-place, i.e. 
  // modifying the string itself
  char s[] = "This is the way.";  

  // curpos will be used to increment over each character in the 'current' 
  // version of the string
  int curpos = 0;

  // newpos will be used to build the 'new' version of the string, it will set 
  // each character in the new version of the string, only setting a character 
  // and incrementing the character curpos refers to is NOT a vowel
  int newpos = 0;

  // loop over each character in the string 
  while (curpos < strlen(s))
  {
    // if the character curpos refers to currently is NOT a vowel, set a new 
    // character at the newpos position and increment newpos
    if ( !(s[curpos] == 'a' || s[curpos] == 'e' ||
           s[curpos] == 'o' || s[curpos] == 'i' ||
           s[curpos] == 'u') )
    {
      s[newpos] = s[curpos];
      newpos++;
    }

    // we always increment curpos because it will need to help us look at 
    // EVERY character in the original version of the string
    curpos++;
  }

  // shift up the null terminator to newpos because the string will be shorter
  // assuming we've encountered some number of vowels
  s[newpos] = '\0';
  
  // output the modified string
  printf("s: %s\n", s);

  return 0;
}
