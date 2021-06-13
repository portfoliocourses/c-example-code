/*******************************************************************************
*
* Program: String append (i.e. concatenation)
* 
* Description: Appends a string to another string in C using dynamic memory 
* allocation to allocate enough space on the heap to store the new string.  
* Though C has a strcat() function in the string.h library, it will only work 
* successfully if the first char array argument has enough space to hold the 
* content of both strings, as the concatenated string is stored here.  The 
* function provided here will work by creating a new string on the heap and 
* storing the result of the append there.
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *string_append(char *s1, char *s2);

int main(void)
{
  // this works, but if we change first[20] to first[10], our program crashes!
  char first[20] = "First ";
  char second[10] = "Second";
  strcat(first, second);
  printf("first: %s\n", first);

  // test out the new string_append function
  char s1[] = "abc";
  char s2[] = "wxyz";
  char *s = string_append(s1, s2);
  printf("s: %s\n", s);

  // because the new resulting string is stored on the heap, we need to remember
  // to use free() when we are done with the string
  free(s);

  return 0;
}

// Returns a new string on the heap containing the result of appending s2 to s1. 
char *string_append(char *s1, char *s2)
{
  // Create space for a new char array (string) on the heap large enough to hold
  // the characters in s1 and s2 AND a null terminator
  int s1_length = strlen(s1);
  int s2_length = strlen(s2);
  int size = s1_length + s2_length + 1;
  char *s = calloc(size, sizeof(char));

  // Copy s1 into s
  for (int i = 0; i < s1_length; i++)
    s[i] = s1[i];

  // Copy s2 into s, but shifted over by the length of s1 to append it after s1!
  for (int i = 0; i < s2_length; i++)
    s[s1_length + i] = s2[i];

  // put the null terminator in to end the string
  s[size - 1] = '\0';

  return s;
}

// Visualization of what is happening in memory and the function with s1, s2, s
//
// s1 - "abc" - s1_length = 3
// a  b  c  \0  <- data
// 0  1  2  3   <- indexes
//
// s2 - "wxyz" - s2_length = 4
// w  x  y  z  \0  <- data
// 0  1  2  3  4   <- indexes
//
// s - "abcwxyz" - s has a length of 7 (a size of 8 incl. the null terminator)
// a  b  c  w  x  y  z  \0
// 0  1  2  3  4  5  6  7  <- indexes
//
