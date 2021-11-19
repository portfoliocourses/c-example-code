/*******************************************************************************
*
* Program: getenv() Function
* 
* Description: Example of using the getenv() function in C to get the value of 
* an environment variable, which are often used to configure how programs run.
*
* YouTube Lesson: https://www.youtube.com/watch?v=bB1PV9Cb98c 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  // getenv will return a pointer to a string for the value of the environment 
  // variable called LOG_DIR
  char *log_dir = getenv("LOG_DIR");
 
  // output the string
  printf("LOG_DIR:\n%s\n", log_dir);

  return 0;
}