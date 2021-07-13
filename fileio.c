/*******************************************************************************
*
* Program: File I/O Tutorial
* 
* Description: Example of using File I/O in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=vr7qCQLrUt8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  // We use a file handle created with FILE to access a file
  FILE *fh_output;

  // Open the file with fopen in writing mode with "w", which will create 
  // the file if it does not already exist and set it to "blank" if it does 
  // exist.  We could use append mode with "a" instead and it would append 
  // whatever we write to the file after the existing content of the file.
  fh_output = fopen("io.txt", "w");
  
  // fputs is one way of writing a string to a file...
  // fputs("abc", fh_output);
  // fputs("123\n", fh_output);
  // fputs("A string\n", fh_output);

  // fprintf works very much like printf, with placeholders that allow us to 
  // output things like int values to the file
  // int data = 5;
  // fprintf(fh_output, "data: %d\n", data);

  // we can write to a file in a loop to output a set of data to a file
  // for (int i = 0; i < 10; i++)
  //  fprintf(fh_output, "%d\n", i);

  // here we use an indefinite loop to output a varying amount of information to
  // the file depending on how many numbers the user wants to input
  int input = 0;
  while (true)
  {
    printf("Enter # (-1 quits): ");
    scanf("%d", &input);
    if (input == -1) break;
    else fprintf(fh_output, "%d\n", input);
  }

  // when we're done with the file we use fclose to close the file handle
  fclose(fh_output);

  // open the same file we just wrote to, but this time open it for reading with
  // "r" mode
  FILE *fh_input;
  fh_input = fopen("io.txt", "r");

  int finput = 0;
  int lines = 0;
  int numbers[100];

  // read each int in the file with fscanf that works much like scanf, it will
  // return EOF when the end of file is reached
  while (fscanf(fh_input, "%d", &finput) != EOF)
  {
    // store the number we've input into the numbers array, keep track of how 
    // many numbers we've read with lines... numbers act as a 'buffer' that is 
    // able to store some amount of numbers (up to 100)
    numbers[lines] = finput;
    printf("file line %d: %d\n", lines+1, finput);
    lines++;
  }

  // compute the average of the numbers in the file to perform some work with 
  // the data we've just read
  int total = 0;
  for (int i = 0; i < lines; i++)
    total += numbers[i];
  printf("Average: %d\n", total / lines);
  
  // close the file handle
  fclose(fh_input);

  // open another file called in.txt for reading... we can re-use the same 
  // file handle fh_input since we have closed it just previously to this
  fh_input = fopen("in.txt", "r");

  // we create a char array called 'buffer', we can call this an inptu buffer 
  // as it will store some amount of input
  char buffer[256];

  // fgets will read up to 256 chars and store them into buffer, until it 
  // encounters EOF (the end of file) or the first newline
  fgets(buffer, 256, fh_input);
  printf("Buffer: %s\n", buffer);

  // close the file handle
  fclose(fh_input);

  return 0;
}
