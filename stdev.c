/*******************************************************************************
*
* Program: Standar deviaton demonstration
* 
* Description: Example of calculating standard deviation in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=B-xEyhbz0-U 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <math.h>

double stdev(double x[], int N);

int main()
{
  // test the function with an example array
  double a[] = {9.2, 1.5, 6.7, 8.2, 5.5, 7.1};
  double result = stdev(a, 6);
  printf("result: %lf\n", result);

  return 0;
}

// compute the standard deviation of elements in a array x with length N
// formula found here: https://en.wikipedia.org/wiki/Standard_deviation
double stdev(double x[], int N)
{
  // first compute the mean
  double mean = 0, total = 0;
  for (int i = 0; i < N; i++) total += x[i];
  mean = total / N;

  // compute the summation portion of the formula
  double sum = 0;
  for (int i = 0; i < N; i++)
    sum += pow(x[i] - mean, 2);  

  // return the result of the final computation required 
  return sqrt( sum / N );
}
