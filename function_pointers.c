/*******************************************************************************
*
* Program: Function Pointers Demonstration
* 
* Description: Examples of using function pointers (i.e. pointers to functions)
* in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=f_uWOWViYc0  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>

// prints int argument x
void function(int x) 
{ 
  printf("x: %d\n", x); 
}

// adds two double arguments and returns result
double add(double x, double y) { return x + y; }

// similar functions for subtract, multiply, divide operations
int subtract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { return x / y; }

// A function that *returns* a pointer to a function (specifically, a pointer
// to a function with two int parameters and an int returns value).
int (*select_operation())(int, int)
{
  // let the user select an option
  int option = 0;
  printf("Select An Operation: \n");
  printf("1) Subtract\n");
  printf("2) Multiply\n");
  printf("3) Divide\n");
  printf("Enter: ");
  scanf("%d", &option);
  
  // return a function pointer to subtract, multiply or divide (or NULL if
  // invalid input)
  if (option == 1) return subtract;
  else if (option == 2) return multiply;
  else if (option == 3) return divide;
  else return NULL;
}

// returns true if the temperature int value is below freezing in Celsius,
// and false otherwise
bool freeze_C(int temperature) {
  if (temperature <= 0) return true;
  else return false;
}

// returns true if the temperature int value is below freezing in Fahrenheit,
// and false otherwise
bool freeze_F(int temperature) {
  if (temperature <= 32) return true;
  else return false;
}

// Function parameter free_check is a function pointer, specically for a 
// function that with a single int parameter that returns a bool.  We call 
// this type of parameter a "callback function":
//   https://en.wikipedia.org/wiki/Callback_(computer_programming)
// The function is_freezing will use the function freeze_check to check if 
// the temperature is freezing.
void is_freezing( bool (*freeze_check)(int) ){
  
  // get a temperature value from the user
  int temperature = 0;
  printf("Enter Temperature: ");
  scanf("%d", &temperature);
  
  // use the provided freeze_check function to determine if it is freezing
  if (freeze_check(temperature)) printf("It's freezing!\n");
  else printf("It's NOT freezing!\n");
}

// Use function pointers with the above functions
int main()
{

  // ***** Example 1 - basic function pointer example *****

  // Declares a function pointer variable called function, that can point to 
  // a function with a single int parameter and a void return value
  void (*function_pointer)(int);

  // set function_pointer to point to the function called function
  function_pointer = &function;
  
  // de-reference the function_pointer to call the function called function with
  // the argument 4!
  (*function_pointer)(4);
  


  // ***** Example 2 - alternative syntax *****

  // add_pointer will be a pointer to a function that accepts to double
  // parameters and returns a double... set it to point to add, notice how we 
  // don't really need the & operator to give us the memory address of the add
  // function, it will actually work find without it!
  double (*add_pointer)(double, double) = add;

  // create two double variables
  double a = 20;
  double b = 30;
  
  // call the function pointed to be add_pointer by just using the regular 
  // function call syntax... i.e. de-referencing the pointer to the function as
  // we did in our first example is actually optional
  double result = add_pointer(a,b);

  // output the result of calling the add_pointer function (we will get 50!)
  printf("result: %f\n", result);



  // ***** Example 3 - array of pointers to functions *****
  
  // declare and initialize an *array* of pointers to functions, using [] to 
  // declare the array and the usual {,} array initalization syntax
  int (*array[])(int, int) = {subtract, multiply, divide};
  
  // call the function at index 1 in the array (i.e. multiply)
  int product = (*array[1])(3,15);
  
  // output the result of calling the function
  printf("product: %d\n", product);



  // ***** Example 4 - function that returns a pointer to a function  *****
  
  // Call select_operation to ask the user for the operation they wish to 
  // run and return a pointer to the function to carry it out (either 
  // subtract, multiply, or divide).
  int (*operation)(int,int) = select_operation();
  
  // output the return value from calling the function pointed to be operation
  printf("answer: %d\n", operation(20,5));
  

  // ***** Example 5 - function pointer as an argument (callback function) *****

  // pass the freeze_C function as an argument to is_freezing
  printf("\nCelsius...\n\n");
  is_freezing(freeze_C);
  is_freezing(freeze_C);
  
  // pass the freeze_F function as an argument to is_freezing
  printf("\nFahrenheit...\n\n");
  is_freezing(freeze_F);
  is_freezing(freeze_F);

  printf("\n");

  return 0;
}