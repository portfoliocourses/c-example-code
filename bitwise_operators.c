/*******************************************************************************
*
* Program: Bitwise operands demonstration
* 
* Description: Examples of using the bitwise operators in C.  The bitwise 
* operators work with the actual bits (0s and 1s) of their operands.
*
* YouTube Lesson: https://www.youtube.com/watch?v=WBim3afbYQw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main() 
{        
  // 9 represented in binary as an unsigned integer     
  // 9 = 0000 1001 
  unsigned int x = 9;

  // 24 represented in binary as an unsigned integer     
  // 24 = 0001 1000 
  unsigned int y = 24;
  
  unsigned int r;
  
  // The shift left operator shifts the bits over some number of digits to the 
  // left, in this case by 2 digits, inserting 0s on the right-hand side.
  // 36 =  0010 0100 
  r = x << 2;
  printf("x << 1: %d\n", r);
  
  // The shift right operator shifts the bits over some number of digits to the 
  // right, in this case by 2 digits, inserting 0s on the left-hand side.
  // 2 =  0000 0010 
  r = x >> 2;
  printf("x >> 2: %d\n", r);

  // The one's complement operator flips 1s to 0s and 0s to 1s, when we output 
  // the result as an int with %d the result will actually be negative number 
  // due to the way C represents negative numbers with what is called 2s 
  // complement, see: https://en.wikipedia.org/wiki/Two%27s_complement
  // -10 = 1111 0110 
  r = ~x;
  printf("~x: %d\n", r);
  
  // Bitwise 'and' operator sets a bit to 1 if both digits in the operands are 
  // 1 and 0 otherwise.
  // 8 =  0000 1000 
  r = x & y;
  printf("x & y: %d\n", r);
  
  // Bitwise 'or' operator sets a bit to 1 if either digit in the operands are 
  // 1, and 0 otherwise.
  // 25 = 0001 1001 
  r = x | y;
  printf("x | y: %d\n", r);
  
  // Bitwise 'xor' (exclusive or) sets a bit to 1 if either (but not both) 
  // digit in the operand is 1, and 0 otherwise.
  // 17 = 0001 0001 
  r = x ^ y;
  printf("x ^ y: %d\n", r);

}

