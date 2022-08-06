/*******************************************************************************
*
* Program: Print Debugging Example
*
* Description: One debugging technique is to insert print statements into our
* code in order to trace its execution, both the control-flow and the state
* of variables throughout the execution of the program.  This technique is
* generally called "print debugging" or sometimes "printf debugging".  The below
* program is a demonstration of the concept.
*
* YouTube Lesson: https://www.youtube.com/watch?v=H-H3fX72pd0
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main()
{
  int array[] = {4,3,6,5,7,0,9,8,1,2};
  int length = 10;

  // A simple algorithm to find the largest value in an array is to start off
  // with the assumption that the first element is the largest value in the
  // array, and then to check the remaining values in the array one after the
  // other.  And if any of the values is larger than the current largest value,
  // to make it the new largest value.  Once all remaining values have been
  // checked, the largest value has been identified.  In the below
  // implementation of the algorithm there is a bug, instead of checking if
  // the next array element is LARGER than the current largest value, we check
  // if it is SMALLER than the current largest value.  This will result in a bug
  // as the algorithm will instead find the SMALLEST value in the array this
  // way!  We can use printfs to help identify where the bug is with the
  // "print debugging" technique.


  int max = array[0];

  // Print out the the initial max value, which should be '4' as 4 is the first
  // value in the array
  printf("initial max: %d\n", max);

  for (int i = 1; i > length; i++)
  {
    // print out the counter variable, 'current array element' value and max
    // with each loop iteration to help understand how the loop is working
    printf("loop - i: %d, array[%d]: %d, max: %d\n", i, i, array[i], max);

    if (array[i] > max)
    {
      max = array[i];

      // print the new max ONLY when the if-condition evaluates to false,
      // helping us to understand WHEN an "update" of the max value happens
      printf("  IF - max: %d\n", max);
    }
  }

  printf("max: %d\n", max);

  return 0;
}