#ifndef C_STRING
#define C_STRING

#include <stdio.h>

typedef struct {
    char *str;
    size_t length;
} string;

string *newString(const char *staticString);

void freeString(const string *str);

string *concat(const string *str1, const string *str2);

string *trim(const string *str);

string *replace(const string *str, const char oldChar, const char newChar);

string *toUpper(const string *str);

string *toLower(const string *str);

string *reverse(const string *str);

string *extract(const string *str, size_t start, size_t end);

int compare(const string *str1, const string *str2);

#endif