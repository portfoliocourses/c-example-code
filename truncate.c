/*******************************************************************************
*
* Program: truncate() Demonstration
* 
* Description: Example of using the truncate() POSIX library function in C to 
* truncate a file.  We need to include unistd.h to use truncate().
*
* YouTube Lesson: https://www.youtube.com/watch?v=viffqXUYN9s 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
  // truncate will truncate "file.txt" to its first 10 bytes, if there is an 
  // error it will return -1
  if (truncate("file.txt", 10) == -1)
  {
    // truncate will set global variable errno in the errno.h library when there
    // is an error, allowing us to use perror() to output a more specific error
    // message as well
    printf("Error Code: %d\n", errno);
    perror("Error");
  }

  return 0;
}