/*******************************************************************************
*
* Program: A program that prints its own source code
* 
* Description: Examples of a program that prints its own source code in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=m8uQ0cJKDM0 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  FILE *fp;
  char c;
  
  // __FILE__ is a preprocessor macro that will be set to the name of the source
  // code file, and we use this to open the source code file for reading
  fp = fopen(__FILE__, "r");
  
  // read in each char of the file, store it into c and then print it, until 
  // the char is set to EOF by getc() which signifies the End Of File
  while (  (c = getc(fp)) != EOF )
    putchar(c);

  fclose(fp);
 
  return 0;
}