/*******************************************************************************
*
* Program: fputs() Demonstration
* 
* Description: Example of using the fputs() function in C to write a string to 
* a file (and output streams in general).
*
* YouTube Lesson: https://www.youtube.com/watch?v=5a5o7Q-4gk8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  // file pointer variable allows us to access a file
  FILE *file;
  
  // Open file.txt in 'write mode', if file.txt doesn't exist it will be created
  // and if it does the content will be overwritten with whatever we write to  
  // the file.
  file = fopen("file.txt", "w");
   
  // If fopen() above fails to open the file it will return NULL, so if file is
  // NULL we know something has gone wrong in the opening of the file.  In this 
  // case we print the user an error message and we return 1 (instead of 0) as 
  // a signal to the shell that something has gone wrong in the execution of 
  // our program.
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  
  // Write a string literal to the file, the characters 'a', 'b', and 'c' 
  // followed by a newline.
  fputs("abc\n", file);
  
  // Write the string literal '123' to the file... we don't need to put a 
  // newline at the end of our string...
  fputs("123", file);

  // ...because we didn't end the string above with a newline, the next string
  // "456\n" will continue on the same line as the text "123" 
  fputs("456\n", file);
  
  // We can write strings stored in char arrays to an output stream with fputs()
  // as well... notably the special \0 null terminator character at the end of 
  // every string that signifies the end of a string is NOT written to the  
  // output stream when we use fputs().
  char string[] = "test string\n";
  
  // Write the string[] to the file... the last character written to the file 
  // will be \n (newline) and NOT the null terminator which is NOT written 
  // to the output stream with fputs().
  fputs(string, file);
  
  // We can use fputs() to write to any output stream, for example the standard 
  // output stream (stdout) which is by default the shell/terminal.
  fputs(string, stdout);
  
  // fputs() could fail for some reasons, for example if we try to write a 
  // string to a file that was opened for reading with "r" as the mode instead 
  // of something like "w" or "a".  Here fputs() will fail because we try to 
  // write to the standard INPUT stream stdin.  When fputs() fails it will 
  // return EOF, and so we check for this.
  if (fputs("writing to stdin", stdin) == EOF)
  {
    // Print out an error message for the user
    printf("fputs() error\n");

    // We can also use perror to output a potentially more specific error 
    // message, with "ERROR" as the prefix to this output
    perror("ERROR");

    // again we return 1 as a signal to the shell that something has gone 
    // wrong in the execution of our program
    return 1;
  }
  
  // close our access to the file since we are done working with it
  fclose(file);

  return 0;
}