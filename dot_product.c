/*******************************************************************************
*
* Program: Dot product
* 
* Description: Example of how to to compute a dot product in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=cJybIb_JvuY 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// dot product example
//
//  v1 = (2, 5, 4)
//  v2 = (3, 2, 1)
//  r = (2 * 3) + (5 * 2) + (4 * 1) = 20 
//

float dot_product(float v1[], float v2[], int length);

int main(void)
{
  // test the dot product function with some example data
  float v1[] = {2,5,4};
  float v2[] = {3,2,1};
  float result = dot_product(v1,v2,3);
  printf("Result: %f\n", result);

  return 0;
}

// accepts two vectors (arrays) as arguments and a length, computes and returns
// the dot product
float dot_product(float v1[], float v2[], int length)
{
  // we compute the dot product by multiply the correspdoning elements in each 
  // array and adding them to a sum
  float sum = 0;
  for (int i = 0; i < length; i++)
    sum += v1[i] * v2[i];
  return sum;
}