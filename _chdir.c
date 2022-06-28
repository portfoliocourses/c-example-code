/*******************************************************************************
*
* Program: _chdir() Demonstration
*
* Description: Example of using the _chdir() function in C to change the current
* working directory of the executing program.  The function is available on 
* Windows machines/compilers using the direct.h library.
*
* YouTube Lesson: https://www.youtube.com/watch?v=g7tqnYfmJ2s
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// the _chdir() function is found in the direct.h library, and the function will
// set errno in the errno.h library if an error occurs
#include <direct.h>
#include <errno.h>

int main(void)
{   
  
  // Create a buffer to store the directory
  char buffer[1024];
  
  // Get the current working directory and store it into the buffer char array,
  // exit with an error message and status if there is an error.
  if (_getcwd(buffer, 1024) == NULL)
  {
    printf("Get current working directory failed.\n");
    return 1;
  }
  
  // Output the current working directory
  printf("Current working directory: \n\n%s\n\n", buffer);
  
  // Create a string literal for the directory we wish to change the current
  // working directory to... this is intended to be a directory that will 
  // cause an error (unless the directory C:\badpath actually exists on 
  // the machine that this code is run on...).
  char *newdir = "C:\\badpath";
  
  // Call _chrdir() to change the current working directory, it will return -1 
  // if it fails to change the current working directory
  if (_chdir(newdir) == -1)
  {
    // Output an general error message
    printf("Change current working directory failed.\n");
    
    // The _chdir() function may set global variable errno to a specific error
    // code that we can check for, and then handle the error based on the type
    // of erro that has occurred (in this case outputting a more specific 
    // error message).
    if (errno == ENOENT)
      printf("Path not found.\n");
    
    // Exit with an error status
    return 1;
  }

  // Get and output the current working directory as before to check that the 
  // current working directory was changed
  if (_getcwd(buffer, 1024) == NULL)
  {
    printf("Get current working directory failed.\n");
    return 1;
  }
  printf("Current working directory: \n\n%s\n\n", buffer);

  return 0;
}