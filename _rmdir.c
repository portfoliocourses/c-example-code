/*******************************************************************************
*
* Program: _rmdir() Demonstration
*
* Description: Example of using the _rmdir() function in C to remove a file 
* system directory.  The function is available on Windows machines/compilers 
* using the direct.h library.
*
* YouTube Lesson: https://www.youtube.com/watch?v=7g_w-cxgZB4
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// the _rmdir() function is found in the direct.h library, and the function will
// set errno in the errno.h library if an error occurs
#include <direct.h>
#include <errno.h>

int main(void)
{ 
  int retval;

  // Attempts to remove a directory called test in the current working 
  // directory, uses a relative path.  If the directory does not exist (perhaps
  // because we run the program twice), an error will occur.
  retval = _rmdir("test");

  // Attempts to remove a directory C:\badtest using an absolute path.  We will
  // also get errors attempting to remove a directory that contains files or 
  // folders or that is being used by another program currently (i.e. an open 
  // handle to the directory exists).
  // retval = _rmdir("C:\\test");
  
  // _rmdir() will return -1 if it fails to remove the directory
  if (retval == -1)
  {
    // output a general error message
    printf("Remove directory failed.\n");
    
    // Global variable errno will be set to a preprocessor constant value by 
    // the _rmdir() function to more specifically identify the error.  Here we 
    // check for the possible values and output more specififc error info.
    if (errno == ENOENT)
      printf("Path not found.\n");
    else if (errno == ENOTEMPTY)
      printf("Directory not empty.\n");
    else if (errno == EACCES)
      printf("An open handle to the directory exists.\n");
    
    // exit with an error stauts
    return 1;
  }
  else printf("Remove directory succeeded.\n");

  return 0;
}
