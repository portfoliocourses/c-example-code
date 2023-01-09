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
    // read the next char from the file, store it into c
    c = fgetc(file);
    
    // if error occurs reading from file, exit with error message and status
    if (ferror(file))
    {
      printf("Error reading from file.\n");
      return 1;
    }
    
    // if we reach the end of the file, stop reading from the file
    if (feof(file))
    {
      // if a line is currently being read, total_chars will not equal 0, this 
      // will occur if the last line of the file doesn't end with a newline
      if (total_chars != 0)
      {        
        // In this case, we'll use realloc to re-allocate the block of memory 
        // for this string to be exaclty large enough to store it (total_chars 
        // plus one extra for the null terminator that ends a string.
        lines[total_lines] = realloc(lines[total_lines], total_chars + 1 );
        
        // end the string by placing null terminator at the end
        lines[total_lines][total_chars] = '\0';
        
        // increment total_lines to acknowledge we have read another line from
        // the file
        total_lines++;
      }
      
      // will stop the loop, and stop the reading of the file
      break; 
    }
    
 
    // If total_chars is set to 0 this is the first char we're reading on this
    // line, and we can allocate MORE_CHARS initial amount of space to store the 
    // string using malloc... i.e. a char array of size MORE_CHARS.
    if (total_chars == 0) lines[total_lines] = malloc(MORE_CHARS); 
    
    // store the char into "the current index of the current line" we've read in
    lines[total_lines][total_chars] = c; 
    
    // increment total_chars as we have just read in another char
    total_chars++;
    
    // if the char is a newline, we have reached the end of the current line
    if (c == '\n')
    {
      // We now know exactly how many chars are required to store the string for
      // this line, and we can reallocate the block of memory to be exacly large
      // enough... total_chars + 1 extra for the null terminator char that ends
      // a string.
      lines[total_lines] = realloc(lines[total_lines], total_chars + 1 );
      
      // end the string by placing the null terminator at the end
      lines[total_lines][total_chars] = '\0';
      
      // increment total_lines as we have completed reading in another line
      total_lines++;
      
      // set total_chars back to zero as we are about to start reading in 
      // another line (or at least, trying to)
      total_chars = 0;
      
      // It's possible that we have read enough lines that we have reached the 
      // maximum size of the array of pointers to chars.  We increase the size 
      // of the array by MORE_LINES amount each time, so if total_lines is a
      // multiple of MORE_LINES then we have reached the size of the current 
      // array of pointers.  
      if (total_lines % MORE_LINES == 0)
      {
        // In this case, we increase the size of the array by MORE_LINES and 
        // use realloc to reallocate space for this larger block of memory.  
        size_t new_size = total_lines + MORE_LINES;
        lines = realloc(lines, sizeof(char *) * new_size);
      }
    }
    // If the character is not a newline character, we haven't reached the end 
    // of the line, and we check if we have reached the size of the current 
    // array of chars.  The same as the above, because we increase the size of
    // the array of chars by MORE_CHARS each time, whenever total_chars is set
    // to a multiple of MORE_CHARS we know we have reached the size of the 
    // current char array.
    else if (total_chars % MORE_CHARS == 0)
    {
      // We increase the size of the array by MORE_CHARS and use realloc to
      // reallocate space for this larger block of memory.
      size_t new_size = total_chars + MORE_CHARS;
      lines[total_lines] = 
        realloc(lines[total_lines], new_size); 
    }

  } while (true);

  // At this point we know exactly how many lines we have read from the file and
  // can reallocate the block of memory for the array of pointers to chars to be
  // exactly the size required.
  lines = realloc(lines, sizeof(char *) * total_lines);
  
  // Output each string/line in the array of strings
  for (size_t i = 0; i < total_lines; i++)
    printf("%s", lines[i]);
  
  // Free the block of memory allocated for each string
  for (size_t i = 0; i < total_lines; i++)
    free(lines[i]);
  
  // Free the block of memory allocated for the array of pointers to chars
  free(lines);
  
  // close the file as we are done working with it
  fclose(file);

  return 0;
}
