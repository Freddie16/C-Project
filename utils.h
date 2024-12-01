#ifndef UTILS_H
#define UTILS_H

// Function to split a string by delimiter
// Returns dynamically allocated array of strings (char**)
// 'count' will be set to the number of resulting strings
// Caller is responsible for freeing the memory
char** split_string(const char* input, char delimiter, int& count);

// Function to free memory allocated by split_string
void free_split_result(char** result, int count);

// Function to convert a string to integer
// Returns 0 if conversion fails
int string_to_int(const char* str);

// Function to compare two strings (case-sensitive)
// Returns 0 if strings are equal, negative if str1 < str2, positive if str1 > str2
int string_compare(const char* str1, const char* str2);

// Function to copy a string
// Returns dynamically allocated string (caller must free)
char* string_duplicate(const char* str);

#endif // UTILS_H