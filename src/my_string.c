#include "my_string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// to create an empty string
int my_string_init(my_string* str) {
    if (str == NULL) return -1;

    str->data = malloc(INITIAL_CAPACITY * sizeof(char));

    if (str->data == NULL) return -1;

    str->size = 0;
    str->capacity = INITIAL_CAPACITY;
    str->data[0] = '\0';

    return 0;
}

// to create a my_string from cstr
int my_string_from_cstr(my_string* str, const char* cstr) {
    if (str == NULL || cstr == NULL) return -1;

    size_t len = strlen(cstr);

    str->data = malloc((len + 1) * sizeof(char));
    if (str->data == NULL) return -1;

    for (size_t i = 0; i < len; i++) {
        str->data[i] = cstr[i];
    }

    str->data[len] = '\0';
    str->size = len;
    str->capacity = len + 1;

    return 0;
}

// destroy the string
void my_string_free(my_string* str) {
    if (str == NULL) return;

    free(str->data);
    str->data = NULL;
    str->size = 0;
    str->capacity = 0;
}

// to push back a character
int my_string_push_back(my_string* str, char ch) {
    if (str == NULL) return -1;

    if (str->size + 1 >= str->capacity) {
        size_t new_capacity = str->capacity * 2;
        char* temp = realloc(str->data, new_capacity);

        if (temp == NULL) {
            return -1;
        }
        str->data = temp;
        str->capacity = new_capacity;
    }
    str->data[str->size] = ch;
    str->size++;
    str->data[str->size] = '\0';

    return 0;
}

// to pop back a character
int my_string_pop_back(my_string* str) {
    if (str == NULL) return -1;
    if (str->size == 0) return -1;

    str->size--;
    str->data[str->size] = '\0';

    return 0;
}

// to clear my_string
void my_string_clear(my_string* str) {
    if (str == NULL) return;
    str->size = 0;
    str->data[0] = '\0';
}

// to append my_string
int my_string_append(my_string* dest, const my_string* src) {
    if (dest == NULL || src == NULL) return -1;

    size_t total_size = dest->size + src->size;

    if (dest->capacity < total_size + 1) {
        size_t new_capacity = total_size + 1;

        char* temp = realloc(dest->data, new_capacity);
        if (temp == NULL) return -1;

        dest->data = temp;
        dest->capacity = new_capacity;
    }

    for (size_t i = 0; i < src->size; i++) {
        dest->data[dest->size + i] = src->data[i];
    }
    dest->size = total_size;
    dest->data[dest->size] = '\0';

    return 0;
}

// to append c-style string
int my_string_append_cstr(my_string* str, const char* cstr) {
    if (str == NULL || cstr == NULL) return -1;

    return 0;
}
