/*******************************************************************************
*
* Program: Function-like Preprocessor Macros
* 
* Description: Examples of using function-like preprocessor macros in C, also 
* known as parameterized macros or macros with arguments.
*
* YouTube Lesson: https://www.youtube.com/watch?v=4DS5E5tgxIA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// What we call "object-like macros" are often used to define constant values in
// a program, such as a maximum value or PI
#define MAX 20
#define PI 3.14

// Macros are really just a text-replacement operation done by the C compiler 
// as part of its first preprocessor phase (there are several more phases).  So
// for example we can replace the text "print" with a call to printf().
#define print printf("PRINT THIS!\n");

// We can also create "function-like macros" that accept and use parameters, 
// here we add 1 to a parameter x.  Really all that will occur is "text 
// replacement" though, so if we pass in the variable a, inc(a) will be 
// replaced with a + 1.  It's important that there is no space between the 
// macro name 'inc' and the beginning of the parameters (... otherwise we will 
// have an error as it appears to be an object-like macro.
#define inc(x) x + 1

// Macros can accept multiple parameters.  One benefit of using macros compared
// to regular C functions is that macros can be "generic", so for example this 
// macro will work with both ints and doubles as all that really occurs is 
// text replacement!
#define area(base,height) 0.5 * base * height

// We can use a macro as an argument to another macro, so for example with the 
// below function-like macro to find the min of two numbers, we could use it 
// like: min(3,min(1,2)).  We wrap the expression in () brackets to give it a 
// higher order of evaluation.  We do this because when the preprocessor 
// expands macros we may get large expressions as a result, and we want the 
// result of this macro to be evaluated FIRST before being used as part of a 
// larger expression in order to get the desired behaviour.
#define min(x,y) ((x < y) ? x : y)

// We can use the # operator, sometimes called the stringizer operator, to turn 
// any function-like macro argument into a string literal (e.g. s1).  It will 
// also concatenate the string with the adjacent string literal.  We can also 
// output a string using printf() in the usual way as we do with s2.
#define output(s1,s2) printf(#s1 " middle %s\n", s2);

// We can define a function-like macro across multiple lines by using ({ ... })
// and ending each line with the \ character.  Here we find the largest element
// in an array.  We use typeof() to find the type of elements in the array so 
// that we can keep the function generic, such that it will work with both ints
// and doubles for example.
#define find_max(array,length) ({ \
  typeof(array[0]) current_max = array[0]; \
  for (int i = 1; i < length; i++) \
    if (array[i] > current_max) \
      current_max = array[i]; \
  current_max; \
})

// Prints a number 3 times.  We make sure to evaluate the parameter using (num)
// before using the paramter, otherwise we may get unwanted behaviors if an 
// expression is passed as a parameter to the function-like macro and that 
// parameter is evaluated 3x (once inside each printf function call).
#define print_number_3x(num) ({ \
  int nume = (num); \
  printf("number: %d\n", nume); \
  printf("number: %d\n", nume); \
  printf("number: %d\n", nume); \
})

// Create a global variable number and a function which increments and returns
// the value of the number, such that we can demostrate a possible issue that 
// may occur when a function-like macro argument is an expression.
int number = 0;
int increment()
{
  number++;
  return number;
}

int main()
{
  // Print out the MAX constant value (i.e. object-like macro), the compiler 
  // will replace MAX with 20 during its first preprocessor phase, so the actual
  // line of code that is truly compiled will be printf("Max: %d\b", 20); 
  printf("Max: %d\n", MAX);
  
  // While it may seem unusual to have a line of code with no ; this will work
  // because print is a macro and this will be replaced with a function call 
  // to printf() as defined above.
  print
  
  // Test out the inc() function-like macro, the code 'a = inc(a);' will be 
  // replaced with the code 'a = a + 1;' and a will be incremented.
  int a = 2;
  a = inc(a);
  printf("a: %d\n", a);
  
  // Test out the area() function-like macro, the code 'area(base1,height1)'
  // will be replaced with the code '0.5 * base1 * height1' as per the macro
  // definition, and the area of the triangle will be calculated.
  int base1 = 20;
  int height1 = 20;
  int area1 = area(base1,height1);
  printf("area1: %d\n", area1);
  
  // We can also use the macro with double variables and unlike a regular C 
  // function it will work fine!  Because again text-replacement will occur, 
  // no function is ever truly called.  This is an advantage of using 
  // function-like macros compared to regular C functions.  Another advantage
  // is a lack of overhead, i.e. extra work, from having to call a function as 
  // the computation is done with an inline expression, in this case 
  // '0.5 * base2 * height2', as opposed to having to call a function which 
  // involves creating and assigning values to local parameter variables 
  // and other work.
  double base2 = 10.5;
  double height2 = 5.2;
  double area2 = area(base2, height2);
  printf("area2: %f\n", area2);
  
  // Use the result of a macro as an argument of another macro.  You can see 
  // the expansion of macros by the preprocessor using the -E option in gcc,
  // so for example: 'gcc -E -o function_like_macros function_like_macros.c'.
  // The below statement will expand into a lengthy expression involving 
  // multiple ternary operators.  It is essential that we wrapped the macro 
  // expression in ( ) when defining min to ensure that the resulting 
  // expressions are evaluated in the desired order, if we did not do this 
  // we may get bugs as a result. 
  int min_num = min(min(8,1),min(6,3));
  printf("min_num: %d\n", min_num);
  
  // The # operator in the output() function-like macro will turn "test1" (or 
  // any other parameter) into a string literal. 
  char string[] = "test2";
  output(test1,string);
  
  // Test the find_max() function-like macro with an int array.
  int int_array[] = {3,5,2,1,8,3,2};
  int max_int = find_max(int_array,7);
  printf("max_int: %d\n", max_int);
  
  // Test the find_max() function-like macro with a double array.
  double dbl_array[] = {9.3, 2.4, 10.2, 10.9};
  double max_dbl = find_max(dbl_array, 4);
  printf("max_dbl: %f\n", max_dbl);
  
  // With a regular function in C, if we were to pass in num = increment() as an
  // argument, the expression would first evaluate.  The increment() function 
  // call would increment the global number variable to 1 and then return it, 
  // this value would be assigned to num, and the entire assignment = operator 
  // would evaluate to '1' which would then be passed to the function.  But 
  // remember that function-like macros are essentially text replacement 
  // operations, and we will not get this behaviour! 
  //
  // Instead the expression num = increment() will be used in function-like 
  // macro, potentially evaluating the expression multiple times as it is used 
  // in the macro (e.g. evaluating 3x in each call to printf() in the 
  // print_number_3x macro).  If this were to occur, we could print out the 
  // numbers 1,2,3 instead of the number 1 three times!
  //
  // Because we evalute the parameter 'num = increment()' in the print_number_3x
  // function-like macro *before* we use it in the macro, we will get the number
  // 1 output three times as desired.
  int num;
  print_number_3x( num = increment() );

  return 0;
}