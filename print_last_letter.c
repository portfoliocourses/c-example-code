/*******************************************************************************
*
* Program: Print The Last Letter Of Each Word In A String 
* 
* Description: Program to print the last letter of each word in a string using
* C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=ZO8SdOyhDJs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
  // char array which stores a test string where last letter of each word 
  // gives us "code"
  char string[] = "Basic Video, Good Code";
  
  // Find the length of the string (not including null terminator character 
  // which signifies the end of the string).  
  int length = strlen(string);

  // We'll go through the string one character at a time and keep track of 
  // whether we are currently "reading a word" or not using reading_word, in 
  // order to help output the last letter of each word.  We initialize it to
  // false because we have not yet read any characters yet.  
  bool reading_word = false;
  
  // Loop counter variable i will go through each index of the string in order
  // one at a time with each loop iteration, INCLUDING the index of the null 
  // terminator.  We use i to examine the string one character at a time.  
  // 
  // We consider words to consist of characters from a-z and A-Z and all other 
  // characters to be non-word characters.  The isalpha() function returns true
  // if a character it is passed is from a-z or A-Z, and false otherwise.  The 
  // algorithm works by keeping reading_word up to date as to whether we are 
  // currently reading a word, and when we transition from reading a word to 
  // not reading a word, we output the last letter of that word. 
  for (int i = 0; i <= length; i++)
  {
    // If we are NOT currently reading a word and the character we are currently
    // examining IS a letter, we have encountered the first letter of a new 
    // word.  We set reading_word to true to acknowledge we are now reading a 
    // word.  
    if (!reading_word && isalpha(string[i]))
    {
      reading_word = true;
    }
    // If we ARE currently reading a word and the character we are currently 
    // examining is NOT a letter, we have reached the end of a word and set 
    // reading_word to false to acknowledge this.  We output the character at
    // the index i-1, i.e. the last letter of the word we've just finished 
    // reading.  Notably the counter variable i will go up until and including
    // the index length which is the index of the null terminator, in this case
    // isalpha() will return false and !isalpha(string[i]) will be true... so 
    // if reading_word is true (as would be in our example above) then we'll 
    // output the last letter of the final word in the string.   
    else if (reading_word && !isalpha(string[i]))
    {
      reading_word = false;
      printf("%c", string[i - 1]);
    }
  }
  printf("\n");
  
  return 0;
}