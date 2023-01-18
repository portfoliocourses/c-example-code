/*******************************************************************************
*
* Program: How To Clear The Input Buffer
* 
* Description: Examples of how to clear the standard input buffer in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=5SbJyxCqRN4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main()
{
  // Declare an int variable to store an age entered from user input, and a 
  // char array to store a name string entered from user input
  int age;
  char name[1024];
  
  // Prompt the user to enter the age value.  If the user enters in something
  // like 65 and hits enter the standard input buffer will contain:
  //
  // 65\n
  //
  // scanf() will then take off the characters 65 (the integer) as it reads in
  // an integer using %d.  Then a newline character \n will remain on the 
  // standard input buffer.  The issue is that the call to fgets() below will
  // not pause and allow the user to enter input, as it stops when it encounters
  // the first \n, and there is *already* one on the standard input buffer.  It
  // will seem as if fgets is "skipped over", but in reality it will store the
  // string \n into name and simply not pause to allow the user to enter input!
  //
  // The user could also put space characters after the integer, for example:
  //
  // 65   \n
  //
  // So we need to clear (or flush) the standard input buffer completely. 
  //
  printf("Enter Age: ");
  scanf("%d", &age);
  
  // Many compilers support using fflush() to flush the standard input buffer
  // by calling it with stdin as below.  This is not part of standard C however
  // as fflush() is for flushing output buffers, and so this solution will make
  // our code less portable.
  // 
  // fflush(stdin);
  
  // An alternative is to read each character from standard input until we 
  // encounter the newline character.  Here the loop continually reads the 
  // next char from standard input, assigning it to c.  The assignment operator
  // = will evaluate to the value of c, so we compare it to the newline 
  // character with != after this and continue so long as c (the last character
  // read) is not the newline character.  It's possible for standard input to 
  // be re-directed to a file, in which case getchar() may return the EOF 
  // character if there is an error reading from the file or if the end of 
  // the file is reached.  We stop the loop in those cases as well by checking
  // that c != EOF to prevent an infinite loop.
  //
  int c;
  while ( (c = getchar()) != '\n' && c != EOF) {} 

  // Prompt the user to enter the name, store into the name char array using
  // fgets().   
  printf("Enter Name: ");
  fgets(name, 1024, stdin);

  // Output the entered age and name values
  printf("Age: %d\n", age);
  printf("Name: %s\n", name);
  
  return 0;
}