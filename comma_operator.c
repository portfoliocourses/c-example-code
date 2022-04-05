/*******************************************************************************
*
* Program: Comma Operator Demonstration
* 
* Description: Examples of using the comma operator in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=N9fRUhT3e1M  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <errno.h>

// here commas are used as a separator, not an operator, to separate the 
// parameters of the function
int function(int a, int b, int c) { return a + b + c; }

// a function that returns an error status AND sets the global errno to a 
// specific value for the type of error that took place
int check_value(int value)
{
  // do some work

  // use comma operator to set errno to an invalid argument error code AND 
  // return a more general "-1" error status to the calling environments
  if (value > 1000) return (errno = EINVAL, -1);

  return 0;
}

int main(void)
{
  // declaring variables, initializing arrays, and calling functions with 
  // multiple arguments all involve using the comma as a *separator* not 
  // an operator
  /*
  int a = 0, b = 0, c = 0;
  int array[] = {1,2,3,4,5};

  function(3,4,5);
  */

  int a = 1;
  int b = 2;
  int c;
  
  // Here we use the comma as an operator, it separates expressions somewhat 
  // like ; separates statements... the expression 'a' will be evaluated (to 1)
  // but than discarded, and then the expression 'b' will be evaluated (to 2) 
  // and then returned, so c will be set to 2.  
  c = (a,b);
  
  // the comma has the lowest precedence of all operators in C, so the below
  // code will actually assign 1 to c as the c = a assignment operator will 
  // evaluate first, leaving the expression b to evaluate to 2 afterwards
  // c = a, b;
  
  // print out c and it will be 2
  printf("c: %d\n", c);
  
  
  int m = 4;
  int n;
  
  // the expressions will evaluate sequentially, so before the 2nd expression 
  // m * 2 executes, the first m += 1 will have executed and m will be 5, thus 
  // m * 2 will evaluate to 10 which will be assigned to n
  n = (m += 1, m * 2);
  
  // m will be 5, n will be 10
  printf("m: %d\nn: %d\n", m, n);

  int number = 5;
  int max = 10;
  int r1, r2;
  
  // we can use the comma operator to shorten our code, here we do in 2 lines 
  // what could take 10
  if (number < max) r1 = 1, r2 = 2;
  else r1 = 3, r2 = 4;
   
  // alternative longer way of conducting the same work as above
  /*
  if (number < max)
  {
    r1 = 1;
    r2 = 2;
  }
  else 
  {
    r1 = 3;
    r2 = 4;
  }
  */
  
  // r1 is 1 and r2 is 2 as expected
  printf("r1: %d\nr2: %d\n", r1, r2);
  

  // the comma operator can be useful when initializing variables as part of 
  // a for loop, when the initialization of one variable depends on the 
  // initialization of the other
  char *s1 = "a string to print from the middle";
  int length, i;

  // both length and the counter variable i need to be initialized, but i's 
  // initial value depends on length... so first we initialize length, then 
  // we initialize i using length
  for (length = strlen(s1), i = length / 2; i < length; i++)
    printf("%c", s1[i]);
  printf("\n");

 
  // we can do something similar in an if-statement condition, first assigning 
  // to a variable the result of a function call (or some other expression) and 
  // then using that variable as part of a condition... remember that the 2nd 
  // expression's result is what is returned, so the condition of the if 
  // statement is really going to be length < 20
  char *s2 = "some string";
  if (length = strlen(s2), length < 20)
  {
    for (int i = 0; i < length; i++) printf("%c", s2[i]);
    printf("\n");
  }

  // test our function that both returns an 'error status value' AND sets the 
  // errno global variable in a single return statement
  int return_value = check_value(1001);
  printf("return value: %d\n", return_value);
  if (errno == EINVAL) printf("errno set by check_value\n");

  return 0;
}