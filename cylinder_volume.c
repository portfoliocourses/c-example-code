/*******************************************************************************
*
* Program: Volume of a Cylinder
*
* Description: Program to compute the volume of a cylinder using user input
* values in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=x2-QWbhUV7A
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// Volume of a Cylinder: πr²h

// Use a preprocessor constant to define the value of PI.  Wherever we use 'PI'
// in our program it will be replaced with the value 3.14... when the program
// is compiled.
#define PI 3.141592653589

double cylinder_volume(double radius, double height);

int main(void)
{
  // Declare variables to store the cylinder radius, height, and volume.  We
  // use type double as cylinders may have a radius, height and/or volume
  // with decimal places.
  double radius = 0;
  double height = 0;
  double volume = 0;

  // Prompt the user to enter the radius, store value entered into the radius
  // variable.  The placeholde %lf in the first (string) argument of scanf tells
  // scanf to expect a double value to be input, and the &radius second argument
  // will pass the memory address (pointer) of the radius variable to scanf()
  // which allows scanf() to set radius to the value the user enters
  printf("Radius: ");
  scanf("%lf", &radius);

  // Prompt the user to enter the height, store the entered height into the
  // height variable in the same way as above.
  printf("Height: ");
  scanf("%lf", &height);

  // We could calculate the cylinder volume in the main function with the
  // below expression, and store the result into the volume variable.
  // volume = PI * radius * radius * height;

  // We could also call the cylinder volume using the cylinder_volume
  // function, passing it the radius and height as arguments, and storing the
  // return value into volume.
  volume = cylinder_volume(radius, height);

  // Output the cyldiner volume.  The placeholder %f will allow us to ouput a
  // double value, which we supply as the second argument to printf (volume).
  // The precision field .2 will limit the decimal places of output to two.
  printf("Cylinder Volume: %.2f\n", volume);

  return 0;
}

// Returns the volime of a cylinder with the given radius and height, using
// these values in the calculated return value (πr²h)
double cylinder_volume(double radius, double height)
{
  return PI * radius * radius * height;
}