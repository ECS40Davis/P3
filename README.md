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

To do:
- 1.3 Replace FILE* declarations and assignments with ifstream declarations.
- 1.4 Replace fgets with getline. Note that getline does not place the '\n' in the array.
- 3.3 Change fopen() to an ifstream constructor, printf() to cout <<, scanf to cin >>, and fgets() to getline().
- 4.1.4 Make initialize() the constructor for the class.
- 4.1.5 Make deallocate() the destructor for the class.
- 4.2.3 Make initialize() the constructor. Note that constructors have no return value.
- 4.2.4 Make deallocate() the destructor for the class. Note that destructors have no return value.
- 4.3.2 Eliminate the calls to initialize() and deallocate(). They will be called implicitly.
- 5.1.2 You will have to retain the deallocate() function for readAirports(), but make a copy of it for the destructor.
- 6 Adding the ability to list all of the traffic from a specific airport. 

Fixed Errors:
1. error: passing XXX as 'this' argument of XXX discard qualifiers
- You're passing in a const but the function does not guarantee it is not going to change the variable.
2. error: name lookup of 'i' changed ISO 'for' scoping [-fpermissive]
- You're trying to access a variable not in the scope. (You've declared something in a for loop but you're trying to access it outside of the for loop.)
