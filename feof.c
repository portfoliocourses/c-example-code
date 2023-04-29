/*******************************************************************************
*
* Program: feof() Function Demonstration
*
* Description: Examples of using the feof() function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Ui0idK9Dh04
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>

int main(void) 
{
  // Declare file pointer variable 'file' to access file.txt 
  //
  // We assume in this example that file.txt contains a single character: T
  FILE *file;

  // Declare int variable 'c' to store characters read from the file
  int c;
  
  // Attempt to open file.txt in reading mode
  file = fopen("file.txt", "r");
  
  // If the file fails to open then fopen() is going to return NULL, in this
  // case we exit the program with an error message and status.  Returning 1
  // is a signal to the shell/terminal that something has gone wrong in the
  // execution of our program.
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1; 
  }
  
  // fgetc() will read and return the next character in the file, we store it
  // into c.  The fgetc() function has a return type of int so we declared c
  // with type int, but as a practical matter fgetc() is going to return a 
  // character (in C, characters are represented with integer values).
  c = fgetc(file);
  
  // Output the character read from the file (i.e. 'T')
  printf("char read: %c\n", c);
  
  // The feof() function returns true when the end-of-file indicator has been
  // set for a stream, and false otherwise.

  // Even though there are no more characters in the file, feof() is going to 
  // return false, because the end-of-file indicator has not yet been set, so 
  // "eof reached" will not yet be reached.
  if (feof(file)) printf("eof reached\n");
  
  // If we try to call fgetc() again when there are no more characters to read
  // from the file, the end-of-file indicator will NOW be set.  Notably the 
  // fgetc() function will also return the special value "EOF".  
  c = fgetc(file); 
  
  // Check that EOF was returned and output this if so
  if (c == EOF) printf("EOF returned\n");
  
  // rewind(file);

  // NOW feof() will return true because the end-of-file indicator has been
  // set.
  if (feof(file)) printf("eof reached\n");
  
  // It's possible to clear the end-of-file indicator.  Fro example if we 
  // uncomment the call to rewind() above, the rewind function will set the 
  // file pointer to the beginning of the file and clear the end-of-file 
  // indicator.  So "eof reached" will no longer be output.  If we uncomment
  // the lines of code below we can actually read the character "T" from 
  // the file again.
  //
  // c = fgetc(file);
  // printf("char read: %c\n", c);
  
  // Close the file as we are done working with it
  fclose(file);


  // A typical use case for feof() is to stop reading a file when there is no
  // more data to read from the file.  The below code assumes data.txt contains
  // the text:
  // 
  // more characters
  // in the file!
  //
  // And in this example we read each character from the file until feof() 
  // indicates there is no more data to read from the file.
  
  // Declare a file pointer variable to read the data.txt file
  FILE *data;
  
  // Open the file for reading
  data = fopen("data.txt", "r");
  
  // If there is an error opening the file exit with an error message and status
  if (data == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  } 
  
  // This loop will indefinitely read the next character from the file ad output
  // it UNTIL the end-of-file indicator is set and feof() returns true, at which
  // point 'break' is used to stop the loop.  So ths loop will read and output
  // all characters in the file.
  while (true)
  {
    c = fgetc(data);

    if (feof(data)) break;

    printf("%c", c);
  }

  // Close the file as we are done working with it. 
  fclose(data);

  return 0;
}