/*******************************************************************************
*
* Program: Merge Sort
* 
* Description: Example implementation of the merge sort algorithm in C.  See 
* the Wikipedia article on Merge Sort: https://en.wikipedia.org/wiki/Merge_sort
*
* YouTube Lesson: https://www.youtube.com/watch?v=LeWuki7AQLo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);

int main()
{
  // test array and length
  int array[] = { 9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
  int length = 10;
  
  // sort the array using merge sort
  merge_sort(array, length);
  
  // print out the array elements to verify they have been sorted
  for (int i = 0; i < length; i++)
    printf("%d ", array[i]);
  printf("\n");
  
  return 0;
}

// Performs a merge sort of the array a with the given length, the function 
// provides an easier/prettier interface for using merge sort for the 
// programmer as they simply need to provide the array and its length
void merge_sort(int a[], int length)
{
  // call the merge sort recursion function, the left index of 0 and the
  // right index of length - 1 are provided as we are initially looking 
  // at sorting "the entire array"
  merge_sort_recursion(a, 0, length - 1);
}

// Applies the merge sort algorithm to the array a between the left index l
// and the right index r.  This function implements the recursive 
// divide-and-conquer step of the merge sort algorithm, splitting the array
// portion between l...r at the middle, and calling itself on each portion, 
// before applying the function to merge the sorted portions of the array 
// that will result.
void merge_sort_recursion(int a[], int l, int r)
{
  // we stop recursion when l >= r
  if (l < r)
  {
    // find the midpoint of l and r
    int m = l + (r - l) / 2;
  
    // apply the function recursively to the left and right portions split 
    // at the midpoint
    merge_sort_recursion(a, l, m);
    merge_sort_recursion(a, m + 1, r);
  
    // at this point both portions of the array have been sorted, and we now 
    // merge the sorted portions of the array
    merge_sorted_arrays(a, l, m, r);
  }
}

// merges the two sorted portions of the array a between the indexes l ... m
// and m + 1 ... r
void merge_sorted_arrays(int a[], int l, int m, int r)
{
  // calculate the length of the left and right portions of the array
  int left_length = m - l + 1;
  int right_length = r - m;
  
  // create temporary arrays to store these portions
  int temp_left[left_length];
  int temp_right[right_length];
  
  // used as index/counter variables for the 3 arrays a, temp_left, temp_right
  int i, j, k;
  
  // copy the left portion into the temp_left array
  for (int i = 0; i < left_length; i++)
    temp_left[i] = a[l + i];
  
  // copy the right portion into the temp_right array
  for (int i = 0; i < right_length; i++)
    temp_right[i] = a[m + 1 + i];
  
  // Use i to move through the indexes of temp_left, j to move through the 
  // indexes of temp_right, and k to move through the portion of the array 
  // a from l ... r.  We basically keep checking the "head" of temp_left 
  // and temp_right (knowing both arrays are sorted) and put the smaller of 
  // the two into array a (using i, j, k to move through the arrays).  When
  // we run out elements in either temp_left or temp_right, the remaining 
  // elements from the other array will be copied over into a.
  for (i = 0, j = 0, k = l; k <= r; k++)
  {
    // so long as we have not already reached the end of the temp_left array 
    // with our variable i, then if the next element in the left_temp array 
    // is smaller OR if we have reached the end of the temp_right array, 
    // then store the next element from temp_left into the next element in 
    // the array a
    if ((i < left_length) &&
        (j >= right_length || temp_left[i] <= temp_right[j]))
    {
      a[k] = temp_left[i];
      i++;
    }
    // otherwise if the next element in temp_right than the next element in 
    // temp_left OR we have reached the end of temp_left, store the next 
    // element from the temp_right array into the next element in array a
    else
    {
      a[k] = temp_right[j];
      j++;
    }
  }  
}


// Example visualization of the merge sort algorithm:
//
//          [38, 27, 43, 3, 9, 82, 10]
//                     /   \
//       [38, 27, 43, 3]   [9, 82, 10]
//        /         |         |      \
//   [38, 27]    [43, 3]   [9, 82]   [10]
//    /   |      /    |    /    \      |
// [38]  [27]  [43]  [3]  [9]   [82]  [10]
//    \  /       \   /     \     /     |
//   [27, 38]    [3, 43]   [9, 82]    [10]
//       \         /          \        /
//     [3, 27, 38, 43]        [9, 10, 82]
//           \                  /
//          [3, 9, 10, 27, 38, 43, 82]
//
// The array is first broken up into progressively smaller unsorted portions of
// the array, and once we have "sub-arrays" of 1 element they are by definition
// sorted arrays.  From here the "sorted arrays" are merged together until we 
// arrive at the complete sorted array.
//