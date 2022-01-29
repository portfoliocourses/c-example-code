/*******************************************************************************
*
* Program: Read From Text File
* 
* Description: Example of reading from a text file using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=UtckqNKZFrA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  // data array to store one million numbers
  int data[1000000];

  // file pointer for text file
  FILE *file;

  // open the text file file.txt in read mode using "r"
  file = fopen("file.txt", "r");

  // check if the file failed to open, exit if so
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  // in the case of a text file, we'll need to read in each number in its 
  // string format, and then convert that number to an int using atoi()

  // buffer will store each number in the file in its string format
  char buffer[100];

  // read in all one million numbers in file.txt
  for (int i = 0; i < 1000000; i++)
  {
    // read in the next line/number of the file, store it into buffer
    fgets(buffer, 100, file);

    // use atoi() found in stdlib.h to convert the string representation of 
    // the number to an int
    data[i] = atoi(buffer);
  }

  // close the file
  fclose(file);

  return 0;
}