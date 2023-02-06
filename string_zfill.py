################################################################################
#
# Program: String zfill() Method
# 
# Description: An example of using the string zfill() method in Python to pad a 
# string with leading zero characters.
#
# YouTube Lesson: https://www.youtube.com/watch?v=cBRBpm3yFTk 
#
# Author: Kevin Browne @ https://portfoliocourses.com
#
################################################################################

# zfill() will return a new string containing enough leading zeros to make the 
# original string the length that it is provided as an argument.  So in the 
# below method call 5 leading 0s will be added to the string "abc" to make it 
# 8 characters in total and the new string will be "00000abc".
string = "abc"
new_string = string.zfill(8)
print( new_string )

# If the length provided as an argument is less or equal to the length of the
# original string than the original string will be returned.  So in the below
# method call we will get back the string "abc" since 2 is less than the length
# of the original string (3).
string = "abc"
new_string = string.zfill(2)
print( new_string )

# If a '-' character is the first character in the string, leading zeros will
# be inserted after this character.
string = "-abc"
new_string = string.zfill(8)
print( new_string )

# If a '-' character is the first character in the string, leading zeros will
# be inserted after this character.
string = "+abc"
new_string = string.zfill(8)
print( new_string )