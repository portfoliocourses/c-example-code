/*******************************************************************************
*
* Program: Race Condition Example
* 
* Description: Example of a race condition in C.  We create a small library 
* to simulate the management of a bank account balance, e.g. ATM machines 
* accessing a central bank server to update a balance after a deposit is made 
* locally.  We demonstrate how statements may interleave when multiple deposit
* functions are run at the same time, cause a race condition and resulting 
* bug to occur.
*
* YouTube Lesson: https://www.youtube.com/watch?v=K1aoimUYTK8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <pthread.h>
#include "bank.h"

void* deposit(void *amount);

int main()
{
  // output the balance before the deposits
  int before = read_balance();
  printf("Before: %d\n", before);
  
  // we'll create two threads to conduct a deposit using the deposit function
  pthread_t thread1;
  pthread_t thread2;
  
  // the deposit amounts... the correct total afterwards should be 500
  int deposit1 = 300;
  int deposit2 = 200;
  
  // create threads to run the deposit function with these deposit amounts
  pthread_create(&thread1, NULL, deposit, (void*) &deposit1);
  pthread_create(&thread2, NULL, deposit, (void*) &deposit2);
  
  // join the threads
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  
  // output the balance after the deposits
  int after = read_balance();
  printf("After: %d\n", after);

  return 0;
}

// carry out a deposit using the bank library (note that the pthread library 
// expects our function to return a void* and accept a void* as an argument)
void* deposit(void *amount)
{
  // retrieve the bank balance
  int account_balance = read_balance();
  
  // make the update locally
  account_balance += *((int *) amount); 
  
  // write the new bank balance
  write_balance(account_balance);

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

//  Visualization of the above program's execution.  When the two deposit 
//  functions run at the same time, the execution of statements over time
//  may interleave (and our simulated "network delay" further assures this),
//  causing a race condition to occur when they access the same shared state.
//  See how both threads access the balance, update the balance, and write 
//  the balance in such a way as to result in an incorrect balance!  
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