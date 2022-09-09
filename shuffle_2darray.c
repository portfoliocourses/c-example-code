/*******************************************************************************
*
* Program: Shuffle A 2D Array
*
* Description: Shuffles the values in a 2D array using C.  Shuffling the values
* means that values in the 2D array are randomly re-arranged, but all the values
* themselves will still be present in the 2D array after shuffling.
*
* YouTube Lesson: https://www.youtube.com/watch?v=ByLrbQibG9g
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// We include stdlib.h so we can generate random integers with the rand()
// function, and time.h so we can seed the random number generator using the
// time() function to return the current time, and unistd.h so we can also
// use the getpid() function which returns the current process ID to help
// seed the random number generator.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Preprocessor constants define the dimensions of the 2D array, and the
// constants are used all over the program to work with the 2D array such
// that we can just change these values here if we want to change the
// dimensions of the 2D array.
#define ROWS 6
#define COLS 5

// functions for printing and shuffling the 2D array will be defined
void print(int array[ROWS][COLS]);
void shuffle(int array[ROWS][COLS]);

int main(int argc, char *argv[])
{
  // Shuffling the 2D array will involve selecting random row and column indexes
  // within the 2D array, using random integers and the rand() function.  We
  // need to seed the random number generator with a number that is unique each
  // time our program runs in order to ensure the random numbers generated
  // are unique each time it runs.  We pass the seed value to the srand()
  // function, and we multiply the current time as represented by a large
  // integer (time(NULL) will return this value) by the process id of the
  // running process as returned by getid().  The time will be different each
  // time our program runs and the process ID of each process on our machine
  // will be different, which allows us to construct a fairly unique
  // seed value.
  srand( time(NULL) * getpid() );

  // Declare an array with ROWS number of rows and COLS number of COLS
  int array[ROWS][COLS];

  // We'll fill the array with integers between 1 ... ROWS * COLS with the
  // help of value to keep track of the next value to be assigned
  int value = 1;

  // The outer loop uses the counter variable i to loop through each row
  // index from 0 ... ROWS - 1
  for (int i = 0; i < ROWS; i++)
  {
    // The innner loop uses the counter variable j to loop through each column
    // index from 0 ... COLS - 1.  With the outer looo looping over each
    // row and the inner loop looping over each column we can use the counter
    // variables i/j to access each row/colum index in our 2D array.
    for (int j = 0; j < COLS; j++)
    {
      // Set the next value at the current element's index
      array[i][j] = value;

      // increment value so the 'next' element is set to the next integer up
      // from the current value
      value++;
    }
  }

  // Output the array before shuffling, notice how it contains values from
  // 0... ROWS * COLS in order going from the top-left to bottom-right of
  // the 2D array
  print(array);

  // Shuffle the 2D array
  shuffle(array);

  // Output the array after shuffling so we can see the effect of the shuffling
  print(array);


  return 0;
}

// Outputs the values in the 2D array into a nicely formatted table
void print(int array[ROWS][COLS])
{
  // Loop over each row index in the 2D array
  for (int i = 0; i < ROWS; i++)
  {
    // Loop over each column index in the 2D array, and output each value
    // for this row as given by the counter variable i of the outer loop
    for (int j = 0; j < COLS; j++)
      printf("%2d ", array[i][j]);

    // Output a new line after outputting all the values in this row so that
    // the next row appears on the next line
    printf("\n");
  }

  // Output a newline after outputing the 2D array values
  printf("\n");
}

// Shuffles the values in the 2D array by randomly re-arranging them
void shuffle(int array[ROWS][COLS])
{
  // We'll perform the shuffling by 'looping over' each element in our 2D
  // array and randomly swapping it with another element in our 2D array.
  // We'll randomly select another element to swap the 'current element' with
  // by generating a random row and colum index.

  // rand_row and rand_col will store the random row and colum indexes
  int rand_row = 0;
  int rand_col = 0;

  // temp will be used as a temporary variable to help perform the swap
  int temp;

  // loop over each row index with counter variable i
  for (int i = 0; i < ROWS; i++)
  {
    // loop over each column index with counter variable j
    for (int j = 0; j < COLS; j++)
    {
      // Randomly generate row and column indexes so that we swap the 'current
      // element' as given by indexes i and j with the element at the indexes
      // that are randomly generated.
      //
      // rand() returns a random integer between 0 and RAND_MAX (a very large
      // positive integer).  The modulus operator % returns the remainder of
      // dividing this number by ROWS.  This will result in an integer between
      // 0...ROWS-1, exactly the index range of our rows!  We use this
      // technique to randomly select a row, and do the same for the column
      // index too.
      rand_row = rand() % ROWS;
      rand_col = rand() % COLS;

      // Swap the elements
      temp = array[i][j];
      array[i][j] = array[rand_row][rand_col];
      array[rand_row][rand_col] = temp;
    }
  }
}