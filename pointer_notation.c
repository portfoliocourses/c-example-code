/*******************************************************************************
*
* Program: Pointer notation
* 
* Description: Examples of pointer notation and arithmetic in contrast to array 
* notation in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=hWGYBMO553A
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

void print(int *a);

int main(void) 
{
  // 'a' stores a memory address to the memory on the stack that stores these 3 
  // values one after the other in memory
  int a[3] = {1,2,3};
  int *b;
  
  // 'a' decays to a pointer and its memory address is stored in b
  b = a;

  //' 'b and 'a' both store the same memory address
  printf("b: %p\na: %p\n", b, a);

  // we can access a using array notation as normal
  printf("a[1] = %d\n", a[1]);

  // we can also pass the array to a function that accepts a pointer to an int 
  // as a parameter... again 'a' decays to a pointer (memory address) when we do
  print(a);
  
  // we can access b using array notation too! Ultimately the array notation is 
  // a way of requesting the value stored at a memory address, shifted over by 
  // the index given... so here we are saying "getting the value shifted one 
  // over from the memory address stored in b"
  printf("b[1] = %d\n", b[1]);

  // we can also access the values in the array pointed to by 'b' using pointer 
  // notation, in this case pointer arithmetic as we add 1 and 2 to b resulting 
  // in the pointer dereference operator * getting the value at the memory 
  // address of b, shifted over by 1 and 2 ints respectively in the last two 
  // cases here...
  printf("*b = %d\n", *b);
  printf("*(b + 1) = %d\n", *(b + 1));
  printf("*(b + 2) = %d\n", *(b + 2));
  
  // we can also access 'a' using pointer notation!  Again we say it decays to a
  // pointer and we can do pointer arithmetic with a as well
  printf("*a = %d\n", *a);
  printf("*(a + 1) = %d\n", *(a + 1));
  printf("*(a + 2) = %d\n", *(a + 2));
 
  // incrementing b will not add 1 to the memory address stored in b, instead 
  // it will shift b to store the next memory address over from where it 
  // currently points... so instead of pointing to 1 in the above array, b 
  // now points to 2!
  b++;
  printf("*b = %d\n", *b);

  // we can still use pointer arithmetic with this now altered pointer
  printf("*(b + 1) = %d\n", *(b + 1));

  // We might use pointer arithmetic when passing an array to a function, 
  // essentially passing only a certain portion of the array to the function.
  // Here we use pointer arithmetic to pass a pointer to the 2nd element in 
  // the array 'a', because once again a decays to a pointer (memory address 
  // of the first element of a) and we add 1 to it and the resulting 
  // memory address is the next element over in the array.
  //
  print(a + 1);

  // All of this might be the question as to whether arrays are really just 
  // pointers... we seem to be able to do everything we can with one to the 
  // other.  But we cannot assign to an array, the below code will cause a 
  // compilation error if we uncomment it!
  //
  // int c[3] = {2,4,5};
  // a = c;
  // a++;
  // printf("\n\na[1] = %d\n", a[1]);

  return 0;
}

// Even though it seems as if the function accepts a pointer... this is 
// functionally equivalent to if we had say int a[] as a parameter... we can 
// use array notation with 'a' to access it as an array as normal.
void print(int *a)
{
  printf("a[1] = %d\n", a[1]);
}
