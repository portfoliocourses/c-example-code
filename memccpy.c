/*******************************************************************************
*
* Program: memccpy() Demonstration
* 
* Description: Example of using the memccpy() function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=apELI9t6XUo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
  // we will copy from the source to destination
  char source[] = "john.smith@microsoft.com";
  char destination[20];
  
  // memcpy will copy chars from the source into the destination until either 
  // 20 chars have been copied OR until the '@' char is encountered in the 
  // source string, whichever occurs first.  It will return a pointer to the 
  // next available position in the destination char array after the copy has 
  // occurred if the '@' character *was* encountered.  If the '@' character 
  // is NOT encountered and all 20 characters are copied from the source to 
  // destination, memccopy will return NULL instead.  When the copy does occur 
  // up until the '@' character, the copy will INCLUDE the '@' character too!
  char *pos = memccpy(destination, source, '@', 20);
  
  // memccpy does not insert a null terminator after performing the copy into 
  // destination, so if we want to treat destination as a string, we need to 
  // insert it ourselves... we do so by inserting the null terminator at 
  // pos[0], which is the next character in the destination character array 
  // after the characters copied over from the source
  pos[0] = '\0';
  
  // output each char in the destination char array individually so we can see 
  // what it looks like
  for (int i = 0; i < 20; i++)
    printf("destination[%d] = %c\n", i, destination[i]);
    
  // because we have inserted the null terminator, we can also print out 
  // destination as a string
  printf("destination: %s\n", destination);
  
  return 0;
}