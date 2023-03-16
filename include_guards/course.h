#ifndef COURSE_H
#define COURSE_H  
 
#include "student.h"

typedef struct 
{
  Student students[100];
  char name[100];
} Course;

#endif 