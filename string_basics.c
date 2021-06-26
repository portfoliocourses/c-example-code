/*******************************************************************************
*
* Program: String basics tutorial
* 
* Description: Examples illustrating the basics of using strings in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=60OI5tzmkCw
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
  // initializing a string, "test" is called a string literal 
  char test[5] = "test";

  // we could also initialize test like this... we would need to manually insert
  // the special null terminator character \0 that signifies the end of the 
  // string
  //
  // test[0] = 't';
  // test[1] = 'e';
  // test[2] = 's';
  // test[3] = 't';
  // test[4] = '\0';

  // we can use the %s placeholder to print a string
  printf("%s\n", test);

  // we could print individual characters in a loop with %c, notice the null 
  // terminator character will not print... it is a special character not 
  // intended for printing
  for (int i = 0; i < 5; i++)
    printf("test[%d]='%c'\n", i, test[i]);

  // we can also declare and initialize a string without specifying a length 
  // for the char array... the C compiler can figure out how large it should 
  // be based on the length of the string literal
  char test2[] = "Some big long string!";
  printf("test2: %s\n", test2);

  // the string.h library includes helpful functions like strlen() that return 
  // the length of the string (not including the null terminator)
  char mystring[] = "Some string!!!";
  int length = strlen(mystring);
  printf("length: %d\n", length);

  // we can use the length of the string to write loops that will do work with 
  // each individual char of the string... like counting the number of S and s
  // characters in the string
  int count_s = 0;
  for (int i = 0; i < length; i++)
    if (mystring[i] == 's' || 
        mystring[i] == 'S')
      count_s++;
  
  // output the count of the number of s and S characters
  printf("S Count: %d\n", count_s);

  // demonstration of the string copy function strcpy() included in the string 
  // library that allows to copy s1 contents into s2 for example... 
  char s1[] = "My string to copy!";
  char s2[50];
  strcpy(s2, s1);
  printf("s2: %s\n", s2);

  return 0;
}