/*******************************************************************************
*
* Program: Convert Seconds To Days, Hours, Minutes and Seconds
*
* Description: Program to convert a total number of seconds into the equivalent
* number of days, hours, minutes and seconds using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=LaVEDKSTYQs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// Algorithm Explained
// -------------------
//
// If we divide the total number of seconds by 60 (the number of seconds in a 
// minute) then the quotient will be the total number of minutes and the 
// remainder will be the number of seconds left over after accounting for the 
// number of minutes.
//
// e.g. 200,000 / 60 = 3,333 remainder 20
//
// If we take that total number of minutes and divide it by 60 (the number of 
// minutes in an hour) then the quotient will be the total number of hours and
// the remainder will be the number of minutes left over after accounting for 
// the number of hours.
//
// e.g. 3,333 / 60 = 55 remainder 33
//
// And if we take that total number of hours and divide it by 24 (the number of
// hours in a day) then the quotient will be the total number of days and the 
// remainder will be the number of hours left over after accounting for the 
// number of days.
//
// e.g. 55 / 24 = 2 remainder 7
//
// So 200,0000 seconds is 2 days, 7 hours, 33 minutes, and 20 seconds

#include <stdio.h>

int main(void)
{
  // stores the total initial amount of seconds
  int total_seconds = 0;

  // Store the total number of whole minutes and hours as used in the above 
  // calculations
  int total_minutes = 0;
  int total_hours = 0;
  
  // Store the equivalent number of days, hours, minutes and seconds
  int days = 0;
  int hours = 0;
  int minutes = 0;
  int seconds = 0;
  
  // Prompt the user for the total number of seconds and store the input
  printf("Total Seconds: ");
  scanf("%d", &total_seconds);
  
  // Find the remaining number of seconds (seconds) and total number of minutes
  // (total_minutes) 
  seconds = total_seconds % 60;
  total_minutes = total_seconds / 60;
  
  // Find the remaining number of minutes (minutes) and total number of hours
  // (total_hours)
  minutes = total_minutes % 60;
  total_hours = total_minutes / 60;
  
  // Find the remaining number of hours (hours) and total days (days)
  hours = total_hours % 24;
  days = total_hours / 24;
  
  // Output the resulting days, hours, minutes and seconds
  printf("%d days\n", days);
  printf("%d hours\n", hours);
  printf("%d minutes\n", minutes);
  printf("%d seconds\n", seconds);
  
  return 0;
}