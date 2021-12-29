/*******************************************************************************
*
* Program: Set Data Structure
* 
* Description: Example of a set data structure and operations (union, subset,
* intersection, etc.) implemented in C.  See the Wikipedia article on Sets:
* https://en.wikipedia.org/wiki/Set_(mathematics)
*
* YouTube Lesson: https://www.youtube.com/watch?v=RVqdK6WAjUI
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define the Set data structure
typedef struct {
  int *members;    // pointer to dynamically allocated array of the set members
  int length;      // the number of members of the set
} Set;

Set* init();
bool is_empty(Set *set);
void insert(Set *set, int member);
void print_set(Set *set);
Set *set_union(Set *setA, Set *setB);
Set *set_intersection(Set *setA, Set *setB);
Set *set_difference(Set *setA, Set *setB);
bool is_subset(Set *setA, Set *setB);
bool set_equality(Set *setA, Set *setB);
bool is_member(Set *set, int value);

int main()
{
  // create a set
  Set *setA = init();
  
  // the set should initially be empty
  if (is_empty(setA)) printf("Set A is empty.\n");
  else printf("Set A is not empty.\n");
  
  // insert several members into the set, including a 'repeat/duplicate' (70)
  insert(setA, 5);
  insert(setA, 6);
  insert(setA, 7);
  insert(setA, 7);
  insert(setA, 8);
  
  // when we print out set A, we should only see 7 once
  printf("Set A: ");
  print_set(setA);
  
  // create a set B
  Set *setB = init();
  insert(setB, 7);
  insert(setB, 8);
  insert(setB, 9);
  insert(setB, 10);
  
  // print out the set B
  printf("Set B: ");
  print_set(setB);

  // find and print the union of sets A and B
  Set *setC = set_union(setA, setB);
  printf("A union B: ");
  print_set(setC);
  
  // find and print the intersection of sets A and B
  Set *setD = set_intersection(setA, setB);
  printf("A intersection B: ");
  print_set(setD);
  
  // find and print the set difference A - B
  Set *setE = set_difference(setA, setB);
  printf("A - B: ");
  print_set(setE);
  
  // find and print the set difference B - A
  Set *setF = set_difference(setB, setA);
  printf("F = B - A: ");
  print_set(setF);
  
  // check if A is a subset of B
  if (is_subset(setA,setB))
    printf("A is a subset of B.\n");
  else
    printf("A is not a subset of B.\n");
  
  // check if F is a subset of B
  if (is_subset(setF, setB))
    printf("F is a subset of B.\n");
  else
    printf("F is not a subset of B.\n");
  
  // check if sets F and B are equal
  if (set_equality(setF, setB))
    printf("F is equal to B.\n");
  else
    printf("F is not equal to B.\n");
  
  // create a set G that is equal to F
  Set *setG = init();
  insert(setG, 9);
  insert(setG, 10);
  printf("Set G: ");
  print_set(setG);
  
  // check if sets F and G are equal
  if (set_equality(setF, setG))
    printf("F is equal to G.\n");
  else
    printf("F is not equal to G.\n");
  
  // check if 9 is a member of set F
  if (is_member(setF, 9))
    printf("9 is in set F.\n");
  else
    printf("9 is not in set F.\n");
 
  // check if 11 is a member of set F
  if (is_member(setF, 11))
    printf("11 is in set F.\n");
  else
    printf("11 is not in set F.\n");
  
  return 0;
}

// returns a pointer to a new Set allocated on the heap
Set* init()
{
  // allocate space for the set
  Set *new_set = malloc(sizeof(Set));
  
  // initially the set will be empty with no members, so set length to 0
  new_set->length = 0;

  // allocate enough space to store 1 member, we'll expand this as needed
  new_set->members = malloc(sizeof(int));

  // return the new Set (or more specifically, a pointer to it)
  return new_set;
}

// returns true if the Set is empty, and false otherwise
bool is_empty(Set *set)
{
  return (set->length == 0);
}

// returns true if value is a member of set, and false otherwise
bool is_member(Set *set, int value)
{
  // if we can find the value in the set's members, it is in the set
  for (int i = 0; i < set->length; i++)
    if (set->members[i] == value) return true;
  
  // if after checking all the set's members we can't find the value, it is 
  // not a member of the set
  return false;
}

// inserts the member value into the set (if it is not already in the set!)
void insert(Set *set, int member)
{
  // check to make the member value is not in the set already
  if (!is_member(set, member))
  {
    // allocate space to store the *new* amount of members in the set 
    set->members =
      realloc(set->members, sizeof(int) * (set->length + 1));

    // put the member into the set at the next available index
    set->members[set->length] = member;

    // increment the set length to acknowledge the new length of the set
    set->length = set->length + 1;
  }
}

// prints out the set
void print_set(Set *set)
{
  // loop through the array of set values, print each of them out separated by 
  // a comma, except the last element - instead output a newline afterwards
  for (int i = 0; i < set->length; i++)
    if (i == (set->length - 1))
      printf("%d\n", set->members[i]);
    else
      printf("%d,", set->members[i]);
}

// returns a pointer to a new set resulting from the union of setA and setB
Set *set_union(Set *setA, Set *setB)
{
  // create the new set
  Set *new = init();
  
  // insert all the values from set A
  for (int i = 0; i < setA->length; i++)
    insert(new, setA->members[i]);
  
  // insert all the values form Set B
  for (int i = 0; i < setB->length; i++)
    insert(new, setB->members[i]);
  
  // return the pointer to the new set
  return new;
}

// returns a pointer to the new set created by the intersection of setA and setB
Set *set_intersection(Set *setA, Set *setB)
{
  // create the new set
  Set *new = init();
  
  // insert each element of A into the new set if it is also a member of B
  for (int i = 0; i < setA->length; i++)
    if (is_member(setB, setA->members[i]))
      insert(new, setA->members[i]);
  
  // return the pointer to the new set
  return new;
}

// returns a pointer to a new set with difference of setA - setB
Set *set_difference(Set *setA, Set *setB)
{
  // create the new set
  Set *new = init();
  
  // insert the element from set A into the new set ONLY if it is not also 
  // a member of set B
  for (int i = 0; i < setA->length; i++)
    if (!is_member(setB, setA->members[i]))
      insert(new, setA->members[i]);
  
  // return the pointer to the new set
  return new;
}

// returns true if setA is a subset of setB, and false otherwise
bool is_subset(Set *setA, Set *setB)
{
  // if any element of setA is NOT a member of setB, then it is not a subset
  for (int i = 0; i < setA->length; i++)
    if (!is_member(setB, setA->members[i])) return false;
  
  // if ALL the elements of setA ARE members of setB, then it IS a subset
  return true;
}

// returns true if setA is equal to setB
bool set_equality(Set *setA, Set *setB)
{
  // if the sets do not have the same length, it is not possible for them to
  // be equal and we return false
  if (setA->length != setB->length) return false;
  
  // if the sets are equal length, and all the elements of setA are in setB,
  // then they MUST be equal and so we let is_subset() determine this
  return is_subset(setA, setB);
}



// Set Basics
//
// A set is a collection of items.
//
// Example set: {4, 9, 2}
//
//
// We can have an empty set with no elements.
//
// Empty set: {}
//
//
// The order of the elements in the set doesn't matter.
//
// So {4, 9, 2} is equal to {9, 2, 4}.
//
//
// The number of occurrences of an element in the set
// doesn't matter.
//
// So {4, 4, 4, 9, 2} is equal to {4, 9, 2}
//
// So we will only need to store unique elements of a set.
//
//
// We can insert elements into a set:
//
// insert 4 int {2, 9} gives us the set {4, 2, 9}
//
//
// Set Union
//
// {1, 2, 3} union {2, 3, 4} = {1, 2, 3, 4}
//
// the union of sets includes all elements from BOTH sets.
//
//
// Set Intersection
//
// {1, 2, 3} intersection {2, 3, 4} = {2, 3}
//
// the intersection of sets contains all the elements of
// one set that are also in the other set.
//
//
// Set Difference:
//
// {1, 2, 3} - {2, 3, 4} = {1}
//
// the difference of the sets contains all the elements
// of the first set that are not also in the second set.
//
//
// Subset
//
// {1, 2} is a subset of {1, 2, 3}
//
// a set A is a subset of set B if all the elements of A
// are also elements of B.
//
//
// Membership
//
// 2 is a member of the set {1, 2, 3}
//
// 4 is NOT a member of the set {1, 2, 3}
//
