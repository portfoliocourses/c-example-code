/*******************************************************************************
*
* Program: Print The Positive Numbers In An Array
* 
* Description: Example of printing the positive numbers in an array using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=jEYDa-zeg64 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

void print_positive(int array[], int length);

int main(void)
{
  // Each element in the below array is stored at an index from 0...length-1.
  // We print only the positive numbers in the array by using a loop with a 
  // counter variable i which will go from 0,1,2,...,length-1 with each loop
  // iteration.  In the loop body we examine the number to see if it is greater
  // than 0 (i.e. if it is positive) and only if it is positive do we print it
  // out. 
  //
 //              -> i ->
  //      index: 0  1 2 3 4  5  6  7   8 9

  int array[] = {-1,5,7,0,-3,45,67,-78,2,1};
  int length = 10;
  
  for (int i = 0; i < length; i++)
  {
    if (array[i] > 0)
    {
      printf("%d\n", array[i]);
    }
  }
  
  // We could also put this logic inside a function and call it to solve the
  // problem too
  print_positive(array, length);
  
  return 0;
}

// Prints the positive numbers in the array with the provided length.  
// 
// Uses same logic as above in main.  Function has a void return type as it 
// does not return a value but instead just prints out values.
//
void print_positive(int array[], int length)
{
  for (int i = 0; i < length; i++)
  {
    if (array[i] > 0)
    {
      printf("%d\n", array[i]);
    }
  }
}