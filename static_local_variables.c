/*******************************************************************************
*
* Program: Static Local Variables
* 
* Description: Examples of using a static local variable in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Hm5Jc7ajZsk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

void f();
void log_message(char *message);

int main()
{
  // notice how the value of the variable calls persists across function calls
  f();
  f();
  f();
  
  // notice how the log messages have a unique, incrementing log message number
  log_message("read data");
  log_message("update data");
  log_message("data error");

  return 0;
}

// appends a log message to a file log.txt on a newline with a unique log number
void log_message(char *message)
{
  // Creates a static local variable total to keep track of the number of log 
  // messages, the variable is initialized to 0 only the FIRST time the function
  // is called.  The variable and its value will otherwise persist across all 
  // log_message() function calls!
  static int total = 0;
  total++;
  
  // open up log.txt and append a line with the log message, using total for 
  // the log message number
  FILE *logfile = fopen("log.txt", "a");
  if (logfile != NULL)
  {
    fprintf(logfile, "log %d: %s\n", total, message);
    fclose(logfile);
  }
}

void f()
{
  // the static local variable calls will only be initialized to 0 the first 
  // time the function f() is called, on all subsequent calls to f the variable
  // calls and its value will be maintained... notice the results of calling 
  // f() three times in main to see the effect
  static int calls = 0;
  calls++;
  printf("calls: %d\n", calls);
}