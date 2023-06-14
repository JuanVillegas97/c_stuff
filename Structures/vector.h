#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vector{
    void* _data;
    size_t _element_size;
    size_t _size;
    size_t _capacity;

    void (*pushBack)(struct Vector*, const void*);
} Vector;

Vector* createVector(size_t element_size);

void destroyVector(Vector* vector);

void pushBack(Vector* vector, const void* value);


#endif  // VECTOR_H
