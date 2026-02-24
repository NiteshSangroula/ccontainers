#include <stdio.h>

#include "my_string.h"

int main() {
    my_string str;
    my_string_from_cstr(&str, "Nitesh Sangroula");
    printf("%s\n", str.data);
    return 0;
}
