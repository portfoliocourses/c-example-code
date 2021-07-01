/*******************************************************************************
*
* Program: Vector addition
* 
* Description: Example of vector addition implementation in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Q075ZhB_8Eo
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// vector addition example
//
//  v1 = (2, 5, 4)
//  v2 = (3, 2, 1)
//  r = v1 + v2 = (5, 7, 5)
//

void vector_add(float v1[], float v2[], float result[], int length);

int main(void)
{
  // create some test vectors and a result vector
  float v1[] = {2,5,4};
  float v2[] = {3,2,1};
  float result[] = {0,0,0};

  // perform the vector addition
  vector_add(v1,v2,result,3);

  // print out the result vector
  for (int i = 0; i < 3; i++)
    printf("result[%d]=%f\n",i,result[i]);

  return 0;
}

// performs vector addition of vectors v1 and v2 of length 'length', stores the 
// result in the 'result' vector
void vector_add(float v1[], float v2[], float result[], int length)
{
  // We use arrays to model vectors/tuples, and add together the corresponding 
  // elements in v1 and v2 and store the result in the corresponding element 
  // of the result array
  for (int i = 0; i < length; i++)
    result[i] = v1[i] + v2[i];
}

