# P3
Converting C to C++

Naming Convention:

_* = original code
 * = Sean Davis' modified code

Progress: 

1. Converted structs to classes.
2. Replace printf with cout statements.
3. Replace scanf with cin statements.
4. Changed structs to classes.
5. File manipulation from C -> C++
6. Created default constructor and destructor.

To do:
- 6 Adding the ability to list all of the traffic from a specific airport. 

Fixed Errors:

1. error: passing XXX as 'this' argument of XXX discard qualifiers
  - You're passing in a const but the function does not guarantee it is not going to change the variable.

2. error: name lookup of 'i' changed ISO 'for' scoping [-fpermissive]
  - You're trying to access a variable not in the scope. (You've declared something in a for loop but you're trying to access it outside of the for loop.)

Helpful Hints:
- String to char *: http://stackoverflow.com/questions/347949/how-to-convert-a-stdstring-to-const-char-or-char
- sscanf double = %lf
- const char * to char *: http://www.cplusplus.com/forum/general/32861/ or http://stackoverflow.com/questions/289347/using-strtok-with-a-stdstring
  - ex. char *dup = strdup(str.c_str());
- strtok with strings: http://stackoverflow.com/questions/289347/using-strtok-with-a-stdstring
- fstream reference: http://www.cplusplus.com/reference/fstream/fstream/
