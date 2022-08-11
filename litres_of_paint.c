/*******************************************************************************
*
* Program: Calculate The Litres Of Paint Required To Paint A Fence
*
* Description: Example of how to calculate the litres of paint required to
* paint a fence using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=lxAReU_RKSo
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// We could define the metres squared covered per litre of paint as a
// preprocessor constant (i.e. a preprocessor macro)
#define M2_PER_LITRE 5

int main()
{
  // Declare variables for the height of the fence, length of the fence,
  // area of the fence and litres required.
  double height, length, area, litres;

  // We could also define the metres squared covered per litre as a constant
  // variable.
  const double m2_per_litre = 5;

  // Prompt the user to enter the height, store the height entered into height
  printf("Height: ");
  scanf("%lf", &height);

  // Prompt the user to enter the length, store the length entered into length
  printf("Length: ");
  scanf("%lf", &length);

  // Calcuate the area of the fence
  area = height * length;

  // Divide the area by the metres squared covered per litre to calculate the
  // number of litres required.  Here we use the preprocessor constant
  // M2_PER_LITRE to perform the calculation.
  litres = area / M2_PER_LITRE;

  // We could also use the constant variable like the below statement.  The
  // advantage of using a preprocessor constant or constant variable is that
  // if the value somehow needs to change in the future, and we use that
  // value in multiple places in our source code, we could change the value
  // in ONE place and have that changed reflected all over our source code
  // instead of making the change in multiple places.
  //
  // litres = area / m2_per_litre;

  // We could also perform the calculation with the literal value '5'
  //
  // litres = area / 5;

  // Output the number of litres required.
  printf("Litres: %f\n", litres);

  return 0;
}