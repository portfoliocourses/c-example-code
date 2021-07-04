/*******************************************************************************
*
* Program: Convert binary to decimal
* 
* Description: A function that accepts a string representation of a binary 
* number and convers it to decimal (int) in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=jEgiZQLNfiE  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int convert(char *string);

// Example of binary number conversion logic/math
//
// 10101 binary -> 21 decimal
// 
// 1    0    1    0    1 
// 2^4  2^3  2^2  2^1  2^0
// 16 + 0 +  4 +  0 +  1
// = 21
//
int main(void)
{
  // test the function with some example values
  char s1[] = "10101";
  int val1 = convert(s1);
  printf("s1 in dec: %d\n", val1);

  char s2[] = "11111";
  int val2 = convert(s2);
  printf("s2 in dec: %d\n", val2);

  char s3[] = "10000001";
  int val3 = convert(s3);
  printf("s3 in dec: %d\n", val3);

  return 0;
}

// converts the binary number in string to a decimal int value
int convert(char *string)
{
  int slen = strlen(string);
 
  // total keeps track of the converted number
  int total = 0;

  // decval is the current 2^n value of the digit the below loop is converting
  int decval = 1;

  // We perform the conversion one digit at a time, going from the right side 
  // of the string to the left.  If the current digit is a '1' we add the value
  // of that digit to the total.  We multiply decval by 2 to keep track of the 
  // increasing worth of each digit as a power of 2 as we move from right to 
  // left in the string.
  for (int i = (slen - 1); i >= 0; i--)
  {
    if (string[i] == '1') total += decval;
    decval *= 2;
  }

  return total;
}
