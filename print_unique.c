/*******************************************************************************
*
* Program: Print unique elements demonstration
* 
* Description: Example of printing out the unique elements of an array in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=RHmURwB-z1I 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

void print_unique(int a[], int length);

int main()
{
  // test the function with a test array where 2, 5, 6, 9, 7 are unique
  int a[] = {1,2,3,4,5,6,3,4,1,8,9,7,8};
  print_unique(a, 13);

  return 0;
}

// prints out the unique elements of an array 'a' with length 'length'
void print_unique(int a[], int length)
{
  // iterate over all elements with index i
  for (int i = 0; i < length; i++)
  {
    // iterate over all elements with index j
    bool match_found = false;
    for (int j = 0; j < length; j++)
      // if we find a matching elements (that is not the same element) then 
      // the element is not unique
      if (a[i] == a[j] && i != j) 
        match_found = true;

    // only print out the element if it is NOT unique
    if (!match_found) printf("%d\n", a[i]);
  }
}
