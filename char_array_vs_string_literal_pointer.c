/*******************************************************************************
*
* Program: Char Array String Vs. Poointer To String Literal
*
* Description: The difference between a string stored in a char array compared
* to a pointer to a string literal in C.  i.e. the difference between
* char s[] = "string"; vs char *s = "string";
*
* YouTube Lesson: https://www.youtube.com/watch?v=Qp3WatLL_Hc
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main()
{
  // String literals like "abcdef" exist in some place in memory, where
  // exactly is not defined by the C standard.  We can use string literals to
  // initialize a char array to store a string, as we do here.  The char array
  // s1 will be 7 chars long (due to the extra null terminator), and it will
  // be in a place in memory called the stack where we know it is possible
  // to modify the values that are stored there.
  char s1[] = "abcdef";

  // Change the first char of the char array s1
  s1[0] = 'X';

  // Output the modified s1 string which should now be Xbcdef
  printf("s1: %s\n", s1);

  // The string literal "abcdef" will exist *somewhere* in-memory during our
  // program's execution (again we don't exactly know where as it is not
  // defined by the C standard and is up to the compiler).  And s2 is a
  // pointer to the first char of this string literal (which is terminated
  // with a null terminator character).
  const char *s2 = "abcdef";

  // Because we've made s2 a pointer to a const char above, the compiler will
  // flag an attempt (like below) to modify what s2 is pointing to as an error.
  // If we did not user the const keyword when declaring s2, the compiler
  // would allow the below statement to be compiled without error.  But we
  // will almost certainly get a runtime error as a result because the
  // modification of a string literal is "undefined" by the C standard.  This
  // does not strictly speaking mean it is not allowed, but as a practical
  // matter the compiler will not support this and we will get a runtime
  // error related to memory acces.  As a result, if we're going to have a
  // pointer to a string literal, we should make sure it's a const char
  // pointer so that we don't accidentally attempt to modify the string.
  // s2[0] = 'X';

  // The char array s1 is like a constant pointer, so we can't increment
  // s1 to have it point to the next element in the array.
  // s1++;

  // s2 is a non-const pointer, so we actually CAN increment s2 to have it
  // point to the next char in the string literal.  Note that s2 is a pointer
  // to a const char, NOT a 'const pointer', there is a difference.
  s2++;

  // Output s2 and we'll get bcdef as s2 has been set to point to the next
  // char in the string literal (i.e. the char 'b' onwards)
  printf("s2: %s\n", s2);

  // We cannot assign a string to s1, we would need to use something like
  // strcpy() in the string.h library to change the string stored in s1
  // s1 = "new string";

  // We actually CAN assign a string literal to s2 because what will happen
  // is that "new string" will be a new string literal in memory, and s2
  // will be changed to point to THIS string literal now.
  s2 = "new string";

  // If we output s2 now we'll get "new string"
  printf("s2: %s\n", s2);

  // If we use the sizeof operator with s1 and s2, we'll get 7 bytes for s1
  // because it stores 7 chars of 1 byte each.  These 7 chars are stored on
  // the stack.  But with s2 we'll get 8 bytes because s2 is REALLY just a
  // pointer on the stack and sizeof will give us the size of that pointer
  // NOT the size of the string literal that it points to.
  printf("sizeof(s1): %d\n", sizeof(s1));
  printf("sizeof(s2): %d\n", sizeof(s2));

  return 0;
}