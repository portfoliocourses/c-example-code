/*******************************************************************************
*
* Program: fprintf() Demonstration
* 
* Description: Example of using the fprintf() function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=DyFsScUbyg4  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  // fprintf() allows us to write strings to output streams, so we'll create a 
  // FILE pointer variable to allow us to access a file
  FILE *file;
  
  // Attempt to open file.txt in write mode with "w", write mode will cause the 
  // file to become blank before we write any content to the file.  
  file = fopen("file.txt", "w");
  
  // fopen() will return the file pointer if it is successful or NULL if it is 
  // not, if opening the file was unsuccessful we exit with an error message 
  // and status (returning 1 is a signal to the shell that something went wrong 
  // in the execution of our program).
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  

  // write the special character 'newline' to the file, which will produce a 
  // newline when we open the file in a text editor
  fprintf(file, "\n");
  
  // the special character \t represents a tab... in the file it is a single 
  // character but when read in a text editor it will appear as a series of 
  // spaces
  fprintf(file, "\t ABC \n");
  

  // The second argument to fprintf() is what is called the format string and 
  // format strings can include format specifiers that allow us to output 
  // numbers and other pieces of data into the string in a formatted way.  
  // Format specifiers have the below format:
  //
  // %[flags][width][.precision][length]specifier
  //
  // Check out this documentation for more details:
  //   https://www.cplusplus.com/reference/cstdio/fprintf/
  //

  // Output an int value using %d format specifier and supplying an additional 
  // int argument to fprintf... this will result in 5 followed by a newline
  int i = 5;
  fprintf(file, "%d\n", i);
  
  // output the char 'd' with %c
  char c = 'd';
  fprintf(file, "%c\n", c);
  
  // output a float with %f
  float f = 2.125;
  fprintf(file, "%f\n", f);
  
  // we can also use %f to output a double
  double d = 9.82;
  fprintf(file, "%f\n", d);
  
  // output a string using %s
  char string[] = "abc";
  fprintf(file, "%s\n", string);
  

  // the format string does not need to end with \n, but if we don't the next 
  // call to fprintf will begin printing on the 'current line' that the last 
  // call to fprintf was printing on... here we print out 1 2 2 on the same 
  // line using three calls to fprintf
  fprintf(file, "%d ", 1);
  fprintf(file, "%d ", 2);
  fprintf(file, "%d\n", 3);
  

  // output the number 22 into a field of width 4 characters, by default the 
  // field will be right aligned and so we'll have 2 blank spaces followed 
  // by the number 22
  fprintf(file, "%4d\n", 22);
  
  // output the number 22 into a field of width 4 character but use '-' to 
  // have it output into the field left-aligned
  fprintf(file, "%-4d<-end\n", 22);
 
  // output the number 22 into a field of width 4 characters but use '0' to 
  // add leading 0s to the field
  fprintf(file, "%04d\n", 22);
  

  // by default only negative numbers will have a - sign in front of them
  fprintf(file, "%d %d\n", 1, -1);
  
  // but with + we can force a sign to output whether the number is positive 
  // or negative
  fprintf(file, "%+d %+d\n", 1, -1);
  

  // by default we may get more decimal digits of a floating point number output
  // than we really need
  fprintf(file, "%f\n", 1.2345);
  
  // we can use .# to limit the number of decimal digits of precision, in this 
  // case we output the number with two decimal digits (1.23)
  fprintf(file, "%.2f\n", 1.2345);
  
  // we can use * to specify the number of decimal digits of precision with an 
  // additional argument to fprintf, in this case 1 digit of precision
  fprintf(file, "%.*f\n", 1, 1.2345);
  
  // we could then use a variable as this argument to programmatically determine
  // at runtime the amount of decimal digits of precision 
  int digits = 3;
  fprintf(file, "%.*f\n", digits, 1.2345);
  

  // output in scientific notation with %e
  fprintf(file, "%e\n", 2.4123);
  
  // output a pointer (memory address) with %p
  fprintf(file, "%p\n", &digits);
  
  // output an unsigned long... generally we can output anything in C if we 
  // follow the documentation for fprintf() 
  unsigned long ul = 123456789012345;
  fprintf(file, "%lu\n", ul);
  
  
  // our program might store an array of results that we wish to output to a 
  // file...
  float results[] = {1.1, 1.2, 1.3, 1.4, 1.5};
  
  // we can use fprintf() in a loop to output each array element, here we add 
  // some formatting related arguments to output each number into a field of 
  // width 7 with leading 0s and 2 decimal digits of precision
  for (int i = 0; i < 5; i++)
    fprintf(file, "%07.2f\n", results[i]);
  

  // our program might also work with a 2d array of data we wish to ouput to 
  // a file...
  double data[3][3] = 
  {
    {1.1, 1.2, 1.3},
    {2.1, 2.2, 2.3},
    {3.1, 3.2, 3.3}
  };
  
  // we could create a loop with a counter variable to 'loop through' each 
  // row in 2d array
  for (int i = 0; i < 3; i++)
  {
    // and then we could have a single fprintf() statement responsible for 
    // outputting the element at each column (0,1,2) in the current row (i)
    fprintf(file,
            "%.1f %.1f %.1f\n", 
            data[i][0],
            data[i][1],
            data[i][2]);
  }
  fprintf(file, "\n\n");
  

  // We can take advantage of field widths to ouput a nicely formatted 'table',
  // here we output "column headings" D1, D2 and D3 left-aligned into fields 
  // of width 5 characters
  fprintf(file,
          "%-5s%-5s%-5s\n",
          "D1", "D2", "D3");
  
  // We then output 15 *s followed by a newline to create a line separating our 
  // column headings from our data output
  for (int i = 0; i < 15; i++)
    fprintf(file, "*");
  fprintf(file, "\n");
  
  // This time we output the 2D array using a nested loop... the outer loop 
  // counter variable i increments over the rows in our 2D array
  for (int i = 0; i < 3; i++)
  {
    // ...and the inner loop counter variable j increments over each column 
    // in the table, so when we output data[i][j] we output the element at 
    // the ith row and jth column... we output the elements left aligned into 
    // a field of width 5 characters to output our data into a 'table' with 
    // width 5 columns
    for (int j = 0; j < 3; j++)
      fprintf(file, "%-5.1f", data[i][j]);

    fprintf(file, "\n");
  }
  fprintf(file, "\n\n");
  

  // So far we've used the backslash \ character to help us output newlines and
  // tabs, we call this special character the 'escape character', to output an 
  // actual \ character we use \\

  fprintf(file, " \\ \n");
  
  // to output a double quote " character we use \"
  fprintf(file, " \" \n");
  
  // we can output to stdout which is by default the terminal/shell by using 
  // the special stdout identifier (stdout is also an output stream)
  fprintf(stdout, "test\n");
  
  // fprintf() will return the number of characters in the output stream, in 
  // this case '3', or a negative number if it fails
  int result = fprintf(file, "abc");
  printf("result: %d\n", result);

  // close our access to the file
  fclose(file);

  return 0;
}