/*******************************************************************************
*
* Program: Null Terminated String Safety Issues
* 
* Description: Examples illustrating issues with null terminated strings in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=kmqesAhY2k8  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

void print_chars(char *string);
void print_chars_safe(char *string, size_t n);

int main(void)
{
  // Strings in C are sequences of characters that are supposed to end with 
  // a null terminator character \0.  This can be error prone and may cause 
  // issues.
  //
  // See: https://en.wikipedia.org/wiki/Null-terminated_string#Limitations

  // Declare a char array of length 8
  char string[8];
  
  // If somehow our code fails to put a null terminator at the end of the string
  // for whatever reason (e.g. the string comes from some external source), then
  // functions like printf() and strlen() that depend on the null terminator 
  // may not function as expected.
  string[0] = 'a';
  string[1] = 'b';
  string[2] = 'c';
  string[3] = 'd';
  // string[4] = '\0';
  
  // printf() and strlen() both go through the string one character at a time 
  // until the null terminator is encountered.  In practice the null terminator
  // \0 is the integer 0, and in memory 0 is often found, so even if the null 
  // terminator is missing it may not cause an issue that is noticed.  The 
  // next char/byte in memory may just happen to be 0, which is will then have
  // the same affect as the null terminator.  But that's not garaunteed, so 
  // these functions may produce incorrect results (e.g. eventually stopping 
  // when 0 is encountered after going through 'garbage values') or even 
  // crashing if memory is eventually accessed that should not be.
  printf("string: %s\n", string);
  printf("length: %zu\n", strlen(string));
  
  // Instead of using strlen() and other functions that are less safe for 
  // working with strings, we could use safer functions like strnlen().  The
  // strnlen() function is available in the POSIX library, which means it 
  // is not supported by all C compilers.  But the function will accept a 
  // 2nd argument, a limiter / bound for the "max length", so that the 
  // function will only check up to the index max_length - 1 in the string,
  // so in the case below only up until index 7, looking for the null 
  // terminator.  This means we can ensure the function will not exceed 
  // the length of the buffer when searching for the null terminator, by
  // passing the length of the buffer as the 2nd argument.
  printf("length: %zu\n", strnlen(string, 8));
  
  // A common issue with null terminated strings is a destination buffer 
  // that is not large enough to store a source string.  In the below 
  // example let's say we want to store codes of length 8 chars.  A 
  // programmer may make a buffer of length 8 chars, forgetting the need
  // to also store the null terminator.
  char code[8];

  // We may get a string from some source, maybe external, like the below,
  // that has 8 characters + 1 more for the null terminator.
  char source[] = "12345678";
  
  // If we try to use strcpy() to copy the source string to the code 
  // destination char array, our program may crash as the source size 
  // exceeds the destination.
  // strcpy(code, source);
  
  // Instead, we could use a safer strncpy() function which accepts a 3rd
  // argument.  The 3rd argument is the max number of chars to copy from 
  // the source to the destination.  We could copy one less than the size 
  // of the buffer and then null terminate the string by adding it 
  // ourselves at the end of the string / char array.  This would ensure 
  // the string is at least null terminated, preventing the program from 
  // crashing as a result (though code would still not be able to store 
  // all 8 characters, this is another issue that we could solve by 
  // making the destination buffer / char array bigger).
  strncpy(code, source, 7);  
  code[7] = '\0';
   
  // Output the code string
  printf("code: %s\n", code);
  
  // We write a character 'E' one beyond the bad_string char array, 
  // which contains a string that is not null terminated.  Functions 
  // that depend on the null terminator to end a string will then 
  // output 'E' (and possibly other data beyond it).
  char bad_string[3];
  bad_string[0] = 'a';
  bad_string[1] = 'b';
  bad_string[2] = 'c';
  bad_string[3] = 'E';
  
  // Using available "safe" libary functions to work with strings is one 
  // way to make working with null terminated strings safer.  But we'll 
  // also need to make sure our own code and functions are designed to 
  // safely work with null terminated strings, e.g. by providing similar 
  // bounds checking functionality.

  // The unsafe function to print characters in the string individually 
  // does not check that a max buffer length is reached and so will 
  // output the 'E' character which is outside the length of the 
  // bad_string array.
  print_chars(bad_string);
  
  // The safe function to print characters in the string individually 
  // DOES check that a max buffer length is not exceeded, and so 
  // will NOT output the 'E' character when we pass it the length of 
  // the bad_string array as the 2nd argument.
  print_chars_safe(bad_string, 3);

  return 0;
}

// Outputs each character in the string individually, stopping only when the 
// null terminator is encountered.  This function is "unsafe" in that if the 
// null terminator is not present we may get undesired results.
void print_chars(char *string)
{
  size_t i = 0;
  
  // The loop will continue until the counter variable i reaches the 
  // null terminator, outputting each character in the string.
  while (string[i] != '\0')
  {
    printf("char: %c\n", string[i]);
    i++;
  }
}

// Outputs each character in the string individually, stopping EITHER when
// the null terminator is encountered OR when the "bound" n for the buffer 
// length is reached.
void print_chars_safe(char *string, size_t n)
{
  size_t i = 0;
  
  // Works as in the above unsafe function, except with an additional 
  // condition that the counter variable i has not reached the size of 
  // the buffer 'n'.
  while (string[i] != '\0' && i < n)
  {
    printf("char: %c\n", string[i]);
    i++;
  }
}