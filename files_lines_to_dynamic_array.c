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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MORE_LINES 1024
#define MORE_CHARS 1024

int main(void)
{
  FILE *file = fopen("big.txt", "r");

  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  char **lines;
  lines = malloc(sizeof(char *) * MORE_LINES);

  size_t total_lines = 0;
  size_t total_chars = 0;
  char c;

  do 
  {
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

/*
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