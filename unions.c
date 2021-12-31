/*******************************************************************************
*
* Program: Union Tutorial
* 
* Description: Example of how to use unions in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=-iJL8E7V6xY 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

// define a union data type called Data with 3 members... all of the members
// occupy the SAME space in memory, so assigning to one of them will effect 
// (overwrite) the others!
union Data
{
  int x;
  double y;
  char z[32];
};

// Because union members use the same memory, the union will take up less 
// space in memory than a struct with the same 3 members
struct Data2
{
  int x;
  double y;
  char z[32];
};

// Because it is often the case that only one union member can be used 
// effectively at any given time, one pattern is to wrap a union in a 
// struct where the struct has a member (in this case type) that signifies 
// which union member is currently 'in use'.  So if type == 0 it could 
// signify that buffer member x is in use, if type == 1 it could signify 
// that buffer member y is in use, and so on...
typedef struct
{
  int type;
  union {
    char x[1024];
    float y[1024];
    double z[1024];
  } buffer;
} Info;

int main()
{
  // declare a union variable
  union Data mydata;
  
  // initialize the members of the union
  mydata.x = 10;
  mydata.y = 20.5;
  strcpy(mydata.z, "test 123");
  
  // mydata.x and mydata.z will not ouput 10 and 20.5 because the union members
  // all occupy the same space in memory, when we write "test 123" into mydata.z
  // we overwrite whatever was in that space in memory before (20.5)
  printf("mydata.x = %d\n", mydata.x);
  printf("mydata.y = %f\n", mydata.y);
  printf("mydata.z = %s\n", mydata.z);
  
  // if we set and output the members one at a time, we do output the value 
  mydata.x = 10;
  printf("mydata.x = %d\n", mydata.x);

  mydata.y = 20.5;
  printf("mydata.y = %f\n", mydata.y);

  strcpy(mydata.z, "test 123");
  printf("mydata.z = %s\n", mydata.z);

  // the union will be allocated enough space to store the largest member, in 
  // this case the 32 byte character array z
  printf("mydata size: %d\n", sizeof(mydata));
  printf("char size: %d\n", sizeof(char));
  
  // a struct allocates enough space to store ALL members, and so a struct with 
  // the same members will take up more space (though all members can be used 
  // simultaneously without issue)
  struct Data2 mydata2;
  printf("mydata2 size: %d\n", sizeof(mydata2));
  
  // we can access the members of a union when we have a pointer to that union
  // using the arrow notation -> the same as with structs
  union Data *ptr = &mydata;
  printf("ptr->z = %s\n", ptr->z);
  
  // the struct info contains a type member
  Info info;

  // we can set the type to '0' to signify that the x member of the buffer 
  // is the one currently in use
  info.type = 0;
  
  // write all 't' characters into the buffer.x member 
  memset(info.buffer.x, 't', 1024);
  
  // we could check to see that a certain member is in use before doing anything
  // with it, as below
  if (info.type == 0)
  {
    for (int i = 0; i < 1024; i++)
      printf("info.buffer.x[%d] = %c\n",
             i, info.buffer.x[i]);
  }
  
  return 0;
}