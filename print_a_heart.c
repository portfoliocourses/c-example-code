/*******************************************************************************
*
* Program: Print A Heart
* 
* Description: Example of how to print out a heart to the terminal made up of 
* stars using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=N5D5tGTURpk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(void)
{
  // will store the "size" of the heart, i.e. the number of rows in the 
  // downwards pointing triangle portion of the heart
  int size = 0;
  
  // prompt the user for the heart size
  printf("Enter Size: ");
  scanf("%d", &size);
  printf("\n");
  
  // print out rows of upper portion of the heart with the two semi-circles
  for (int i = size/2; i <= size; i += 2)
  {
    // print the left gap (see 1 in the below illustration)
    for (int j = 1; j < size-i; j += 2) printf(" ");
    
    // print the left semi-circle (see 2 in the below illustration)
    for (int j = 1; j <= i; j++) printf("*");
    
    // print the gap between the semi-cricles (see 3 in the below illustration)
    for (int j = 1; j <= size - i; j++) printf(" ");

    // print the right semi-circle (see 4 in the below illustration)    
    for (int j = 1; j <= i; j++) printf("*");

    // print a newline so the next row starts on the next line
    printf("\n");
  }
  
  // print out the downward pointing triangle
  for (int i = size; i >= 1; i--)
  {
    // prints out increasing number of spaces on each row
    for (int j = i; j < size; j++) printf(" ");
    
    // prints out decreasing number of stars on each line
    for (int j = 0; j <= ((i * 2) - 1); j++) printf("*");
    
    // print out a newline so the next row starts on the next line
    printf("\n");
  }
  
  return 0;
}

// Program will print out hearts that look roughly like this...
//
//                        ------
//                       | This upper portion of the heart can be broken into 4
// 1  2   3   4          | sections, 1) left gap, 2) left semi-circle, 
// |  |   |   |          | 3) gap between semi-circles, 4) right semi-circle.
//   ****    ****        | Each portion is handled by an inner-loop of the first
//  ******  ******       | for loop in the above program.
// ****************       ------ 
// ****************       ------
//  **************       |
//   ************        |
//    **********         |  The "downward triangle" portion of the heart that 
//     ********          |  is printed by the second for loop in the above 
//      ******           |  program.
//       ****            | 
//        **              ------