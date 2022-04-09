/*******************************************************************************
*
* Program: Get Char From File Portability Bug
* 
* Description: Example of bugs that can occur when reading chars from a file 
* using a char variable and functions like fgetc() in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Zd5OThnCZ7w  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

int main()
{
  // create a file pointer variable
  FILE *file;

  // open the file for reading
  file = fopen("file.txt", "r");  
  
  // if there is an error opening the file exit with an error message and status
  if (file == NULL)
  {
    printf("Error opening a file.\n");
    return 1;
  }
  
  
  // Reading a char from a file can fail if we are reading a file encoded 
  // using ASCII character encoding: 
  // https://www.rapidtables.com/code/text/ascii-table.html
  //
  // This is because fgetc() *really* returns an int, not a char, and the 
  // constant value EOF is really just "255".  The number 255 represents the 
  // special character ÿ in ASCII.  So if the file is encoded with ASCII and 
  // includes the character ÿ, then the loop will stop at this character even 
  // if there are more characters in the file!
  //
  /*
  char c;

  while ( (c = fgetc(file)) != EOF)
  {
    printf("%c\n", c);
  } 
  */


  // EOF will also not play nicely with unsigned char variables, we will get 
  // an infinite loop below, see the explanation here:
  //   https://stackoverflow.com/a/8586867
  //
  // Notably, C does not ensure that char variables will be signed by default 
  // and some compilers and some compilers on some systems will use unsigned 
  // char: https://stackoverflow.com/a/3728218
  //
  /*
  unsigned char c;

  while ( (c = fgetc(file)) != EOF)
  {
    printf("%c\n", c);
  } 
  */


  // The above errors are 'portability bugs' in the sense that their occurrence 
  // depends on the type of system we are on.  The below method should be much 
  // more portable.
  

  // Alternative Method
  //
  // Instead we can store the value retrived from fgetc() into an int variable, 
  // and depend on feof() and ferror() to let us know when either an error has 
  // occurred or we have reached the end of the file.

  int c;
  char string[128];
  int i = 0;

  while (true)
  {
    c = fgetc(file);

    if (feof(file)) break;
    if (ferror(file)) break;

    string[i] = c;
    i++;
    printf("%c\n", c);
  }

  printf("string: %s\n", string);

  fclose(file);

  return 0;
}
