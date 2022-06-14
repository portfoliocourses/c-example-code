/*******************************************************************************
*
* Program: Create Your Own tolower() Function Example
*
* Description: Demonstration of how to build our own tolower() function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=XJ1KUC4vzoM
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// The regular tolower() function is in the ctype.h library and will return
// the lowercase letter version of an uppercase letter when it is passed an
// uppercase letter (and the same character if it is passed anything else).
#include <ctype.h>

// Our own version of the function (note the _) will do the same... returning
// the lowercase letter version of an uppercase letter when it is passed an
// uppercase letter, and again the same character if it is passed anything else.
int to_lower(int c)
{
  // We take advantage of how characters are encoded with ASCII/UTF-8.  All
  // characters are stored as integer values (so like the tolower() library
  // function, our version accepts and returns an int).  All characters
  // are represented with a different unique integer.  'A' is represented with
  // 65, 'B' is represented with 66, and it continues in sequence until we
  // get to 'Z' which is represented with 90, giving the uppercase characters
  // the range 65 - 90.  Similarily the lowercase characters are represented
  // with the range 97 - 122.  So if we detect a character in the range
  // 'A' to 'Z' we can convert it to a lowercase letter by adding 32!  See
  // the encoding below.  It may seem odd to use operators <= and >= with
  // characters, but remember char values like 'A' and 'Z' are really just
  // integers (65 and 90), so this is OK.
  if (c >= 'A' && c <= 'Z')
    return c + 32;

  // If the argument is not an uppercase letter, we do nothing with it
  return c;
}

int main()
{
  // Test out our version of the tolower() function, remove the _ to test
  // the ctype.h library version to check it is equivalent.
  printf("tolower('Y') = %c\n", to_lower('Y'));
  printf("tolower('b') = %c\n", to_lower('b'));
  printf("tolower('#') = %c\n", to_lower('#'));
  printf("tolower('A') = %c\n", to_lower('A'));
  printf("tolower('Z') = %c\n", to_lower('Z'));

  // All characters are represented with an int value, we'll see that 'Y'
  // is represented with 89 when we print out 'Y' as an int value using %d.
  printf("Y: %d\n", 'Y');

  return 0;
}


//   ASCII / UTF-8 Encoding (partial list)
//
//   Integer -> Character
//
//       60  -> <
//       61  -> =
//       62  -> >
//       63  -> ?
//       64  -> @
//       65  -> A
//       66  -> B
//       67  -> C
//       68  -> D
//       69  -> E
//       70  -> F
//       71  -> G
//       72  -> H
//       73  -> I
//       74  -> J
//       75  -> K
//       76  -> L
//       77  -> M
//       78  -> N
//       79  -> O
//       80  -> P
//       81  -> Q
//       82  -> R
//       83  -> S
//       84  -> T
//       85  -> U
//       86  -> V
//       87  -> W
//       88  -> X
//       89  -> Y
//       90  -> Z
//       91  -> [
//       92  -> \
//       93  -> ]
//       94  -> ^
//       95  -> _
//       96  -> `
//       97  -> a
//       98  -> b
//       99  -> c
//       100 -> d
//       101 -> e
//       102 -> f
//       103 -> g
//       104 -> h
//       105 -> i
//       106 -> j
//       107 -> k
//       108 -> l
//       109 -> m
//       110 -> n
//       111 -> o
//       112 -> p
//       113 -> q
//       114 -> r
//       115 -> s
//       116 -> t
//       117 -> u
//       118 -> v
//       119 -> w
//       120 -> x
//       121 -> y
//       122 -> z
//       123 -> {
//       124 -> |
//       125 -> }
//       126 -> ~
//
//
//  Lowercase letters a-z have the range: 97-122
//
//  Uppercase letters A-Z have the range: 65-90
//
//  97 - 65 = 32
//
//  Algorithm: if the char is between 'A' and 'Z' then add 32 to get the
//  lowercase character!