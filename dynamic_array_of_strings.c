/*******************************************************************************
*
* Program: Dynamically Allocate Memory For An Array Of Strings
* 
* Description: Demonstration of how to dynamically allocate memory for an 
* array of strings in C.  We allow the user to determine the number of strings, 
* as well as enter each individual string.
*
* YouTube Lesson: https://www.youtube.com/watch?v=4_2BEgOFd0E
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int main()
{
  // used to store a dynamically allocated array of pointers to char
  char **strings;

  // stores the total number of strings to be stored
  int total = 0;
  
  // ask user for the number of strings they wish to store, store this in total
  printf("Enter Number Of Strings: ");
  scanf("%d", &total);
  
  // dynamically allocate space for total number of pointers to chars
  strings = malloc(total * sizeof(char *));
  
  // buffer will be used to accept each string of input from the user, we give 
  // it a very large size to be sure it can accept a large amount of amount
  char buffer[BUFFER_SIZE];

  // length will store the length of the string the user enters
  int length = 0;
  
  // flush the stdin stream so we can use fgets below, if we do not flush the 
  // stdin stream there will still be a \n char and the first call to fgets 
  // will store an empty string into the buffer and will not pause for user 
  // input as it will see a \n on the stdin stream which is what *ends* input
  // when using fgets (i.e. when the user hits enter) 
  while (getchar() != '\n');
  
  printf("\n");
  for (int i = 0; i < total; i++)
  {
    // ask the user for the string, store it into buffer, get string length
    printf("Enter string %d: ", i + 1);
    fgets(buffer, BUFFER_SIZE, stdin);
    length = strlen(buffer);

    // fgets will store the \n char entered by the user when they hit enter, 
    // we assume the user does not want this so we shift up the null 
    // terminator by one char so the \n is eliminated from the string
    buffer[length - 1] = '\0';

    // dynamically allocate enough space to store the the string, store the 
    // pointer to this block of memory in strings[i]
    strings[i] = malloc(length * sizeof(char));

    // copy the string from the buffer to the dynamically allocated memory
    strcpy(strings[i], buffer);
  }
  
  // print out the array of strings to verify success
  printf("\nResulting strings array:\n\n");
  for (int i = 0; i < total; i++)
  {
    printf("strings[%d] = %s\n", i, strings[i]);
  }
  printf("\n");
  
  return 0;
}