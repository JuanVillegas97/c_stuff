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
    free(vector);
    printf("Vector killed\n");
}

void initialize(Vector* vector){
    printf("Enter the size of the array: ");
    scanf("%d",&(vector->_size));

    vector->_array = (int *)malloc(vector->_size * sizeof(int));
    if(vector->_array == NULL){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void populate(Vector* vector){
    printf("Enter the number of elements: ");
    scanf("%d", &(vector->_length));
    if (vector->_length < 0 || vector->_length > vector->_size) {
        printf("Invalid length. Length must be between 0 and %d.\n", vector->_size);
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
        printf(" %d", vector->_array[i]);
    }
    printf("\n");
}

void push(Vector* vector, int value){
    if(vector->_array == NULL){
        printf("You haven't allocated memory for the array");
        return;
    }


    vector->_array[vector->_length] = value;
    vector->_length++;
}