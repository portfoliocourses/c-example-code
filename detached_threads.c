/*******************************************************************************
*
* Program: Detached Threads (pthreads) Example
* 
* Description: Example of using detached threads in C with the POSIX thread
* library.  This program uses a detached thread to write a log entry to a log 
* file approx. every second until the program terminates.
*
* YouTube Lesson: https://www.youtube.com/watch?v=p142bNjIsms 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

// the log file pointer
FILE *log_file;

// the program state will be a number of 'incidents' that the user can add to 
// as they use the application
int incidents = 0;

// the logger function will be run in the detached thread and will write to 
// a log file approx. every 1 second the current date/time + the number of 
// incidents (i.e. the state of the application)
void *logger()
{
  // create an infinite loop as it will run in the detached thread until the 
  // program terminates
  while (true)
  {
    // get the current time
    time_t current_time;
    time(&current_time);
    
    // get the struct tm format of the time
    struct tm *tm = localtime(&current_time);
    
    // use strftime to get a string timestamp of the current time that includes
    // the date and current hour, minute and second
    char timestamp[256];
    strftime(timestamp, 256, "%x@%H:%M:%S", tm);

    // write to the log file the timestamp and the number of incidents 
    fprintf(log_file, "%s: %d\n", timestamp, incidents);
    
    // pause execution for 1 second
    sleep(1);
  }
  
  // pthread functions are required to return a void *, so we just return 
  // NULL in this case
  return NULL;
}


int main()
{
  // open the log file for writing, if there is an error then exit with an 
  // error message and status
  log_file = fopen("log.txt", "w");
  if (log_file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  
  // create the pthread_t variable to manage the thread
  pthread_t thread;
   
  // call pthread_create to create the thread and run the logger function, if 
  // there is an error exit with an error status
  int return_value = 0;
  return_value = pthread_create(&thread, NULL, &logger, NULL);
  if (return_value != 0) return 1;
  
  // call pthread_detach to make the thread a detached thread, if there is an 
  // error exit with an error status
  return_value = pthread_detach(thread);
  if (return_value != 0) return 1;
  
  // the "main program" just allows the user to repeatedly enter in a number 
  // of new incidents that will be added to the incidents total, and they can 
  // enter -1 when they wish to quit... allowing the user to "work" for some 
  // unknown amount of time
  int input = 0;
  do 
  {
    printf("Enter -1 to quit.\n");
    printf("New incidents: ");
    scanf("%d", &input);

    if (input != -1) incidents += input;
  } while (input != -1);
  
  // close the log file when we're done with it
  fclose(log_file);

  return 0;
}

 
// Visualizations of joinable vs detached threads.
//
//
//          Joinable Thread
//          ---------------
//
//      |
//      |   ...                       pthread
//      |   pthread_create --------    
//      |   ...                    |  ...
//      |   printf("%d", sum);     |  do work
// Time |   ...                    |  ...
//      |   pthread_join   --------↓
//      |   ...       | 
//      |   ...       |   
//      ↓          Execution PAUSES here until
//                 thread is done work
//
//
//
//          Detached Thread
//          ---------------
//
//      |
//      |   ...                       pthread
//      |   pthread_create --------    
//      |   pthread_detach         |  ...
//      |   ...                    |  ...
//      |   do work                |  do work
// Time |   ...                    |  ...
//      |   ...                    |  ...
//      |   ...                    |  ...
//      |   exit                   |-> resources
//      ↓                          ↓   released