/*******************************************************************************
*
* Program: _mkdir() Demonstration
*
* Description: Example of using the _mkdir() function in C to create a file 
* system directory.  The function is available on Windows machines/compilers 
* using the direct.h library.
*
* YouTube Lesson: https://www.youtube.com/watch?v=VHsWVQXoTMI
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// the _mkdir() function is found in the direct.h library, and the function will
// set errno in the errno.h library if an error occurs
#include <direct.h>
#include <errno.h>

int main(void)
{ 
  // Attempts to create a directory called test in the current working 
  // directory, uses a relative path.  If the directory already exists (perhaps
  // because we run the program twice), an error will occur.
  int retval = _mkdir("test");
  
  // Attempts to create a directory 'abc' in C:\badtest, if C:\badtest does 
  // not exist an error will occur.
  // int retval = _mkdir("C:\\badtest\\abc");
  
  // the function will return -1 if there is an error
  if (retval == -1)
  {
    // report to the user that an error has occurred
    printf("Make directory failed.\n");
   
    // errno is a global variable in errno.h that _mkdir will set to a 
    // preprocessor constant to identify the specific error that has occurred

    // Here we check for the directory already exists and path not found errors
    // and report which has occurred if one of them has
    if (errno == EEXIST)
      printf("Directory already exists.\n");
    else if (errno == ENOENT)
      printf("Path not found.\n");

    // exit with an error status
    return 1;
  }
  else printf("Make directory succeeded.\n"); 

  return 0;
}
