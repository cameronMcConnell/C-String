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
    string *newStr = newString(str->str);

    for (size_t i = 0; i < newStr->length; i++) {
        size_t unicode_value = (int) newStr->str[i];
        if (unicode_value >= 65 && unicode_value <= 90) {
            newStr->str[i] = (char) unicode_value + 32;
        }
    }

    return newStr;
}

string *reverse(const string *str) {
    string *newStr = newString(str->str);

    size_t i = 0;
    size_t j = newStr->length - 1;

    while (i < j) {
        char temp = newStr->str[i];
        newStr->str[i] = newStr->str[j];
        newStr->str[j] = temp;
        i++;
        j--;
    }

    return newStr;
}

string *extract(const string *str, size_t start, size_t end) {
    string *newStr = (string*) malloc(sizeof(string));
    if (newStr == NULL) {
        return NULL;
    }

    newStr->length = end - start + 1;
    newStr->str = (char*) malloc((newStr->length + 1) * sizeof(char));
    if (newStr->str == NULL) {
        free(newStr);
        return NULL;
    }

    for (size_t i = 0; start < end; i++) {
        newStr->str[i] = str->str[start];
        start++;
    }

    newStr->str[newStr->length] = '\0';

    return newStr;
}

int compare(const string *str1, const string *str2) {
    if (str1->length != str2->length) {
        return 0;
    }

    for (size_t i = 0; i < str1->length; i++) {
        if (str1->str[i] != str2->str[i]) {
            return 0;
        }
    }

    return 1;
}

string *copyString(const string *str) {
    return newString(str->str);
}

int isSubstring(const string *str, const string *sub) {
    if (sub->length > str->length) {
        return 0;
    }

    size_t k = 0;

    for (size_t i = 0; i < str->length; i++) {
        k = 0;
        for (size_t j = i; j < str->length; j++) {
            if (sub->str[k] == str->str[j]) {
                k++;
            }

            if (k == sub->length) {
                return 1;
            } else {
                break;
            }
        }
    }

    return 0;
}

string **split(const string *str, const char delimeter, size_t *count) {
    size_t delimeterCount = 0;

    for (size_t i = 0; i < str->length; i++) {
        if (str->str[i] == delimeter) {
            delimeterCount++;
        }
    }

    if (delimeterCount == 0) {
        string **splitArray = (string**) malloc(sizeof(string*));
        if (splitArray == NULL) {
            return NULL;
        }
        *count = 1;
        splitArray[0] = copyString(str);
        return splitArray;
    }

    string **splitArray = (string**) malloc((delimeterCount + 1) * sizeof(string*));
    if (splitArray == NULL) {
        return NULL;
    }

    size_t start = 0;
    size_t arrayIndex = 0;
    size_t bufferIndex = 0;

    for (size_t i = 0; i <= str->length; i++) {
        if (str->str[i] == delimeter || i == str->length) {
            size_t subLength = i - start;
            
            char *stringBuffer = (char*) malloc((subLength + 1) * sizeof(char));
            if (stringBuffer == NULL) {
                for (size_t j = 0; j < arrayIndex; j++) {
                    freeString(splitArray[j]);
                }
                free(splitArray);
                return NULL;
            }

            bufferIndex = 0;

            while (start < i) {
                stringBuffer[bufferIndex] = str->str[start];
                bufferIndex++;
                start++;
            }

            stringBuffer[subLength] = '\0';

            splitArray[arrayIndex] = newString(stringBuffer);
            free(stringBuffer);
            arrayIndex++;
            start++;
        }
    }

    *count = delimeterCount + 1;
    return splitArray;
}