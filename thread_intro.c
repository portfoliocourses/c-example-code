/*******************************************************************************
*
* Program: Threads Demonstration
* 
* Description: Example of using threads in C with the pthread.h libray (POSIX
* thread library).
*
* YouTube Lesson: https://www.youtube.com/watch?v=ldJ8WGZVXZk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <pthread.h>

void *computation(void *add);

int main()
{
  // pthread_t will be used to uniquely identify, create, and manage threads
  pthread_t thread1;
  pthread_t thread2;
  
  long value1 = 1;
  long value2 = 2;
  
  // Create two threads that will each run the computation function, one is 
  // passed a void-casted pointer to value1 as an argument, the other is 
  // passed a void-cased pointer to value2 as an argument.
  pthread_create(&thread1, NULL, computation, (void*) &value1);
  pthread_create(&thread2, NULL, computation, (void*) &value2);
  
  // execution will pause at pthread_join until the thread provided as an 
  // argument has completed its execution
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  return 0;
}

// Accepts a void pointer and returns a void pointer as pthread_create expects
// both of these properties.  We pass in a value via the void pointer.  The 
// function does some meaningless work to simulate meaningful computational 
// working occurring.
void *computation(void *add)
{
  long sum = 0;

  // cast the void pointer add to a long pointer
  long *add_num = (long *) (add);
  
  // de-reference add_num to get at the value pointed to by add_num, have 
  // the loop run many, many times doing some computational work
  for (long i = 0; i < 1000000000; i++)
    sum += *add_num;

  return NULL;
}


// Visualizations of single-threaded vs. multi-threaded execution.
//
//
//              Single-Threaded Program
//
//          |   int x;
//          |   x = 20;
//          |   int y;
//  Time    |   y = 50;
//          |   int sum;
//          |   sum = x + y;
//          ↓
//     
//
//
//              Multi-Threaded Program 
//
//          |   int x;                 |  int a;
//          |   x = 20;                |  a = 3;
//          |   int y;                 |  int b;
//  Time    |   y = 50;                |  b = 5;
//          |   int sum;               |  int product;
//          |   sum = x + y;           |  product = a * b;
//          ↓                          ↓
//
//          Parallel Execution 
//
//
//
//              Multi-Threaded Program 
//
//          |   int x;                 |  
//          |                          |  int a;
//          |                          |  a = 3;
//          |   x = 20;                |  
//          |   int y;                 |   
//          |                          |  int b;
//  Time    |   y = 50;                |  
//          |                          |  b = 5;
//          |                          |  int product;
//          |   int sum;               |  
//          |   sum = x + y;           |  
//          |                          |  product = a * b;
//          ↓                          ↓
//
//          Concurrent But Not Parallel Execution 
//
//
//
//              Multi-Threaded Program 
//
//          |                             pthread
//          |
//          |   sum = x + y;           
//          |   pthread_create --------   function()
//          |   ...                    |  int a = 5;
//          |   printf("%d", sum);     |  int b = 3;
//  Time    |   ...                    |  int result = x + y;
//          |   pthread_join   --------↓
//          |   ...       | 
//          |   ...       |   
//          ↓          execution PAUSES here until thread done
//
//          Parallel Execution 
