/*******************************************************************************
*
* Program: strcpy() and strncpy() Tutorial
* 
* Description: Examples of using strcpy() and strncpy() in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=1hUF8IAP-P8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
  // source string
  char src[10] = "123456789";
  
  // strcpy copies the source string str into dest1
  char dest1[50];
  strcpy(dest1, src);
  printf("dest1: %s\n", dest1);
  
  // if the destination character array is not large enough to hold the source 
  // string we can expect an error at runtime
  // char dest2[5];
  // strcpy(dest2, src);
  
  // strncpy allows to copy a specified number of characters with a 3rd argument
  // in this case we copy all 10 characters from src to dest3
  char dest3[50];
  strncpy(dest3, src, 10);
  printf("dest3: %s\n", dest3);
  
  // as with strcpy, if the destination character array is too small to hold 
  // the source string we can expect an error at runtime
  //char dest4[5];
  // strncpy(dest4, src, 10);
  
  // if the number of characters to copy is larger than the number of characters
  // in the source string, this is actually OK, the string will copy and to 
  // the destination characater array and extra characters beyond the length 
  // of the string will be set to the null terminator
  char dest5[50];
  strncpy(dest5, src, 40);
  printf("dest5: %s\n", dest5);
  
  // If we only copy 2 characters from this source string, the null terminator 
  // will not be copied over (as it is in the 10th position of the source 
  // string), and the "string" in destination will not be a proper string as 
  // it will not necessarily be null terminated this way.  If we try to 
  // print out the string, or use strlen() for example, we may get unexpected
  // results as it is not a proper string.  strncpy() will not automatically 
  // insert a null terminator for us in this situation, we need to manually 
  // insert the null terminator to properly terminate the string as done below.
  char dest6[5];
  strncpy(dest6, src, 2);
  dest6[2] = '\0';
  printf("dest6: %s\n", dest6);
  
  return 0;
}
