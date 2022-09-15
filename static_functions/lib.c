// We implement our report_value() function in the .c file, but we also have a 
// static function print which helps to carry out the work of this library.  
// Making print() a static function will limit its visiblity (or 'scope') to 
// this file (or more accurately, "translation unit").  This means that the 
// rest of the program (aka "the outside world") CAN'T use the print function.
// This is a form of information hiding, where changes to print() will now 
// only require changes to this library because this is the only place it 
// can be used.  If print() were accessible everywhere in our program, and 
// we changed the way print() works, we may need to make changes all over 
// our program.  This library "hides" how printing works from the rest of 
// the program and exposes a more stable report_value() function that should
// not change as often as print().  So the static keyword allows us to implement
// information hiding in C, somewhat like private member functions in C++.
// We could also re-use the print() function name in other files as well as 
// its visibility is limited to this file, due to the static keyword.

#include <stdio.h> 

// Outputs the value some number of times
static void print(double value, int times)
{
  for (int i = 0; i < times; i++)
    printf("%.3f\n", value);
}

// Does some validation work before using the print function to print the value
void report_value(double value)
{
  if (value >= 1000)
    printf("Value out of range!\n");
  else 
    print(value,3);
}