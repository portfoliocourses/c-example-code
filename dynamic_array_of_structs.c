/*******************************************************************************
*
* Program: Dynamically Allocate An Array Of Structs
*
* Description: Examples of how to dynamically allocate an array of structs in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=lq8tJS3g6tY
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct for representing a point, the description member is expected to
// point to dynamically allocated memory where a string will be stored.
typedef struct {
  int x;
  int y;
  char *description;
} Point;

int main(int argc, char *argv[])
{
  // Declare a Point struct on the stack
  Point p1;

  // Initialize the members using the dot operator
  p1.x = 5;
  p1.y = 2;

  // Output the members
  printf("(%d, %d)\n", p1.x, p1.y);


  // Declare a pointer to a Point struct that will store the memory address
  // of a Point struct on the heap.  malloc() will allocate enough space in
  // bytes on the heap for the Point struct, by using sizeof(Point) we get
  // the size in bytes to store a Point struct and pass it to malloc to
  // ensure it allocates this amount of space.  malloc() will return the memory
  // address of this block of memory, and we store it into the pointer
  // variable p2.
  Point *p2 = malloc(sizeof(Point));

  // We can set the struct members of the struct on the heap either by
  // dereferencing the pointer and then using the dot operator, or by using
  // the arrow operator.
  (*p2).x = 6;
  p2->y = 10;

  // Output the members
  printf("(%d, %d)\n", (*p2).x, p2->y);

  // Free the dynamically allocated memory to make it available again and
  // to prevent a memory leak.
  free(p2);


  /****************************************************************************
      Example of dynamically allocating space for an array of structs and then
      using realloc() to increase the length of the array.
  ****************************************************************************/

  // Declare and initialize a length variable to keep track of the length of
  // the array
  int length = 3;

  // array is a pointer to a Point struct.  This time when we call malloc() and
  // provide the number of bytes to allocate as an argument, we multiply
  // sizeof(Point) (which is the size in bytes to store a Point struct) by the
  // length of our array (i.e. the number of Point structs to be stored).  This
  // will give us enough space to store the array of structs, and malloc() will
  // return the memory address of the first Point struct which we store
  // into array.
  Point *array = malloc(sizeof(Point) * length);

  // We can access and set the members of each struct in the array with this
  // syntax, here we set the members of the first struct in the array.
  array[0].x = 1;
  array[0].y = 1;

  // Setting the members of the second struct in the array
  array[1].x = 2;
  array[1].y = 2;

  // Setting the members of the third struct in the array
  array[2].x = 3;
  (*(array + 2)).y = 3;

  // We might be surprised that we are using the . dot operator to access the
  // struct members, given in the above example where we had a pointer to a
  // struct (p2) we either had to dereference the pointer THEN use the . dot
  // operator OR we had to use the arrow operator.  But remember that the
  // syntax...
  //
  // array[2].y = 3;
  //
  // ...is acutally the same as this, where we use pointer arimthetic to get
  // the memory address of the struct "two over" from where array is pointing
  // (i.e. the 3rd struct in the array), and then dereference the pointer to
  // access the struct:
  //
  // (*(array + 2)).y = 3;
  //
  // Using the array index notation array[2] is effectively like using a
  // dereferenced pointer to the struct.  We use pointer arimthetic to access
  // the struct in the above example for the y member of the 3rd struct in
  // the array.

  // Output the values of the members of the elements of the array...
  printf("\n");
  printf("Array...\n");
  for (int i = 0; i < length; i++)
  {
    printf("(%d, %d)\n", array[i].x, array[i].y);
  }
  printf("\n");

  // One of the key benefits of using dynamically allocated memory is that we
  // can reallocate blocks of memory to modify their size, for example by
  // increasing the size of the array by 1.  Let's start by setting length to
  // 4 to keep track of the new array length.
  length = 4;

  // Then we call realloc() to allocate space for this larger block of memory
  // to store the larger array.  The 2nd argument to realloc() is the size of
  // the new block of memory.  We multiply the new length of the array by the
  // size in bytes that it takes to store a Point struct as given by
  // sizeof(Point) to get the total number of bytes required.  We pass as a
  // first argument to realloc() the pointer (memory address) of the block
  // of memory that we wish to reallocate.  Sometimes the block of memory will
  // be increased in size at its existing location in memory, in which case
  // realloc() will return the same pointer (memory address) which we then store
  // into array.  It's possible that the block of memory that's allocated cannot
  // be expanding at its existing location in memory (perhaps it would require
  // overwriting nearby memory that is not available).  In this case, realloc()
  // may move the block of memory to a new location in memory, in which case it
  // will return this new pointer (memory address) and we will store this into
  // array to ensure that array continues to point to our dynamically allocated
  // array on the heap.
  array = realloc(array, sizeof(Point) * length);

  // After increasing the size of the array, it will have a 4th element, and
  // we can set the members of that element
  array[3].x = 4;
  array[3].y = 4;

  // Output the values of the members of the elements of the array that is
  // now one element larger so we can see the difference
  printf("\n");
  printf("Array...\n");
  for (int i = 0; i < length; i++)
    printf("(%d, %d)\n", array[i].x, array[i].y);
  printf("\n");

  // Free the dynamically allocated array to make the memory avaiable again
  // and to prevent a memory leak.
  free(array);


  /****************************************************************************
      Example of dynamically allocating space for an array of structs, where
      the struct members themselves contain pointers to dynamically allocated
      memory.  This example is intended to illustrate that we need to free
      the dynamically allocated memory for each of these struct member pointers,
      otherwise we will have a memory leak.  To test out this example, wrap the
      above example in multiline comments and then uncomment the code below.
  ****************************************************************************/

  /*

  // Declare and initialize a variable to keep track of the length of the
  // dynamically allocated array.  Allocate space for an array with this
  // length on the heap, using the same technique as previously outlined in
  // the above example.
  int length = 3;
  Point *array = malloc(sizeof(Point) * length);

  // Initialize the x and y members of the first struct in the array
  array[0].x = 1;
  array[0].y = 1;

  // Dynamically allocate space for a char array of 10 characters using
  // malloc() and have description store the pointer (memory address) for this
  // dynamically allocate char array.  Note that a char = 1 byte on virtually
  // all systems, so we can just pass 10 directly instead of using sizeof(char).
  // Technically malloc doesn't allocate space for a number of bytes, it
  // actually allocates space for a "number of char sized units", so even if
  // a char wasn't 1 byte this would work!
  array[0].description = malloc(10);

  // Use strcpy() to store a string into the dynamically allocated char array
  // that description points to
  strcpy(array[0].description, "point 1");

  // Do the same as the above for the 2nd struct in the array
  array[1].x = 2;
  array[1].y = 2;
  array[1].description = malloc(10);
  strcpy(array[1].description, "point 2");

  // And again do the same as the above for the 3rd struct in the array
  array[2].x = 3;
  (*(array + 2)).y = 3;
  array[2].description = malloc(10);
  strcpy(array[2].description, "point 3");

  // Output the values of the members of the structs in the array, including
  // the description string.
  printf("\n");
  printf("Array...\n");
  for (int i = 0; i < length; i++)
  {
    printf("(%d, %d)", array[i].x, array[i].y);
    printf(" - %s\n", array[i].description);
  }
  printf("\n");

  // We cannot JUST use free(array) to free the dynamically allocated memory
  // in this case, because the structs THEMSELVES contain pointers to
  // dynamically allocated memory.  We need to free THIS dynamically allocated
  // memory as well, and we do so by looping through the array elements and
  // freeing the block of memory allocated for each description.
  for (int i = 0; i < length; i++)
    free(array[i].description);

  // We can then free the block of memory for our array of structs
  free(array);

  */

  return 0;
}
