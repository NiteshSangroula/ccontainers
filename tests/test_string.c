#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

#define RUN_TEST(fn)              \
    printf("Running %-30s", #fn); \
    fn();                         \
    printf(" [PASSED]\n");

void test_create() {
    my_string str;
    my_string_init(&str);
    assert(str.size == 0);
    assert(str.size == strlen(str.data));
    assert(str.capacity == 16);
    assert(str.data[0] == '\0');

    // free
    my_string_free(&str);
}

void test_create_from_cstr() {
    my_string str;
    char* cstr = "Hello";
    my_string_from_cstr(&str, cstr);
    assert(str.size == 5);
    assert(str.size == strlen(str.data));
    assert(str.capacity == 6);
    assert(strcmp(str.data, cstr) == 0);
    assert(str.data[5] == '\0');

    // free
    my_string_free(&str);
}

void test_my_string_push_back_tight() {
    my_string str;
    my_string_from_cstr(&str, "Hello");
    my_string_push_back(&str, 'A');

    assert(str.size == 6);
    assert(str.size == strlen(str.data));
    assert(str.capacity == 12);
    assert(str.data[5] == 'A');
    assert(str.data[6] == '\0');

    // free
    my_string_free(&str);
}

void test_my_string_push_back_loose() {
    my_string str;
    my_string_init(&str);
    my_string_push_back(&str, 'A');

    assert(str.size == 1);
    assert(str.size == strlen(str.data));
    assert(str.capacity == 16);
    assert(str.data[0] == 'A');
    assert(str.data[1] == '\0');

    // free
    my_string_free(&str);
}

void test_multiple_push_back() {
    my_string str;
    my_string_init(&str);

    for (int i = 0; i < 100; i++) {
        my_string_push_back(&str, 'A');
    }

    assert(str.size == 100);
    assert(str.data[100] == '\0');
    assert(str.capacity == 128);

    my_string_free(&str);
}

void test_push_back_exact_capacity() {
    my_string str;
    my_string_init(&str);

    for (int i = 0; i < 15; i++) {
        my_string_push_back(&str, 'A');
    }

    assert(str.size == 15);
    assert(str.capacity == 16);

    my_string_push_back(&str, 'B');

    assert(str.size == 16);
    assert(str.capacity == 32);

    my_string_free(&str);
}

void test_pop_back() {
    my_string str;
    my_string_from_cstr(&str, "Hello");
    my_string_pop_back(&str);

    assert(strcmp(str.data, "Hell") == 0);

    my_string_free(&str);
}

void test_pop_back_empty() {
    my_string str;
    my_string_init(&str);
    int result = my_string_pop_back(&str);

    assert(result == -1);
    my_string_free(&str);
}

void test_clear() {
    my_string str;
    my_string_from_cstr(&str, "Hello");
    my_string_clear(&str);

    assert(str.size == 0);
    assert(strcmp(str.data, "") == 0);

    my_string_free(&str);
}

int main() {
    RUN_TEST(test_create);
    RUN_TEST(test_create_from_cstr);
    RUN_TEST(test_my_string_push_back_loose);
    RUN_TEST(test_my_string_push_back_tight);
    RUN_TEST(test_multiple_push_back);
    RUN_TEST(test_push_back_exact_capacity);
    RUN_TEST(test_pop_back);
    RUN_TEST(test_pop_back_empty);
    RUN_TEST(test_clear);

    printf("All tests passed!\n");
    return 0;
}
