/*******************************************************************************
*
* Program: Mutex Example
* 
* Description: Example of using a mutex to avoid a race condition in C using 
* the POSIX library.  We create a small library  to simulate the management of 
* a bank account balance, e.g. ATM machines accessing a central bank server to 
* update a balance after a deposit is made locally.  We have multiple threads 
* access this shared state and use a mutex lock to prevent a race condition 
* from leading to incorrect results.
*
* YouTube Lesson: https://www.youtube.com/watch?v=raLCgPK-Igc 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <pthread.h>
#include "bank.h"

void* deposit(void *amount);

// mutex variable
pthread_mutex_t mutex;

int main()
{
  // output the balance before the deposits
  int before = read_balance();
  printf("Before: %d\n", before);
  
  // we'll create two threads to conduct a deposit using the deposit function
  pthread_t thread1;
  pthread_t thread2;
  
  // initialize the mutex
  pthread_mutex_init(&mutex, NULL);

  // the deposit amounts... the correct total afterwards should be 500
  int deposit1 = 300;
  int deposit2 = 200;
  
  // create threads to run the deposit function with these deposit amounts
  pthread_create(&thread1, NULL, deposit, (void*) &deposit1);
  pthread_create(&thread2, NULL, deposit, (void*) &deposit2);
  
  // join the threads
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  
  // destroy the mutex
  pthread_mutex_destroy(&mutex);

  // output the balance after the deposits
  int after = read_balance();
  printf("After: %d\n", after);

  return 0;
}

// carry out a deposit using the bank library (note that the pthread library 
// expects our function to return a void* and accept a void* as an argument)
void* deposit(void *amount)
{
  // The first thread this reaches this statement will acquire the lock, and
  // the second thread will then wait here until the lock is unlocked.  the 
  // first thread that reaches this look will execute the statements below 
  // and then reach the unlock statement, at which point the second thread 
  // will then itself be able to acquire the lock and begin to execute 
  // this section of code.  We call this section of code between the lock 
  // and unlock a critcal section, as we are accessing and modifying shared 
  // state between threads.  If we do not use a lock to "guard" this critical 
  // section of code from being entered by multiple threads at the same time, 
  // we will have a race condition.  As the function is executed by two 
  // threads over the same period of time, the statements executed will 
  // interleave leading to incorrect results.  Comment out the lock and 
  // unlock function calls to see the effect.  See the visualization below 
  // of how the code executes with a race condition present vs with our mutex
  // code below.
  //
  pthread_mutex_lock(&mutex);

  // retrieve the bank balance
  int account_balance = read_balance();
  
  // make the update locally
  account_balance += *((int *) amount); 
  
  // write the new bank balance
  write_balance(account_balance);
  
  // unlock to make the critical section available to other threads
  pthread_mutex_unlock(&mutex);

  return NULL;
}

//  What is a race condition? 
//
//  A race condition occurs when a program depends on the 
//  timing of one or more events to function correctly.
//
//  A race condition typically occurs when multiple threads
//  access a shared variable (or state) at the same time.
//
//
//  What is a mutex?
//
//  A mutex is a synchronization primitive that enforces 
//  limits on access to a shared resource when we have 
//  multiple threads of execution.
//
//  
//
//  Race Condition Visualization
// 
//
//  Thread #1             Thread #2              Bank Balance
//     
//  Read Balance  <----------------------------------- 0
//  balance = 0 
//                        Read Balance  <------------- 0
//                        balance = 0
//
//  Deposit +300
//  balance = 300
//                        Deposit +200 
//                        balance  = 200
//
//  Write Balance  ----------------------------------> 300
//  balance = 300
//                        Write Balance  ------------> 200
//                        balance = 200
//
//
//
//  Mutex Version Execution Visualization
//
//
//
//  Thread #1             Thread #2              Bank Balance
//
//                        **  LOCK  **
//       
//  WAIT @ LOCK           Read Balance  <------------- 0
//       |                balance = 0
//       |
//       |                Deposit +200 
//       |                balance  = 200
//       |
//       |                Write Balance  ------------> 200
//       |                balance = 200
//       |
//   LOCK FREE            ** UNLOCK **
// 
//  **  LOCK  ** 
//
//  Read Balance  <----------------------------------- 200
//  balance = 0 
//
//  Deposit +300
//  balance = 500
//
//  Write Balance  ----------------------------------> 500
//  balance = 500
//
//  ** UNLOCK **
//