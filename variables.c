/*******************************************************************************
*
* Program: Basics of variables
* 
* Description: Basic examples of the four standard variable types in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=zPObUTmiCzk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// Variables can be thought of as boxes in memory that store values our program
// will use, and each box has a name (e.g. position) and a type (int).
// 
//       position   x   y   z
//  int  10         2   3   4
//

int main(void)
{
  // int variables store numbers with no decimal point like these:
  //   -5, 0, 20, 512
  // they are like whole numbers (0,1,2,3,...) but they include the negative 
  // integers too (-1,-2,...)
  //
  // We can declare int variables and assign values to them:
  //
  int position = 10;
  int x, y, z;
  x = 2;
  y = 3;
  z = 4;

  // float and double variables both store real numbers, i.e. numbers with 
  // decimal points to them like: -2.5, 98.2, 150.456789
  //
  // we can declare and initialize floats and doubles:
  float mynum = 98.125678;
  double mydouble = 98.125678;

  // char variables store individual characters like 'Y'
  //
  char c = 'Y';

  // char variables *technically* are an int value too... int values are 
  // assigned to characters via an encoding, such as ASCII, that represents 
  // printable characters like A,B,C,etc with positive integers, see:
  //   https://en.wikipedia.org/w/index.php?title=ASCII&oldid=1027589878
  //
  // if we uncomment the below line, c will store the character 'q'!
  //
  // char c = 113;

  // output the variables
  printf("position: %d\n", position);
  printf("x: %d, y: %d, z: %d\n", x,y,z);
  printf("mynum: %lf\n", mynum);
  printf("mydouble: %lf\n", mydouble);
  printf("c: %c\n", c);

  // we can change the value of variables as the program is running...
  x = 10;
  y = 20;
  z = 30;

  // we can then output the altered values
  printf("x: %d, y: %d, z: %d\n", x,y,z);

  return 0;
}