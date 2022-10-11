/*******************************************************************************
*
* Program: How To Return A String From A Function
*
* Description: Examples of different methods for returning a string from a
* function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=033DXBYql8w 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*******************************************************************************
*
* Methods which are NOT recommended:
*
* 1) Using a global variable to "return" a string by storing the string into the
*    global char array which can then be accessed by the calling function.
*
*   - Using global state via global variables often results in code that is more
*     difficult to understand, trace and debug, i.e. spahgetti code.
*
*   - The memory will be put aside for the global char array whether we are
*     using it or not, taking up space.
*
* 2) Using a static local char array in the function, then storing the string
*    to be returned into this char array, and then returning a pointer to
*    this char array (which will continue to exist even after the function
*    returns because it is static).
*
*   - Like a global variable, the memory will be put aside for the char array
*     whether we are using it or not, taking up space!
*
*******************************************************************************/

// Method 1: Global char array

// We could create a global char array that all functions have access to
char global_array[256];

// A function could then "return" a string by storing it in the global char
// array, the calling function could then acces the global char array to
// retrieve it.
void bad_global_method()
{
  strcpy(global_array, "a string to return");
}

// Method 2: Static local char array

// A function could have a static local char array, which would have a lifetime
// beyond when the function returns (i.e. the duration of the program
// execution).  The function could store a string into this char array, and then
// return a pointer to this char array to the calling function, which could then
// access the string in the char array via this pointer.
char *bad_static_method()
{
  static char static_array[256];
  strcpy(static_array, "a string to return");
  return static_array;
}


// See the decriptions of each method below the main function
const char *method1();
char *method2();
void method3(char *s);
char *method4();

int main(int argc, char *argv[])
{
  // method1() will return a const char pointer, which means the compiler will
  // give us a warning unless the variable we store the pointer into is also
  // a const char pointer.  We cannot modify the string that method1() will
  // return, so it's important that this is the case.
  const char *str1 = method1();

  // We can output the string...
  printf("str1: %s\n", str1);

  // But we can't modify the string, as method1() returns a pointer to a string
  // literal, doing so would cause the program to crash.  Because the pointer
  // is type const char pointer, the compiler won't even allow the program
  // to compile with the below statement uncommented.
  // str1[0] = 'a';


  // method2() returns a pointer to a char array that is a local variable of
  // the function, and so by the time the function returns the char array
  // will no longer exist, and str2 will be a pointer to a string that
  // no longer exists. If we try to output the string, we'll get garbage values.
  char *str2 = method2();
  printf("str2: %s\n", str2);


  // method3() will use a the pointer (memory address) of the char array it
  // is passed, and store a string there.  Because the ret char array is local
  // to the main function, it will still exist even after method3() returns,
  // at which point the calling function (in this case main) can do whatever
  // it wants with the string.  It's improtant
  char ret[256];
  method3(ret);
  printf("ret: %s\n", ret);


  // method4() will return a pointer to dynamically allocated memory where the
  // string is stored.  The function allocates space for the string, stores the
  // string into that space, and then returns a pointer to that space.  When
  // using this technique, the dynamically allocated memory will need to be
  // freed at some later point in order to ensure that a memory leak does
  // not occur, which is a potential drawback of this technique.
  char *dynamic = method4();
  printf("dynamic: %s\n", dynamic);
  free(dynamic);

  return 0;
}

// We can return a pointer to a string literal.  A string literal like "string"
// below is immutable and cannot be modified, so we make the return type of the
// function a const char * to make this clear and help enforce this.  This
// technique would be OK if we're sure we would never want to modify the
// string being returned.
const char *method1()
{
  return "string";
}

// This technique WILL NOT WORK.  The char array try[] is LOCAL to the function
// method2(). But it's not static, so it's lifetime will be until the function
// returns, at which point it will cease to exist.  So when we return a pointer
// to the char array with "return try" (i.e. return the memory address of the
// first char in the array), the calling function won't be able to use this to
// access the char array because it will no longer exist when the function
// returns.  This technique is highlighted only because it will NOT work but
// a new C programmer may think that it may work.
char *method2()
{
  char try[] = "try";
  return try;
}

// This technique uses "pass by reference" (aka "pass by pointer").  The
// function accepts as an argument a pointer to a string, and the calling
// function can pass as an argument the memory address of a char array on
// the stack (or technically, a char array on the heap as well allocated with
// dynamically allocated memory).  The function can then copy the string to be
// "returned" into this char array by using this pointer.  The calling function
// will have direct acces then to the string using the char array it provided
// a pointer to as an argument to this function.  If we use this technique
// it's important that the char array used as an argument is large enough to
// store the string.  We may want to set a maximum size for the string that
// may be stored into the char array, so that as long as the char array is
// large enough there will be no issue.  We could also have an additional
// function parameter that specifies the size of the char array, so that the
// function could ensure that it does not copy a string large than this into
// the char array.
void method3(char *s)
{
  strcpy(s, "method3 string");
}

// This technique uses dynamically allocated memory.  The function allocates
// space for a block of memory on the heap using malloc, and maintains a
// pointer to this space.  A string can then be stored into this space, and the
// pointer can be returned.  Unlike variables on the stack, data on the heap
// will persist until we free it.  So the string will still exist when the
// function returns (though it will be the job of the calling function, or some
// other function in our code, to free this space to prevent a memory leak).
char *method4()
{
  char *string = malloc(8);
  strcpy(string, "dynamic");
  return string;
}