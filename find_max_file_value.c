/*******************************************************************************
*
* Program: Find The Largest Number In A File
* 
* Description: Example of finding the largest number in a file with C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=FkbpSvdE6Z8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// defines the input buffer size
#define BSIZE 1024

int main()
{
  FILE *fh;
  char buffer[BSIZE];
  double current, max;
  int numbers = 0;
  
  // open the file for reading
  fh = fopen("file.txt", "r");
  
  // if there was an error opening the file, notify the user and return a 
  // value that indicates the program did not complete as normal
  if (fh == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  
  // read each line of the file one at a time, storing the line into buffer
  while (fgets(buffer,BSIZE,fh) != NULL)
  {
    // convert the string representation of the number to type double
    current = atof(buffer);
    
    // keep track of the maximum number found so far... in the case of the 
    // first number read it is by default the maximum found so far
    if (numbers == 0) max = current;
    else if (current > max) max = current;
   
    // keep track of how many numbers we've read in
    numbers++;
  }

  // close the file
  fclose(fh);
  
  // output the largest number found in the file
  printf("max: %.2f\n", max);

  return 0;
}
