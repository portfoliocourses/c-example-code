/*******************************************************************************
*
* Program: Temperature Conversion Calculator
* 
* Description: Converts temperatures from Celsius to Fahrenheit and Fahrenheit
* to Celsius.
*
* YouTube Lesson: https://www.youtube.com/watch?v=1TTaK83ng00 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(void)
{
  double celsius = 0;
  double fahrenheit = 0;
  int option = 0;  

  printf("********** Temperature Conversion Tool **********\n");
  printf("1) Celsius to Fahrenheit\n");
  printf("2) Fahrenheit to Celsius\n");
  printf("Enter Option: ");
  scanf("%d", &option);
   
  if (option == 1)
  {
    printf("Enter Temperature (C): "); 
    scanf("%lf", &celsius);
  
    fahrenheit = celsius * (9/5.0) + 32; 

    printf("Temperature (F): %lf\n", fahrenheit);
  }
  else if (option == 2)
  {
    printf("Enter Temperature (F): "); 
    scanf("%lf", &fahrenheit);
  
    celsius = (fahrenheit - 32) * (5/9.0);

    printf("Temperature (C): %lf\n", celsius);    
  }
  else 
  {
    printf("Invalid option selected.\n");
  }

  return 0;
}