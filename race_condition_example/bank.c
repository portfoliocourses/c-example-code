// A simple Bank account function library that allows us to read and write 
// a bank account balance.

// We'll include unistd.h so we can use the usleep() function to simulate 
// a delay in reading and writing the balance due to network traffic.  This is
// the sort of issue that can cause race conditions in the "real world".
#include <unistd.h>

// the initial balance is 0
int balance = 0;

// returns the balance (after a simulated 1/4 seond delay)
int read_balance()
{
  usleep(250000);
  return balance;
}

// write the new balance (after as simulated 1/4 second delay)
void write_balance(int new_balance)
{
  usleep(250000);
  balance = new_balance;
}