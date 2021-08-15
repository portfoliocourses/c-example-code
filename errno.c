/*******************************************************************************
*
* Program: Error handling
* 
* Description: Example of error handling in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=OOuZLI5ingc 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <errno.h>
#include <string.h>

// allows us to access errno from errno.h in this file, errno will store a 
// number representing the error that has taken place
extern int errno;

int main(void) 
{
  FILE *fh;

  // before any error takes place, errno will be set to zero by default
  printf("Errno before: %d\n", errno);

  // try to open a file that doesn't exist
  fh = fopen("dne.txt", "r");

  if (fh == NULL)
  {
    // now errno will be set to '2', a number representing the error, we use 
    // fprintf to print to stderr which by default may be the terminal but 
    // could instead perhaps be a file
    fprintf(stderr, "Errno after: %d\n", errno);
   
    // perror will append a : and space and then output the error message 
    // associated with errno
    perror("Error msg");

    // if we call perror with a blank string it will simply output the 
    // error message
    //  perror("");
    
    // we can use also pass strerror the errno in order to get the error 
    // message string
    fprintf(stderr,  "Error msg: %s\n", strerror(errno) );

  // we know the file doesn't exist, but just in case it does let's be proper 
  // and close the file handle
  } else fclose(fh);

  return 0;
}
