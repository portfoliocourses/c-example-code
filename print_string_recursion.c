/*******************************************************************************
*
* Program: Print A String Using Recursion
*
* Description: Program to print a string using a recursive function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=0H9kxHXZrgs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

void print_string(char *string);

int main(void)
{
  // Test string to print
  char test_string[] = "ABCD";

  // Call function to print string  
  print_string(test_string);

  // Output a newline afterwards (so it looks nicer on the terminal)
  printf("\n");
  
  return 0;
}

// Prints the string pointed to by 'string' recursively
void print_string(char *string)
{
  // If the string pointer is pointing to the null terminator then we've either
  // reached the end of the string OR the string was empty to begin with
  if (*string != '\0')
  {
    // Otherwise output the character in the string that 'string' is currently 
    // pointing to (the very first time the function is called 'string' will be
    // pointing to the first character in the string).
    printf("%c", *string);

    // Increment the string pointer so that it is pointing to the next character
    // in the string.
    string++;

    // Function calls itself recursively with the incremented string pointer 
    // which points to the next character in the string.  This function call 
    // will thus print out the NEXT character in the string OR STOP calling 
    // itself recursively if 'string' now points to the null terminator (when 
    // the end of the string has been reached). 
    print_string(string);
  }
}

