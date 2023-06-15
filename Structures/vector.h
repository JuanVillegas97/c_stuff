#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector{
    int* _data;
    size_t _capacity;
    size_t _size;
};

struct Vector createVector();

void pushBack(struct Vector* vector, size_t value);
void displayVector(const struct Vector vector);

#endif  // VECTOR_H
