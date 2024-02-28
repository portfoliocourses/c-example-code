/*******************************************************************************
*
* Program: Reverse A String Using Pointers
* 
* Description: Program to reverse a string using pointers in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=dad8Tnm1xYs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

void reverse_string(char *string);

int main(void)
{
  // create a test string
  char string[] = "abcde";
  
  // call the function to reverse the string
  reverse_string(string);
  
  // output the reversed string
  printf("%s\n", string);
  
  return 0;
}

// The algorithm to reverse the string will involve two pointers, one that 
// initially points to the first character in the string (start) and another
// that initially points to the last character in the string (end) before 
// the null terminator.  We then swap the characters start and end point 
// to, and move start and end inwards into the middle of the string, swapping
// each pair of corresponding characters until we reach the middle of the
// string and the reversal of the string is complete.
//
//
//    a  b  c  d  e  \0     <--- before first swap
//    |           |
// start         end
//
//    e  b  c  d  a  \0     <--- after first swap
//       |     |
//    start    end  
//
//    e  d  c  b  a  \0     <--- after second swap
//         / \
//    start   end
//
// To do this we'll need to have the end pointer point to the last character
// in the string, we move it there from the first character in the string.   
//
// Also note how we use *pointer to access the char in memory that pointer 
// points to, to either modify the position in memory to store a character 
// there or to use that character in an assignment, etc.
//
// i.e. *pointer = 'c' would assign the char 'c' to the position in memory
// that pointer points to.
//
// Also note that pointer++ and pointer-- are examples of pointer arithmetic, 
// which modify what the pointer points too, pointer++ will have the pointer
// point to the next char in memory and pointer-- will have the pointer point
// to the previous char in memory.


// Reverses the string passed to the function using pointers
void reverse_string(char *string)
{
  // If string 'points to nothing' we can't really do anything so just return
  // to stop the function
  if (string == NULL) return ;
  
  // Set end to point to the first character in the string
  char *end = string;
  
  // If the string is 'empty', i.e. it consists only of the null terminator,
  // we can't really do anything so just return to stop the function
  if (*end == '\0') return ;
  
  // Otherwise continually increment the end pointer to have it point to the
  // next character in the string until end points to the null terminator at
  // the end of the string.  THEN decrement end so it points to the last 
  // character in the string before the null terminator.
  while (*end != '\0') end++;
  end--;
  
  // Set the start pointer to point to the first character in the string
  char *start = string;
  
  // temp variable to assist with swapping chars
  char temp;

  // Continually swap the corresponding characters at opposite ends of the 
  // string until start is no longer less than end.  We can reliably compare
  // the pointers in this way using < because they both point to the same 
  // array in memory. 
  //
  while (start < end)
  {
    // Swap the characters that start and end point to
    temp = *start;
    *start = *end;
    *end = temp;
    
    // increment start to point to the next character in the string
    start++;
    
    // decrement end to point to the previous character in the string
    end--;
  }
}




