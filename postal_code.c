/*******************************************************************************
*
* Program: Verify Canadian Postal Codes
* 
* Description: 
*
* Canadian postal codes have the format: "A#A #A#", where A is a letter A-Z and 
* # is a number from 0-9.  In this example we create a function to verify a 
* string is a valid postal code and run it with some example strings.  We
* check for the correct number of characters (7 including the space), and the 
* correct character at each position.  We use isdigit and isalpha from the ctype
* library to help with this.  We use strlen from string library to help check 
* for the string length.
*
* YouTube Lesson: https://www.youtube.com/watch?v=R0qIYWo8igs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>    // needed for strlen, strcmp
#include <ctype.h>     // needed for isdigit, isalpha
#include <stdbool.h>   // needed for using bools

bool is_postal_code(char postal_code[]);

int main()
{
  char code1[] = "L8K 4B6";  // valid
  char code2[] = "L86 4B65"; // too long
  char code3[] = "L864B6";   // missing space
  char code4[] = "L8G 4BG";  // last char is not a digit

  if (is_postal_code(code1)) printf("%s is a postal code\n", code1);
  else printf("%s is not a postal code\n", code1);

  if (is_postal_code(code2)) printf("%s is a postal code\n", code2);
  else printf("%s is not a postal code\n", code2);

  if (is_postal_code(code3)) printf("%s is a postal code\n", code3);
  else printf("%s is not a postal code\n", code3);

  if (is_postal_code(code4)) printf("%s is a postal code\n", code4);
  else printf("%s is not a postal code\n", code4);    

  return 0;
}

// returns true if postal_code contains a postal_code and false otherwise
bool is_postal_code(char postal_code[])
{
  // check for all conditions that could break the postal code pattern
  if (strlen(postal_code) != 7) return false;
  if (!isalpha(postal_code[0])) return false;
  if (!isdigit(postal_code[1])) return false;
  if (!isalpha(postal_code[2])) return false;
  if (postal_code[3] != ' ') return false;
  if (!isdigit(postal_code[4])) return false;
  if (!isalpha(postal_code[5])) return false; 
  if (!isdigit(postal_code[6])) return false;
  
  // if none of the above, we have a postal code!
  return true;
}