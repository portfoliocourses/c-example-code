/*******************************************************************************
*
* Program: Convert Decimal To Binary
* 
* Description: Convert a non-negative integer decimal number to a binary number
* stored in a string using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=DSZ4pNCoYZY    
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main()
{
  // used to store binary number represented as a string
  char binary[256];
  
  // used to store the decimal number
  int decimal;
  
  do
  {
    // prompt the user for the number, store it into decimal 
    printf("Enter A Non-Negative Integer: ");
    scanf("%d", &decimal);
    
    // if the number is negative, tell the user it must be non-negative
    if (decimal < 0)
      printf("Integer Must Be Non-Negative");

  // continue to ask the user until a non-negative number is entered
  } while (decimal < 0);
  
  // length keeps track of the current length of binary number as we build it
  int length = 0;
  
  // perform the conversion algorithm (see description below main function)
  do
  {
    // determine the next digit of the binary number
    if (decimal % 2 == 0) binary[length] = '0';
    else binary[length] = '1';
    
    // divide the number by 2 for the next iteration of the algorithm
    decimal /= 2;

    // advance length by 1 to set the next index of binary, the next digit in
    // our binary number
    length++;
    
  // continue with the algorithm until decimal is equal to 0
  } while (decimal != 0);
  
  // put a null terminator at the end of the string to terminate the string
  binary[length] = '\0';
  
  // the binary number stored in binary is technically reversed, so we reverse 
  // the string to put it in the correct order

  // find the middle position of the string
  int middle = length / 2;
  
  // swap each character/digit at the beginning of the string until the middle 
  // of the string with the corresponding character at the end of the string in
  // order to reverse the string, see... 
  //    - Reverse A String: https://www.youtube.com/watch?v=PtSHcou0WIs
  char temp;
  for (int i = 0; i < middle; i++)
  {
    temp = binary[i];
    binary[i] = binary[length - i - 1];
    binary[length - i - 1] = temp;
  }
  
  // output the binary number
  printf("\nBinary Number: %s\n\n", binary);
  
  return 0;
}

// Conversion Algorithm:
//
// Repeat until the number is equal to 0:
//
//   Divide the number by 2:
//     - remainder is the next digit in the binary number
//     - quotient is used as the number in next iteration
//
// So for exmample if we wish to conver the number 43:
//
// 43 / 2 = 21   1 remainder
// 21 / 2 = 10   1 remainder
// 10 / 2 = 5    0 remainder
//  5 / 2 = 2    1 remainder
//  2 / 2 = 1    0 remainder
//  1 / 2 = 0    1 remainder
//
// Binary Number: 101011
//               /  | | \
//             32   8 2  1  = 43