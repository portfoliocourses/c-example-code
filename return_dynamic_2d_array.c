/*******************************************************************************
*
* Program: Return A Dynamically Allocated 2D Array
*
* Description: Example of how to return a dynamically allocated 2D array from
* a function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=22wkCgsPZSU
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// We cannot actually return a 2D array from a function C as we cannot return
// arrays from functions.  But a 2D dynamically allocated array is accessed
// via a pointer, and what we can return is a pointer to the 2D array!

// Returns a pointer to a 2D array of m rows and n columns that the function
// will dynamically allocate and fill with the value fill_value
int **create_matrix(int m, int n, int fill_value)
{
  // A pointer to a pointer to an int is used to store the pointer to our
  // 2D array of ints
  int **matrix;

  // malloc() is used to allocate space to store an array of pointers to ints
  // of length m... each element in this array will point to one of the 'm'
  // number of rows in our 2D array.  matrix will thus store the memory address
  // of the first elemetn in this array, but we can also think of it as a
  // pointer to our 2D array.  We use sizeof(int *) to get the size in bytes
  // of a pointer to an int, and multiply this by the number of elements
  // needed in our array (m) to allocate space for an array able to store
  // this amount of pointers to ints.
  matrix = malloc(sizeof(int *) * m);

  // Next we allocate space for each row of ints in our 2D array, where each
  // element in our array of pointers to ints as given by matrix[i] is set to
  // point to one of these rows.  sizeof(int) will give us the number of bytes
  // that it takes to store an int, and we multiply this by the number of
  // ints stored at each row (n, i.e. the number of columns), to have malloc()
  // allocate enough space to store a row of ints of this size.
  for (int i = 0; i < m; i++)
    matrix[i] = malloc(sizeof(int) * n);

  // Set the element in the 2D array at each row/column index to the fill value
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      matrix[i][j] = fill_value;

  // Return the pointer to our 2D array... effectively returning the memory
  // address of the first element in the array of pointers to ints (i.e. the
  // array of pointers to each row of data).
  return matrix;
}

int main(void)
{
  // We need to store the returned pointer value somewhere in order to access
  // and use the dynamically allocated 2D array the function created, so we
  // declare matrix as a pointer to a pointer to an int to store this value.
  int **matrix;

  // Declare and initialize variables for the number of rows (5) and columns (4)
  // in our 2D array.
  int m = 5;
  int n = 4;

  // Call the function to create an mxn 2D array and fill it with the value 2,
  // we assign the returned pointer to matrix.
  matrix = create_matrix(m,n,2);

  // We can use "array notation" when working with the pointer matrix (the same
  // as we did in the create_matrix() function).  Here we output the 2D array
  // as a 2D grid of values.
  for (int i = 0; i < m; i++)
  {
    // Outputs the values at each row
    for (int j = 0; j < n; j++)
      printf("%d ", matrix[i][j]);

    // Outputs a newline at the end of each row so the next row of values
    // appears on a new line
    printf("\n");
  }

  // Free the memory that was allocated for each row in the 2D array
  for (int i = 0; i < m; i++)
    free(matrix[i]);

  // Free the memory that was allocated for the array of pointers to each
  // row in our 2D array
  free(matrix);

  return 0;
}