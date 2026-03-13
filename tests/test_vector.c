#include <assert.h>
#include <stdio.h>

#include "my_vector.h"

#define RUN_TEST(fn)              \
    printf("Running %-30s", #fn); \
    fn();                         \
    printf(" [PASSED]\n");

void test_vector_init() {
    my_vector vec;
    int code = my_vector_init(&vec);

    assert(vec.size == 0);
    assert(vec.capacity == VECTOR_INITIAL_CAPACITY);
    assert(code == 0);

    my_vector_free(&vec);
}

void test_vector_push() {
    my_vector vec;
    my_vector_init(&vec);
    int a = 10;
    int code = my_vector_push(&vec, &a);

    assert(vec.data[0] == &a);
    assert(vec.size == 1);
    assert(*(int*)vec.data[0] == 10);
    assert(code == 0);

    my_vector_free(&vec);
}

void test_vector_push_more() {
    my_vector vec;
    my_vector_init(&vec);
    int a = 10;

    for (int i = 0; i < 100; i++) {
        my_vector_push(&vec, &a);
    }

    assert(vec.size == 100);
    assert(vec.capacity == 128);

    my_vector_free(&vec);
}

void test_vector_resize_integrity() {
    my_vector vec;
    my_vector_init(&vec);

    int values[100];

    for (int i = 0; i < 100; i++) {
        values[i] = i;
        my_vector_push(&vec, &values[i]);
    }

    for (int i = 0; i < 100; i++) {
        int* ptr = my_vector_get(&vec, i);
        assert(*ptr == i);
    }

    my_vector_free(&vec);
}

void test_vector_get() {
    my_vector vec;
    my_vector_init(&vec);
    int a = 10;
    int b = 20;
    int c = 30;

    my_vector_push(&vec, &a);
    my_vector_push(&vec, &b);
    my_vector_push(&vec, &c);

    int* ptr;
    ptr = my_vector_get(&vec, 1);
    assert(*ptr == b);

    my_vector_free(&vec);
}

void test_vector_get_invalid() {
    my_vector vec;
    my_vector_init(&vec);

    int* ptr;
    ptr = my_vector_get(&vec, 1);
    assert(ptr == NULL);
    assert(my_vector_get(&vec, 5) == NULL);

    my_vector_free(&vec);
}

void test_vector_set() {
    my_vector vec;
    my_vector_init(&vec);
    int a = 10;
    int b = 20;

    my_vector_push(&vec, &a);

    int code = my_vector_set(&vec, 0, &b);

    assert(vec.data[0] == &b);
    assert(*(int*)vec.data[0] == b);
    assert(code == 0);

    my_vector_free(&vec);
}

void test_vector_set_invalid() {
    my_vector vec;
    my_vector_init(&vec);

    int b = 10;

    assert(my_vector_set(&vec, 1, &b) == -1);

    my_vector_free(&vec);
}

void test_null_vector() {
    int a = 10;

    assert(my_vector_push(NULL, &a) == -1);
    assert(my_vector_set(NULL, 0, &a) == -1);
    assert(my_vector_get(NULL, 0) == NULL);
}

int main() {
    RUN_TEST(test_vector_init);
    RUN_TEST(test_vector_push);
    RUN_TEST(test_vector_push_more);
    RUN_TEST(test_vector_resize_integrity);
    RUN_TEST(test_vector_get);
    RUN_TEST(test_vector_get_invalid);
    RUN_TEST(test_vector_set);
    RUN_TEST(test_vector_set_invalid);
    RUN_TEST(test_null_vector);
    return 0;
}
