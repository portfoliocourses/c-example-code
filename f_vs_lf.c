/*******************************************************************************
*
* Program: %f vs %lf Format Specifiers Explained
*
* Description: Examples of how and when to use the %f and %lf format specifiers.
*
* YouTube Lesson: https://www.youtube.com/watch?v=aQ4d391d8Vk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main()
{
  // Declare double and float variables
  double double_number = 0;
  float float_number = 0;

  // In the case of scanf, we MUST use the %lf format specifier to accept a
  // double value
  printf("double_number: ");
  scanf("%lf", &double_number);

  // We also need to use the %f format specifier to accept a float value
  printf("float_number: ");
  scanf("%f", &float_number);

  // In the case of printf, we use %f for BOTH double and float values.  When
  // a float value is passed to printf() it is automatically "promoted" to a
  // double (i.e. the float value will become a double value).  This is true
  // of any function in C that accepts a variable number of arguments as
  // printf() does.  So we just use %f for both doubles and floats!
  printf("double_number: %f\n", double_number);
  printf("float_number: %f\n", float_number);

  // The newer C99 standard explicitly states that the 'l' length specifier
  // will have no effect when used with 'f'.  In the older C89 standard it
  // is undefined behaviour, which means technically it doesn't need to
  // work.  So we should use %f to be safe, though using %lf will probably
  // be OK too in practice, especially when using a compiler that conforms
  // to the C99 standard.
  //
  // printf("double_number: %lf\n", double_number);
  // printf("float_number: %lf\n", float_number);

  return 0;
}
