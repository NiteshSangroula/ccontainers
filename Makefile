CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -Iinclude
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))
TEST_SRC = $(wildcard tests/*.c)
TEST_OBJ = $(patsubst tests/%.c, build/%.test.o, $(TEST_SRC))

TARGET = build/libccontainers.a
TEST_TARGET = build/tests_runner

all: $(TARGET)

build:
	mkdir -p build

$(TARGET): build $(OBJ)
	ar rcs $@ $(OBJ)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# ---- Tests ----

test: $(TARGET) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) -Lbuild -lccontainers -o $(TEST_TARGET)
	./$(TEST_TARGET)

build/%.test.o: tests/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build

.PHONY: all test clean
