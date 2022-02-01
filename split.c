/*******************************************************************************
*
* Program: Split Function
* 
* Description: A split function that splits a string into an array of substrings
* based on separator characters using C.  This function is very similar to the 
* split function in Python and JavaScript.
*
* YouTube Lesson: https://www.youtube.com/watch?v=GpATOKdvgLs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **split(char *string, char *seperators, int *count);

int main()
{
  // test the function
  char s[] = "To be, or not to be, that is the question.";
  int count_strings = 0;
  char **split_strings = split(s, " ,.", &count_strings);
  
  // print out the substrings, which should be each word of the sentence above
  for (int i = 0; i < count_strings; i++)
    printf("%s\n", split_strings[i]);
  
  // free the dynamically allocated space for each string
  for (int i = 0; i < count_strings; i++)
    free(split_strings[i]);
  
  // free the dynamically allocated space for the array of pointers to strings
  free(split_strings);
  
  return 0;
}

// Separates the string into substrings, splitting the string into substrings 
// based on the separator characters (i.e separators).  The function returns an
// array of pointers to strings, dynamically allocated on the heap, and it 
// effectively "returns" the number of these strings via pass-by-pointer using 
// the parameter count.  
char **split(char *string, char *seperators, int *count)
{
  // get the length of the string
  int len = strlen(string);
  
  // use count to keep a count of the number of substrings
  *count = 0;
  
  // We make one pass of the string to first determine how many substrings 
  // we'll need to create, so we can allocate space for a large enough array 
  // of pointer to strings.  The variable i will keep track of our current 
  // index in the string
  int i = 0;
  while (i < len)
  {
    // skip over the next group of separator characters
    while (i < len)
    {
      // keep incrementing i until the character at index i is NOT found in the 
      // separators array, indicating we've reached the next substring to create 
      if (strchr(seperators, string[i]) == NULL)
        break;
      i++;
    }
    
    // skip over the next group of substring (i.e. non-separator characters), 
    // we'll use old_i to verify that we actually did detect non-separator 
    // characters (perhaps we're at the end of the string)
    int old_i = i;
    while (i < len)
    {
      // increment i until the character at index i IS found in the separators 
      // array, indicating we've reached the next group of separator 
      // character(s)
      if (strchr(seperators, string[i]) != NULL)
        break;
      i++;
    }

    // if we did encounter non-seperator characters, increase the count of 
    // substrings that will need to be created  
    if (i > old_i) *count = *count + 1;
  }
  
  // allocate space for a dynamically allocated array of *count* number of 
  // pointers to strings
  char **strings = malloc(sizeof(char *) * *count);
  
  // we'll make another pass of the string using more or less the same logic as 
  // above, but this time we'll dynamically allocate space for each substring 
  // and store the substring into this space
  i = 0;

  // buffer will temporarily store each substring, string_index will keep track 
  // of the current index we are storing the next substring into using the 
  // dynamically allocated array above
  char buffer[16384];
  int string_index = 0;
  while (i < len)
  {
    // skip through the next group of separators, exactly the same as above
    while (i < len)
    {
      if (strchr(seperators, string[i]) == NULL)
        break;
      i++;
    }
    
    // store the next substring into the buffer char array, use j to keep 
    // track of the index in the buffer array to store the next char
    int j = 0;
    while (i < len)
    {
      if (strchr(seperators, string[i]) != NULL)
        break;
      
      buffer[j] = string[i];
      i++;
      j++;
    }
    
    // add a null terminator on to the end of buffer to terminate the string
    buffer[j] = '\0';
    
    // calculate how much space to allocate... we need to be able to store 
    // the length of buffer (including a null terminator) number of characters
    int to_allocate = sizeof(char) * (strlen(buffer) + 1);
    
    // allocate enough space using malloc, store the pointer into the strings 
    // array of pointers at hte current string_index
    strings[string_index] = malloc(to_allocate);
    
    // copy the buffer into this dynamically allocated space 
    strcpy(strings[string_index], buffer);
    
    // assuming we really did read in a substring, advance string_index
    if (j > 0) string_index++;
  }

  // return our array of strings  
  return strings;
}