/*******************************************************************************
*
* Program: Compute Volume Of A Sphere
* 
* Description: Example of how to compute the volume of a sphere in C.  The 
* formula for the volume of a sphere is: (4/3)πr³
*
* YouTube Lesson: https://www.youtube.com/watch?v=UL12Lumo1AM 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// define PI as a constant
#define PI 3.141592653589

double sphere_volume(double radius);

int main(void)
{
  // test the function
  printf("%f\n", sphere_volume(3));
  
  return 0;
}

// compute the volume of a sphere using the formula (4/3)πr³
double sphere_volume(double radius)
{
  // we must use 3.0 instead of 3, otherwise integer division will occur and 
  // 4/3 will result in 1, but with 3.0 double division will occur instead
  return (4/3.0) * PI * (radius * radius * radius);
}
