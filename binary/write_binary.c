/*******************************************************************************
*
* Program: Write To Binary File
* 
* Description: Example of writing to a binary file using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=UtckqNKZFrA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main()
{
  // data array to store one million numbers
  int data[1000000];

  // write one million numbers to the data array
  for (int i = 0; i < 1000000; i++)
    data[i] = 1000000000 + i;

  // file pointer for binary file
  FILE *file;

  // open the binary file file.bin in write mode using "wb"
  file = fopen("file.bin", "wb");

  // check if the file failed to open, exit if so
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }


  fwrite(data, sizeof(data), 1, file);

  // close our access to the file
  fclose(file);
  
  return 0;
}
