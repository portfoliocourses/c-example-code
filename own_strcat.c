/*******************************************************************************
*
* Program: Create Your Own strcat() Function
* 
* Description: Example of creating our own version of the strcat() function  
* found in the string.h library to concatenate two strings in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=rMOF82jCq4o 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

char *_strcat(char *destination, const char *source);

int main()
{
  // Create a destination char array that stores the string "First".  The char 
  // array can store many more characters than what is required because it will
  // store the larger concatenated result string... it can store 1024 chars max.
  char destination[1024] = "First";

  // Create a source char array/string that will be concatenated with the 
  // destination string.
  char source[] = "Second";
  
  // We can call the strcat() function in the string.h libray as follows, it 
  // will concatenate destination and source and the result will be stored into
  // destination, in this case the string "FirstSecond".
  //
  // strcat(destination, source);

  // We have created our own version of the function that begins with an _ 
  // character and we test it here
  _strcat(destination, source);
  
  // Output the resulting string stored in destination to verify the function 
  // is working correctly
  printf("Result: %s\n", destination);
  
  return 0;
}

// Concatenates the strings stored at destination and source and stores the 
// result into destination.  Also returns a pointer to the destination.  See
// the comments below the function body for a visualization of the algorithm.
// Note that source is 'const' because we will not modify source.
//
char *_strcat(char *destination, const char *source)
{
  // Declare counter variables i and j that will be used to keep track of 
  // the current index of destination and source, initialize them to 0 as 
  // we begin reading each string at the first index.  We could have used 
  // type int, but size_t will allow for larger non-negative positive 
  // integers and therefore will support larger strings.  
  size_t i = 0, j = 0;
  
  // Keep incrementing i and checking to see if the character in the destination
  // string is the null terminator... once we find the null terminator we'll  
  // have found the index in the destination char array where we need to begin 
  // copying the source string.
  while (destination[i] != '\0')
  {
    i++;
  }
  
  // Copy each char from source to destination until we reach the null 
  // terminator (i.e. the end) of the source string.  We use counter variables 
  // i and j to keep track of the index of the char we are currently copying
  // into the destination from the source.
  while (source[j] != '\0')
  {
    destination[i] = source[j];
    i++;
    j++;
  }

  // Insert the null terminator as the last char stored in destination to 
  // terminate the destination string.
  destination[i] = '\0';
  
  // Return a pointer to the destination.
  return destination;
}


// The first loop increments 'i' until we find the index of the null terminator
// in the the destination...
// 
//  destination
//
//                         i
//  index:  0  1  2  3  4  5  6  7  8  9  10  11  12  ...
//   char:  F  i  r  s  t  \0
//
//  source
//
//  index:  0  1  2  3  4  5  6
//   char:  S  e  c  o  n  d  \0
//


// The second loop then copies each char in the source into the destination, 
// using the counter variables i and j to keep track of the index in each, 
// stopping when we encounter the null terminator in the source.
// 
//  destination
//
//                         -> -> i
//  index:  0  1  2  3  4  5  6  7  8  9  10  11  12  ...
//   char:  F  i  r  s  t  S  e  c
//
//  source
//
//          -> -> j
//  index:  0  1  2  3  4  5  6
//   char:  S  e  c  o  n  d  \0
//

// Finally we terminate the destination string by storing the null terminator
// at the index i...
// 
//  destination
//
//                                             i
//  index:  0  1  2  3  4  5  6  7  8  9  10  11  12  ...
//   char:  F  i  r  s  t  S  e  c  o  n  d   \0
//
//  source
//
//                            j
//  index:  0  1  2  3  4  5  6
//   char:  S  e  c  o  n  d  \0
//