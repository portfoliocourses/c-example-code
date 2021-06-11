/*******************************************************************************
*
* Program: Leap year checker
* 
* Description: An example of how to determine whether a year is a leap year.
*
* YouTube Lesson: https://www.youtube.com/watch?v=gAC1FGQitdo
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year);

int main(void)
{
  // determine which of the years from 1900-2100 are leap years
  for (int y = 1900; y <= 2100; y++)
  {
    if (is_leap_year(y))
      printf("%d LEAP YEAR\n", y);
    else 
      printf("%d\n", y);
  }

  return 0;
}

// Determines if a year is a leap year using this algorithm...
//   en.wikipedia.org/w/index.php?title=Leap_year&oldid=1027751480#Algorithm
bool is_leap_year(int year)
{
  if (year % 4 != 0) return false;
  else if (year % 100 != 0) return true;
  else if (year % 400 != 0) return false;
  else return true;
}
