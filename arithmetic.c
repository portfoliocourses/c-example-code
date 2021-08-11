/*******************************************************************************
*
* Program: Arithmetic operations
* 
* Description: Examples of arithmetic operations in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=R0qIYWo8igs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <math.h>

int main(void)
{
  int a = 5;
  int b = 2;

  // standard operations include addition, subtraction, multiplication, 
  // division and modulus
  printf("%d + %d = %d\n", a, b, a + b);
  printf("%d - %d = %d\n", a, b, a - b);
  printf("%d * %d = %d\n", a, b, a * b);
  printf("%d / %d = %d\n", a, b, a / b);
  printf("%d %% %d = %d\n", a, b, a % b);
 
  // increment and decrement examples
  a++;
  printf("a: %d\n", a);
  a--;
  printf("a: %d\n", a);

  // increment and decrement also come in prefix variants
  ++a;
  printf("a: %d\n", a);
 
  // postfix increment will first use the value of the variable in the 
  // expression and then increment the number
  printf("a++: %d\n", a++ );
  printf("a: %d\n", a );
  
  // prefix increment will FIRST increment a and then use its value in 
  // the expression
  printf("++a: %d\n", ++a );

  double x = 5.0;
  double y = 2.0;

  // operations in C behave differently depending on the type... notice how 
  // division behaves in this case
  printf("%f + %f = %f\n", x, y, x / y);

  // many operators we might expect to have are not included in the language 
  // itself, such as power, but we can include math.h or other libraries to 
  // use them
  double z = pow(x, y);

  printf("%f^%f = %f\n", x, y, z);

  return 0;
}


