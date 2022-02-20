/*******************************************************************************
*
* Program: Reverse A File
* 
* Description: Example of reversing a file's contents using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=q6e6H2Ogsh0
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main()
{
  // file pointer variable for the original file, and file that will store the
  // reversed contents of the original file
  FILE *file;
  FILE *reverse;

  // store the filename of the original file and the reversed contents file
  char filename[1024];
  char reversename[1024];

  // prompt user for the original filename, store it into filename
  printf("File To Reverse: ");
  scanf("%s", filename);

  // prompt user for the reversed contents filename, store it into reversename
  printf("New File: ");
  scanf("%s", reversename);
  
  // open original file for reading, and the reversed contents file for writing
  file = fopen(filename, "r");
  reverse = fopen(reversename, "w");
  
  // if either file failed to open, exit with an error message and return value
  if (file == NULL || reverse == NULL)
  {
    printf("Error opening file(s)\n");
    return 1;
  }
  
  // move the file pointer to the end of the file
  fseek(file, 0, SEEK_END);

  // use ftell() to return the current value of the position indicator, which 
  // will give us the number of characters in the file
  int length = ftell(file);

  // move the file pointer back one character so it is positioned at the last
  // character in the file
  fseek(file, -1, SEEK_CUR);

  // Continuously read in the next character from the original file moving from 
  // the end of the file to the beginning, and write the characters to the 
  // reversed contents file... having the effect of reversing the file contents!
  // We do this for "length" amount of characters that we determined above 
  // to read and write each character.
  while (length > 0)
  {
    // read in the next character from the file
    char c = fgetc(file);

    // write the character to the reversed contents file
    fputc(c, reverse);

    // print the character to the terminal
    printf("%c", c);

    // Move the file pointer back *2* characters from its current position.  
    // After running the two above fseeks(), the file pointer will positioned
    // at the last character in the file... after reading this character in 
    // using fgetc() above, the file pointer will be at the end of the file.
    // We move it back 2 characters so we can read in the 2nd last character,
    // and in the next iteration of the loop after calling fgetc() to read 
    // in the 2nd last character, the file pointer will again be at the 
    // last character.  This function call will then move it back to the 
    // 3rd last character, and on and on... we continuously read in a 
    // character but move the file pointer back two characters to have the 
    // effect of reading the file backwards!
    fseek(file,-2,SEEK_CUR);
    
    // decrement length to keep track of how many characters remain to be read
    length--;
  }

  // print out a newline so if we are running the program from the terminal 
  // the next terminal prompt occurs on a newline from the output above
  printf("\n");
  
  // close both files
  fclose(file);
  fclose(reverse);

  return 0;
}