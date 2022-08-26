/*******************************************************************************
*
* Program: Fill An Array With Unique Random Numbers
* 
* Description: Example of how to fill an array with unique random numbers in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=wnjYD_euSJQ 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

void fill_unique(int array[], int length, int min, int max);

int main(void)
{
  // Seed the random number using both the current time and process ID to 
  // ensure it is unique each time the program is executed, so that the 
  // random numbers are unique each time the program executes.
  srand( time(NULL) * getpid() );
  
  // Declare an array of 10 int values
  int a[10];
  
  // Fill the array with unique random values in the range 920-990
  fill_unique(a, 10, 920, 990);
  
  // Output the array elements to verify they are unique, random and in the 
  // desired range 920-990
  for (int i = 0; i < 10; i++)
    printf("a[%d] = %d\n", i, a[i]);
  
  return 0;
}

// Populates the array with the given length with random values in the range 
// min - max, including min and max as possible values
void fill_unique(int array[], int length, int min, int max)
{
  // Store each random number generated
  int new_random;

  // Helps to verify whether the random number generated is unique
  bool unique;
  
  // Loop over each index in the array with counter variable i to set each 
  // element in the array to a unique random integer
  for (int i = 0; i < length; i++)
  {
    // We randomly generate a number, and if it is not unique (i.e. if the 
    // number has already been generated and assigned to a previous array 
    // element), then we repeatedly attempt to generate the number again 
    // until a unique random number is found.
    do
    {
      // Generates a random number in the range min-max
      new_random = (rand() % (max - min + 1)) + min;
      
      // Assume the number is unique, but check all previously generated 
      // random numbers from index 0 ... i-1 in the array, and if the number 
      // is already in this portion of the array we know it is not unique.
      unique = true;
      for (int j = 0; j < i; j++)
        if (array[j] == new_random) unique = false;
    
    // Keep the loop going until we DO identify a unique random number
    }
    while (!unique);
    
    // When the do-while loop has completed we know that new_random will be set
    // to a new unique random value, and we assign this to the next array index
    // as given by the counter variable i.
    array[i] = new_random;
  } 
}