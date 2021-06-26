/*******************************************************************************
*
* Program: Temperature conversion
* 
* Description: A C program to convert Celsius temperatures to Fahrenheit.  
* Converts temperatures from a start to end range incrementing by a step, all 
* of which are input from the user.
*
* YouTube Lesson: https://www.youtube.com/watch?v=LM18CB0xEIc
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// Formula for converting Celsius to Fahrenheit:
// Multiply by 1.8 (or 9/5) and add 32

int main(void)
{
  double C = 0;
  double start = 0;
  double end = 0;
  double step = 0;
  double F = 0;

  // ask the user to input the start, end and step values
  printf("Enter start C temp: ");
  scanf("%lf", &start);

  printf("Enter end C temp: ");
  scanf("%lf", &end);

  printf("Enter step value: ");
  scanf("%lf", &step);

  // Convert from C to F and output results into a table format
  printf("C           F\n");
  printf("***************************\n");
  for (C = start; C <= end; C += step)
  {
    F = (C * 1.8) + 32;
    printf("%-8.2lf %8.2lf\n", C, F);
  }

  return 0;
}