/*******************************************************************************
*
* Program: system() function demo
* 
* Description: Examples of using the system() function in C to run shell 
* commands.
*
* YouTube Lesson: https://www.youtube.com/watch?v=rVFpdKtS5jA  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  // run an ls command to list files in the current directory
  system("ls");

  // run commands to create a file called test.txt and fill it with some 
  // content and then output that content
  system("echo 'some content' > test.txt");
  system("cat test.txt");
  
  // if there is an error with the command system will return a non-zero value
  if (system("abc") != 0)
    printf("\nError executing command.\n");

  return 0;
}