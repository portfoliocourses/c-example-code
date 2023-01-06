/*******************************************************************************
*
* Program: Structure Padding
* 
* Description: Examples related to structure padding in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=iDD6qk8Amlw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// Many compilers support this preprocessor directive that will pack the struct
// with 1 byte alignment such that no padding will be used.  
//
// #pragma pack(1) 


// We would expect that this struct may take up 5 bytes in memory given that 
// it takes 1 byte to store a char and 4 bytes to store an int (at least on 
// the system/compiler this program was written with).  But instead it takes 
// up 8 bytes.  This is due to structure padding.
//
struct data
{
  char x;
  int y;
};

//   Address  Data
//
//      0x00  x
//      0x01  padding
//      0x02  padding
//      0x03  padding
//      0x04  y
//      0x05  y
//      0x06  y
//      0x07  y

// The struct ends up being stored like in the illustration above.  The reason
// for this is that it improves performance, as the CPU only needs to perform 
// one read to access 'y'.  This is because the CPU will read one "word" at at 
// time, not one byte at a time, where a word can vary from one system to the 
// next but may be something like 4 bytes (e.g. a 32 bit CPU could read 4 
// bytes at once as 32 bits is 4 bytes).

// If the struct were instead stored like this...

//   Address  Data
//
//      0x00  x
//      0x01  y
//      0x02  y
//      0x03  y
//      0x04  y
//      0x05  
//      0x06  
//      0x07  

// The CPU would take "two reads" to read all of y, as it could read the first
// 3 bytes of y with one read of 0x00 - 0x03 (that would include x), and then 
// the last byte of y with a second rad of 0x04 - 0x07.

// It's up to the compiler how structs are stored, but compilers will optimize
// performance over storage and use padding to achieve this.

/*
struct data
{
  char x;
  int y;
  char z;
};
*/

// If we create a struct like they above it will take up 12 bytes instead of 9
// bytes, because the compiler will also align the struct data to a multiple of 
// a word if one of the members is the size of a word or higher.  In this case 
// we've included an int member which is 4 bytes and the struct data will be 
// aligned to 4 bytes, which means the struct will be stored like this:

//   Address  Data
//
//      0x00  y
//      0x01  padding
//      0x02  padding
//      0x03  padding
//      0x04  x
//      0x05  x
//      0x06  x
//      0x07  x
//      0x08  z
//      0x09  padding
//      0x0A  padding
//      0x0B  padding

// As a best practice we should list the members of our struct from largest to 
// smallest to optimize the memory taken to store our struct.  If we listed the 
// members like this:

/*
struct data
{
  int y;
  char x;
  char z;
};
*/

//   Address  Data
//
//      0x00  y
//      0x01  y
//      0x02  y
//      0x03  y
//      0x04  x
//      0x05  z
//      0x06  padding
//      0x07  padding

// ...then our struct would only require 8 bytes of storage!

// Notably many compilers support the preprocessor directive at the top of the
// file or the attribute below in this struct to effectively "turn off" 
// structure padding, and instead pack the struct with 1 byte alignment.  This
// will reduce the amount of memory used, at the cost of performance.  We would
// rarely want to make this trade-off in practice, perhaps in some embedded 
// programming or networking programming situations.

/* 
struct data
{
  int y;
  char x;
  char z;
}__attribute__((packed));
*/

int main(void)
{
  // Output the size in bytes to store an int and a char
  printf("sizeof(int): %zu\n", sizeof(int));
  printf("sizeof(char): %zu\n", sizeof(char));
  
  // Output the size in bytes to store the struct data, try commenting
  // and uncommenting the above structs, etc, to see the effect (and of 
  // course watch the YouTube video!)
  printf("sizeof(data): %zu\n", sizeof(struct data));
  
  return 0;
}