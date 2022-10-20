/*******************************************************************************
*
* Program: Find The Two Elements Of An Array Whose Sum Is Closest To Zero
*
* Description: Program to find the two elements of an array whose sum is closest
* to zero using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=3YFMiDk3TvE 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void find_min_sum_pair(int array[], int length);

int main(int argc, char *argv[])
{
  // Declare and initialize a test array.  A "pair" of elements in the array
  // could be the elements at index 0 and 2 with the values 25 and -31 which
  // sum to -6.  We want to find the two elements in the array with a sum
  // that is closest to zero.
  int array[] = {25, 42, -31, 12, 55, -20, -18, -48, 16, 34};

  // Call the find_min_sum_pair() function to find the two elements in the array
  // whose some is closet to zero
  find_min_sum_pair(array, 10);

  return 0;
}

// Finds and outputs the two elements of the given array with the given length
// whose some is closest to zero.
void find_min_sum_pair(int array[], int length)
{
  // We can't find *any* pair of elements if the array length isn't at least 2,
  // so stop the function by returning if lenfth is less than 2
  if (length < 2) return ;

  // We'll start off with the assumption that the elements at indexes 0 and 1
  // have the sum that is closest to zero.  We'll calculate the sum and store
  // it into the min_sum variable, and keep track of the indexes of the two
  // array elements whose sum is closest to zero using min_index1 and
  // min_index2.  We'll then check every possible pair of elements in the array
  // and whenever we find one whose sum is closer to zero than min_sum, we'll
  // update min_sum to this new sum (as well as updating min_index1 and
  // min_index2 to the indexes of these elements).
  int min_sum = array[0] + array[1];
  int min_index1 = 0;
  int min_index2 = 1;

  // We need to find all possible pairs of elements.  The outer loop will take
  // the counter variable i from 0 up until length - 1 incrementing by 1, this
  // will be the index of 1 of the two elements.
  for (int i = 0; i < (length - 1); i++)
  {
    // The inner loop and counter variable j will give us the index of the other
    // element in the pair.  j will be taken from i + 1 up until length
    // incrementing by 1.  In other words, we'll check the pair of elements at
    // the index i with each of i + 1, i + 2, ..., length.  Over the course of
    // the execution of the loops, we'll check every possible pair of indexes.
    for (int j = i + 1; j < length; j++)
    {
      // calculate the sum of the elements at the pair of indexes given by i & j
      int new_sum = array[i] + array[j];

      // Use the absolute value function abs() to check if the sum of these
      // two elements is closer to zero than min_sum, if it is, make this sum
      // the new min_sum.  We use absolute value because -1 is closer to zero
      // than 2 for example, and we want to account for this when making our
      // comparison.
      if (abs(new_sum) < abs(min_sum))
      {
        // Set min_sum to this new sum, and update indexes of the pair of
        // elements whose sum is closest to zero
        min_sum = new_sum;
        min_index1 = i;
        min_index2 = j;
      }
    }
  }

  // Output the sum of the elements that is closest to zero
  printf("Min Sum: %d\n", min_sum);

  // Output the values and the indexes of the two elements whose sum is
  // closest to zero
  printf("Value1: %d (occurs at index %d)\n", array[min_index1], min_index1);
  printf("Value2: %d (occurs at index %d)\n", array[min_index2], min_index2);
}
