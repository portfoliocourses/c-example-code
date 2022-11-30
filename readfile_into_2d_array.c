/*******************************************************************************
*
* Program: Read Numbers In A File Into A 2D Array
*
* Description: Read rows of numbers stored on each line of a file and store them
* into a 2D array using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Gaq10GBlRJA
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// This program assumes the file will have 8 columns with 4 float values each,
// for example:
//
// 1.1 1.2 1.3 1.4
// 2.1 2.2 2.3 2.4
// 3.1 3.2 3.3 3.4
// 4.1 4.2 4.3 4.4
// 5.1 5.2 5.3 5.4
// 6.1 6.2 6.3 6.4
// 7.1 7.2 7.3 7.4
// 8.1 8.2 8.3 8.4
//
// The program can work for other row and column numbers by adjusting the
// ROW and COLUMN preprocessor constants.

#include <stdio.h>

// Define preprocessor constants for the number of rows and columns in the file,
// the 2D array will be declared using these and the constants will be used
// to help read the file contents and output the 2D array.
#define ROWS 8
#define COLUMNS 4

int main(void)
{
  // Declare the 2D array of floats with ROWS number of rows and COLUMNS number
  // of columns
  float array[ROWS][COLUMNS];

  // Declare a file pointer variable called file to access and read the file
  FILE *file;

  // Attempt to open the file named file.txt for reading
  file = fopen("file.txt", "r");

  // If fopen() fails to open the file, for example because the file does not
  // exist, it will return NULL and NULL will be assigned to file.  Before
  // proceeding, check to see if file is NULL (i.e. that opening the file
  // failed) and exit the program with an error message and status if so.
  // Returning 1 instead of returning 0 with exit the program with a status
  // that signals to the shell that an error has occurred.
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  // row will keep track of which row in the 2D array we are storing numbers
  // into, as in the loop beloe we'll read the file into the 2D array one
  // line ('row') at a time
  int row = 0;

  // Continue the loop until we reach the end of the file (as feof() returns
  // true once we reach the end of the file).
  while (!feof(file))
  {
    // Check if an error has occured while reading the file and exit with an
    // error message and status similar to how we did above (ferror() will
    // return true if an error has occurred while reading the file).
    if (ferror(file))
    {
      printf("Error reading file.\n");
      return 1;
    }

    // The outer loop will read in each line/row of data, this inner loop will
    // read the value at each column in that row and store them into the 2D
    // array.  The counter variable i goes from 0 to the number of columns.
    for (int i = 0; i < COLUMNS; i++)
    {
      // fscanf() will read the next value from the file and store into the
      // row/column index as given by row/i (where row is the current row
      // being stored, and i the current column).  The fscanf() function
      // automatically skips over whitespace characters when reading the next
      // float value, so the spaces separating values on a line and the newlines
      // separating each row will be automatically skipped.  It's possible that
      // the file could end with trailing whitespace characters scuh as trailing
      // newlines, if so the feof() call above in the while loop condition
      // will not recogonize the end of the file.  fscanf() will return EOF
      // in this case though, as it will attempt to read another number but
      // there will be no additional number.  We use break to stop the
      // inner loop if this occurs.
      if (fscanf(file, "%f", &array[row][i]) == EOF)
        break;
    }

    // Increment row so that the numbers on the next row/line in the file are
    // stored in the next row of the 2D array
    row++;

    // If we've reached the "capacity" of the 2D array in that all rows are
    // now filled with data, we can break to stop the loop as we cannot
    // store anymore data.
    if (row == ROWS) break;
  }

  // close the file as we are done working with it
  fclose(file);

  // Output the values in the 2D array.  The outer loop uses the counter
  // variable i to loop over all row indexes and the inner loop that executes
  // for each row index i will loop over all column indexes using counter
  // variable j.  We output the values at the row/column index given by i/j
  // and output a newline after outputing the values on each row so that the
  // next row appears on the next line.
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLUMNS; j++)
      printf("%.1f ", array[i][j]);
    printf("\n");
  }

  return 0;
}