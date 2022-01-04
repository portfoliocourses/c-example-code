/*******************************************************************************
*
* Program: Find The Minimum Distance Between Two Different Numbers In An Array
* 
* Description: How to find the minimum distance between two different numbers
* in an array in C.  See the explanation of difference in the example array
* below.
*
* YouTube Lesson: https://www.youtube.com/watch?v=cDxIGjnKsS8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int min_distance(int array[], int length, int a, int b);

int main()
{
  // The distance between 0 and 1 in this array would be '1', and the distance 
  // between 1 and 6 in this array would be '7'.  There are only one of each 
  // 0, 1 and 6 number in the array, so by default we would say these are the
  // minimum distances between 0 and 1, and 1 and 6.  In the case of 5 and 4, 
  // there are two distances... we have 5,4 right next to each other (a distance
  // of 1), and we have 4,8,5 (a distance of 2), so in this case the minimum 
  // distance would be 1.  In the case of 8 and 2 we have:
  //
  //    2,3,5,4,8 - a distance of 4
  //    2,3,4,5,8,5,6,8 - a distance of 7
  //    8,5,6,8,3,2 - a distance of 5
  //    8,3,2 - a distance of 2
  //
  // and so the minimim distance between an 8 and a 2 in the array would be 2.
  //
  int array[] = {0,1,2,3,5,4,8,5,6,8,3,2};
  int length = 12;
  
  int a = 2;
  int b = 8;
  
  // call the function to find the min distance between 'a' and 'b'
  int min = min_distance(array, length, a, b);
  
  printf("min distance between %d & %d: %d\n", a, b, min);
  
  return 0;
}

// Finds the minimum distance between values 'a' and 'b' in the array with the 
// given length, returning -1 if no distance can be found (e.g. one of the 
// numbers is not in the array at all)
int min_distance(int array[], int length, int a, int b)
{
  // min will store the minimum distance found so far, and -1 is used as a 
  // placeholder for no minimum distance at all found yet
  int min = -1;

  // previous will keep track of the index of the previous occurrence of 
  // either 'a' or 'b' in the array, it will be used to calculate distances,
  // and we set it to -1 to signify that no previous 'a' or 'b' value has 
  // been encountered yet
  int previous = -1;
  
  // loop through the array one index at a time with counter variable i
  for (int i = 0; i < length; i++)
  {
    // check if we've found one of our two numbers of interest at index i
    if (array[i] == a || array[i] == b)
    {
      // if previous DOES equal -1, this is the first 'a' or 'b' number we've 
      // found, and we want to set previous to the current index as 
      // previous will keep track of the previous occurrence of 'a' or 'b', 
      // and so we only proceed further in this if-statement if previous != -1
      // 
      // the right operand of the && operator will ONLY execute if the 
      // left operand is TRUE... because if the left operand is false 
      // there is no reason to check the second as the && is already known 
      // to be false
      //
      // in the right operand of the && we check to see if the number at 
      // index i (which we know is either 'a' or 'b') is DIFFERENT from the 
      // 'a' or 'b' number we found at the previous index... if it IS the same
      // all we want to do is update previous and we proceed no further in 
      // this if-statement, because at this point all we've found is an 'a' 
      // or 'b' value that will be "closer" in distance to whatever 'b' or 'a' 
      // value is next 
      //
      // notice how we access the array at index previous in the right 
      // operand... it's a good thing the right operand will only execute 
      // if the first operand is true, because if previous was equal to -1, 
      // then we would be accessing the array at index -1 which is definitely 
      // an error!
      //
      if (previous != -1 && array[i] != array[previous])
        // 
        // at this point we know we have found an 'a' followed by a 'b' 
        // or a 'b' followed by an 'a', and we want to now potentially 
        // adjust the min distance found thus far 
        //
        // first we check if min == -1, if it is this is the *first* distance
        // to be computed, and we set min to this distance
        //
        // similar to the above logic with the && operator, the right operand 
        // of the || will only execute if the left operand is FALSE, as there 
        // is no point in checking the right operand of an || operator if 
        // the left is already true as it by definition makes the || true
        //
        // we check to see if the new distance (given by i - previous) is 
        // less than the min distance found thus far, and if it is we update 
        // the min distance
        //
        // again it's a good thing that the right operand only executes if 
        // the first is false, as i - previous would always be less than -1
        // otherwise
        //
        if (min == -1 || ((i - previous) < min))
          min = i - previous;
      
      previous = i;
    }
  }
   
  // after we've checked the length of the array, we can be sure whatever min 
  // distance we've found is the min distance between the two numbers in the 
  // array and we return it (if no distance at all was found, min will remain 
  // -1 as assigned above)
  return min;
}
