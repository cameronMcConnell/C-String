#include "c-string.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void test_newString() {
    string *str = newString("Hello, World!");
    assert(str != NULL);
    assert(str->length == 13);
    assert(strcmp(str->str, "Hello, World!") == 0);
    freeString(str);
}

void test_freeString() {
    string *str = newString("Test");
    freeString(str);
}

void test_concat() {
    string *str1 = newString("Hello");
    string *str2 = newString(", World!");
    string *result = concat(str1, str2);
    assert(result != NULL);
    assert(result->length == 13);
    assert(strcmp(result->str, "Hello, World!") == 0);
    freeString(str1);
    freeString(str2);
    freeString(result);
}

void test_trim() {
    string *str = newString("   Hello, World!   ");
    string *result = trim(str);
    assert(result != NULL);
    assert(result->length == 13);
    assert(strcmp(result->str, "Hello, World!") == 0);
    freeString(str);
    freeString(result);
}

void test_replace() {
    string *str = newString("Hello, World!");
    string *result = replace(str, 'o', 'a');
    assert(result != NULL);
    assert(result->length == 13);
    assert(strcmp(result->str, "Hella, Warld!") == 0);
    freeString(str);
    freeString(result);
}

void test_toUpper() {
    string *str = newString("Hello, World!");
    string *result = toUpper(str);
    assert(result != NULL);
    assert(result->length == 13);
    assert(strcmp(result->str, "HELLO, WORLD!") == 0);
    freeString(str);
    freeString(result);
}

void test_toLower() {
    string *str = newString("Hello, World!");
    string *result = toLower(str);
    assert(result != NULL);
    assert(result->length == 13);
    assert(strcmp(result->str, "hello, world!") == 0);
    freeString(str);
    freeString(result);
}

void test_reverse() {
    string *str = newString("Hello, World!");
    string *result = reverse(str);
    assert(result != NULL);
    assert(result->length == 13);
    assert(strcmp(result->str, "!dlroW ,olleH") == 0);
    freeString(str);
    freeString(result);
}

void test_extract() {
    string *str = newString("Hello, World!");
    string *result = extract(str, 7, 11);
    assert(result != NULL);
    assert(result->length == 5);
    assert(strcmp(result->str, "World") == 0);
    freeString(str);
    freeString(result);
}

void test_compare() {
    string *str1 = newString("Hello, World!");
    string *str2 = newString("Hello, World!");
    string *str3 = newString("Hello!");
    assert(compare(str1, str2) == 1);
    assert(compare(str1, str3) == 0);
    freeString(str1);
    freeString(str2);
    freeString(str3);
}

void test_copyString() {
    string *str = newString("Hello, World!");
    string *copy = copyString(str);
    assert(copy != NULL);
    assert(copy->length == 13);
    assert(strcmp(copy->str, "Hello, World!") == 0);
    freeString(str);
    freeString(copy);
}

void test_isSubstring() {
    string *str = newString("Hello, World!");
    string *sub1 = newString("World");
    string *sub2 = newString("world");
    assert(isSubstring(str, sub1) == 1);
    assert(isSubstring(str, sub2) == 0);
    freeString(str);
    freeString(sub1);
    freeString(sub2);
}

void test_split() {
    string *str = newString("Hello, World! This is a test.");
    size_t count;
    string **result = split(str, ' ', &count);
    assert(result != NULL);
    assert(count == 6);
    assert(strcmp(result[0]->str, "Hello,") == 0);
    assert(strcmp(result[1]->str, "World!") == 0);
    assert(strcmp(result[2]->str, "This") == 0);
    assert(strcmp(result[3]->str, "is") == 0);
    assert(strcmp(result[4]->str, "a") == 0);
    assert(strcmp(result[5]->str, "test.") == 0);
    for (size_t i = 0; i < count; i++) {
        freeString(result[i]);
    }
    free(result);
    freeString(str);
}

int main() {
    test_newString();
    test_freeString();
    test_concat();
    test_trim();
    test_replace();
    test_toUpper();
    test_toLower();
    test_reverse();
    test_extract();
    test_compare();
    test_copyString();
    test_isSubstring();
    test_split();

    printf("All tests passed!\n");
    return 0;
}
