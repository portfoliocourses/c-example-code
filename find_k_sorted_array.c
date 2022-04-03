/*******************************************************************************
*
* Program: Find A Value In A Sorted Array OR Where It Belongs 
* 
* Description: A solution written in C to this problem:
*
* Given a sorted array arr[] consisting of N distinct integers and an integer K, 
* the task is to find the index of K, if it’s present in the array arr[].
* Otherwise, find the index where K must be inserted to keep the array sorted.
*
* YouTube Lesson: https://www.youtube.com/watch?v=5k3t4uaDU30 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int find_index(int array[], int length, int K);

int main(void)
{
  // test the function, in this case we expect to get back index 3
  int array1[] = {1,4,5,7,8,9};
  int length1 = 6;
  int k1 = 6;
  int index1 = find_index(array1, length1, k1);
  printf("index1: %d\n", index1);
  
  return 0;
}

// returns the index where K occurs in the array of distinct integers with the 
// provided length, OR if K does not exist in the array it returns the index in 
// in the array where it should go in order to keep the array sorted
int find_index(int array[], int length, int K)
{
  // we can search from left to right because we know the array is sorted, and 
  // once we find the index where the element is either EQUAL to K or GREATER 
  // than k we've either found k itself or we've found where it would need to 
  // go to keep the array sorted!
  for (int i = 0; i < length; i++)
    if (array[i] >= K) return i;

  // if we make it through all the values of the array, then k must belong at 
  // the end of the array so we return the index 'length' (i.e. the next index 
  // after the last element currently in the array)
  return length;
}