/*******************************************************************************
*
* Program: Interleave Switch Cases Within Other Control Structures
* 
* Description: Example of how we can interleave switch cases within other 
* control structures in C.  This feature should very rarely be used because it 
* makes the code too difficult to understand, though it does have the odd 
* practical use case such as a Duff's Device: 
*   https://en.wikipedia.org/wiki/Duff%27s_device
* The feature is so seldom used that it is not widely known and in this sense
* is a "coding trick" or "hidden feature" of the language.
*
* YouTube Lesson: https://www.youtube.com/watch?v=hzrnBgmRx-U 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main()
{
  // We can use option to try out the different cases of the switch.  Try 
  // changing option to 1,2,3 and see the effect.
  int option = 3;
  
  switch (option)
  {
    // If option is 1, we'll output 'Option 1 Selected', the if statement 
    // condition will be true, and we'll output 'Option 2 Selected' in the
    // if statement body.  There is no break to prevent "falling through"
    // into case 2 here, or case 3, and so execution will continue down to
    // the loop below.
    case 1:
      printf("Option 1 Selected.\n");
      
      if (option >= 1)
      {
        
      // Even though case 2 is INSIDE this if statement body which is itself 
      // "inside" case 1 (in some sense), this is allowed.  If option == 2 
      // then the switch statement will jump execution down to case 2, and 
      // execution will begin here right inside the if-statement body.  
      case 2:
        printf("Option 2 Selected.\n");
        
      }
      
      while (option <= 10)
      {

      // We can also interlace a switch case inside the body of a loop as we 
      // do here... if option == 3 then the switch statement will jump execution
      // down to case 3, and execution will begin in the middle of the loop!
      case 3:
        printf("option: %d\n", option);
        option++;
      }
      
  }
  
  return 0;
}