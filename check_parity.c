/*******************************************************************************
*
* Program: Check If An Integer Is Even Or Odd 
* 
* Description: How to check whether an integer is even or odd (i.e. its parity)
* in C.  Parity as a concept is described here: 
* https://en.wikipedia.org/wiki/Parity_(mathematics)  
*
* YouTube Lesson: https://www.youtube.com/watch?v=6Zd69FQpc3A 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

bool is_even(int number);
bool is_odd(int number);

int main(void)
{
  int number = 15;
  
  // check if the number is even or odd... modify the number above to get 
  // different results
  if (is_even(number))
    printf("number is even\n");
  else if (is_odd(number))
    printf("number is odd\n");
  
  return 0;
}

// returns true if the number is even and false if it is odd
bool is_even(int number)
{
  // A number is even if it is divisible by 2... i.e. if when we divide the 
  // number by 2, the remainder is 0.  The modulus operator % returns the 
  // remainder of a division, and so we check if number % 2 == 0
  if (number % 2 == 0) return true;
  else return false;
}

// returns true if the number is odd and false if it is even
bool is_odd(int number)
{
  // the remainder of dividing an integer by 2 can only be 0 or 1, so if the 
  // remainder of number % 2 is 1 then it must be odd
  if (number % 2 == 1) return true;
  else return false;
}
