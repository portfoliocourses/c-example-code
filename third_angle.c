/*******************************************************************************
*
* Program: Find The Third Angle Of A Triangle
* 
* Description: Program to find the third angle of a triangle when the first two 
* angles have been provided from user input with C.  The program utilizes the 
* property that the sum of the angles of a triangle must equal 180 degrees.
*
* YouTube Lesson: https://www.youtube.com/watch?v=wZ0BxDNQTCw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main()
{
  // Declare variables to store angle1, angle2, and angle3
  double angle1, angle2, angle3;
  
  // Prompt the user to enter angle1, store the value entered into angle1
  printf("angle1: ");
  scanf("%lf", &angle1);
  
  // Prompt the user to enter angle2, store the value entered into angle2
  printf("angle2: ");
  scanf("%lf", &angle2);
  
  // Ensure angle1 and angle2 are valid before computing angle3... angle1 and 
  // angle2 must both be between 0-180, and we can't have that angle1 + angle2
  // is greater than or equal to 180 otherwise angle3 will be negative or zero!  
  if ((angle1 > 0 && angle1 < 180) &&
      (angle2 > 0 && angle2 < 180) &&
      ((angle1 + angle2) < 180))
  {
    // The sum of the 3 triangle sides must be 180, so if we know angle1 and 
    // angle2 are valid then angle3 must be 180 - angle1 - angle2.    
    angle3 = 180 - angle1 - angle2;

    // Output angle3
    printf("angle3: %f\n", angle3);
  }
  // Output an error message in the case angle1 and/or angle2 are invalid
  else printf("angle1 and/or angle2 are invalid!\n");
  
  return 0;
}