#ifndef VECTOR_H
#define VECTOR_H

// Structure to represent a vector
typedef struct Vector {
    int* _array;                 // Pointer to the array
    unsigned int _size;                   // Number of elements in the vector
    unsigned int _length;               // Length of the vector

    void (*kill)(struct Vector*);
    void (*initialize)(struct Vector*);
    void (*populate)(struct Vector*);
    void (*display)(const struct Vector*);
    void (*push)(struct Vector*, int value);
} Vector;

// Function to create a vector
Vector* createVector();

// Function to destroy a vector and free memory
void kill(Vector* vector);

// Function to intialize the array
void initialize(Vector* vector);

// Function to populate the array
void populate(Vector* vector);

// Function to display the array
void display(const Vector* vector);

// Function to push an element to the end of the array
void push(Vector* Vector, int value);

#endif  // VECTOR_H
