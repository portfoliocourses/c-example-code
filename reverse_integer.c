/*******************************************************************************
*
* Program: Reverse An Integer
* 
* Description: Example of reversing an integer in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=lXr6KKha-ig 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  int number = 0;
  int reverse = 0;
  int remainder = 0;

  // ask the user to enter the number  
  printf("Enter number: ");
  scanf("%d", &number);

  // The algorithm works by continually extracting the next right-most digit 
  // from number, shifting the reverse number to the left by 1 digit by 
  // multiplying it by 10, adding that new digit to the end of reverse, and 
  // then "contracting" number by a digit by dividing it by 10.
  while (number != 0)
  {
    // extracts the right-most digit from number
    remainder = number % 10;

    // shift the numbers in reverse over by 1 to the left
    reverse = reverse * 10;

    // adds the remainder to the end of reverse
    reverse = reverse + remainder;

    // contracts the number by 1 digit, removing the leftmost remainder digit 
    // we just accounted for from the number
    number = number / 10;
  }
  
  // output the reverse the number
  printf("Reversed number: %d\n", reverse);
  
  return 0;
}
