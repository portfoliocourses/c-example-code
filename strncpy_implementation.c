/*******************************************************************************
*
* Program: strncpy() Function Implementation
*
* Description: Example of how to implement the strncpy() function in C which 
* copies a maximum of some number of characters from a source string to a 
* destination (padding the destination with zeros, i.e. the null terminator, in 
* the case that the maximum characters to copy exceeds the number of characters 
* in the source string).
*
* YouTube Lesson: https://www.youtube.com/watch?v=cUky0mPMwBw
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

char *_strncpy(char *dest, const char *src, size_t n);

int main()
{
  //  string[] will act as our source string, storing characters as follows:
  // 
  //               abcdef\0
  //         index:0123456
  char string[] = "abcdef";
  
  // buffer will act as our destination char array (notably 3 chars larger than
  // required to store the source string)
  char buffer[10];
  
  // Fill the entire buffer with the '#' char so we can see the affect of 
  // calling strncpy() with different numbers.
  for (int i = 0; i < 10; i++)
  {
    buffer[i] = '#';
  }
  
  // Remove the _ to compare the output of our function to the official 
  // function.  In the case of copying 7 chars from string to buffer, EXACTLY
  // the string stored into the string char array will be copied into the 
  // buffer (including the single null terminator char that ends the string).
  // We'll notice that the '#' char remains in indexes 7,8,9 of buffer in
  // this case.
  _strncpy(buffer, string, 7);
  
  // If we call the function with 10 as the max number of chars to copy, then 
  // again the string will be copied into the buffer, but this time indexes 
  // 7,8,9 will be padded with additional null terminator characters.
  // _strncpy(buffer, string, 10);

  // If we call the function with '3' as the max number of chars to copy, then
  // ONLY 3 chars 'a', 'b', and 'c' will be copied from string to buffer, and 
  // buffer will not store a proper null-terminated string.  As a result the 
  // output below may be incorrect if we try to output the buffer 'as a string'.
  // _strncpy(buffer, string, 3);
  
  // Output the buffer "as a string" using %s.  Notably if a null terminator 
  // char is not copied from the source to the buffer, the string output may 
  // be incorrectly formatted as the buffer does not actually store a 
  // proper string in this case.
  printf("buffer: %s\n", buffer);
  
  // Loop through each index of the buffer and output the char stored there
  for (int i = 0; i < 10; i++)
  {
    // A null terminator \0 (i.e. the value 0) is not a printable character so
    // it will have no visible output if we use %c to output it.  Instead if 
    // the char is a null terminator, we'll output the index the char is 
    // stored at and then \\0 which will result in \0 in output to represent 
    // the null terminator.  The double \\ is to output a single \ as the \ 
    // char is normally an escape character for special chars like \n, etc.
    if (buffer[i] == '\0')
    {
      printf("buffer[%d] = \\0\n", i);
    }
    // If the char is not the null terminator, just output it normally using %c
    // along with the index of the character in the buffer
    else
    {
      printf("buffer[%d] = %c\n", i, buffer[i]);
    }
  }
  return 0;
}

// Copies a maximum of n characters from the source string src to the 
// destination dest.  If the end of the source string is encountered before
// n characters are copied, then the destination will be padded with null 
// terminator characters (i.e. the value 0) until n characters total have 
// been put into the destination.  The function will return a pointer to the 
// destination (i.e. dest).
//
char *_strncpy(char *dest, const char *src, size_t n)
{
  // The official strncpy() function has undefined behavior if the 
  // destination or source pointers are NULL, so we create our function in a 
  // more defensive programming style and return the destination pointer in
  // this case.  We also do the same if the max number of characters to copy
  // is 0 as this means there is no work to be done.
  if (dest == NULL || src == NULL || n == 0)
  {
    return dest;
  }
  
  // Create a counter variable to ensure we copy n characters total into 
  // the destination (potentially including padding characters).
  size_t i = 0;
  
  // Create a loop that will copy characters from the source to the destination
  // (keeping track of the index with counter variable i), until we have either 
  // copied n characters total (at which point we are done) or we have 
  // encountered the null terminator in the source (at which point we need to
  // insert the null terminator into the destination char array until we have
  // put 'n' characters total into the destination).
  while (i < n && src[i] != '\0')
  {
    dest[i] = src[i];
    i++;
  }
  
  // If the above loop terminates, but we have still copied less than n 
  // characters from source to destination as kept track of by 'i', then we 
  // pad the destination with null terminators until we have put 'n' chars 
  // total into the destination.
  while (i < n)
  {
    dest[i] = '\0';
    i++;
  }
   
  // The function returns a pointer to the destination
  return dest;
}