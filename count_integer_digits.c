/*******************************************************************************
*
* Program: Count The Digits In An Integer Number
*
* Description: Program to count the digits in an integer number using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=plcWVEzH5PI
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(void)
{
  // 415 / 10 = 41 remainder 5
  //  41 / 10 =  4 remainder 1
  //   4 / 10 =  0 remainder 4
  
  int number = 0;
  int total = 0;
  
  printf("Enter Number: ");
  scanf("%d", &number);
  
  do
  {
    number /= 10;
    total++;
  } while (number != 0);
  
  printf("Total Digits: %d\n", total);
  
  return 0;
}