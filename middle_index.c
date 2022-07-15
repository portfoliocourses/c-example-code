/*******************************************************************************
*
* Program: Find Middle Index Without Integer Overflow
* 
* Description: In the below C program we demonstrate why l + (r - l) / 2 
* [or start + (end - start) / 2] is a better way to calculate the middle of two 
* indexes of an array, compared to using (l + r) / 2 [or (start + end) / 2], 
* because the first approach is less prone to integer overflow errors than the 
* second the approach.  
*
* YouTube Lesson: https://www.youtube.com/watch?v=JNFGvjATOUA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
  // declare and initialize an array with the integers from 0...9
  int array[] = {0,1,2,3,4,5,6,7,8,9};
  
  // If we set l to 5 and r to 9, we'll find that both the middle1 and middle2
  // variables below are correctly set to 7, the middle index between l and r.
  // So both calculations will technically calculate the right value.
  // 
  // int l = 5;
  // int r = 9;

  // But int variables in C can only store values up to the range of INT_MAX,
  // which was about 2 billion on the machine/compiler this program was written 
  // on.  If we set l to 1.5 billion and r to 1.9 billion, we'll experience 
  // an integer overflow issue with the first approach but not the second!
  int l = 1500000000;
  int r = 1900000000;
  
  // Allocate space for a massive 2 billion char array on the heap.  We use the 
  // heap because we typically can't have an array this large on the stack.
  char *massive = malloc(2000000000);
  
  // store at the correct middle index 1.7 billion the char 'Y'
  massive[1700000000] = 'Y';
  
  // l + r will result in 3.4 billion, which is too large for an int as it 
  // exceeds INT_MAX... an integer overflow results and an incorrect negative 
  // value is stored into middle1!
  int middle1 = (l + r) / 2;

  // With this approach, we first subtract 1.5 billion from 1.9 billion with 
  // (r - l) giving us 400 million, which we then divide by 2 to 200 million 
  // and add to 1.5 billion to give us 1.7 billion!  An integer overflow error
  // does not occur with this approach.
  int middle2 = l + (r - l) / 2;
  
  // middle1 will be an incorrect negative value, middle2 the correct 1.7 
  // billion value
  printf("middle1: %d\n", middle1);
  printf("middle2: %d\n", middle2);
  
  // We can access the massive array at the correctly computed middle2 index 
  // successfully and we'll get the char 'Y' as output
  printf("massive[%d] = %c\n", middle2, massive[middle2]);
  
  // Output INT_MAX which gives the largest number an int can store, which 
  // on the machine/compiler this program was written on was about 2 billion, 
  // though this can vary depending on the machine/compiler and this would 
  // potentially throw off the above results from what is described here!
  printf("INT_MAX: %d\n", INT_MAX);
  
  // Free the dynamically allocated massive array
  free(massive);
  
  return 0;
}