/*******************************************************************************
*
* Program: Input Validation Example
* 
* Description: Example of performing input validation with a do-while loop in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=IDIJXsZRqP4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main()
{
  int day = 0;
  
  do
  {
    // ask the user to enter a day between 1-31
    printf("Enter day of the month (1-31): ");
    scanf("%d", &day);
    
    // if the day is out of range, inform the user
    if (day < 1 || day > 31)
      printf("Error day must be between 1-31\n");
  
  // keep asking the user to enter a day until they enter one that is in range
  } while (day < 1 || day > 31);
  
  // output the day of the month once a valid day has been entered
  printf("Day of the month: %d\n", day);
  
  return 0;
}
