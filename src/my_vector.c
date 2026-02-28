#include "my_vector.h"

#include <stdlib.h>

int my_vector_init(my_vector* v) {
    if (v == NULL) return -1;
    v->data = malloc(VECTOR_INITIAL_CAPACITY * sizeof(void*));
    if (v->data == NULL) return -1;

    v->size = 0;
    v->capacity = VECTOR_INITIAL_CAPACITY;

    return 0;
}

int vector_push(my_vector* v, void* element) {
    if (v == NULL) return -1;
    if (v->size == v->capacity) {
        size_t new_capacity = v->capacity * 2;
        void** temp = realloc(v->data, new_capacity * sizeof(void*));
        if (temp == NULL) return -1;
        v->data = temp;
        v->capacity = new_capacity;
    }
    v->data[v->size++] = element;
    return 0;
}

void* vector_get(my_vector* v, size_t index) {
    if (v == NULL) return NULL;

    if (index > v->size) return NULL;
    return v->data[index];
}

int vector_set(my_vector* v, size_t index, void* element) {
    if (v == NULL) return -1;

    if (index >= v->size) return -1;
    v->data[index] = element;
    return 0;
}

void vector_free(my_vector* v) {
    if (v == NULL) return;

    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}
