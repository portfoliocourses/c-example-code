/*******************************************************************************
*
* Program: tolower() Function Demonstration
* 
* Description: Examples of using the tolower() function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=1EhN5HFjmw0
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
  // Set before to uppercase 'A'
  char before = 'A';
  
  // Call to the tolower() function, pass it before, and store the return value
  // into the char variable after.  The tolower() function will return the 
  // lowercase version of a letter when it is passed an uppercase letter as 
  // an argument.  So after will be set to 'a'.  The tolower() function will 
  // just return the character it is passed if it is passed a character that is 
  // not an uppercase letter.  Try changing 'A' above to 't' or '@' to see this.
  char after = tolower(before);
  
  // Ouput the before and after characters
  printf("before: %c\n", before);
  printf(" after: %c\n", after);
  

  // We can also use the tolower() function to work with characters in strings.

  // Declare a char array string and store a string inside of it
  char string[] = "STRING OF CHARACTERS";
  
  // Output the string before any modifications
  printf("string before: %s\n", string);
  
  // Pass the 3rd character in the string (at index 2) to tolower() (the char
  // 'R') and store the return value (the char 'r') back into the string at 
  // the index 2.  This will have the effect of turning that uppercase 'R'
  // character in the string into a lowercase 'r' character. 
  string[2] = tolower(string[2]);
    
  // Output the string after this modification to see the difference
  printf(" string after: %s\n", string);
  
  // The strlen() function will return the length of the string it is passed as 
  // an argument (not including the null terminator \0 character that ends the 
  // string).  Store this length into the variable length.
  int length = strlen(string);
  
  // The counter variable i in this for loop will go from 0 up until length by
  // 1 with each loop iteration, i.e. the counter variable will go over each
  // index in the string with each loop iteration.  We take each char in the 
  // string and apply tolower() and store the return value back into that 
  // char/index of the string.
  for (int i = 0; i < length; i++)
  {
    string[i] = tolower(string[i]);
  }
  
  // Now all of the uppercase letters in the string will be turned into 
  // lowercase letters.
  printf(" string lower: %s\n", string);

  return 0;
}