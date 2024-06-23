# C-String
C-String is a comprehensive, efficient, and easy-to-use string manipulation library for C, designed to make string operations simpler and more robust.

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/cameronMcConnell/C-String.git
    ```
2. Navigate to the project directory:
    ```sh
    cd C-String
    ```

## Usage

Include the header file in your project:
```c
#include "src/c-string.h"
```
Compile your project with the source files:

```sh
gcc -o your_program your_program.c src/c-string.c
```

## Functions

`string *newString(const char *staticString)`
* Creates a new string object from a C-style string.

`void freeString(string *str)`
* Frees the memory allocated for a string object.

`string *concat(string *str1, string *str2)`
* Concatenates two strings.

`string *trim(string *str)`
* Trims leading and trailing whitespace from a string.

`string *replace(string *str, const char oldChar, const char newChar)`
* Replaces all occurrences of oldChar with newChar in a string.

`string *toUpper(string *str)`
* Converts all characters in a string to uppercase.

`string *toLower(string *str)`
* Converts all characters in a string to lowercase.

`string *reverse(string *str)`
* Reverses a string.

`string *extract(string *str, size_t start, size_t end)`
* Extracts a substring from start to end.

`int compare(string *str1, string *str2)`
* Compares two strings for equality.

`string *copyString(string *str)`
* Creates a copy of a string.

`int isSubstring(string *str, string *sub)`
* Checks if sub is a substring of str.

`string **split(string *str, const char delimiter, size_t *count)`
* Splits a string by the given delimiter into an array of strings.

## Examples

### Creating a new string

```c
string *str = newString("Hello, World!");
```

### Concatenating strings

```c
string *str1 = newString("Hello, ");
string *str2 = newString("World!");
string *result = concat(str1, str2);
```

### Trimming whitespace

```c
string *str = newString("   Hello, World!   ");
string *trimmed = trim(str);
```

### Replacing characters

```c
string *str = newString("Hello, World!");
string *replaced = replace(str, 'o', 'a');
```

### Converting to uppercase

```c
string *str = newString("Hello, World!");
string *upper = toUpper(str);
```

### Reversing a string

```c
string *str = newString("Hello, World!");
string *reversed = reverse(str);
```

### Extracting a substring

```c
string *str = newString("Hello, World!");
string *substring = extract(str, 7, 11);
```

### Comparing strings

```c
Copy code
string *str1 = newString("Hello");
string *str2 = newString("Hello");
int isEqual = compare(str1, str2);
```

### Checking for substring

```c
string *str = newString("Hello, World!");
string *sub = newString("World");
int isSub = isSubstring(str, sub);
```

### Splitting a string

```c
string *str = newString("Hello,World,!");
size_t count;
string **parts = split(str, ',', &count);
```

## License
This project is licensed under the MIT License - see the LICENSE file for details.
