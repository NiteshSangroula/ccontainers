#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <stddef.h>

#define VECTOR_INITIAL_CAPACITY 4

typedef struct {
    void** data;
    size_t size;
    size_t capacity;
} my_vector;

// core
int my_vector_init(my_vector* v);
int vector_push(my_vector* v, void* element);
void* vector_get(my_vector* v, size_t index);
int vector_set(my_vector* v, size_t index, void* element);
void vector_free(my_vector* v);

#endif  // !MY_VECTOR_H
