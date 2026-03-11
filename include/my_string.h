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

/***************************************************/
// A. CONSTRUCTION & DESTRUCTIONS
/***************************************************/
// 1. to create an empty string
int my_string_init(my_string* str);

// 2. initialize from c style string
int my_string_from_cstr(my_string* str, const char* cstr);

// 3. release memory
void my_string_free(my_string* str);

/***************************************************/
// B. MODIFICATION
/***************************************************/
// 4. Push back a character
int my_string_push_back(my_string* str, char ch);

// 5. Pop back a character
int my_string_pop_back(my_string* str);

// 6. clear the string
void my_string_clear(my_string* str);

/***************************************************/
// C. CONCATENATION
/***************************************************/
int my_string_append(my_string* dest, const my_string* src);
int my_string_append_cstr(my_string* str, const char* cstr);

/***************************************************/
// D. ACCESS
/***************************************************/
const char* my_string_cstr(const my_string* str);
size_t my_string_length(const my_string* str);
char my_string_at(const my_string* str, size_t index);

#endif  // !MY_STRING_H
