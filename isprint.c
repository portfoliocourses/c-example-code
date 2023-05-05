/*******************************************************************************
*
* Program: isprint() Demonstration
* 
* Description: Example of using the isprint() function in C to check if a 
* character is printable or not (where a non-printable character is a control
* character).
*
* YouTube Lesson: https://www.youtube.com/watch?v=5i09lKLnLAQ 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
  // Declare a test char variable c and assign it the null terminator which is
  // a non-printable character.  Try setting c to different values and see the 
  // effect.  Printable characters include letters, digits and symbols, they 
  // are characters which occupy a printing position on the terminal.  
  // Non-printable characters are also known as control characters, they are 
  // characters which do not occupy a printing position on the terminal. 
  // Examples of each are provided in comments below the main function.
  //
  char c = '\0';
  
  printf("c: '%c'\n", c);

  // The isprint() function will return a non-zero integer (true) if it is 
  // passed a printable character and zero (false) otherwise. 
  if (isprint(c))
  {
    printf("character is printable.\n");
  }
  else
  {
    printf("character is not printable.\n");
  }

  return 0;
}

//   Printable characters...
//
//   ! " # $ % & ' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9
//   : ; < = > ? @ A B C D E F G H I J K L M N O P Q R S
//   T U V W X Y Z [ \ ] ^ _ ` a b c d e f g h i j k l m
//   n o p q r s t u v w x y z { | } ~
//
//
//   Non-printable characters...
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
