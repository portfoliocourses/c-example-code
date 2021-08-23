/*******************************************************************************
*
* Program: Area of a circle example
* 
* Description: Examples of computing the area of a circle in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=YxDD_ImhELk
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void) 
{
  double radius = 0;

  // ask the user to enter the radius, store it into the radius variable
  printf("Enter radius: ");
  scanf("%lf", &radius);

  // compute and output the area
  double area = 3.141592 * radius * radius;
  printf("area: %f\n", area);

  return 0;
}
