/*******************************************************************************
*
* Program: Add Line Numbers To A File
* 
* Description: Add line numbers to a file in C.  We solve the problem by 
* creating a temporary file, writing the lines of the original file to the 
* temporary file with a line number in front, and then deleting the original 
* file and renaming the temp file to have the original file's name. 
*
* The filename itself is provided as a command-line argument, so we would run
* the program like this: ./add_file_line_numbers file.txt
* where file.txt is the name of the file we wish to add line numbers to. 
*
* YouTube Lesson: https://www.youtube.com/watch?v=MbDwut1b1hE
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

// constants use to create and work with char arrays to store the temporar 
// filename, and each line of the original file
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

int main(int argc, char *argv[])
{
  // file pointers to access the original file and temp file
  FILE *file, *temp;

  // used to point to the filename command-line argument
  char *filename;

  // stores the temporary filename
  char temp_filename[FILENAME_SIZE];

  // stores each line of the original file
  char buffer[MAX_LINE];

  // check to make sure the correct number of command-line arguments is 
  // provided, if it is not then exit with an error message and status
  if (argc != 2)
  {
    printf("Argument missing.\n");
    return 1;
  }
  // otherwise set filename to point to the 2nd command line argument string
  else filename = argv[1];
  
  // build a temporary filename by first copying the string "temp____" into the 
  // temp_filename char array, and then appending on the original filename, so
  // if the name of the original file was file.txt we'll have "temp____file.txt"
  strcpy(temp_filename, "temp____");
  strcat(temp_filename, filename);
  
  // open the original file for reading, and the temp file for writing
  file = fopen(filename, "r");
  temp = fopen(temp_filename, "w");
  
  // if either or both files failed to open, exit with an error message & status
  if (file == NULL || temp == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  
  // keep track of the current line number to print on each line of temp file
  int current_line = 1;
  
  // read each line of the original file into the buffer until we reach the end
  // of the file
  while (fgets(buffer, MAX_LINE, file) != NULL)
  {
    // write the int value of current_line to the temp file, followed by a 
    // space, followed by the line in the original file
    fprintf(temp, "%d %s", current_line, buffer);

    // increment the current line so that it is the correct value for the next
    // line in the file
    current_line++;
  }
  
  // close both files
  fclose(temp);
  fclose(file);
  
  // delete the original file, and rename the temporary file to the original
  // file's name
  remove(filename);
  rename(temp_filename, filename);

  return 0;
} 
