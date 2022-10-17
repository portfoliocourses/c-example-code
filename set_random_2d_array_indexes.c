/*******************************************************************************
*
* Program: Insert A Value At Random Positions In A 2D Array
*
* Description: Example of how to set randomly chosen indexes in a 2D array to
* a value using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=rzWq24bYuvo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

// Preprocessor constants to define the dimensions of the array
#define ROWS 8
#define COLS 8

void set_random(int array[ROWS][COLS], int value, int total);

int main(int argc, char *argv[])
{
  // Seed the random number generator with the current time multiplied by the
  // process id of the running process, which should make for a very unique
  // value (unique to both the time the process runs, and which process runs).
  // This will ensure we get a different sequence of random numbers each time
  // we run the program.
  srand( time(NULL) * getpid() );

  // Declare the 2D array
  int array[ROWS][COLS];

  // Set all elements in the 2D array to the value '1' initially.  The outer
  // loop will use counter variable i to loop through each row index, and then
  // FOR each row index we loop over each column index with the inner loop
  // and counter variable j.  By setting array[i][j] = 1 we'll set the
  // element at each possible row/column index combination to 1.
  for (int i = 0; i < ROWS; i++)
    for (int j = 0; j < COLS; j++)
      array[i][j] = 1;

  // Output the elements in the 2D array before randomly setting positions
  // in the 2D array to a value
  printf("BEFORE: \n");
  for (int i = 0; i < ROWS; i++)
  {
    // The inner loop will ouput all the values in a given row, and this will
    // be done for each row in the 2D array due to the outer loop
    for (int j = 0; j < COLS; j++)
      printf("%d ", array[i][j]);

    // Output a newline at the end of each row of values so that the next row
    // appears on the next line
    printf("\n");
  }

  // Use set_random() to insert the value 2 at 10 random positions in the
  // 2d array
  set_random(array, 2, 10);

  // The same as above, output the elements of the 2D array AFTER inserting the
  // value into the 2D array at random positions, so we can see where the value
  // was inserted
  printf("AFTER: \n");
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
      printf("%d ", array[i][j]);
    printf("\n");
  }

  return 0;
}

// Inserts the value total number of times into the array at unique positions
void set_random(int array[ROWS][COLS], int value, int total)
{
  // Store the randomly generated row and column indexes
  int row_random = 0;
  int col_random = 0;

  // Store the previous used row and column indexes, where each index in the
  // two arrays stores a 'pair' of row/column indexes.  Used to ensure the
  // values are inserted at unique positions in the 2D array.
  int previous_row[total];
  int previous_col[total];

  // Used to help check if the randomly selected row and column indexes
  // have been previosly used, and whether or not new row and column indexes
  // need to be generated again.
  bool already_selected = false;

  // Loop has counter variable i go from 0 ... total so we insert the value
  // total number of times into the 2D array
  for (int i = 0; i < total; i++)
  {
    // loop responsible for generating unique random row/colum index to insert
    // the value into
    do
    {
      // assume that the row and colum indexes randomly generated have NOT
      // been previously used
      already_selected = false;

      // Generate random row and column indexes.  rand() will return a random
      // integer between 0 and RAND_MAX (a very large positive integer), and
      // the modulus operator % will give us the remainder of a division
      // operation.  So rand() % ROWS will give us a random integer between
      // 0 ... ROWS-1 (in this case with ROWS=8 it will be 0...7, because the
      // only possible remainders when dividing by 8 are 0,1,2,3,4,5,6,7).
      // We use this technique to get random integers in the range of the
      // row and colum indexes.
      row_random = rand() % ROWS;
      col_random = rand() % COLS;

      // We check the previous_row and previous_col arrays to see if this
      // pair of row and column indexes that we've just randomly generated
      // was previously used together, and if so we set already_selected to
      // true to continue the loop and generate another random row and
      // column index.  Note that the ith index of each "previous" array
      // contains a "pair of indexes" between the two of them (the row, and
      // the column) that was previously used.
      for (int j = 0; j < i; j++)
        if (previous_row[j] == row_random && previous_col[j] == col_random)
          already_selected = true;

    // If the randomly generated row and column index was previously used then
    // already_selected will have been set to true by the loop above, and we'll
    // run this loop body again to generate new randomy row and column indexes.
    } while (already_selected);

    // Store the randomly generated row and column index into the previous_row
    // and previous_col arrays so we can keep track of the fact that this row
    // and column index were previously used together.  The ith index of these
    // arrays together make up a "row and colum index position" that has already
    // had the value inserted.
    previous_row[i] = row_random;
    previous_col[i] = col_random;

    // Insert the value into the array at the randomly generated row and
    // colum index position
    array[row_random][col_random] = value;
  }
}