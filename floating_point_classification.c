/*******************************************************************************
*
* Program: Floating-point Number Classification Functions
* 
* Description: Examples of using the floating-point number classification 
* functions in C (available in the C99 standard onwards).
*
* YouTube Lesson: https://www.youtube.com/watch?v=RQw2M9lpujU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <math.h>
#include <float.h>

int main(void)
{
  // Notably the functions below to classify floating point values are 
  // implemented as function macros and will work for double and long double
  // floating point values as well.


  // Declare a float variable finite and initialize it to a "typical" finite 
  // float value
  float finite = 2.5;
  
  // isfinite() returns true if the value supplied as an argument is finite, and
  // false otherwise
  if (isfinite(finite))
    printf("%f is finite\n", finite);
  
  
  // 1.0 / 0 will result in the special floating point value positive infinity
  float infinite = 1.0 / 0;
  
  // isinf() will return true if the value supplied as an argument is infinite,
  // and false otherwise
  if (isinf(infinite))
    printf("%f is infinite\n", infinite);
  
  
  // -1.0 / 0 will results in the special floating point value negative infinity
  float negative_infinite = -1.0 / 0;
  
  // signbit() will return true if the value supplied as an argument is negative,
  // and false otherwise (technically it checks if the sign bit is set)
  if (signbit(negative_infinite))
    printf("%f is negative\n", negative_infinite);
  else
    printf("Not negative\n");
  

  // 0.0 / 0.0 will result in the special floating point value not a number
  float not_a_number = 0.0 / 0.0;
  
  // isnan() will return true if the value supplied as an argument is not a 
  // number, and false otherwise
  if (isnan(not_a_number))
    printf("%f is not a number\n", not_a_number);
  
  
  // Floating point numbers can be "normalized" or "denormalized/subnormal".  A
  // subnormal number sacrifices the potential precision of the type float in 
  // exchange for the ability to store an "extra small number".  See this 
  // article for a more: https://en.wikipedia.org/wiki/Subnormal_number.
  //
  // FLT_MIN is the smallest number that can be stored in a normalized way, 
  // if we divide it by 10 we will get a subnormal number.
  float number = FLT_MIN / 10;
  
  // isnormal() returns true if the number is normal and false if it is 
  // not normal... number is subnormal so we will get "... is not normal"
  if (isnormal(number))
    printf("%e is normal\n", number);
  else
    printf("%e is not normal\n", number);
    
  
  // test value
  float test = 0.0;
  
  // fpclassify() will classify the floating point number it is provided as an 
  // argument, it will return the preprocessor values in the cases below when 
  // the number is infinite, nan, normal, subnormal or zero.
  switch (fpclassify(test))
  {
    case FP_INFINITE:
      printf("%f is infinite\n", test);
      break;
      
    case FP_NAN:
      printf("%f is not a number\n", test);
      break;
      
    case FP_NORMAL:
      printf("%f is normal\n", test);
      break;
      
    case FP_SUBNORMAL:
      printf("%f is subnormal\n", test);
      break;
      
    case FP_ZERO:
      printf("%f is zero\n", test);
      break;
    
    // It is possible for a compiler to support implementation specific 
    // return values as well, we handle these with a default case.
    default:
      printf("Unknown\n");
  }
  
  return 0;
}