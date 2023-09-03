/*******************************************************************************
*
* Program: Countdown Timer
* 
* Description: A countdown timer program using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=dG1HBSArgjM 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <time.h>

int main(void)
{ 
  // Stores the total number of seconds remaining to countdown
  int seconds = 0;

  // Prompt the user for the total number of seconds to countdown and store
  // the number into the variable seconds
  printf("Seconds: ");
  scanf("%d", &seconds);

  // Continue the loop so long as there are seconds remaining, the loop 
  // will output the time remaining and pause for a second each time...
  while (seconds > 0)
  {
    // We can output the countdown in format hh:mm:ss where hh, mm and ss are 
    // the number of hours, minutes and seconds remaining.
    // 
    // There are 3600 seconds in an hour so dividing seconds by 3600 gives us
    // the number of hours remaining.
    int h = seconds / 3600;

    // seconds % 3600 will give us the number of seconds remaining after 
    // accounting for the number of hours because the modulus operator % 
    // gives us the remainder of a division operation... we divide THIS 
    // number by 60 to give us the number of minutes remaining
    int m = (seconds % 3600) / 60;

    // Finally seconds % 60 will give us the number of seconds remaining after 
    // accounting for the number of hours and minutes
    int s = seconds % 60;
  
   // Output the countdown in the format hh:mm:ss with leading 0s, we use 
   // carriage return \r to return the cursor to the current line after each
   // printf() call so that the timer appears on the same line for each 
   // second that is counted down.
    printf("\r%02d:%02d:%02d", h, m, s);

    // If we just want to output the total number of seconds and not in the 
    // format of hours:minutes:seconds we could ouput this instead...
    // printf("\r%04d\n", seconds);
    
    // Because the call to printf() does not ouput a \n newline the stdout 
    // buffer will not automatically flush and cause the time to output, 
    // so we flush it 'manually' using fflush(stdout)
    fflush(stdout);
   
    // Get the current number of clock ticks that have occurred since the 
    // program started running with clock() and add the number of clock tics
    // that occur in one second, store the result into stop.
    clock_t stop = clock() + CLOCKS_PER_SEC;

    // When clock() DOES return the number of clock tics greater than or 
    // equal to the expected number one second in the future, stop this 
    // loop.  This loop will thus cause the program to pause for one second. 
    while (clock() < stop) { }
   
    // Decrement seconds as another second has elapsed
    seconds--;
  } 
  
  // Output time's up when the timer reaches zero
  printf("\rTime's up!\n");

  return 0;
}