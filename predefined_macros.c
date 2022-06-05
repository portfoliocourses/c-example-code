/*******************************************************************************
*
* Program: Predefined Preprocessor Macros Demonstration
* 
* Description: Examples of using the predefined preprocessor macros in C, 
* including to implement program logging.
*
* YouTube Lesson: https://www.youtube.com/watch?v=vIy0vEZpjtQ  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h> 

// When creating large programs made up of hundreds of source code files it 
// may be useful to implement logging.  A log function can be used by the 
// program to write log messages to the log file at important points in its 
// execution, to help trace the execution of the program after it runs if 
// there is a bug for example.  If these log messages contain the filename 
// and line number at which they were written, this can help us to determine 
// the part of our source code we need to examine to understand the bug.
// We'll implement a log function called 'logger' to do this!
void logger(char *msg, char *src, int line);

int main()
{
  // The __FILE__ predefined macro will be set to a string of the source code 
  // filename in which it is contained
  printf("File: %s\n", __FILE__ );

  // The __DATE__ predefined macro will be set to a string of the date at which
  // the program was compiled
  printf("Date: %s\n", __DATE__ );

  // The __TIME__ predefined macro will be set to a string of the TIME at which 
  // the program was compiled
  printf("Time: %s\n", __TIME__ );

  // The __LINE__ predefined macro will be set to the line number of the source 
  // code file at which it appears
  printf("Line: %d\n", __LINE__ );

  // The __STDC__ predefined macro will be set to 1 if the compiler conforms to 
  // the ANSI C standard
  printf("ANSI: %d\n", __STDC__ );

  
  // Create a log message 'task 1 done' that is stamped with this source code 
  // filename and the line number at which it occurs 
  logger("task 1 done", __FILE__, __LINE__);


  // Create a log message 'task 2 done' that is also stamped with this source 
  // code filename and the DIFFERENT line number at which it occurs
  logger("task 2 done", __FILE__, __LINE__);

  return 0;
}

// Appends a log message string (msg) to a log file called log.txt that is 
// "stamped" with the source code filename and line number at which it occurs.
void logger(char *msg, char *src, int line)
{
  // File pointer variable to open the log file
  FILE *file;
  
  // Open the log file in 'append mode' so we can append additional log messages
  // to the file... typically this is the mode we use when accessing a log file 
  // as we may run the program multiple times and want previous log messages 
  // to 'persist' in this log file rather than be overwritten.
  file = fopen("log.txt", "a");
  
  // If the log file failed to open exit with an error message and status.
  if (file == NULL)
  {
    printf("Error opening log file.\n");
    exit(1);
  }
  
  // Write the log message to the file, prepended with the source code filename
  // AND the line number:  source:line:msg format
  fprintf(file, "%s:%d:%s\n", src, line, msg);
  
  // Close the log file as we are done working with it
  fclose(file);
}