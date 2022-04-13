/*******************************************************************************
*
* Program: Merge Two Sorted Arrays Using Recursion
* 
* Description: Example of merging two sorted arrays using recursion in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=yi4nomTUR6U 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

void merge(int a[], int i, int b[], int j, int r[]);

int main(void)
{
  // two sorted arrays and a third array large enough to store the result
  int x[] = {1,3,5,7,9};
  int y[] = {2,4,6,8};
  int result[9];
  
  // call the merge function with the two sorted arrays and their lengths as 
  // well as the result array to store the resulting array
  merge(x, 5, y, 4, result);
  
  // print out the result array to ensure the merger was successful
  for (int i = 0; i < 9; i++)
    printf("%d ", result[i]);
  printf("\n\n");
  
  return 0;
}

// merge sorted arrays a and b and store the result into array r using 
// recursion... when merge is initially called i and j should be the length 
// of arrays a and b... but on subsequent recursive calls to merge i and j 
// are used to keep track of the number of elements in a and b remaining to 
// be merged into r!
void merge(int a[], int i, int b[], int j, int r[])
{
  // if one of i or j is not zero, there are still elements remaining in 
  // array a or b, and so we continue, otherwise recursion will stop
  if (i != 0 || j != 0)
  {
    // if i is zero, there are no more elements remaining to be merged in 
    // array a, so we'll copy the next element from array b into array r
    if (i == 0)
    {
      // copy the next element from array b into array the result array r
      r[0] = b[0];

      // Call merge to continue merging the arrays... but remember that array
      // parameters in C are really just pointers, and so we use pointer 
      // arithemetic to increment b by 1, having it point to the next element
      // in the array b, and we decrement j by 1 to recognize there is one 
      // less element in b that needs to be merged.  We also increment r by 1 
      // so that r will point to the next element in the result array, so that 
      // next time we store a value into r[0] it will refer to the next 
      // element in the result array!
      merge(a, i, b + 1, j - 1, r + 1);
    }
    // if j is zero there are no more elements left in b and so we need to 
    // store the next element from a into r, OR if there are more elements in 
    // array b (and we know from the above condition being false there are 
    // more elements left in array a), then we check if the next element in 
    // array a is less than the next element in array b and if it is then we
    // ALSO want to store the next element from a into r.
    else if (j == 0 || a[0] < b[0])
    {
      // store the next element from a into r
      r[0] = a[0];

      // similar to above, advance the pointers for a and r so they now refer
      // to the next element in each array, and decrement i to recognize there
      // is one less element in array a
      merge(a + 1, i - 1, b, j, r + 1);
    }
    // otherwise if there are elements remaining in arrays a and b AND 
    // b[0] <= a[0] then we want to copy the next element from array b into 
    // the result array r
    else
    {
      // we use the same technique as the above conditions, this time 
      // copying the next element from b into the result array r
      r[0] = b[0];
      merge(a, i, b + 1, j - 1, r + 1);
    }
  }
}

// We effectively use the pointers a,b & r to "advance through" the arrays 
// associated with a,b & r, using i and j to keep track of when there are 
// no more elements to examine.  We can visualize the process like this, 
// with the elements of r being constructed/set as we advance through 
// the elements of a and b:
//
//    a
//    |
//  1,3,5,7,9    i: 4
//
//    b
//    |
//  2,4,6,8      j: 3
//
//      r
//      |
//  1,2,
//
// With | representing what each pointer is pointing to, the above visualizes 
// the state after two recursive calls to merge.

