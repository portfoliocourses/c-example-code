/*******************************************************************************
*
* Program: puts() Demonstration
* 
* Description: Examples of using the puts() string output function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=63DBdFI-7tw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(void)
{
  // We can use puts() to ouput a string, including string literals.  The string
  // provided as an argument will be output, followed by a newline character, 
  // so in the below function calls "Print another string" will occur on the 
  // next line of the terminal/shell.
  puts("Print string literal");
  puts("Print another string");
  
  // Unlike printf() we cannot use a format string with placeholders and supply
  // multiple arguments to puts().  The below function call to printf() for 
  // example would ouput the string "10 12".  With puts() we only supply one 
  // string as an argument and exactly that string is output.
  //
  // printf("%d %d", 10, 12);

  // puts() adds a newline on to the end of a string unlike printf(), notice 
  // how these calls to printf() will output one string directly after the 
  // other. 
  //
  // printf("Print string literal");
  // printf("Print another string");  
  
  // We can supply a pointer to a string literal as an argument and puts() 
  // will output the string.
  char *text1 = "Print string literal";
  puts(text1);
  
  // We can supply an array storing a string as an argument to puts() and it 
  // will also output the string.
  char text2[] = "String in char array";  
  puts(text2);

  // If puts() fails it will return EOF, we can check for that and end the 
  // program with '1' as the status code if this is the case to signal to the 
  // shell that something has gone wrong with the execution of our program.
  if (puts(text2) == EOF)
  {
    return 1;
  }

  return 0;
}