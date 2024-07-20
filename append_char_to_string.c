/*******************************************************************************
*
* Program: Append A Character To A String
*
* Description: Program to append a character to a string using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=cDvA89WpgMw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
  // The string "subscribe" is stored into the char array buffer.  Notably the 
  // the string only takes 10 chars to store (9 characters for subscribe and 
  // then one more for the null terminator \0 that terminates the string).  So
  // because the buffer can store up to 100 characters, there is 90 extra 
  // chars worth of space in this char array.
  char buffer[100] = "subscribe";

  // Declare a char variable to store the character we wish to append to the
  // string
  char character = 'r';
  
  // Appends the character onto the string stored in buffer.
  strncat(buffer, &character, 1);

  // Typically when strncat() is called we pass it two string as arguments,
  // so something like this:
  //
  // char source[] = "AAA";
  //
  // strncat(buffer, source, 2);
  //
  // When we pass buffer (i.e. the destination string) and source to the 
  // function, what really gets passed is the memory address of the first 
  // character in those strings.  In this function call here, the first two
  // characters of source would be appended to the string stored in 
  // buffer.
  //
  // Above when we call strncat() and pass it &character, what we're passing
  // in the memory address of the character variable, i.e. the character 
  // we want to append to the string.  And because was pass in '1' this is 
  // OK as we are only going to append this one single character to the 
  // buffer string.
  //
  // Note that buffer, or whatever destination char array we use, must be
  // large enough to store the new string which will be one character 
  // longer.  
  
  // Output the new string stored in buffer.
  printf("%s\n", buffer);
  
  return 0;
}