/*******************************************************************************
*
* Program: Round A Double To A Specific Number Of Decimal Places
* 
* Description: Function that can round a double value to a specified number of 
* decimal places in C.  For example rounding a double to two decimal places, 
* or rounding a double to one decimal place.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Oq2IYFiq-AM 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <math.h>

double double_round(double value, int decimal_places);

int main(int argc, char *argv[])
{
  // declare a double variable and store a value with many decimal places in it
  double number = 36.65777777;
  
  // One technique to "round" the number down to a specific amount of decimal 
  // places is to use the precision field of the placeholder, here we use .1 
  // to output the number with 1 decimal place.
  printf("number: %.1f\n", number);
  
  // We could use .2 to output the number with 2 decimal places.
  printf("number: %.2f\n", number);
  
  // This technique does not actually change the number stored in memory though,
  // it just outputs the number with a limited amount of decimal places of 
  // precision (which may be sufficient for our purposes).  As we can see if we
  // output the number with no precision field, the number itself is still 
  // stored with many decimal places.
  printf("number: %f\n\n", number);
  
  // Try using the double_round() function implemented below to round the 
  // number down to one decimal place, and output the resulting value that 
  // the function returns.
  double one_decimal_round = double_round(number, 1);
  printf("one_decimal_round: %f\n", one_decimal_round);
  
  // Try using the double_round() function to round the number down to two 
  // decimal places, and output the result.
  double two_decimal_round = double_round(number, 2);
  printf("two_decimal_round: %f\n", two_decimal_round);
  
  return 0;
}

// Returns the value number rounded to decimal_places number of decimal places
double double_round(double value, int decimal_places)
{
  // The round() function in the math.h library will round a double to the 
  // nearest integer.  We can multiply the double by 10 to the power of the 
  // amount of decimal places we wish to round it down to ("shifting the decimal
  // place over"), amd then apply the round() function to this number, and then
  // divide the resulting number by 10 to the power of the amount of decimal 
  // places we wish to round it down to (again shifting the decimal place over).
  // This will result in the number rounded to the desired number of decimal 
  // places.
  //
  // If we apply the process above to 36.65777777 to round it two decimal 
  // places we get...
  //
  // 36.65777777 * 100
  // round(3665.777777)
  // 3666 / 100
  // 36.66

  // Will store the rounded number
  double rounded;
  
  // Compute the number used to shift the decimal place
  double shift = pow(10, decimal_places);
  
  // Multiply the number by the shift number to shift the decimal place
  rounded = value * shift;
  
  // Use the round function to round the resulting number to the nearest integer
  rounded = round(rounded);
  
  // Divide the number by the shift number to shift back the decimal place
  rounded = rounded / shift;
  
  // Return the resulting rounded number
  return rounded;
}