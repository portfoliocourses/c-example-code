#ifndef COURSE_H
#define COURSE_H  
 
#include "student.h"

typedef struct 
{
  Student students[100];
  char name[100];
} Course;

#endif 

// The #ifndef preprocessor directive will check to see if COURSE_H does not 
// exist, and it will only include the source code if it does not exist.  We 
// then define the preprocessor macro COURSE_H *inside* the #ifndef, so that 
// after the first time student.h is included, COURSE_H will now be defined. If 
// student.h is included again, now COURSE_H will be defined, and so #ifndef 
// will not include the contents of the file because COURSE_H is defined.
//
// We call this an include guard.  The choice of the macro name COURSE_H is 
// up to us as the programmer, we follow a convention of the filename followed 
// by _H.  The issue is that we could just happen to have somewhere else a 
// macro COURSE_H, which would cause this to break.  So we need to manage the
// macro names if we use include guards.
//
// An alternative is to use #pragm once.  We could delete the #ifndef, #define
// and #endif directives above and only have "#pragma once" as the first line 
// of the file instead.  #pragma once is a widely support preprocessor 
// directive that has the same effect as an include guard, it will prevent the
// header contents from being included twice.  Technically #pragma once is not
// part of the C standard, but it is effectively universally supported by C 
// compilers, and so for the slight hit we take to portability for using 
// #pragma once it is likely worth it for not having to manage macro names.
