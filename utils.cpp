#include "utils.h"
#include <cstring>
#include <cstdlib>

char** split_string(const char* input, char delimiter, int& count) {
    // First pass: count the number of substrings
    count = 1;
    for (const char* p = input; *p; ++p) {
        if (*p == delimiter) {
            ++count;
        }
    }

    // Allocate array of char* pointers
    char** result = new char*[count];

    // Second pass: split the string
    int index = 0;
    const char* start = input;
    for (const char* p = input; ; ++p) {
        if (*p == delimiter || *p == '\0') {
            // Calculate length of current substring
            size_t len = p - start;

            // Allocate memory for substring
            result[index] = new char[len + 1];

            // Copy substring
            strncpy(result[index], start, len);
            result[index][len] = '\0';  // Null-terminate

            ++index;

            // Move start if not end of string
            if (*p == '\0') break;
            start = p + 1;
        }
    }

    return result;
}

void free_split_result(char** result, int count) {
    if (!result) return;

    // Free each dynamically allocated string
    for (int i = 0; i < count; ++i) {
        delete[] result[i];
    }

    // Free the array of pointers
    delete[] result;
}

int string_to_int(const char* str) {
    if (!str) return 0;

    int result = 0;
    int sign = 1;
    
    // Handle optional sign
    if (*str == '-') {
        sign = -1;
        ++str;
    }
    else if (*str == '+') {
        ++str;
    }

    // Convert string to integer
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            result = result * 10 + (*str - '0');
        }
        else {
            // Invalid character
            return 0;
        }
        ++str;
    }

    return result * sign;
}

int string_compare(const char* str1, const char* str2) {
    if (!str1 || !str2) {
        // Handle null pointer cases
        return (str1 ? 1 : (str2 ? -1 : 0));
    }

    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return *str1 - *str2;
        }
        ++str1;
        ++str2;
    }

    // If we've reached here, one string might be a prefix of the other
    return *str1 - *str2;
}

char* string_duplicate(const char* str) {
    if (!str) return nullptr;

    // Calculate length
    size_t len = 0;
    while (str[len]) ++len;

    // Allocate new memory
    char* duplicate = new char[len + 1];

    // Copy string
    for (size_t i = 0; i <= len; ++i) {
        duplicate[i] = str[i];
    }

    return duplicate;
}