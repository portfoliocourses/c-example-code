/*******************************************************************************
*
* Program: Create Your Own strchr() Function
* 
* Description: Example of creating our own version of the strchr() function in 
* C found in the string.h library.  The function returns a pointer to the 
* 
*
* YouTube Lesson: https://www.youtube.com/watch?v=nxCnKVMGAFs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

// We put an underscore in front of the name of the function to differentiate it
// from the official version of the function.  The return type and parameters 
// are the same as the official version.  Notably the first parameter, the
// pointer to the string, is of type const char *.  This means the pointer 
// itself is mutable, i.e. we can change which character str is pointing to.  
// BUT 'const' means that we cannot change the values in the string, i.e. we 
// can't set the char that str is pointing to to some other character.  This 
// makes it very explicit that the function will not be modifying the string 
// itself.  The function returns a non-const char * because the programmer 
// using the function may want to modify the string in some other way.  Also 
// note that the second argument is of type int, this is because characters in C
// are represented with integers (with the help of a character encoding like 
// ASCII or UTF-8).  
char *_strchr(const char *str, int c);

int main(int argc, char *argv[])
{
  // create a test string
  char *string = "This is MY string!";
  
  // first_M should be a pointer to the first 'M' character in the test string
  char *first_M = _strchr(string, 'M');
  
  // If we output the string starting from first_M we will get "MY string!"
  printf("first_M: %s\n", first_M);
  
  // There is no 'Z' character in the string, so the function should return NULL
  char *first_Z = _strchr(string, 'Z');
  
  // check that first_Z is set to NULL by outputting "No 'Z' found!" if it is
  if (first_Z == NULL)
    printf("No 'Z' found!\n");
  
  return 0;
}

// Returns a pointer to the first occurrence of the character c in the string 
// pointed to be str
char *_strchr(const char *str, int c)
{
  // str++ will use pointer arithmetic to set str to point to the next character
  // in the string from where it currently points to
  //
  // *str will access the character that str is currently pointing to

  // We "loop through each character" in the string using the str pointer, we 
  // stop the loop when str points to the null terminator and with each 
  // loop iteration we set str to point to the next character in the string with
  // str++
  while (*str != '\0')
  {
    // Check to see if the character str is currently pointing to is equal to 
    // the character we're looking for, if it is we return the pointer to this 
    // character.  We typecase the pointer to (char *) because str is of type 
    // (const char *).
    if (*str == c) return (char *) str;
    
    // Set str to point to the next character in the string
    str++;
  }
  
  // If the character was not found in the string, we return NULL the same as
  // the official version of the function
  return NULL;
}