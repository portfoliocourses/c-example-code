/*******************************************************************************
*
* Program: Iterate Through A String Using A Pointer
* 
* Description: Example of using a pointer variable to iterate through (aka 
* "loop over") a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=lSiA2S0WjCA  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
  // Declare a char array called string and initialize it with the string "jump"
  char string[] = "jump";

  // Each char in the string is at an index, and the string is terminated with 
  // the special null terminator character \0...
  //
  //   index:    0     1     2     3     4
  //  string:    j     u     m     p     \0
  
  // We could use the strlen() function to find the length of the string to help
  // us loop through each character in the string using the array indexes up 
  // until the length.  So here strlen() returns the length of the string not 
  // including the null terminator character, which will be 4 in this case.
  int length = strlen(string);
  
  // Output the string length, which will be 4
  printf("length: %d\n", length);
  
  // If we have a loop counter variable i go from 0 up until but not including 
  // the length (4) by 1 with each loop iteration, i will go from 0 to 1 to 2 to
  // 3 with each loop iteration, the exact indexes of each char in the string 
  // from the start to the finish.  We can access and output each char in the
  // string using the counter variable as an index.
  for (int i = 0; i < length; i++)
  {
    printf("%c\n", string[i]);
  }
  printf("\n");


  // While the above approach is easier to understand from a performance 
  // perspective we are going through the string twice.  Once in our own for 
  // loop.  And before this, the strlen() function will need to iterate over 
  // the string to determine the string length... it iterates from the start
  // of the string until the null terminator is encountered, counting the 
  // number of characters and returning this count.  We could iterate over the
  // string only once by using a pointer variable.


  // A char in C is one byte in length and the chars of our string will be 
  // stored sequentially in memory, so "in memory" the array looks something 
  // like this, with the addresses of each char separated by one byte.
  
  // address: 0x01  0x02  0x03  0x04  0x05
  //   index:    0     1     2     3     4
  //  string:    j     u     m     p   \0
 
  // If we output the memory address of the first character in the string ('j')
  // and the last character (the special null terminator '\0') then we'll find 
  // the difference between those memory addresses is 4 bytes, confirming the
  // above understanding.
  printf("&string[0]: %zu\n", &string[0]);
  printf("&string[1]: %zu\n", &string[4]);

  // We can create a counter variable p and set it to point to the first char
  // in the string like this.  This means that p will store the memory address
  // of the first char in the string (we say that "p points to the first char
  // in the string").  The below is equivalent to: char *p = &string[0];
  char *p = string;

  // If we output the memory address stored in p we'll find it matches 
  // the memory address output with &string[0], this is why we say "p points to
  // the first char in the string".
  printf("         p: %zu\n", p);

  // We can use pointer arithmetic to modify what the pointer variable p points
  // to, here we'll have p point to the NEXT char in the string by incrementing 
  // the pointer by 1.
  p++;

  // If we output p afterwards we'll find it now stores the next memory address,
  // 1 byte more than it was before, for the next char in the string.
  printf(" (after) p: %zu\n", p);
  
  // We can access the character that p is currently pointing to with *p, this
  // de-references the pointer, it gives us back the char that is stored at the
  // memory address that p stores (so in this case it will now be 'u').
  printf("        *p: %c\n", *p);
  

  // We can use these two tools to loop through the string!

  // Let's set p1 to point to the first char in the string
  char *p1 = string;
  
  // We'll stop the loop when p1 points to the null terminator
  while (*p1 != '\0')
  {
    // We'll output the char that p1 is currently pointing to with each loop
    // iteration...
    printf("%c\n", *p1);
    
    // We'll increment p1 to have it point to the next char in the string at 
    // the end of each loop
    p1++;
  }
  printf("\n");
  
  
  // We could actually make the loop condition even simpler.  The null 
  // terminator character \0 is equal to the integer 0, as all characters in C
  // are represented with integers.  So '\0' is REALLY the integer 0.  All other
  // characters in C will be represented with non-zero integers.
  //
  // In C non-zero integers are considered true, and zero is considered false.
  //
  // So we could just have *p as out loop condition!  When *p == '\0' it will be
  // the null terminator, and the loop will stop because '\0' == 0 == false. But
  // if *p is a char that is not the null terminator, it will be a non-zero 
  // integer, which is considered true, and the loop will continue!

  // We could write a for-loop the same way... 
  for (char *p = string; *p; p++)
  {
    printf("%c\n", *p);
  }
  printf("\n");
  
  return 0;
}