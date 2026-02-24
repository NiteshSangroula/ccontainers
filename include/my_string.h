#ifndef MY_STRING_H
#define MY_STRING_H

#define INITIAL_CAPACITY 16

#include <stddef.h>

typedef struct {
    char* data;
    size_t size;
    size_t capacity;
} my_string;

/***************************************************/
/*              Functions                          */
/***************************************************/

// 1. to create an empty string
int my_string_init(my_string* str);

// 2. initialize from c style string
int my_string_from_cstr(my_string* str, const char* cstr);

// 3. push back one character to the string
int my_string_push_back(my_string* str, char ch);

// 4. release memory
void my_string_free(my_string* str);

#endif  // !MY_STRING_H
