/*******************************************************************************
*
* Program: Count occurrences of a value in an array
* 
* Description: Example of counting the occurrences of a value in an array.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Im1xqbJmZD8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int occurrences(int array[], int length, int to_find);

int main(void)
{
  // test data
  int myarray1[] = {4,9,5,5,5,5,6,2,1,5};
  int myarray2[] = {0,0,1,1,0,2,0,3};

  // run tests 
  int findarr1_5 = occurrences(myarray1, 10, 5);
  int findarr2_0 = occurrences(myarray2, 8, 0);

  // output test results
  printf("# of 5s found in myarray1: %d\n", findarr1_5);
  printf("# of 0s found in myarray2: %d\n", findarr2_0);

  return 0;
}

// returns the number of times to_find occurs in the array with the given length
int occurrences(int array[], int length, int to_find)
{
  // start count at 0
  int count = 0;

  // check each array element, increment count whenever a match is found
  for (int i = 0; i < length; i++)
    if (array[i] == to_find) count++;

  return count;
}