#include "c-string.h"

string *newString(const char *staticString) {
    string *newStr = (string*) malloc(sizeof(string));
    if (newStr == NULL) {
        return NULL;
    }

    newStr->length = 0;

    while (staticString[newStr->length] != '\0') {
        newStr->length++;
    }

    newStr->str = (char*) malloc((newStr->length + 1) * sizeof(char));
    if (newStr->str == NULL) {
        free(newStr);
        return NULL;
    }
    
    for (size_t i = 0; i < newStr->length; i++) {
        newStr->str[i] = staticString[i];
    }

    newStr->str[newStr->length] = '\0';

    return newStr;
}

void freeString(const string *str) {
    if (str != NULL) {
        free(str->str);
        free(str);
    }
}

string *concat(const string *str1, const string *str2) {
    string *newStr = (string*) malloc(sizeof(string));
    if (newStr == NULL) {
        return NULL;
    }

    newStr->length = str1->length + str2->length;
    newStr->str = (char*) malloc((newStr->length + 1) * sizeof(char));
    if (newStr->str == NULL) {
        free(newStr);
        return NULL;
    }
    
    size_t index = 0;
    
    for (size_t i = 0; i < str1->length; i++) {
        newStr->str[index] = str1->str[i];
        index++;
    }

    for (size_t j = 0; j < str2->length; j++) {
        newStr->str[index] = str2->str[j];
        index++;
    }

    newStr->str[index] = '\0';

    return newStr;
}

string *trim(const string *str) {
    string *newStr = (string*) malloc(sizeof(string));
    if (newStr == NULL) {
        return NULL;
    }

    size_t i = 0;
    size_t j = str->length - 1;

    while (i < str->length && str->str[i] == ' ') {
        i++;
    }

    if (i == str->length) {
        newStr->length = 0;
        newStr->str = (char*) malloc(sizeof(char));
        if (newStr->str == NULL) {
            free(newStr);
            return NULL;
        }

        newStr->str[0] = '\0';

        return newStr;
    }
    
    while (j > i && str->str[j] == ' ') {
        j--;
    }

    newStr->length = j - i + 1;
    newStr->str = (char*) malloc((newStr->length + 1) * sizeof(char));
    if (newStr->str == NULL) {
        free(newStr);
        return NULL;
    }

    for (size_t k = 0; k < newStr->length; k++) {
        newStr->str[k] = str->str[i + k];
    }

    newStr->str[newStr->length] = '\0';

    return newStr;
}

string *replace(const string *str, const char oldChar, const char newChar) {
    string *newStr = newString(str->str);

    for (size_t i = 0; i < newStr->length; i++) {
        if (newStr->str[i] == oldChar) {
            newStr->str[i] = newChar;
        }
    }

    return newStr;
}

string *toUpper(const string *str) {
    string *newStr = newString(str->str);

    for (size_t i = 0; i < newStr->length; i++) {
        size_t unicode_value = (int) newStr->str[i];
        if (unicode_value >= 97 && unicode_value <= 122) {
            newStr->str[i] = (char) unicode_value - 32;
        }
    }

    return newStr;
}

string *toLower(const string *str) {

}

string *reverse(const string *str) {

}

string *extract(const string *str, size_t start, size_t end) {

}

int compare(const string *str1, const string *str2) {

}