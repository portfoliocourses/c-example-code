/*******************************************************************************
*
* Program: Read And Store All File Lines Into A Dynamically Allocated Array Of
* Strings.
*
* Description: Reads and stores all the lines of a file into a dynamically 
* allocated array of strings in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=vQno9S3yF80 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

/*
  
  We'll store the file lines into a dynamically allocated array of strings.  An
  array of pointers to chars will be used to point to each string storing each
  line of the file.  The blocks of memory for each string and the array of 
  pointers to chars will be dynamcially allocated and made exactly the right 
  size (no more, no less) to store the data required.
  
  
                                      each string is stored
  char * array                      / in a block of memory
                                   /
          -- [0] -> .... string ...  
block    |   [1] -> .... string ... 
 of    <-|   [2] -> .... string ...
memory   |   [3] -> .... string ...
          --  .  
              .   
              .   
              ↓   

  We can't know how big the blocks of memory need to be until we read in the 
  file.  So when reading in each line of the file, we'll initially use 
  malloc to allocate enough space for 1024 chars.  Then if we reach 1024 
  chars when reading in that line, we'll use realloc to make the block of 
  memory bigger by 1024 chars.  We'll continue this until we reach the end 
  of the line, at which point we *know* how big the block of memory will 
  need to be, and we will reallocate the block of memory to be exactly the
  right size.  We'll use the same technique for allocating reallocating our
  array of pointers to chars.

        initial      
         malloc      realloc      realloc
              |            |            |
           1024         2048         3072
              |            |            |
  ... chars ...... chars .......\n ~~~~~~
                                |
                            realloc to SHORTEN the block
                            of memory to what is required
  
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The sizes for each "memory aallocation increase" of both the arrays of
// chars storing each line (MORE_CHARS), and the array of pointers to chars 
// pointing to the strings/lines (MORE_LINES).
#define MORE_LINES 1024
#define MORE_CHARS 1024

int main(void)
{
  // open file.txt for reading
  FILE *file = fopen("file.txt", "r");
  
  // if the file failed to open, exit with an error message and status
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  
  // lines will point to the array of pointers to chars
  char **lines;
  
  // allocate space for MORE_LINES amount of pointers to char elements initially
  lines = malloc(sizeof(char *) * MORE_LINES);

  // used to keep track of the current number of lines read
  size_t total_lines = 0;
  
  // used to keep track of the current number of chars read on the current line
  size_t total_chars = 0;

  // used to store each char read from the file
  char c;
  
  // loop will read each char from the file until the end of the file is 
  // reached or an error occurs reading from the file
  do 
  {
    // read the next char from the file
    c = fgetc(file);

    if (ferror(file))
    {
      printf("Error reading from file.\n");
      return 1;
    }

    if (feof(file))
    {
      if (total_chars != 0)
      {
        lines[total_lines] = 
          realloc(lines[total_lines], total_chars + 1 );
        lines[total_lines][total_chars] = '\0';

        total_lines++;
      }
      break; 
    }
    
    if (total_chars == 0)
      lines[total_lines] = malloc(MORE_CHARS); 

    lines[total_lines][total_chars] = c; 
    total_chars++;

    if (c == '\n')
    {
      lines[total_lines] = 
        realloc(lines[total_lines], total_chars + 1 );
      lines[total_lines][total_chars] = '\0';

      total_lines++;
      total_chars = 0;

      if (total_lines % MORE_LINES == 0)
      {
        size_t new_size = total_lines + MORE_LINES;
        lines = realloc(lines, sizeof(char *) * new_size);
      }
    }
    else if (total_chars % MORE_CHARS == 0)
    {
      size_t new_size = total_chars + MORE_CHARS;
      lines[total_lines] = 
        realloc(lines[total_lines], new_size); 
    }

  } while (true);

  lines = realloc(lines, sizeof(char *) * total_lines);

  for (size_t i = 0; i < total_lines; i++)
    printf("%s", lines[i]);

  for (size_t i = 0; i < total_lines; i++)
    free(lines[i]);

  free(lines);

  fclose(file);






  return 0;
}
