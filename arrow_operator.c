/*******************************************************************************
*
* Program: Arrow Operator For Pointers To Structs
* 
* Description: Example of how to use the arrow operator to access the member
* variables of a struct when we have a pointer to a struct in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=w5XM1N7hLgc 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// define a simple struct, for 2d points
typedef struct {
  int x;
  int y;
} Point;

int main(void)
{
  // declare a regular struct variable
  Point p1;
  
  // use the dot notation to set member variable values
  p1.x = 3;
  p1.y = 2;
  
  // we can use the dot notation to access member variable values in expressions
  // or function arguments 
  printf("p1: (%d,%d)\n", p1.x, p1.y);
  
  // declare a pointer to a struct (of type Point)
  Point *p2;

  // have p2 point to p1, i.e. store the memory address of p1
  p2 = &p1;
  
  // we can use the -> arrow notation to access the member variables of a struct
  // when we have a pointer to a struct
  p2->x = 5;
  p2->y = 4;
  
  // we can use the arrow operator in expressions and function calls as well, 
  // also note that because p2 points to p1 when we access member variables 
  // x and y we are actually accessing p1's member variables
  printf("p1: (%d,%d)\n", p1.x, p1.y);
  printf("p2: (%d,%d)\n", p2->x, p2->y);
 
  // dynamically allocate space for a Pointer struct and have p3 point to it
  Point *p3;
  p3 = malloc(sizeof(Point));
  
  // we can access the member variables of this dynamically allocated struct 
  // using arrow notation as well
  p3->x = 5;
  p3->y = 10;
  
  // output p3 
  printf("p3: (%d,%d)\n", p3->x, p3->y);

  // As a less readable alternative to the arrow operator, we could first 
  // dereference the pointer with the * operator and then us the . operator, 
  // but we *must* have the () to ensure he deference operation occurs first.
  (*p3).x = 2;
  (*p3).y = 4;
  
  // output p3 using this dereference-followed-by-dot-operator approach
  printf("p3: (%d,%d)\n", (*p3).x, (*p3).y);

  return 0;
}