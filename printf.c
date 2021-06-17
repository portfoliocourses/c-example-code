/*******************************************************************************
*
* Program: printf tutorial
* 
* Description: Examples of using printf.
*
* YouTube Lesson: https://www.youtube.com/watch?v=ycKZKDCMMzM
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// Printf placeholder structure (simplified):
//
// %[flags][width][.precision]specifier
//
// Wikipedia article gives full coverage of all possibilities (pretty 
// extensive): https://w.wiki/3VtV
//

int main(void)
{
  // Basic examples of printf with special characters for newline, tab, etc.
  printf("Hello, World! \n");
  printf("\tAnother line of text!\n");
  printf("double quote: \" \n");
  printf(" \\ \n");

  // using placeholders to output ints
  int x = 5;
  printf("x: %d \n", x );
  printf("%d, %d, %d \n", x, x+1, x+2 );

  // examples for char, double, float and strings
  char c = 'Q';
  printf("c: %c\n", c);

  double y = 4.56;
  printf("y: %f \n", y);

  float z = 2.5;
  printf("z: %f \n", z);

  char str[] = "A string to output!\n";
  printf("str: %s", str);

  // examples of using width, precision, etc, placeholder fields to alter output 
  printf("|||%-10d|||\n", 5);
  printf("|||%-8.3f|||\n", y);

  return 0;
}




