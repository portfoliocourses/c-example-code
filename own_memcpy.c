/*******************************************************************************
*
* Program: Create Your Own memcpy() Function
* 
* Description: Example of how to create our own version of memcpy() function 
* in C that comes with the string.h library.
*
* YouTube Lesson: https://www.youtube.com/watch?v=PThPm24wGEo
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

void *mem_cpy(void *dest, void *src, int n);

// memcpy can be used to copy any data in memory, including structs like Student
typedef struct
{
  char name[256];
  int age;
  double average;
} Student;

int main()
{
  // TEST #1 - test string data for our mem_cpy
  char src[] = "copy this";
  char dest[100];
  
  // copy src to dest, we give strlen(src) + 1 as the number of bytes to copy 
  // because chars are one byte each and so the length of the string + one more 
  // byte/char for the null terminator will be the number of chars to copy
  char *dest_ptr = mem_cpy(dest, src, strlen(src) + 1);
  
  // print out the dest to confirm it's the same as src now
  printf("src: %s\n", src);
  printf("dest: %s\n", dest);
  
  // we also return the destination pointer the same as the official memcpy,
  // and so we compare these pointer values to make sure they are the same too
  printf("dest_ptr: %p\n", dest_ptr);
  printf("    dest: %p\n", dest);
  

  // TEST #2 - test copying of double arrays
  double src_array[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double dest_array[5];
  
  // attempt to copy the src double array to the dest double array, we can use 
  // sizeof(src_array) to get the number of the bytes the array takes up in 
  // memory... we could have also used sizeof(double) * 5 here
  mem_cpy(dest_array, src_array, sizeof(src_array));
  
  // output the dest array values to confirm the copy was successful 
  for (int i = 0; i < 5; i++)
    printf("dest_array[%d] = %f\n", i, dest_array[i]);
  

  // Test # - test copying of struct data
  // declare and initialize a Student struct
  Student student1;
  strcpy(student1.name, "Sai");
  student1.age = 20;
  student1.average = 95.2;
  
  // declare a second Student struct
  Student student2;
  
  // call memcpy... again we use sizeof(Student) as it will return the number of
  // bytes to store a Student struct, and we use the & operator to get the 
  // memory address of each Student struct, because our function expects a 
  // pointer for the first 2 arguments (which we got automatically when using 
  // the array names in the two above tests)
  mem_cpy(&student2, &student1, sizeof(Student));
  
  // output second Student struct member values to verify copy was successful
  printf("Name: %s\n", student2.name);
  printf("Age: %d\n", student2.age);
  printf("Average: %f\n", student2.average);
  
  return 0;
}

// copies n bytes from the src memory address to the dest memory address, 
// and returns the dest pointer (or NULL if dest is NULL)
void *mem_cpy(void *dest, void *src, int n)
{
  // if dest is NULL we can't perform a copy so return NULL as an 'error status'
  if (dest == NULL) return NULL;
  
  // We need to copy each byte from src to dest, but we can't assign as we do 
  // in the loop below using void (we'll get an error).  At the same time, we 
  // know that a char == one byte, and that we can assign from a char to a char,
  // so instead we cast both dest and src to pointers to chars so we can assign 
  // each char/byte from src to dest.
  char *char_dest = (char *) dest;
  char *char_src = (char *) src;
  
  // copy each n char/bytes from src to dest
  for (int i = 0; i < n; i++)
    char_dest[i] = char_src[i];
    
  // return the dest pointer as the official memcpy() function does
  return dest;
}