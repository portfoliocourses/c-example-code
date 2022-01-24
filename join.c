/*******************************************************************************
*
* Program: Join Strings Function
* 
* Description: A join strings function using C that joins strings together 
* separating them by a separator string.
*
* YouTube Lesson: https://www.youtube.com/watch?v=zuKqVTbIXOI  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A join function should join together strings and separate them by a 
// separator string... for example if we joined these strings with this 
// separator we would expect the new string as a result:
//
// strings: "abc", "0123456789", "wxyz"
// separator: "@@@"
// new string: "abc@@@0123456789@@@wxyz"
//
// Similar to Python's join function: 
//   - https://www.w3schools.com/python/ref_string_join.asp


// max length of strings for the join function
#define MAX 20

// works with 2d char arrays for storing strings
char *join(char strings[][MAX], int count, char *separator);

// works with dynamically allocated array of pointers to dynamically allocated
// strings on the heap
char *join2(char **strings, int count, char *separator);

int main()
{
  // test data for the join function
  char strings[][MAX] =
  { {"In"}, {"a"}, {"gentle"}, {"way"}, {"you"}, {"can"},
    {"shake"}, {"the"}, {"world"}
  };
  char separator[] = " ";
  
  // test the join function
  char *new_string = join(strings, 9, separator);
  printf("%s\n", new_string);
  

  // dynamically allocate array of 3 pointers to strings
  char **strings2 = malloc(sizeof(char *) * 3);
  
  // dynamically allocate space for a string, store "abc"
  strings2[0] = malloc(sizeof(char) * 4);
  strcpy(strings2[0], "abc");
  
  // dynamically allocate space for a string, store "0123456789"
  strings2[1] = malloc(sizeof(char) * 11);
  strcpy(strings2[1], "0123456789");
  
  // dynamically allocate space for a string, store "wxyz"
  strings2[2] = malloc(sizeof(char) * 5);
  strcpy(strings2[2], "wxyz");
  
  // separator can be multiple characters, e.g. "@@@"
  char separator2[] = "@@@";
  
  // test the join2 function
  char *new_string2 = join2(strings2, 3, separator2);
  printf("%s\n", new_string2);
  

  // free all of the dynamically allocated memory
  free(new_string);
  free(new_string2);
  free(strings2[0]);
  free(strings2[1]);
  free(strings2[2]);
  free(strings2);
  
  return 0;
}

// returns a pointer to a string that joins all of the strings provided in the 
// first argument (there will be 'count' number of strings), separated by the 
// separator string
char *join(char strings[][MAX], int count, char *separator)
{
  // we can't 
  if (count <= 0) return NULL;
  
  // we'll allocate space on the heap for the new string, so we'll first need 
  // to figure out how much space to allocate... we'll store this into
  // new_length... first we add the number of characters to store all the 
  // separator strings:
  int new_length = strlen(separator) * (count - 1);
  
  // then we add in the length of each string
  for (int i = 0; i < count; i++)
    new_length += strlen(strings[i]);
  
  // and then one more character for the null terminator to end the string
  new_length++;
  
  // allocate enough space for this new string
  char *new_string = malloc(sizeof(char) * new_length);
  
  // copy in the first string to new_string to start building the new string
  strcpy(new_string, strings[0]);

  // repeatedly concatenate on a separator followed by the next string
  for (int i = 1; i < count; i++)
  {
    strcat(new_string, separator);
    strcat(new_string, strings[i]);
  }
  
  // return the pointer to the now built string
  return new_string;
}

// exactly the same as join, except, our parameter is now a dynamically 
// allocated array of pointers to strings which are themselves dynamically 
// allocated too!
char *join2(char **strings, int count, char *separator)
{
  if (count <= 0) return NULL;
  
  int new_length = strlen(separator) * (count - 1);
  
  for (int i = 0; i < count; i++)
    new_length += strlen(strings[i]);
  
  new_length++;
  
  char *new_string = malloc(sizeof(char) * new_length);
  
  strcpy(new_string, strings[0]);
  for (int i = 1; i < count; i++)
  {
    strcat(new_string, separator);
    strcat(new_string, strings[i]);
  }
  
  return new_string;
}
