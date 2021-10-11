/*******************************************************************************
*
* Program: Average of Numbers In a File
* 
* Description: Example of finding the average of numbers in a file in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=e6MxeC7htSE 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// size of input buffer
#define BSIZE 1024

int main()
{
  FILE *fh;
  char buffer[BSIZE];
  double average, sum = 0;
  int total = 0;
  
  // open the file
  fh = fopen("file.txt", "r");
  
  // if the file failed to open successfully, exit with an error message
  if (fh == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  
  // read each line of the file until we reach the end of the file
  while (fgets(buffer,BSIZE,fh) != NULL)
  {
    // convert the string format number at each line to a double, add it to 
    // the sum, and keep track of the total number of numbers
    sum += atof(buffer);
    total++;
  }
  
  // compute the average and print the result
  average = sum / total;
  printf("average: %.2f\n", average);

  return 0;
}
