/*******************************************************************************
*
* Program: iscntrl() Demonstration
* 
* Description: Example of using the iscntrl() function in C to check if a 
* character is a control character or not (where a control character is a 
* special character that does not occupy a printing position on the terminal).
*
* YouTube Lesson: https://www.youtube.com/watch?v=3qtxOcYtTtk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
  // Declare a test char variable c and assign it the new line which is
  // a control character.  Try setting c to different values and see the 
  // effect.  Control characters are special characters which do not occupy a 
  // printing position on the terminal. 
  //
  char c = '\n';
  
  // The iscntrl() function will return a non-zero integer (true) if it is 
  // passed a control character and zero (false) otherwise. 
  if (iscntrl(c))
  {
    printf("character is a control character.\n");
  }
  else
  {
    printf("character is not a control character.\n");
  }

  return 0;
}

//   Some control characters...
//
//   DEC  HEX  CHARACTER
//   0    0    NULL
//   1    1    START OF HEADING (SOH)
//   2    2    START OF TEXT (STX)
//   3    3    END OF TEXT (ETX)
//   4    4    END OF TRANSMISSION (EOT)
//   5    5    END OF QUERY (ENQ)
//   6    6    ACKNOWLEDGE (ACK)
//   7    7    BEEP (BEL)
//   8    8    BACKSPACE (BS)
//   9    9    HORIZONTAL TAB (HT)
//   10   A    LINE FEED (LF)
//   11   B    VERTICAL TAB (VT)
//   12   C    FF (FORM FEED)
//   13   D    CR (CARRIAGE RETURN)
//   14   E    SO (SHIFT OUT)
//   15   F    SI (SHIFT IN)
//   16   10   DATA LINK ESCAPE (DLE)
//   17   11   DEVICE CONTROL 1 (DC1)
//   18   12   DEVICE CONTROL 2 (DC2)
//   19   13   DEVICE CONTROL 3 (DC3)
//   20   14   DEVICE CONTROL 4 (DC4)
//   21   15   NEGATIVE ACKNOWLEDGEMENT (NAK)
//   22   16   SYNCHRONIZE (SYN)
//   23   17   END OF TRANSMISSION BLOCK (ETB)
//   24   18   CANCEL (CAN)
//   25   19   END OF MEDIUM (EM)
//   26   1A   SUBSTITUTE (SUB)
//   27   1B   ESCAPE (ESC)
//   28   1C   FILE SEPARATOR (FS) RIGHT ARROW
//   29   1D   GROUP SEPARATOR (GS) LEFT ARROW
//   30   1E   RECORD SEPARATOR (RS) UP ARROW
//   31   1F   UNIT SEPARATOR (US) DOWN ARROW
