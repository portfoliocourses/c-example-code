/*******************************************************************************
*
* Program: Store File Contents Into A Dynamically Allocated String (Suboptimal)
*
* Description: An unoptimized example of how to store the contents of a file
* into a dynamically allocated string in C.  In this version of the program
* we read the file contents twice... once to determine the size of the string
* to be allocated, and again to store the file contents into the string.  This
* will lead to suboptimal performance as the file must be read twice and
* accessing a file on disk is a relatively expensive operation.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Oa_ji3dDFew 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // File pointer variable to allow us to access the file.
  FILE *file;

  // We'll accept the name of the file to be read as a command-line argument,
  // and so argc should be set to 2 (the program name + the argument).
  if (argc != 2)
  {
    // Exit with an error message and status if we have the incorrect number
    // of arguments... returning 1 instead of returning 0 is a signal to the
    // shell/terminal that something has gone wrong in the execution of our
    // program.
    printf("Invalid number of arguments!\n");
    return 1;
  }

  // Open the file for reading, where argv[1] is the command-line argument
  // that was provided to our program (i.e. the name of the file).
  file = fopen(argv[1], "r");

  // If fopen() fails to open the file it will return NULL, so we check if file
  // is set to NULL and exit with an error message and status if so.
  if (file == NULL)
  {
    printf("Error opening file!\n");
    return 1;
  }

  // total will keep track of the total number of characters in the file
  size_t total = 0;

  // Keep reading the file one character at a time, incrementing total each
  // time, until we reach the end of the file (as deteched by feof()) or an
  // error occurs (as deteched by ferror()).
  while (!feof(file) && !ferror(file))
  {
    // Eventually fgetc() will return EOF when we reach the end of the file,
    // and the next time the loop condition is checked feof() will return
    // true and the loop will stop.  This means total will be set to one
    // character more than there is in the file... but that's OK, that's
    // exactly the amount of space we need to allocate as we need one
    // additional character in our string than there is in the file to store
    // the special null terminator character that terminates the string.
    fgetc(file);
    total++;
  }

  // It's unlikely but it's possible the loop above stopped not because we
  // reached the end of the file, but because an error occurred while reading
  // from the file.  We check ferror() to see if this is what cause the loop
  // to stop, and if so, we exit the program with an error message and status.
  if (ferror(file))
  {
    printf("Error reading from file!\n");
    return 1;
  }

  // We can now dynamically allocate space for the string using total, as we
  // know we need total number of bytes/chars to store the string (including
  // the null terminator).
  char *string = malloc(total);

  // As of now the file pointer is at the end of the file, but if we call
  // rewind() and pass it the file pointer it will be rewinded to the start
  // of the file so we can read through it one character at a time again.
  rewind(file);

  // index will be used to keep track of our current index in the string as
  // we read and store each char from the file into the string
  size_t index = 0;

  // As before, we read each character from the file one at a time until we
  // reach the end of the file or an error occurs.
  while (!feof(file) && !ferror(file))
  {
    // This time we store each char into the string
    string[index] = fgetc(file);
    index++;
  }

  // Again if an error occurred reading the file we exit with an error message
  // and status...
  if (ferror(file))
  {
    printf("Error reading from file!\n");
    return 1;
  }

  // As with total in the first loop, 'index' will be set to the size of our
  // dynamically allocated string, and index-1 will give us the last index
  // in that string, which we set to the null terminator character to
  // terminate the string.
  string[index - 1] = '\0';

  // Close the file as we are done working with it now.
  fclose(file);

  // Output the string containing the file contents
  printf("File Contents:\n\n");
  printf("%s\n", string);

  // Free the dynamically allocated string as we are done working with it too.
  free(string);

  return 0;
}