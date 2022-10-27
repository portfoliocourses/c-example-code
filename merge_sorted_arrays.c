/*******************************************************************************
*
* Program: Merge sorted arrays demonstration
* 
* Description: Example of merging two sorted arrays in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=n1jgmsbCA6s 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

void merge(int a[], int m, int b[], int n, int r[]);

int main(void) 
{
  // a1 and a2 are the sorted arrays, and we'll store the merged result into r
  int a1[] = {1,3,5,7,9};
  int a2[] = {2,4,5,6,8};
  int r[10];
  
  // merge the arrays
  merge(a1, 5, a2, 5, r);

  // output the result
  for (int i = 0; i < 10; i++)
    printf("r[%d] = %d\n", i, r[i]);

  return 0;
}

// merges sorted arrays a and b of length m and n into result array r
void merge(int a[], int m, int b[], int n, int r[])
{
  // we use i to step through the elements of a, j to step through the elements 
  // of b, and k to set the elements of r
  int i = 0, j = 0, k = 0;
  
  // we'll eventually reach the end of one of the arrays
  while (i < m && j < n)
  {
    // i and j keep track of what element we are looking at 'next' in a and b,
    // and so we check to see if the next element in a is less than the next 
    // element in b, and if it is we set *that* as the next element of r and 
    // increment the relevant counters
    if (a[i] < b[j])
    {
      r[k] = a[i];
      k++;
      i++;
    }
    // otherwise, we set the next element of b as the next element in r and 
    // increment the relevant counters
    else 
    {
      r[k] = b[j];
      k++;
      j++;
    }
  }
  
  // one of the two arrays will have at least one element remaining to be 
  // stored into r... if i < m that means a has elements remaning and we store
  // those into r
  while (i < m)
  {
    r[k] = a[i];
    k++;
    i++;
  }

  // if j < n that means b has elements remaining and we store those into r
  while (j < n)
  {
    r[k] = b[j]; // index should be j instead of i so function works correctly with other test cases
    k++;
    j++;
  }

}
