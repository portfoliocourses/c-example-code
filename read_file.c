/*******************************************************************************
*
* Program: Read All File Contents Into A String
* 
* Description: Example of reading the entire contents of a file into a char
* array as a string using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=8AVZYAE4FEU
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

char *read_file(char *filename);

int main()
{
  // prompt the user for filename of the file to read, store it into filename
  char filename[1024];
  printf("File: ");
  scanf("%s", filename);
  
  // read the file contents of the file
  char *file_contents = read_file(filename);

  // if there was an error reading the file, file_contents will be set to NULL,
  // handle the error gracefully with an error message and error return status
  if (file_contents == NULL)
  {
    printf("Error reading file.\n");
    return 1;
  }
  
  // output the file contents to verify they were read into the string correctly
  printf("File Contents:\n\n%s\n", file_contents);
  
  // free the dynamically allocated memory as a best practice to prevent a 
  // memory leak from occurring
  free(file_contents);

  return 0;
}

// Reads and stores the whole contents of the file with filename into a 
// dynamically allocated char array on the heap, returns a pointer to this char
// array (or NULL if there was an error reading the file contents)/
char *read_file(char *filename)
{
  // file pointer variable used to access the file
  FILE *file;
  
  // attempt to open the file in read mode
  file = fopen(filename, "r");
  
  // if the file fails to open, return NULL as an error return value
  if (file == NULL) return NULL;
  
  // move the file pointer to the end of the file
  fseek(file, 0, SEEK_END); 

  // fseek(file) will return the current value of the position indicator, 
  // which will give us the number of characters in the file
  int length = ftell(file);

  // move file pointer back to start of file so we can read each character
  fseek(file, 0, SEEK_SET);
  
  // dynamically allocate a char array to store the file contents, we add 1 to 
  // length for the null terminator we will need to add to terminate the string
  char *string = malloc(sizeof(char) * (length+1));
  
  // c will store each char we read from the string
  char c;

  // i will be an index into the char array string as we read each char
  int i = 0;

  // keep reading each char from the file until we reach the end of the file
  while ( (c = fgetc(file)) != EOF)
  {
    // store char into the char array string
    string[i] = c;

    // increment i so we store the next char in the next index in the char array
    i++;
  }

  // put a null terminator as the final char in the char array to properly 
  // terminate the string
  string[i] = '\0';
  
  // close the file as we are now done with it
  fclose(file);
  
  // return a pointer to the dynamically allocated string on the heap
  return string;
}
