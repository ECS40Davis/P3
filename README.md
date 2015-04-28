# P3
Converting C to C++

Naming Convention:
_* = original code
 * = Sean Davis' modified code

Progress: 
1. Converted structs to classes

To do:
- Replace printf with cout statements.
- Replace scanf with cin statements.
- Replace FILE* declarations and assignments with ifstream declarations.
- Replace fgets with getline. Note that getline does not place the '\n' in the array.
- Don't forget to add "using namespace std;" to any files with C++ header files.
- ... Everything practically. xD

Issue: Not all cities with airports are listed in the cityArray.
- Guess: readAirports and readCities are incorrect.

Fixed Errors:
1. error: passing XXX as 'this' argument of XXX discard qualifiers
- You're passing in a const but the function does not guarantee it is not going to change the variable.
2. error: name lookup of 'i' changed ISO 'for' scoping [-fpermissive]
- You're trying to access a variable not in the scope. (You've declared something in a for loop but you're trying to access it outside of the for loop.)
