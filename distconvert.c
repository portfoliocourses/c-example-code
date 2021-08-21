/*******************************************************************************
*
* Program: Kilometer to miles and natural miles distance conversion
* 
* Description: Presents a table of conversions from kilometers to miles and 
* nautical miles according to a starting km value, step km value, and ending km 
* value.
*
* The program will convert kms starting from the starting value, increasing by
* the step value for each conversion, until the next value to be converted is 
* past the end value.  Values are output with 4 digits of precision.
*
* YouTube Lesson: https://www.youtube.com/watch?v=L5en1y4BBQg 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

double km_to_miles(double km);
double km_to_nautical_miles(double km);

int main()
{
  double start_km = 0;
  double end_km = 0;
  double step_km = 0;
  double current_km = 0;

  printf("\n\nDistance Conversion Tool\n\n");

  // ask for the starting km value from the user
  do 
  {
    printf("Enter the start km value: ");
    scanf("%lf", &start_km); // we can use %lf to read a double
    if (start_km < 0) printf("Start km value cannot be less than 0!\n");
  } while (start_km < 0);

  // ask for the step km value from the user
  do 
  {
    printf("Enter the step km value: ");
    scanf("%lf", &step_km); // we can use %lf to read a double
    if (step_km <= 0) printf("Step km value must be greater than 0!\n");
  } while (step_km <= 0);

  // ask for the end km value from the user
  do 
  {
    printf("Enter the end km value: ");
    scanf("%lf", &end_km); // we can use %lf to read a double
    if (end_km <= 0) printf("End km value must be greater than 0!\n");
  } while (end_km <= 0);  

  printf("\n\n");
  printf("%-20s%-20s%-20s\n", "Kilometers","Miles","Nautical");
  printf("************************************************************\n");
  for (current_km = start_km; current_km < end_km; current_km += step_km)
  {
    printf("%-20.4f%-20.4f%-20.4f\n", 
           current_km,
           km_to_miles(current_km),
           km_to_nautical_miles(current_km)
           );
  }

  printf("\n");

  return 0;
}

double km_to_miles(double km) { return km * 0.62137; }
double km_to_nautical_miles(double km) { return km * 0.539957; }
