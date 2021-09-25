/*******************************************************************************
*
* Program: Verify Password Requirements Demonstration
* 
* Description: Example of verifying a password conforms to requirements in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=jBx_COn2ptE 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool verify_password(char *p);

int main()
{
  // test out this password
  char p[] = "Ax5@abcdefg";
  bool result = verify_password(p);
  if (result) printf("Verified password!\n");
  else printf("Invalid password!\n");
  
  return 0;
}

// Verifies that the password conforms to the following requirements:
//
// at least 8 characters long
// at least 1 uppercase letter
// at least 1 lowercase letter
// at least 1 digit
// at least 1 symbol
//
// returns true if password p conforms to these requirements and false otherwise
//
bool verify_password(char *p)
{
  // check if the length is insufficient
  int length = strlen(p);
  if (length < 8) return false;
  
  bool has_upper = false;
  bool has_lower = false;
  bool has_digit = false;
  bool has_symbol = false;
  
  // check for each of the required character classes
  for (int i = 0; i < length; i++)
  {
    if (isupper(p[i])) has_upper = true;
    if (islower(p[i])) has_lower = true;
    if (isdigit(p[i])) has_digit = true;
    if (ispunct(p[i])) has_symbol = true;
  }
  
  // return false if any required character class is not present
  if (!has_upper) return false;
  if (!has_lower) return false;
  if (!has_digit) return false;
  if (!has_symbol) return false;
  
  // if we couldn't invalidate the password it must be valid
  return true;
}


