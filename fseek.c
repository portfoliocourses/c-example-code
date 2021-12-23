/*******************************************************************************
*
* Program: fseek() Tutorial
* 
* Description: Example of using fseek() in C to modify the position of a stream.
*
* YouTube Lesson: https://www.youtube.com/watch?v=tY6o2ZrGdeM  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  FILE *file;

  // open file.txt for writing
  file = fopen("file.txt", "w");

  // if the file did not open successfully exit with an error status
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  // write 0-9 followed by a newline to the file
  fprintf(file, "0123456789\n");

  // when we write to the file again, writing will continue right at the 
  // location in the file that the last write ended at... we can say this 
  // is the file location or the file position of the stream.  Our file will 
  // now have 0123456789 on the first line and abcdefghij on the second line.
  fprintf(file, "abcdefghij\n");

  // we can use fseek() to modify the file location... SEEK_SET will move 
  // the file location to the start of the file, and an offset of 4 characters
  // will be applied from there
  fseek(file, 4, SEEK_SET);

  // now when we write to the file at this new file location, we change the 
  // first line of our file from 012345679 to 0123ABC789
  fprintf(file, "ABC");

  // the constant SEEK_CUR will apply the offset to the CURRENT file location, 
  // so in this case an offset of 1 is added to the current file location
  fseek(file, 1, SEEK_CUR);

  // now when write "D" to the file the first line of our file changes from 
  // 0123ABC789 to 0123ABC8D9
  fprintf(file, "D");

  // the constant SEEK_END will move the file location to the end of the file, 
  // and an offset of -4 will be applied from there (moving the file location 
  // to 4 characters BACK FROM the end of the file)
  fseek(file, -4, SEEK_END);

  // this will change the second line of our file from abcdefghij to abcdefg**j
  // (remember that the newline \n is also a character!)
  fprintf(file, "**");

  // if fseek fails it will return 0... in this case it will fail because it 
  // makes no sense to add an offset of 10 when the file location is the end of 
  // the file... 
  if (fseek(file, 10, SEEK_END) == 0)
  {
    printf("Seek failed!\n");
    return 1;
  }

  // close the file when we are done with it
  fclose(file);

  return 0;
}