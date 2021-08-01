/*******************************************************************************
*
* Program: enum tutorial
* 
* Description: Example of using enum in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=vr7qCQLrUt8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// we can use enum to create a 'new type' Day that has the possible values 
// Monday - Sunday.  We can then use Monday, Tuesday, etc, in our code improving
// its readability.  Really what happens is that the compiler assigns values 
// starting from 0, incrementing by 1 to teach enum value... so Monday=0, 
// Tuesday=1, Wednesday=3, etc.  We can override this behaviour and set our 
// own values as we've done with Tuesday and Friday below.  In this sense 
// enums really aren't so much a new type as they are a way of defining a 
// collection of related constant values.  :-)
enum Day { Monday, Tuesday = 9, Wednesday, Thursday, Friday = 20, 
          Saturday, Sunday};

// We can use typedef to give a type alies to an enum... this way we can declare
// buttons using "Button x;" instead of "enum button x;", which is a bit nicer.
typedef enum button { ON, OFF } Button;

// enums can be function return types and parameters
Button press(Button current);
void print_button(Button current);

int main(void)
{
  // we can declare variables of type Day and assign the values we've created
  enum Day today = Tuesday;
  enum Day yesterday = Monday;
  enum Day tomorrow = Wednesday;

  // we can print out enums with %d as the placeholder as they are really int
  // values in practice
  printf("Yesterday: %d\n", yesterday);
  printf("Today: %d\n", today);
  printf("Tomorrow: %d\n", tomorrow);
  printf("Friday: %d\n", Friday);

  // declare and initialize a Button
  Button power = ON;

  // call our functions to work with Buttons
  print_button(power);
  power = press(power);
  print_button(power);
  power = press(power);
  power = press(power);
  print_button(power);

  return 0;
}

// flips the state of a button by returning the opposite of its current value
Button press(Button current)
{
  if (current == ON) return OFF;
  else return ON;
}

// does a "pretty print" of a button... prints a string ON or string OFF
void print_button(Button current)
{
  if (current == ON) printf("ON\n");
  else if (current == OFF) printf("OFF\n");
}
