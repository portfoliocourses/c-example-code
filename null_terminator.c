/*******************************************************************************
*
* Program: Null Terminator Examples
*
* Description: Examples of using the null terminator character in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=2C-PSQCcDDo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(void)
{
  // Declare a char array and initialize it with a string, when we do this a 
  // special null terminator character \0 will be the last character in the 
  // string.  This character is a special character that terminates the string,
  // it signifies the end of the string.
  char string[] = "abcd";

  // When we use printf() to output the string, the printf() functions and 
  // others in C use the null terminator to recognize when the end of the string
  // has been reached (and when to stop printing characters).
  printf("string: %s\n\n", string);
  
  // We can output each character in the string individually, but the final 
  // null terminator character is not printable and so we will not get any 
  // character output for the final null terminator character.
  printf("string[0] = %c\n", string[0]);
  printf("string[1] = %c\n", string[1]);
  printf("string[2] = %c\n", string[2]);
  printf("string[3] = %c\n", string[3]);
  printf("string[4] = %c\n\n", string[4]);
  
  // But the character IS there, we can detect it with an if-statement...
  if (string[4] == '\0')
  {
    printf("Null terminator character at string[4]\n\n");
  }
  
  // If we were to put another null terminator character at an earlier 
  // position in the string then the string would be terminated earlier! So here
  // we will terminate the string after the characters "ab" and our string will
  // now only be "ab" and not "abcd".
  string[2] = '\0';
  
  // Output the string again to verify it is now considered "ab"
  printf("string: %s\n\n", string);
  
  // Each character is represented with an integer according to a character
  // encoding, so 'A' is the integer 65 and 'B' is the integer 66.
  printf("A = %d\n", 'A');
  printf("B = %d\n", 'B');
  
  // Though '\0' looks like two characters, this is only the case in the 
  // text editor used to write the program.  It is actually one character and 
  // '\0' is used to represent the character.  When we output the integer 
  // that represents the null terminator '\0' we will find it is 0.  So the 
  // null terminator is equivalent to 0, i.e. the byte with all bits set to 0.
  printf("\\0 = %d\n\n", '\0');
  
  // We can declare another char array and initialize it with another string
  char string2[] = "Portfolio";
  
  // We can output the string 
  printf("string2: %s\n", string2);
  
  // If we set the index 4 in the char array to 0, this is equivalent to 
  // inserting a null terminator at index 4, and so the string will now only
  // by "Port", the first 4 characters in the char array from indexes 0...3.
  string2[4] = 0;
  
  // Output the string again to verify is it now only "Port"
  printf("string2: %s\n\n", string2);
  
  // The integer 0 is "false" in C and all non-zero integers are "true" in C.
  // So we can use the null terminator in if-statement and loop conditions to 
  // detect if a null terminator character is present or not.  For example if 
  // we have !character as a condition and the character IS the null 
  // terminator, the condition will be true (otherwise it will be false).  We
  // utilize this below to output that the character at the index 4 is the 
  // null terminator...
  if (!string2[4])
  {
    printf("Character is the null terminator.\n");
  }
  else
  {
    printf("Character is NOT the null terminator.\n");
  }
  
  // Declare a char array and initialize it with a string
  char string3[] = "Courses";
  
  // We can loop through the characters in the string using a char pointer 
  // variable.  We set the char pointer variable p to point to the string, this
  // will have p point to the first character in the string.
  char *p = string3;
  
  printf("\n");

  // We can de-reference p and access the character it is pointing to with *p,
  // so by having *p as a loop condition, the loop will continue so long as p
  // is NOT pointing to the null terminator (as all other characters are 
  // considered true).  And the loop will STOP once p reaches the end of the 
  // string and IS pointing to the null terminator (which is considered false).
  while (*p) 
  {
    // De-reference p and output the character that p is currently pointing to
    printf("%c\n", *p);
    
    // Use pointer arithmetic to increment p and have it point to the next 
    // character in the string, in this way we'll "loop through" each character
    // in the string.
    p++;
  }
  printf("\n");
 
  return 0;
}