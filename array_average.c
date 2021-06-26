/*******************************************************************************
*
* Program: Array average
* 
* Description: An example of a function for computing the average of the 
* elements in an array.
*
* YouTube Lesson: https://www.youtube.com/watch?v=gCv170-cN_s
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

double avg(double array[], int length);

int main(void)
{
  // example arrays
  double arr1[] = {5.2,9.3,6.5,4.1,7.8};
  double arr2[] = {10.0};
  double arr3[] = {9.8,9.6};
  double arr4[] = {-50,50,-100,100,-2,2};

  // call the average function to calculate the average, print the results
  printf("arr1 avg: %.2lf\n", avg(arr1,5));
  printf("arr2 avg: %.2lf\n", avg(arr2,1));
  printf("arr3 avg: %.2lf\n", avg(arr3,2));
  printf("arr4 avg: %.2lf\n", avg(arr4,6));

  return 0;
}

// computes the average of the array with the given length
double avg(double array[], int length)
{
  // sum the array elements & divide the sum by the length (i.e. # of elements)
  double sum = 0;
  for (int i = 0; i < length; i++)
  {
    sum = sum + array[i];
  }
  return sum / length;
}