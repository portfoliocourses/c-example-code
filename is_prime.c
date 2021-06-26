/*******************************************************************************
*
* Program: Check if a number is prime
* 
* Description: An example of a function for checking whether a number is prime 
* or not.
*
* YouTube Lesson: https://www.youtube.com/watch?v=TT3mJoKQocw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int number);

int main(void)
{

  // check if the integers 2-9999 are prime or not, output the prime numbers
  for (int i = 2; i < 10000; i++)
    if (is_prime(i)) printf("%d,", i);
  printf("\n");

  return 0;
}

// returns true if number is prime, false otherwise
bool is_prime(int number)
{
  if (number <= 1) return false;

  // Check if a number is not prime by checking for possible factors between 2 
  // and the number... if the number can be divided by the potential factor 
  // (i.e. zero remainder) then the potential factor is a factor and the number 
  // is not prime!  We only need to search up until number / 2 since factors 
  // come in pairs (e.g. 2 and 4 are both factors of 8).
  for (int i = 2; i < (number / 2); i++)
     if (number % i == 0) return false;

  // if we couldn't find a factor, the number must be prime!
  return true;
}

