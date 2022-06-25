/*******************************************************************************
*
* Program: _getcwd() Demonstration
*
* Description: Example of using the _getcwd() function in C to get the current 
* working directory of the executing program.  The function is available on 
* Windows machines/compilers using the direct.h library.
*
* YouTube Lesson: https://www.youtube.com/watch?v=RzDqYPB0QzU
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// the _getcwd() function is found in the direct.h library, and the function will
// set errno in the errno.h library if an error occurs
#include <direct.h>
#include <errno.h>

int main(void)
{ 
  // buffer to store the path of the current working directory as a string
  char buffer[20];

  // We could call the function like this, supplying a pointer to a char as a 
  // first argument as the location in memory to store the string of the path 
  // of the current working directory.  We also supply a 'max length' for the 
  // string that can be stored into this buffer.  And the function will store 
  // the string into this buffer, if it cannot, perhaps because the max length 
  // is not large enough to store the path, the function will return NULL.  If
  // the function CAN store the string into the buffer, it will return a 
  // char pointer to the buffer.
  //
  // char *retptr = _getcwd(buffer, 20);
  
  // If we supply NULL as a first argument to the function the behaviour will 
  // be different.  The function will instead dynamically allocate space for to 
  // store the path of the current working directory as a string, and it will 
  // return a char pointer to this space.  We supply a length argument, but this
  // time it is the minimum amount of space that will be allocated to store the 
  // path.  If more space is required, more space will be allocated to store the 
  // path.  If the function cannot get the current path (perhaps because space 
  // cannot be allocated), it will return NULL to represent an error again.
  char *retptr = _getcwd(NULL, 1024);
  
  // chekc if an error occurred
  if (retptr == NULL)
  {
    // Output a generic error message
    printf("Get current working directory failed.\n");

    // When we include errno.h we gain access to the errno global variable, the 
    // _getcwd() function may set errno to a more specific error code if an 
    // error occurs.
    
    // Check for the possible specific error codes, and output a more specific 
    // error message.  We could handle each error in a different way specific 
    // to the nature of the error.
    if (errno == ERANGE)
      printf("Path exceeds max buffer length.\n");
    else if (errno == ENOMEM)
      printf("Memory cannot be allocated for path.\n");

    return 1;
  }
  
  // Ouput the current working directory if no error has occcrred
  printf("Current working directory: \n\n%s\n", retptr);
  
  // Important: we need to free the dynamically allocated memory in the case 
  // that _getcwd() was passed NULL as a first argument and dynamically 
  // allocated space to store the path.
  free(retptr);

  return 0;
}