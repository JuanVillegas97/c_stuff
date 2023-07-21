#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector{
    int* _data;
    int _capacity;
    int _size;

    int (*binarySearch)(const struct Vector vector, const int key);
    void (*display)(const struct Vector vector);
    void (*push)(struct Vector* vector, int value);
    int (*pop)(struct Vector* vector);
    void (*insert)(struct Vector* vector, const int index, const int value);
    int (*delete)(struct Vector* vector, const int index);
    int (*get)(const struct Vector vector, const int index);
    void (*set)(struct Vector* vector,const int index, const int key);
    int (*sum)(const struct Vector vector);
    float (*avg)(const struct Vector vector);
    int (*max)(const struct Vector vector);
    int (*min)(const struct Vector vector);
    void(*reverse)(struct Vector* vector);
    void(*leftShift)(struct Vector* vector);
    int(*isSorted)(struct Vector vector);
};


struct Vector createVector();

int max(const struct Vector vector);
int min(const struct Vector vector);
int binarySearch(const struct Vector vector, const int key);
void display(const struct Vector vector);
void push(struct Vector* vector, int value);
int pop(struct Vector* vector);
void insert(struct Vector* vector, const int index, const int value);
int delete(struct Vector* vector, const int index);
int get(const struct Vector vector, const int index);
void set(struct Vector* vector, const int index, const int key);
int sum(const struct Vector vector);
float avg(const struct Vector vector);
void reverse(struct Vector* vector);
void leftShift(struct Vector* vector);
int isSorted(const struct Vector Vector);

#endif  // VECTOR_H

