/*******************************************************************************
*
* Program: Remove Duplicate Array Elements
*
* Description: Program to remove the duplicate elements from an array in C.  
* This solution involves creating another dynamically allocated array on the 
* heap that contains the same elements as the original array with the duplicates
* removed.
*
* YouTube Lesson: https://www.youtube.com/watch?v=vJLt_VG8bqA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *remove_duplicates(int array[], int length, int *new_length);

int main()
{
  // test array contains two duplicates: 1,2
  int test[] = {1,2,3,4,1,2,5,6,7,8};
  
  // will store the length of the array after duplicates have been removed 
  int after_length = 0;
  
  // remove the duplicates from the test array, 'after' will point to the new
  // dynamically allocated array on the heap with the duplicates removed and 
  // after_length will be set to this new array's length
  int *after = remove_duplicates(test, 10, &after_length);
  
  // loop through the after array elements and print them out to verify the 
  // duplicates have been removed
  for (int i = 0; i < after_length; i++)
    printf("after[%d] = %d\n", i, after[i]);
  
  // free the dynamically allocated array
  free(after);
  
  return 0;
}

// Returns a pointer to a dynamically allocated array on the heap that 
// contains the elements of the array 'array' with length 'length' with the 
// duplicates removed, where we use pass by pointer (i.e. pass by 
// reference) to return the length of this dynamically allocated array 
// via new_length.
int *remove_duplicates(int array[], int length, int *new_length)
{
  // Allocate the maximum amount of space required for the new_array using 
  // malloc, we assume that EVERY element in the array may be unique and 
  // so allocate space for an array of the same length.  We will use realloc()
  // to "re-size" this new_array later if needed. 
  int *new_array = malloc(length * sizeof(int));
  
  // unique_count will keep track of the number of unique elements
  int unique_count = 0;
  
  // the outer loop will be used to check each element of the original array
  for (int i = 0; i < length; i++)
  {
    // this inner loop will check to see if the element at index i in the 
    // original array is found in the new_array, setting is_unique to false 
    // if this is the case
    bool is_unique = true;
    for (int j = 0; j < unique_count; j++)
      if (new_array[j] == array[i])
      {
        is_unique = false;
        break;
      }
    
    // If the element at index i in in the original array is NOT found in 
    // new_array, this must be the first occurrence of this value, and so we 
    // add it to the new_array and increment unique_count.  If the element IS
    // found in new_array above, we don't do this, which will have the effect 
    // of filtering the duplicate values as they will NOT be added to new_array.
    if (is_unique)
    {
      new_array[unique_count] = array[i];
      unique_count++;
    }
  }
  
  // If the count of unique elements matches the original length of the array 
  // then the original array must not have contained any duplicate elements and 
  // there is no need to re-size the new_array.  But if the unique_count does 
  // not equal the length of the original array, there must have been some 
  // duplicate(s), and so new_array can be stored in less space than the 
  // original array.  So we use realloc() to reallocate space for the array, 
  // allocating just enough space to store unique_count number of ints.
  if (unique_count != length)
    new_array = realloc(new_array, unique_count * sizeof(int));
  
  // We de-reference the new_length pointer variable to set "whatever it is 
  // pointing to" to the unique_count value, as a way of "returning" to the 
  // calling environment the length of the new array with duplicates removed.
  *new_length = unique_count;
  
  // Return the pointer to the new array on the heap with duplicates removed
  return new_array;
}