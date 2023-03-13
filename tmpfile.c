/*******************************************************************************
*
* Program: tmpfile() Demonstration
*
* Description: An example of creating a temporary file using tmpfile() in C,
* including writing data to and reading data from the temp file. 
*
* YouTube Lesson: https://www.youtube.com/watch?v=ixGKKGMEmGk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// A temporary file will be created when we call tmpfile(), which returns a 
// FILE pointe that allows us to access the file.  The file is opened in wb+
// mode so we can write to and read from the binary file.  The file will be 
// deleted either when the program exits or when we close the file.  We might 
// use a temp file to store data that our program does not need for a period of
// time, perhaps to free up space on the heap that was otherwise normally be 
// occupied with this data.  The code below is an example of doing this.

#include <stdio.h>
#include <stdlib.h>

// The length of an array of ints to be stored both in the heap and in a temp
// file created by tmpfile().
#define LENGTH 10

int main(void)
{
  // Use malloc() to allocate space for a block of memory on the heap large 
  // enough to store LENGTH number of int values, store the pointer (memory 
  // address) it returns into data1.  This block of memory can be treated like
  // an array of data.
  int *data1 = malloc(sizeof(int) * LENGTH);

  // Store the values from 0 ... LENGTH-1 into this array on the heap
  for (int i = 0; i < LENGTH; i++)
  {
    data1[i] = i;
  }

  // Open a temporary file using tmpfile().  The function will return a FILE 
  // pointer to the file that we store into the FILE pointer variable file.
  FILE *file = tmpfile();
  
  // If tmpfile() fails to open the temp file it will return NULL, we check for
  // this an exit with an error message and status if this is the case.  Note 
  // that returning 1 instead of returning 0 is a signal to the shell/terminal 
  // that something has gone wrong in our program.
  if (file == NULL)
  {
    printf("Error opening temp file.\n");
    return 1;
  }

  // The file will be opened in wb+ mode which means we can read and write to 
  // the binary file.  Here we use fwrite() to write LENGTH number of elements 
  // of size sizeof(int) into the file from the block of memory located at the 
  // memory address (pointer) stored by data1.  i.e. we store the array of data
  // into the temp file.
  fwrite(data1, sizeof(int), LENGTH, file);

  // Let's imagine our program no longer needs this data for some period of 
  // time, so we free the block of memory on the heap that data1 points to.
  free(data1);

  // Let's imagine that our program now needs the data again, and we allocate 
  // space to store LENGTH number of int values again and store the pointer to
  // the block of memory in data2.
  int *data2 = malloc(sizeof(int) * LENGTH);
 
  // The FILE pointer 'file' will now point to the end of the file as we have 
  // just written to the file.  If we want to read the data from the file we 
  // should have it point to the beginning of the file.  The rewind() function
  // will rewind the file pointer to the beginning of the file.
  rewind(file);

  // We now call fread() to read LENGTH number of elements of size sizeof(int)
  // from the file and store them into the block of memory located at the 
  // memory address stored by data2.
  fread(data2, sizeof(int), LENGTH, file);

  // We could say that we are now done working with the file, and so we close 
  // our access to the file.  This will delete the temporary file.  Note the 
  // file will also be deleted when our program exits.  But we should still 
  // call fclose() to close access to the temporary file when we are done 
  // working with it, as it is still a 'resource' for the operating system, and
  // there is ultimately a limit to how many temporary files we can have open
  // at once (however high that limit may be in practice).
  fclose(file);
  
  // Output the values stored in the array of ints that data2 points to.
  for (int i = 0; i < LENGTH; i++)
  {
    printf("%d ", data2[i]);
  }
  printf("\n");

  // Free the block of memory that data2 points to.
  free(data2);

  return 0;
}