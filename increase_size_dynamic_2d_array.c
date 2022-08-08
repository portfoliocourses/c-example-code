/*******************************************************************************
*
* Program: Increase The Size Of A Dynamically Allocated 2D Array
*
* Description: Example of how to increase the number of rows and columns in a
* dynamically allocated 2D array in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=d0yeZboE1aI
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  // We'll create our dynamically allocated 2D array by first allocating space
  // for an array of pointers to ints (for each row in the 2D array), and then
  // allocating space for an array of ints for each row.  So we create a pointer
  // to a pointer to an int variable to point to the array of pointers to ints
  // that we will dynamically allocate.
  int **array;

  // Keep track of the number of rows and columns in the 2D array.
  int cols = 4;
  int rows = 4;

  // Allocate space for the array of pointers to ints... i.e. the array of
  // pointers to each 1D array for each row in the 2D array.
  array = malloc(sizeof(int *) * rows);

  // Allocate space for each row of ints in the 2D array, have array[i] point
  // to each row.
  for (int i = 0; i < rows; i++)
    array[i] = malloc(sizeof(int) * cols);

  // Set each element in the array to a unique value.
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      array[i][j] = (i * 10) + j;

  // Print out the values in the 2D array as a grid.
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
      printf("%02d ", array[i][j]);
    printf("\n");
  }
  printf("\n");



  // EXAMPLE: Increase The Number Of COLUMNS

  // Increase the number of columns by 3.
  cols += 3;

  // Each row needs to increase in size by 3, so we use realloc() to reallocate
  // space for each row (array[i]) using the new cols value.
  for (int i = 0; i < rows; i++)
    array[i] = realloc(array[i], sizeof(int) * cols);


  // Set each element in the array to a unique value.
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      array[i][j] = (i * 10) + j;

  // Print out the values in the 2D array as a grid.
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
      printf("%02d ", array[i][j]);
    printf("\n");
  }
  printf("\n");



  // EXAMPLE: Increase The Number Of ROWS

  // Increase the number of rows by 3
  int new_rows = 3;
  rows += new_rows;

  // We need to use realloc() to allocate enough space to store the new number
  // of rows.  This will give us the ability to store pointers to the new
  // rows we'll need to allocate.
  array = realloc(array, sizeof(int *) * rows);

  // Allocate space for the new rows... these are NEW rows so we'll need to use
  // malloc instead of realloc, and we only need to allocate space for the
  // "new rows" at the end of our array of pointers to ints, i.e. from
  // rows - new_rows ... rows.
  for (int i = rows - new_rows; i < rows; i++)
    array[i] = malloc(sizeof(int) * cols);


  // Set each element in the array to a unique value.
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      array[i][j] = (i * 10) + j;

  // Print out the values in the 2D array as a grid.
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
      printf("%02d ", array[i][j]);
    printf("\n");
  }
  printf("\n");



  // free the memory allocated for each row in the 2D array
  for (int i = 0; i < rows; i++)
    free(array[i]);

  // free the memory allocated for the array of pointers
  free(array);


  return 0;
}