/*******************************************************************************
*
* Program: memchr() Demonstration
* 
* Description: Example of using the memchr() function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=GbwaXI75AfE 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(void)
{
  // test char array
  char data[] = {'q', 'r', 's', 't', 'p', 'a', 'x'};
  
  // memchr will search 7 chars deep into the data array for the char 't' 
  // and return a pointer to the first occurrence of the character
  char *pos = memchr(data, 't', 7);
  
  // if memchr can't find the character it will return NULL, so for example
  // if we searched for 'z' in the above char array we would expect a 
  // return value of NULL
  if (pos == NULL)
  {
    printf("Character not found!\n");
  }
  // we should get 't' and 'p' as output if use array indexing with the pointer
  else
  {
    printf("pos[0] = %c\n", pos[0]);
    printf("pos[1] = %c\n", pos[1]);
  }
  
  // an obvious use case for the function is working with strings, for example:
  char str[] = "john.smith@microsoft.com";
  
  // let's find the first occurrence of the '@' char in the email address above,
  // giving us the domain of the e-mail
  char *domain = memchr(str, '@', strlen(str));
  
  // we can increment the pointer by 1 to skip over the @ character so that 
  // domain will point to the string "microsoft.com" instead of "@microsoft.com"
  domain++;
  
  // we will get "microsoft.com" as output
  printf("domain: %s\n", domain);
  
  return 0;
}