/*******************************************************************************
*
* Program: Pointer Declarations: int* p vs. int *p 
* 
* Description: Example code for a discussion about pointer declarations in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=H5MlTh5cBOg
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main()
{
  // Declare an int variable num and assign it the value 5
  int num = 5;
  
  // ALL of these approaches will declare a variable of type pointer to an int!
  //
  // int *p1;
  // int* p2;
  // int * p3;
  //
  // The second approach might seem the "best" approach as it clearly expresses
  // the type "pointer to an int" with int* all together.
  //


  // We might think that the below statement will declare two pointer to int 
  // variables p1 and p2.  But it doesn't.  Only p1 will be a pointer to an 
  // int, p2 will be an int variable!
  //
  int* p1, p2;
  
  // We could declare the variables like this to declare two pointer to an int 
  // variables.  That's why using the "int *p1;" approach might make more sense,
  // though opinions may differ.
  //
  // int *p1, *p2;
  
  // Assign to p1 and p2 the memory address of num, i.e. have them point to num
  p1 = &num;
  p2 = &num;
  
  // Output the size of a pointer to an int and the size of an int, in bytes.
  // On the machine this code was written on the size of a pointer to an int 
  // was 8 bytes and the size of an int was 4 bytes.
  printf("sizeof(int*): %d\n", sizeof(int *));
  printf("sizeof(int): %d\n", sizeof(int));
  
  // If we output the size in bytes of p1 and p2, we'll find that p1 is the 
  // same size as a pointer to an int because it IS a pointer to an int.  And 
  // p2 will match the size of an int because it IS an int.
  printf("sizeof(p1): %d\n", sizeof(p1));
  printf("sizeof(p2): %d\n", sizeof(p2));
  
  // We can de-reference p1 to output the value 5, but we'll get an error if we
  // try to de-reference p2 because it's not a pointer to an int... it's an int!
  printf("*p1: %d\n", *p1);
  printf("*p2: %d\n", *p2);
  
  return 0;
}