/*******************************************************************************
*
* Program: Array disjoint check demonstration
* 
* Description: Check if two arrays are disjoint in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=zaYk09uW-tg 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

bool is_disjoint(int a1[], int l1, int a2[], int l2);

int main(void) 
{
  // test arrays that are disjoint because there is no value in both arrays
  int array1[] = {1,3,5,7,9};
  int array2[] = {2,4,6,8,10};
  
  // test the function
  if (is_disjoint(array1,5,array2,5))
    printf("arrays are disjoint\n");
  else 
    printf("arrays are not disjoint\n");

  return 0;
}

// accepts two arrays and their lengths as arguments.
// returns true if arrays are disjoint, and false otherwise.
bool is_disjoint(int a1[], int l1, int a2[], int l2)
{
  // outer loop cycles through each element of a1, inner loop cycles through 
  // each elmenet of a2, we compare them and if we ever find a match there is 
  // a value found in both arrays and the arrays are not disjoint 
  for (int i = 0; i < l1; i++)
    for (int j = 0; j < l2; j++)
      if (a1[i] == a2[j]) return false;
  
  // if after comparing all values there is no match, arrays must be disjoint
  return true;
}




