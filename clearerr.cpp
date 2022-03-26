/*******************************************************************************
*
* Program: clearerr() Function Example
* 
* Description: Examples of using the clearerr() function in C to clear the end 
* of file indicator and error indicator.
*
* YouTube Lesson: https://www.youtube.com/watch?v=SNBTCbzFEtE 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

void dump_file(FILE *file);

int main()
{
  // create file pointers for reading and writing
  FILE *file_read;
  FILE *file_write;
  
  // open file.txt for reading with one pointer, and writing with the other
  file_read = fopen("file.txt", "r");
  file_write = fopen("file.txt", "w");
  
  // if an error occurs opening the file with either pointer, exit with an 
  // error message and status
  if (file_read == NULL || file_write == NULL)
  {
    printf("Error opening file(s).\n");
    return 1;
  }
  
  // write two characters to the file and close the file_write pointer
  fputc('w', file_write);
  fputc('x', file_write);
  fclose(file_write);
  
  // call the dump_file function to read and output the contents up until we 
  // encounter the end of the file, using the file_read pointer
  dump_file(file_read);
  
  // though the above function call will output characters, this function call 
  // will only output "File Dump Complete!" because the end of file indicator 
  // is set and there are no more characters to read from the file
  dump_file(file_read);
  
  // open up the file with another file pointer, this time in append mode to 
  // add *more* characters to the file
  FILE *file_append;
  file_append = fopen("file.txt", "a");
  
  // if an error occurs opening the file exit with an error message and status
  if (file_append == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  
  // append two more characters to the file and close the file_append pointer
  fputc('y', file_append);
  fputc('z', file_append);
  fclose(file_append);
  
  // IF we call clearerr with the file_read pointer, we will clear the end of 
  // file indicator, and subsequent calls to dump_file will then be able to 
  // read the additional content that has now been appended to the file
  clearerr(file_read);
  
  // the function will now successfully read additional content from the file,
  // without the clearerr() function call above however it will not read the 
  // new characters as the end of file indicator will remain set
  dump_file(file_read);
  
  // close our file_read file pointer as well
  fclose(file_read);



  // Another example of using clearerr() to clear the error indicator, allowing
  // us to keep reading a file even after an error occurs.  Delete the above 
  // code and uncomment this code to test it out.
  //
  /*
  
  // create a file pointer variable
  FILE *file;
  
  // open the file file.txt for READING
  file = fopen("file.txt", "r");
  
  // if the file failed to open exit with an error message and status
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  
  // attempt to WRITE to the file, this will cause an error to occur
  fputc('d', file);
  
  // the error indicator has been set, and so ferror() will return true
  if (ferror(file)) printf("Write error!\n");
  
  // if we clear the error, we can continue to access the file successfully 
  // using the code below
  clearerr(file);
  
  // read and print each character in the file, stopping if an error occurs or 
  // if we reach the end of the file
  int c;
  while (true)
  {
    c = fgetc(file);
    if (feof(file) || ferror(file)) break;

    printf("%c\n", c);
  }
  */

  return 0;
}

// reads and outputs the file contents using the file pointer file
void dump_file(FILE *file)
{
  // read the next character from the file and output it on a newline until 
  // we either reach the end of the file or an error occurs
  int c;
  while (true)
  {
    c = fgetc(file);
    if (feof(file) || ferror(file)) break;
    printf("%c\n", c);
  }

  // regardless of what happens or does not happen above, output File Dump 
  // Complete so we have an indication that the work is done and that the 
  // function has indeed executed
  printf("File Dump Complete!\n");
}