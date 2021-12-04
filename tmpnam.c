/*******************************************************************************
*
* Program: tmpnam() Demonstration
* 
* Description: Example of using the tmpnam() function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=qo8nwek0Jx8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  // allocates char array large enough to hold temporary filename using the 
  // constant L_tmpnam
  char filename[L_tmpnam];

  // tmpnam will store the filename into the filename char array
  tmpnam(filename);

  // output the temporary filename
  printf("%s\n", filename);

  // if we pass the argument NULL, tmpnam will return a pointer to a temporary 
  // file name string... the string is stored into a temporary buffer that will 
  // be overridden when tmpnam is called again
  char *filename2 = tmpnam(NULL);

  // output the second temporary filename
  printf("%s\n", filename2);
  
  // open the first temporary filename for writing
  FILE *file = fopen(filename, "w");

  // if the file is opened successfully, write some content to the file
  if (file == NULL)
  {
    printf("Error opening temporary file.\n");
    return 1;
  }
  else fprintf(file, "Some content\n");

  // close the file
  fclose(file);
 
  // we could remove the file with the remove() function is we wanted to delete
  // it when our program is done its work, otherwise the file will remain after 
  // our program finishes execution
  //
  // remove(filename);
  
  return 0;
}