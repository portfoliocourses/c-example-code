/*******************************************************************************
*
* Program: Read And Write Array Of Structs To A Binary File
* 
* Description: Example of writing an array of structs to a binary file and 
* reading an array of structs from a binary file.
*
* YouTube Lesson: https://www.youtube.com/watch?v=0SkdAoVzWpk
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// define a simple Student struct with 3 members (student name, age, average)
typedef struct 
{
  char name[256];
  int age;
  double average;
} Student;

bool write_data(char *filename, Student *data, int total);
Student *read_data(char *filename, int *total);

int main()
{
  // dynamically allocate space for an array of 3 Student structs
  Student *school;
  school = malloc(sizeof(Student) * 3);
  
  // initialize the array of structs with sample data
  strcpy(school[0].name, "John");
  school[0].age = 19;
  school[0].average = 80.25;

  strcpy(school[1].name, "Nyra");
  school[1].age = 21;
  school[1].average = 90.50;

  strcpy(school[2].name, "Nageeb");
  school[2].age = 20;
  school[2].average = 85.66;
  
  // attempt to write the data to the file, exit with an error status if there
  // is a problem writing the data otherwise report writing data was OK
  if (write_data("school.bin", school, 3))
    printf("Write data OK.\n");
  else 
  {
    printf("Error writing to file.\n");
    return 1;
  }
  
  // free the original dynamically allocated array as we are done with it now
  free(school);
  
  // total will store the total number of structs (we could call them records 
  // of data) retrieved from the file, and file_data will be a pointer to a 
  // dynamically allocated array on the heap containing the structs
  int total = 0;
  Student *file_data;
  
  // attempt to read the data from the file
  file_data = read_data("school.bin", &total);
  
  // if the read was unsuccessful, report the error and exit with error status
  if (file_data == NULL)
  {
    printf("Error reading from file.\n");
    return 1;
  }
  
  // output the data that was read from the file for verification
  printf("\nData read OK.\n\n");
  for (int i = 0; i < total; i++)
  {
    printf("Student %d\n", i + 1);
    printf("Name: %s\n", file_data[i].name);
    printf(" Age: %d\n", file_data[i].age);
    printf(" Avg: %.2f\n", file_data[i].average);
    printf("\n");
  }
  
  // free the dynamically allocated array used to store the data read from 
  // the file
  free(file_data);

  return 0;
}

// Returns true if the function was successful in writing total number of 
// Student structs stored in the data array to the file named filename, and 
// returns false if there was an error.
//
// We write the *total* to the file first, followed by the array of structs, 
// so that way when the file is later read we know large of an array to 
// allocate space for to store the data, i.e. the file format will be:
//
// total
// data[0]
// data[1]
// ...
//
bool write_data(char *filename, Student *data, int total)
{
  // file pointer variable
  FILE *file;
  
  // attempt to open the file with name filename, in 'write to binary file mode'
  file = fopen(filename, "wb");
  
  // return false if there was an error opening the file
  if (file == NULL) return false;
  
  // write the total number of structs in the array to the file, return false 
  // if the function fails to write the data successfully
  if (fwrite(&total, sizeof(int), 1, file) != 1)
    return false;
  
  // write the structs in the array to the file, return false if the function 
  // fails to write the data successfully
  if (fwrite(data, sizeof(Student), total, file) != total)
    return false;
  
  // close access to the file, return false if this fails
  if (fclose(file) == EOF) return false; 
  
  // if everything is successful return true
  return true;
}

// Reads the array of Student structs from the file with filename, storing 
// them in a dynamically allocated array a pointer to which is returned by 
// the function, which also returns via the total parameter and pass by 
// pointer the total number of structs read from the file.  If reading the 
// file was unsuccessful we return NULL.
Student *read_data(char *filename, int *total)
{
  FILE *file;
  
  // open the file with name filename in 'read a binary file mode'
  file = fopen(filename, "rb");
  
  // if fopen() failed to open the file, return NULL 
  if (file == NULL) return NULL;
  
  // read the total number of Student struct data records stored in the file 
  // into the total pointer parameter
  if (fread(total, sizeof(int), 1, file) != 1) 
    return NULL;
  
  // allocate enough space to store the array of Student structs
  Student *data = malloc(sizeof(Student) * *total);
  
  // read the data from the file into the block of memory we have allocated, 
  // return NULL if the read was unsuccessful and free the dynamically allocated
  // memory to prevent a memory leak
  if (fread(data, sizeof(Student), *total, file) != *total)
  {
    free(data);
    return NULL;
  }
  
  // close the file, if this is unsuccessful free the dynamically allocated 
  // memory to prevent a memory leak and return NULL 
  if (fclose(file) == EOF) 
  {
    free(data);
    return NULL;
  }
  
  // if everything is successful, return the pointer to the dynamically 
  // allocated array of Student structs
  return data;
}