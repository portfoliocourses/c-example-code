/*******************************************************************************
*
* Program: strtok demo
* 
* Description: A demonstration of the strtok function in C that allows us to 
* split a string into several strings based on delimeters.
*
* YouTube Lesson: https://www.youtube.com/watch?v=nrO_pXGZc3Y 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(void) 
{
  // a test string (s) and test delimeter (d)
  char s[] = "This is the way again.";
  char d[] = " ";
 
  // Notice that p1 and s will have the same memory address if we uncomment the 
  // below code.  
  //
  // char *p1 = strtok(s, d);
  // printf("p1: %p\n", p1);
  // printf(" s: %p\n", s);

  // we can process a string with an unknown number of delimeters by utilizing 
  // the fact that strtok will return NULL when the string has been processed
  char *portion = strtok(s, d);
  
  // Keep checking for another portion of the string until strtok returns NULL
  while (portion != NULL)
  {
    printf("%s\n", portion);

    // When we call strtok with NULL as the string, that is a signal to tell 
    // strtok to continue to use the string it was already given
    portion = strtok(NULL, d);
  }
  
  // if we print out each character, we'll find that strtok alters the original
  // string by inserting null terminators into it... we need to be aware of this
  // as this means our original string in some sense no longer exists as it did
  // before using the function!
  for (int i = 0; i < 23; i++)
    if (s[i] == '\0') printf("\\0\n");
    else printf("%c\n", s[i]);
  

  // try chaning s to "This is the way." and the below code will process the 
  // string one portion at a time
  /*
  char *portion1 = strtok(s, d);
  printf("%s\n", portion1);

  char *portion2 = strtok(NULL, d);
  printf("%s\n", portion2);

  char *portion3 = strtok(NULL, d);
  printf("%s\n", portion3);

  char *portion4 = strtok(NULL, d);
  printf("%s\n", portion4);  

  char *again = strtok(NULL, d);
  if (again == NULL) 
    printf("We're done!\n");
  else
    printf("Still more to go!\n");
  
  */

  return 0;
}
