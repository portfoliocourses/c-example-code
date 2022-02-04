/*******************************************************************************
*
* Program: String Rotation Checker
* 
* Description: Function to check if one string is a rotation of another string
* in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=4-KDj-vVk2E 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_rotation(char *s1, char *s2);

// The algorithm works as follows, given two strings, we concatenate the first
// string with itself to form a check string.  If we can find the second string
// in the check string, then the two strings must be rotations of each other!
// 
//  sA: LMNOP
//  sB: NOPLM
//
//           NOPLM      <---- found second string in check string!
//  check: LMNOPLMNOP
//
//
int main()
{
  // test data
  char sA[] = "LMNOP";
  char sB[] = "NOPLM";
 
  // test if the strings are rotations
  if (is_rotation(sA, sB))
    printf("%s is a rotation of %s\n", sA, sB);
  else
    printf("%s is NOT a rotation of %s\n", sA, sB);
  
  return 0;
}

// returns true if s1 and s2 are rotations of each other, and false otherwise 
bool is_rotation(char *s1, char *s2)
{
  // get the length of s1 and s2
  int s1_length = strlen(s1);
  int s2_length = strlen(s2);
  
  // if the lengths are not equal, there is no way they can be a rotation of 
  // each other, and we can return false without having to do more work
  if (s1_length != s2_length) return false;
  
  // we'll need to store the first string (s1) twice AND a null terminator 
  // character to build the check_string, so we'll compute the number of 
  // characters we'll needed to store the check string
  int check_size = s1_length + s1_length + 1;
  
  // allocate space on the heap for the check string 
  char *check_string = malloc(sizeof(char) * check_size);
  
  // copy s1 into check_string, then concatenate s1 onto itself 
  strcpy(check_string, s1);
  strcat(check_string, s1);
  
  // strstr will return NULL if it CANNOT find s2 in the check_string, 
  // and a pointer to the position in check_string where s2 begins if it 
  // DOES find s2 in the check_string
  char *check_result = strstr(check_string, s2);
  
  // free the space allocated for check_string to prevent a memory leak 
  // as we are now done working with it and the function will return next 
  free(check_string);
  
  // if we couldn't find s2 in the check_string, strstr will return NULL and 
  // we return false, otherwise strstr DID find s2 in the check_string and the 
  // strings ARE rotations of eachother so we return true
  if (check_result == NULL) return false;
  else return true;
  
}