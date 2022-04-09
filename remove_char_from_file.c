/*******************************************************************************
*
* Program: Remove All Occurrences Of A Char From A File (Without A Temp File)
* 
* Description: Program that removes all occurrences of a char from a file but 
* without using a temporary or additional file, implemented using C.  This 
* program assumes the file is made up of 1 byte ASCII chars and will not work
* with 2-4 byte UTF-8 characters.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Lie-jO2cpSY  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

int main(void)
{
  // stores the filename of the file to remove the char from
  char filename[1024];

  // we'll open the file with one pointer to read chars from the file and 
  // another to write chars to the file
  FILE *read;
  FILE *write;

  // stores the char to remove
  char remove;

  // prompt the user for the char to remove, store the char in remove
  printf("Char: ");
  scanf("%c", &remove);
  
  // prompt the user for the filename, store it into filename
  printf("File: ");
  scanf("%s", filename);
  
  // open the file in read mode with read file pointer to read each char
  read = fopen(filename, "r");

  // open the file in r+ mode which allows us to write to the file starting
  // from the first char in the file *and* without making the file contents 
  // blank as w mode would 
  write = fopen(filename, "r+");
  
  // if there is an error opening the file, exit with error message and status
  if (read == NULL || write == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  // stores each char read from the file
  int c;
  
  // keeps a count of how many chars encountered are *not* occurrences of 
  // the char to remove, and will be used to truncate the file
  int count = 0;

  // we read each in the file with the read pointer one at a time, until we 
  // reach the end of the file or there is an error at which point we stop
  while (true)
  {
    // read the next char in the file with the read pointer
    c = fgetc(read);
    
    // stop if we reach the end of the file or there is a file access error
    if (feof(read) || ferror(read))
      break;
    
    // if the char we've just read is *not* the one we want to remove we write
    // it to the very same file but using the *write* pointer instead... this 
    // effectively overwrites the existing file contents with a version of the 
    // file contents that exclude the char we want to remove, this will leave 
    // us with "excess chars" in the file however... so for example if we wish
    // to remove the char 'c' and our file looks like this:
    //
    // bbbbccccdddd
    //
    // then after running this loop our file will look like this:
    //
    // bbbbdddddddd
    //
    // where we have written the existing contents of the file minus the char 
    // we wish to remove (i.e. bbbbdddd) into the file from the start of the 
    // file, but now we have 4 excess "dddd" chars.  
    //
    // So we keep a count of how many chars we want to have in our new version
    // of the file using count, and we will truncate our file down to this 
    // number of characters!  This number of characters is the amount of 
    // characters that were *not* the character we want to remove.
    //
    if (c != remove)
    {
      fputc(c, write);
      count++;
    }
  }
  
  // truncate will truncate the file down to 'count' bytes, removing the 
  // excess characters from the file... if it fails it returns -1 and so 
  // we exit with an error message and status if this is the case
  if (truncate(filename, count) == -1)
  {
    printf("Error truncating file.\n");
    return 1;
  }

  // Note that because we truncate our file to "count" bytes, we're depending 
  // on the chars in our file being one byte in length!  So for one byte
  // ASCII chars our program will be fine, but it will not work for 2-4 
  // byte UTF-8 characters.

  return 0;
}