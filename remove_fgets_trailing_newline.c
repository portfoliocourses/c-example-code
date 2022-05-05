/*******************************************************************************
*
* Program: Remove Trailing Newline From fgets() User Input
* 
* Description: Example how to remove the trailing newline character that occurs
* in a string when using fgets() to accept string input from the user.
*
* YouTube Lesson: https://www.youtube.com/watch?v=0UJX96_ZpVE  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// include string.h so we can use the strlen() function that finds the length 
// of a string (the number of characters not includ the null terminator)
#include <string.h>

int main()
{
  // char array to store the string
  char string[256];
  
  // prompt the user to enter the string
  printf("Enter String: ");
  
  // If we try to use scanf("%s", string) to accept and store a string of input
  // from the user, it will not accept and store a string with spaces like 
  // "abc 123", instead only "abc" will be stored.  So sometimes programmers 
  // use fgets() to accept a string of input from the user.  Here we call 
  // fgets() to store up to 256 characters into the string char array, reading 
  // the string from standard input (stdin) which will by default be the 
  // terminal/shell.  When the user hits enter, the string will be stored into 
  // the string char array, but there will be a trailing newline on the end 
  // of the string.
  //
  fgets(string, 256, stdin);
  
  // get the length of the string (not including the null terminator) 
  int length = strlen(string);
  
  // print out the length before removing the trailing newline char
  printf("before length: %d\n", length);
  
  // If we enter the string "abc 123" above then the string char array will 
  // contain the chars:
  //
  //   string[0] = 'a'
  //   string[1] = 'b'
  //   string[2] = 'c'
  //   string[3] = ' '
  //   string[4] = '1'
  //   string[5] = '2'
  //   string[6] = '3'
  //   string[7] = '\n'
  //   string[8] = '\0'
  //
  // And the string length will be '8'.  We set the char at strlen(string) - 1
  // to the null terminator, i.e. '7' if the string entered was "abc 123".  This
  // will have the effect of ending the string one character earlier, and 
  // removing the trailing newline character, as afterwards the string will 
  // look like this:
  //
  //   string[0] = 'a'
  //   string[1] = 'b'
  //   string[2] = 'c'
  //   string[3] = ' '
  //   string[4] = '1'
  //   string[5] = '2'
  //   string[6] = '3'
  //   string[7] = '\0'
  //   string[8] = '\0'   <--- this extra null terminator won't matter!
  //
  string[strlen(string) - 1] = '\0';
  
  // Uncomment the below lines to see the effect on the string length that 
  // the above line of code has had... the length will be reduced by one 
  // character...
  //
  // length = strlen(string);
  // printf("after length: %d\n", length);

  // Print out each character of the string individually so we can see the 
  // effect of the above statement that removes the newline characater and 
  // replaces it with the null terminator.  The newline character will print 
  // on the terminal as a newline, and the null terminator will print out 
  // as 'nothing', so we detect these characters and manually print them out 
  // in a more human-readable way.  Note that if we uncomment the above 
  // two lines to see the 'after' length this will effect this loop as 
  // well...
  //
  for (int i = 0; i <= length; i++)
    if (string[i] == '\n')
      printf("string[%d] = \\n \n", i);
    else if (string[i] == '\0')
      printf("string[%d] = \\0 \n", i);
    else
      printf("string[%d] = %c \n", i, string[i]);
  
  // print out the string itself
  printf("String: %s\n", string);
  
  return 0;
}