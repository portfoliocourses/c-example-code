/*******************************************************************************
*
* Program: Write An Array Of Structs To A CSV File
* 
* Description: Example of writing an array of structs to a CSV file in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=7ZFgphYJvUA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

// A struct for representing student data in a file formatted like this:
//
// U,Virat Kohli,23,95.6
// U,Serena Williams,22,83.2
// G,Wayne Gretzky,19,84.2
//
// with a "student type" (e.g. undergraduate, graduate) single character, 
// followed by the student's name, age and then average.
//
typedef struct 
{
  // members for the student's type, name, age and average  
  char type;
  char name[50];
  int age;
  double average;
} Student;

// total number of students stored in the array of structs
#define TOTAL_STUDENTS 3

int main(void)
{
  // file pointer variable for accessing the file  
  FILE *file;
  
  // Attempt to open the file file.csv for writing, if the file does not exist
  // it will be created and if it does any existing content will be erased 
  // before we begin to write to the file.
  file = fopen("file.csv", "w");
  
  // If the call to fopen() above is successful it will return a file pointer 
  // we can use to write to the file, and if it fails it will return NULL.  So 
  // if file is set to NULL we know there has been an error opening the file, 
  // and we exit with an error message and status.
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  
  // Declare our array of Student structs.  We used typedef when creating our 
  // struct so that we can more simply create our array with "Student ..." 
  // instead of something like "struct Student ...".
  Student students[TOTAL_STUDENTS];
  
  // Initialize the members of the first Student struct in the array
  students[0].type = 'U';
  strcpy(students[0].name, "Nageeb");
  students[0].age = 20;
  students[0].average = 90;

  // Initialize the members of the second Student struct in the array
  students[1].type = 'U';
  strcpy(students[1].name, "Mary");
  students[1].age = 19;
  students[1].average = 95;

  // Initialize the members of the third Student struct in the array
  students[2].type = 'G';
  strcpy(students[2].name, "Kulvinder");
  students[2].age = 21;
  students[2].average = 85;
  
  // This loop will output each Struct to the CSV file as a record of comma 
  // separated values.  We use a counter variable i going from 0 to the number
  // of student records to access each array element (Student struct).
  for (int i = 0; i < TOTAL_STUDENTS; i++)
  {
    // Output to the file a line of comma separated values for the current 
    // Student struct.  The placeholders %c %s %d and %.2f are used to output
    // a char, a string, an int and a double respectively for the members/fields
    // type, name, age and average.  The %.2f is used to output the average 
    // with two decimal digits of accuracy.
    fprintf(file,
            "%c,%s,%d,%.2f\n",
            students[i].type,
            students[i].name,
            students[i].age,
            students[i].average);
    
    // If there is an error writing to the file we identify that it has 
    // occurred using ferror(file) and exit with an error message and status 
    // if so.
    if (ferror(file))
    {
      printf("Error writing to file.\n");
      return 1;
    }
  }
  
  // close the file since we are done working with it
  fclose(file);

  // output the total number of records written to the file
  printf("\n%d records written.\n\n", TOTAL_STUDENTS);

  return 0;
}