#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector{
    int* _data;
    size_t _capacity;
    size_t _size;

    void (*display)(const struct Vector vector);
    void (*push)(struct Vector* vector, size_t value);
    int (*pop)(struct Vector* vector);
    void (*insert)(struct Vector* vector, const size_t index, const size_t value);
    int (*delete)(struct Vector* vector, const size_t index);
};

struct Vector createVector();

void display(const struct Vector vector);
void push(struct Vector* vector, size_t value);
int pop(struct Vector* vector);
void insert(struct Vector* vector, const size_t index, const size_t value);
int delete(struct Vector* vector, const size_t index);
#endif  // VECTOR_H
