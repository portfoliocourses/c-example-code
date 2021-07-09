/*******************************************************************************
*
* Program: struct Tutorial
* 
* Description: Example of using struct (and typedef) in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=dqa0KMSMx2w 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structs are useful when we have a record of data that needs to be stored, 
// e.g. a student with multiple attributes like name, id, etc.
//
// Student:
//   - name (stirng)
//   - id (string)
//   - age (int)
//   - grades (int array)

// Define a struct student with members name, id, age, grades
typedef struct 
{
  char name[50];
  char id[10];
  int age;
  int grades[5];
} Student;

// Define a struct to model 2D points
typedef struct
{
  int x;
  int y;
} Point;

// Define a struct that contains a pointer to dynamically allocated memory
typedef struct 
{
  int *array;
} Data;

// we can pass structs and arrays of structs to functions
void print_student(Student student);
void print_points(Point points[]);

int main(void)
{
  // declare a struct
  Student kevin;

  // we can initialize the struct members, we access them using .membername
  strcpy(kevin.name, "Kevin");
  strcpy(kevin.id, "000123123");
  kevin.age = 40;
  kevin.grades[0] = 1;
  kevin.grades[1] = 2;
  kevin.grades[2] = 3;
  kevin.grades[3] = 4;
  kevin.grades[4] = 5;

  // we can pass the struct to a function
  print_student(kevin);

  // alternative ways of initializing a struct, e.g. with { } we assign values 
  // in the same order as members are listed
  Point p1 = {5, 10};

  // notably the order in which we initialize members does not matter here...
  Point p2 = 
    { 
      .y = 8, 
      .x = 2
    };

  // output p1 and p2 members before assignment
  printf("p1.x: %d\n", p1.x);
  printf("p1.y: %d\n", p1.y);
  printf("p2.x: %d\n", p2.x);
  printf("p2.y: %d\n", p2.y);

  // an assignment from one struct to another works like a memory copy
  p1 = p2;

  // p1 will now contain the same values as p2
  printf("p1.x: %d\n", p1.x);
  printf("p1.y: %d\n", p1.y);  

  // Create an array of structs
  Point points[10];

  // initialize the values of the structs in the array
  for (int i = 0; i < 10; i++)
  {
    points[i].x = i;
    points[i].y = 10 - i;
  }

  // pass the array of structs to a function
  print_points(points);

  // Data x and y both contain pointer members array
  Data x;
  Data y;

  // set each array member to point to some dynamically allocated memory
  x.array = malloc(sizeof(int) * 5);
  y.array = malloc(sizeof(int) * 5);

  // initialize the values of the dynamically allocated arrays
  x.array[0] = 1;
  x.array[1] = 2;
  x.array[2] = 3;
  x.array[3] = 4;
  x.array[4] = 5;

  y.array[0] = 9;
  y.array[1] = 9;
  y.array[2] = 9;
  y.array[3] = 9;
  y.array[4] = 9;

  // when we perform assignment what happens is essentially a memory copy from 
  // y to x... this does *not* mean that the array values are copied however, 
  // as what the struct really stores is a pointer (and we've set those 
  // pointers to point to the array memory on the heap).  So when we perform the
  // assignment what actually happens is that x's array pointer is set to the 
  // same value as y's... in other words, x now points to the same array on 
  // the heap as y!
  x = y;

  // if we output x, we'll see the values that we had set for y's array member,
  // this may make us believe the array values have been copied into a duplicate
  // array...
  for (int i = 0; i < 5; i++)
    printf("x.array[%d] = %d\n",i,x.array[i]);

  // let's try modifying one of the x array values...
  x.array[0] = 10;

  // And when we print the y array values, we will see that y.array[0] has been 
  // set to 10!  What's going on here again is that x.array is now pointing to
  // the exact same array on the heap as y, and so when we modify one, we modify
  // the other!
  for (int i = 0; i < 5; i++)
    printf("y.array[%d] = %d\n",i,y.array[i]);

  return 0;
}

// prints out an array of points of length 10 (x and y values)
void print_points(Point points[])
{
  for (int i = 0; i < 10; i++)
    printf("p%d = (%d,%d)\n", i, points[i].x,
                              points[i].y);
}

// prints out a Student struct's member values
void print_student(Student student)
{
  printf("Name: %s\n", student.name);
  printf("ID: %s\n", student.id);
  printf("Age: %d\n", student.age);
  printf("Grades: ");
  for (int i = 0; i < 5; i++)
    printf("%d ", student.grades[i]);
  printf("\n");
}
