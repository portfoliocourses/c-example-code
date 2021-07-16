/*******************************************************************************
*
* Program: ctype demo
* 
* Description: Demonstration of the ctype library functions in C.
*
* Character classes:
*   https://en.cppreference.com/w/c/string/byte
*
* YouTube Lesson: https://www.youtube.com/watch?v=aTSJFoqTZrI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
  // isalnum returns true if the char is alphanumeric, false otherwise 
  //
  // if (isalnum('a')) printf("true\n");
  // else printf("false\n"); 
  // if (isalnum('Z')) printf("true\n");
  // else printf("false\n"); 
  // if (isalnum('8')) printf("true\n");
  // else printf("false\n"); 
  // if (isalnum('$')) printf("true\n");
  // else printf("false\n"); 

  // isalpha returns true if the char is alphabetic, false otherwise 
  // 
  // if (isalpha('c')) printf("true\n");
  // else printf("false\n"); 
  // if (isalpha('8')) printf("true\n");
  // else printf("false\n"); 

  // iscntrl returns true if the character is a control char, false otherwise
  //
  // if (iscntrl('c')) printf("true\n");
  // else printf("false\n"); 
  // if (iscntrl('\n')) printf("true\n");
  // else printf("false\n"); 

  // isdigit returns true if the char is a digit, false otherwise
  //
  // if (isdigit('2')) printf("true\n");
  // else printf("false\n"); 
  // if (isdigit('T')) printf("true\n");
  // else printf("false\n"); 

  // isgraph returns true if the char has a graphical representation, false 
  // otherwise
  //
  // if (isgraph('5')) printf("true\n");
  // else printf("false\n"); 
  // if (isgraph(' ')) printf("true\n");
  // else printf("false\n"); 

  // islower returns true if the char is lowercase, false otherwise
  // 
  // if (islower('g')) printf("true\n");
  // else printf("false\n"); 
  // if (islower('G')) printf("true\n");
  // else printf("false\n"); 

  // isupper returns true if the char is uppercase, false otherwise
  //
  // if (isupper('g')) printf("true\n");
  // else printf("false\n"); 
  // if (isupper('G')) printf("true\n");
  // else printf("false\n"); 

  // isprint returns true if the char is printable, false otherwise
  //
  // if (isprint(' ')) printf("true\n");
  // else printf("false\n"); 
  // if (isprint('\n')) printf("true\n");
  // else printf("false\n"); 

  // ispunct returns true if the char is punctuation, false otherwise
  //
  // if (ispunct(';')) printf("true\n");
  // else printf("false\n"); 
  // if (ispunct('x')) printf("true\n");
  // else printf("false\n"); 

  // isspace returns true if the char is whitespace, false otherwise
  //
  // if (isspace(' ')) printf("true\n");
  // else printf("false\n"); 
  // if (isspace('\t')) printf("true\n");
  // else printf("false\n"); 
  // if (isspace('\n')) printf("true\n");
  // else printf("false\n");   
  // if (isspace('@')) printf("true\n");
  // else printf("false\n");  
 

  // isxdigit returns true if the char is a hexidecimal digit, false otherwise 
  //
  // 0 - 9, a-f, A-F
  // if (isxdigit('F')) printf("true\n");
  // else printf("false\n");  

  // if (isxdigit('G')) printf("true\n");
  // else printf("false\n");  

  
  // tolower and toupper convert chars to lowercase and uppercase, having no 
  // effect if the char cannot be converted
  char c = tolower('A');
  printf("c: %c\n", c);
  char d = toupper('a');
  printf("d: %c\n", d);
  char e = toupper('@');
  printf("e: %c\n", e);

  return 0;
}
