/*******************************************************************************
*
* Program: Command-line argument tutorial
* 
* Description: Examples of using command-line arguments in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=wa2AfzyOff0  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  // check if the correct number of arguments is present, exit if they are not
  if (argc != 3)
  {
    printf("Two args required!\n");
    exit(-1);
  }
  
  // convert the arguments to an int
  int lower = atoi(argv[1]);
  int higher = atoi(argv[2]);

  // use the arguments to determine how the program should function
  for (int i = lower; i <= higher; i++)
    printf("%d\n", i);

  // print out the number of arguments, which includes the program name itself!
  // printf("argc: %d\n", argc);

  // we could have a loop print out the arguments and handle the number of 
  // arguments "programmatically" using argc
  // for (int i = 0; i < argc; i++)
  //  printf("argv[%d]=%s\n",i,argv[i]);

  // or we can print out the arguments individually...
  // printf("argv[0]=%s\n", argv[0]);
  // printf("argv[1]=%s\n", argv[1]);
  // printf("argv[2]=%s\n", argv[2]);
  // printf("argv[3]=%s\n", argv[3]);

  return 0;
}
