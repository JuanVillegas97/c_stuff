#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create an array with a given size
Vector* createVector() {
    Vector* vector = malloc(sizeof(Vector));
    if (vector == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Intializing members 
    vector->_array = NULL;
    vector->_size = 0;
    vector->_length = 0;

    vector->initialize = initialize;
    vector->populate = populate;
    vector->display = display;
    vector->push = push;
    vector->kill = kill;
    return vector;
}

void kill(Vector* vector){
    printf("\n");
    free(vector->_array);
    free(vector);
    printf("Vector killed\n");
}

void initialize(Vector* vector){
    printf("Enter the size of the array: ");
    scanf("%u", &(vector->_size));

    if(vector->_size<=0){
        printf("Size must be greater than 0\n");
        exit(EXIT_FAILURE);
    }

    vector->_array = malloc(vector->_size * sizeof(int));
    if(vector->_array == NULL){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void populate(Vector* vector){
    printf("Enter the number of elements: ");
    scanf("%u", &(vector->_length));

    if (vector->_length < 0 || vector->_length > vector->_size) {
        printf("Invalid length. Length must be between 0 and %u.\n", vector->_size);
        return;
    }

    for (int i = 0; i < vector->_length; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &(vector->_array[i]));
    }
}

void display(const Vector* vector){
    if (vector->_length == 0) {
        printf("Array has no elements to display\n");
        return;
    }

    for (int i = 0; i < vector->_length; i++) {
        printf("%d ", vector->_array[i]);
    }
    printf("\n");
}

void push(Vector* vector, int value){
    if(vector->_array == NULL){
        // Array not initialized, allocate initial memory block
        vector->_size = 1;
        vector->_length = 0;
        vector->_array = malloc(vector->_size * sizeof(int));
        if(vector->_array == NULL){
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }else if(vector->_length >= vector->_size){
        // Chech if there is enough memory in the array
        int new_size = vector->_size * 2;
        int* new_array = realloc(vector->_array, new_size * sizeof(int));
        if(new_array == NULL){
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        
        vector->_array = new_array;
        vector->_size = new_size;
    }

    // Add the evalue to the array
    vector->_array[vector->_length] = value;
    vector->_length++;
}