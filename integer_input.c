/*******************************************************************************
*
* Program: Advanced Integer Input Validation
* 
* Description: How to validate integer input in C using more advanced techniques
* than the standard approach using scanf.
*
* YouTube Lesson: https://www.youtube.com/watch?v=W3dtyZr8rcY 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 4096

bool parse_int(char *string, int *integer);

int main(void)
{
  int integer = 0;
  bool parsed_correct = true;
  
  // keep asking the user for an integer until it has been validated as correct
  do
  {
    // prompt the user for the integer
    printf("Enter integer: ");
    
    // accept a line of string input from the user, store it into buffer
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stdin);
    
    // validate the integer input, store the int into integer if it was 
    // validated as correct
    parsed_correct = parse_int(buffer, &integer);
    
    // if the input was not a valid integer, tell the user this
    if (!parsed_correct)
      printf("Must be an integer value!\n");
    
  } while (!parsed_correct);
  
  // once an integer has been successfully entered, output it back to the user
  printf("Integer: %d\n", integer);
  
  return 0;
}

// Returns true if string contains one integer (with possible leading and 
// trailing whitespace), and false otherwise.  If the string contains an 
// integer, return it via the integer pointer and pass-by-pointer.
//
// So valid strings would include:
//
// "4", "   56", "-52  ", " -00000 ", "     -12    "
//
// And invalid strings would include:
//
// "4  5", "  9    2   ", "  3.4", "-4.5", "  abc", "sd",  "123 9.4"
//
bool parse_int(char *string, int *integer)
{
  // i will keep our current index into the string as we loop through it 
  // one character at a time
  int i = 0;
  
  // move through any leading whitespace
  while (isspace(string[i])) i++;
  
  // get the length of the string
  int length = strlen(string);
  
  // if the entire string was just whitespace characters ("a blank string") 
  // we'll have reached the end of the string and we can return false as the 
  // string did not contain an integer
  if (length == i) return false;
  
  // the integer chars will be stored into integer_buffer, we'll use 
  // integer_chars to keep track of our index into this buffer as we store 
  // each character
  char integer_buffer[BUFFER_SIZE];
  int integer_chars = 0;
  
  // in the case of a negative integer, the first char may be - symbol
  if (string[i] == '-')
  {
    // store the symbol into the buffer, and advance both indexes into the 
    // string and buffer
    integer_buffer[integer_chars] = '-';
    integer_chars++;
    i++;
    
    // if the - character is not followed by a digit, the string does not 
    // contain a valid integer
    if (!isdigit(string[i])) return false;
  }
  
  // loop through characters until we reach the end of the string or a trailing
  // whitespace character
  while (i < length && !isspace(string[i]))
  {
    // if we encounter anything that is not a digit, we do not have a valid int 
    // in the string
    if (!isdigit(string[i])) return false;
    
    // store the next character into the buffer, advance both indexes
    integer_buffer[integer_chars] = string[i];
    integer_chars++;
    i++;
  }
  
  // put a null terminator onto the end of the buffer to make it a proper string
  integer_buffer[integer_chars] = '\0';
  
  // loop through any trailing whitespace characters
  while (isspace(string[i])) i++;
  
  // if after doing so, we are NOT at the end of the string, then the string 
  // does not contain a valid integer
  if (string[i] != '\0') return false;
  
  // atoi converts the string representation of our integer to an int type 
  // value in C, and we de-reference integer to "return" the value via a pointer
  *integer = atoi(integer_buffer);
  
  // we've successfully validated the presence of an int and so can return true
  return true;
}