/*******************************************************************************
*
* Program: Split An Array At An Index
*
* Description: Example of splitting an array at an index into two arrays with C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=nrvLkjfsJx4
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void split(int *array,
           int length,
           int split_index,
           int **subarray1,
           int *length1,
           int **subarray2,
           int *length2);

int main(int argc, char *argv[])
{
  // Declare and initialize an array to split
  int array[] = {1,2,3,4,5,6,7,8,9,10};

  // Store length of the array into a variable
  int length = 10;

  // Declare variables that will store the two subarray lengths
  int sublength1 = 0, sublength2 = 0;

  // Declare variables that will point to the two subarrays on the heap
  int *subarray1 = NULL, *subarray2 = NULL;

  // Split the array with the given length at index 3, storing the length of the
  // first subarray into sublength1, and having subarray1 point to the first
  // subarray (and the same for sublength2/subarray2 and the second subarray).
  split(array, length, 3, &subarray1, &sublength1, &subarray2, &sublength2);

  // Output the first subarray length and its elements
  printf("sublength1: %d\n", sublength1);
  for (int i = 0; i < sublength1; i++)
    printf("subarray1[%d] = %d\n", i, subarray1[i]);
  printf("\n");

  // Output the second subarray length and its elements
  printf("sublength2: %d\n", sublength2);
  for (int i = 0; i < sublength2; i++)
    printf("subarray2[%d] = %d\n", i, subarray2[i]);
  printf("\n");

  // Free the dynamically allocated memory for both subarrays
  free(subarray1);
  free(subarray2);

  return 0;
}

// Splits the array with the given length at the given split index.  So if we
// have an array of length 10:
//
// {0,1,2,3,4,5,6,7,8,9,10}
//
// and we split the array at index 3, we would expect two new arrays of length
// 3 and length 7 as follows:
//
// {0,1,2} and {3,4,5,6,7,8,9,10}
//
// We use pass-by-pointer to return the new subarray lengths and pointers to the
// subarrays that have been stored in dynamically allocated memory on the heap.
//
// length1 is a pointer to an int, which as a practical matter will be an int
// variable in the function that calls split().  We dereference the pointer
// to set the length of the first subarray to what length1 points to.
//
// subarray1 is a pointer to a pointer to an int... so we pass in the memory
// address (i.e. pointer) of a pointer to an int.  We again dereference the
// pointer to set the pointer to an int to point to a block of dynamically
// allocated memory that will store the first subarray.
//
// We do the same as described above for length2 and subarray2 for the 2nd
// subarray.
//
void split(int *array,
           int length,
           int split_index,
           int **subarray1,
           int *length1,
           int **subarray2,
           int *length2)
{
  // The length of the first subarray will be equal to the split index.  Notice
  // how we dereference the pointer length1... this will set the int variable
  // in the calling function to the length int value.
  *length1 = split_index;

  // The length of the second subarray will be equal to the length of the
  // original array subtracting the number of elements in the first subarray
  // as given by the split index.
  *length2 = length - split_index;

  // Allocate space for an array of ints of the length of the first subarray
  // by multiping the size in bytes that it takes to store an int by the
  // number of bytes in the first subarray.  We again dereference length1 to
  // access the array length that we set above.  We also dereference subarray1
  // so that we store the memory address (pointer) returned by malloc() into
  // the pointer to an int that subarray points to.
  *subarray1 = malloc(sizeof(int) * *length1);

  // Do the same as the above, but for the second subarray
  *subarray2 = malloc(sizeof(int) * *length2);

  // Loop through the indexes of the first subarray from 0 ... the length of
  // the first subarray.  Copy the values from the original array into the first
  // subarray.  Notice that we need to dereference subarray1 to access the
  // pointer to an int (i.e. what subarray1 itself is pointing to), and at that
  // point we have an array that we can use the standard array index notation
  // with, i.e. [i].
  for (int i = 0; i < *length1; i++)
    (*subarray1)[i] = array[i];

  // Copy the elements from the original array into the second subarray.  We
  // use split_index as an offset into the original array, as its the elements
  // in the second portion of the array from the split index onwards that need
  // to be copied into the second subarray.  So if the split_index is 3 we
  // need to copy the elements from 3 onwards in the original array, by adding
  // the split index to i, we account for this and copy the right elements.
  for (int i = 0; i < *length2; i++)
    (*subarray2)[i] = array[split_index + i];
}