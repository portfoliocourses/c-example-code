/*******************************************************************************
*
* Program: Check If An Array Is Sorted
* 
* Description: Check if an array is sorted in an ascending order or descending
* order in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=aF9WrmuRrKU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>

bool sorted_ascending(int array[], int length);
bool sorted_descending(int array[], int length);
bool sorted(int array[], int length);

int main()
{
  
  // Test arrays... array1 is sorted in ascending order (smallest to largest) 
  // and array2 is sorted in descending order (largest to smallest)
  int array1[] = {1,2,3,4,5,6,7,8,9,10};
  int array2[] = {10,9,8,7,6,5,4,3,2,1};
  

  // Test the sorted_ascending() function with array1 and array2
  
  if (sorted_ascending(array1, 10)) printf("array1 is ascending\n");
  else printf("array1 not ascending\n");
  
  if (sorted_ascending(array2, 10)) printf("array2 is ascending\n");
  else printf("array2 not ascending\n");
  
  printf("\n");
  

  // Test the sorted_descending() function with array1 and array2

  if (sorted_descending(array1, 10)) printf("array1 is descending\n");
  else printf("array1 not descending\n");
  
  if (sorted_descending(array2, 10)) printf("array2 is descending\n");
  else printf("array2 not descending\n");
  
  printf("\n");
  

  // Test the sorted() function with array1 and array2

  if (sorted(array1, 10)) printf("array1 is sorted\n");
  else printf("array1 not sorted\n");
  
  if (sorted(array2, 10)) printf("array2 is sorted\n");
  else printf("array2 not sorted\n");


  return 0;
}

// Returns true if the array with the provided length is sorted in ascending 
// order and false otherwise.
bool sorted_ascending(int array[], int length)
{
  // An array of length 0 or 1 is sorted by default (it cannot be unsorted) so 
  // we return true in these cases.
  if (length == 0 || length == 1)
    return true;
  
  // If an element is NOT greater than or equal to the element previous to it 
  // than the array is not in ascending order... so if we detect an element 
  // like this in the array we return false as the array is not in ascending 
  // order as we have detected elements out of order.  We start examining 
  // elements from the 2nd index in the array (1) because the first element in 
  // the array has no element previous to it.
  for (int i = 1; i < length; i++)
    if (array[i - 1] > array[i])
      return false;
  
  // If NONE of the elements were out of order, the array must be sorted in 
  // ascending order, and we return true.
  return true;
}

// Returns true if the array with the provided length is sorted in descending 
// order and false otherwise.  
//
// The function uses the exact same logic as the sorted_ascending() function 
// except we flip "array[i - 1] > array[i]" to "array[i - 1] < array[i]" 
// because we are checking for the opposite order.  If an array is sorted in 
// descending order, an array element should be less than or equal to the 
// element previous to it.
bool sorted_descending(int array[], int length)
{
  if (length == 0 || length == 1)
    return true;
  
  for (int i = 1; i < length; i++)
    if (array[i - 1] < array[i])
      return false;
  
  return true;
  
}

// Returns true if the array with the given length is sorted in either ascending
// OR descending order, and false otherwise.  Utilizes the above functions to 
// check for this.
bool sorted(int array[], int length)
{
  return (sorted_ascending(array, length) ||
          sorted_descending(array, length));
}