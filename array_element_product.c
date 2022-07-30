/*******************************************************************************
*
* Program: Compute The Product Of All The Elements In An Array
* 
* Description: A C program to compute the product all the elements in an array
* (i.e. multiply all the elements of an array).
*
* YouTube Lesson: https://www.youtube.com/watch?v=0HDvRIUodcg 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int element_product(int array[], int length);

int main()
{
  // declare and initialize a test array
  int array[] = {2,5,3,4,2};
  
  // call the function to compute the product of all the elements in the array,
  // pass in the array and array length (5) as arguments, store the return 
  // value result into product
  int product = element_product(array, 5);
  
  // output the resulting product (240)
  printf("product: %d\n", product);
  
  return 0;
}

// Returns the product of all the elements in array of the given length
int element_product(int array[], int length)
{
  // used to build the product one multiplication at a time
  int product = 1;
  
  // loop through each array element, multiply it by the product and store the
  // result back into product to build the product of all the elements one 
  // multiplication at a time... initializing product to 1 above ensures that 
  // when the first array element is multiplied by product we get back the 
  // array element itself (which is what we want to get a[1] * a[2] ... )
  for (int i = 0; i < length; i++)
    product *= array[i];

  // return the resulting product
  return product;
}