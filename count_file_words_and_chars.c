/*******************************************************************************
*
* Program: Count The Number Of Words And Characters In A File
* 
* Description: Example of counting the number of words and characters in a file 
* using C.  This program considers ALL characters in the file, including 
* whitespace like spaces and newlines, to be considered 'characters'.
*
* YouTube Lesson: https://www.youtube.com/watch?v=H-dehw4nLVM 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
  // Stores the filename of the file
  char filename[1024];
  
  // Prompt the user for the filename, store what they enter into filename 
  printf("File: ");
  scanf("%s", filename);
  
  // Attempt to open the file with the given filename for reading, store the 
  // file pointer returned into the file variable.
  FILE *file = fopen(filename, "r");
  
  // If the file fails to open fopen() will return NULL, so check for this 
  // and exit with an error message and status if this occurs.
  if (file == NULL) 
  {
    // Output the error message to the user
    printf("Error opening file.\n");

    // Returning 1 instead of 0 will cause the program to exit with an error
    // status given to the shell/terminal
    return 1;
  }
   
  // We'll read the file one character at a time until we reach the end of the 
  // file, keeping a count of each character read.  In order to count the words
  // in the file we'll acknowledge that a new word is in the file whenever we 
  // switch from reading a sequence of whitespace characters to a sequence 
  // of non-whitespace characters.

  // c will store each character as it is read from the file  
  int c;
  
  // characters and words will keep a running count of the characters and words
  // encountered in the file
  int characters = 0;
  int words = 0;

  // whitespace will be true if we have been reading a sequence of whitespace
  // characters and false if we have been reading a sequence of non-whitespace
  // characters... we'll use it to help us recognize when a switch has occurred!
  bool whitespace = true;
  
  // keep reading the file one character at a time
  while (true)
  {
    // fgetc() will return the next char of the file, and we store it into c
    c = fgetc(file);
    
    // Stop the loop if we reach the end of the file
    if (feof(file)) break;
    // If an error occurs exit with an error message and status
    else if (ferror(file))
    {
      printf("Error reading file.\n");
      return 1;
    }
    
    // Increment our count of characters as we've read another character from 
    // the file successfully.
    characters++;
    
    // If we've been reading whitespace characters prior to this new character
    // stored in c, and now this character c is NOT a whitespace character, 
    // we consider this the start of a new word and increment words to 
    // acknowledge this new word.  We also set whitespace to false as we are 
    // now reading in non-whitespace characters.  The isspace() function of 
    // the ctype.h library will return true for whitespace characters like 
    // ' ', '\n', '\t', and false otherwise.
    if (whitespace && !isspace(c))
    {
      words++;
      whitespace = false;
    }
    // If we've been reading in non-whitespace characters and now this new 
    // character stored in c IS a whitespace character, set whitespace to 
    // true to acknowledge we are reading in a sequence of whitespace 
    // characters.  
    else if (!whitespace && isspace(c))
    {
      whitespace = true;
    }
  }
  
  // Close our access to the file since we are done working with it 
  fclose(file);

  // Output the number of characters and words in the file
  printf("Analysis complete!\n");
  printf("Characters: %d\n", characters);
  printf("Words: %d\n", words);

  return 0;
}