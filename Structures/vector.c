#include "vector.h"

struct Vector createVector(){
    struct Vector vector;
    vector._capacity = 4;
    vector._size = 0;
    vector._data = malloc(vector._capacity * sizeof(int));

    return vector;
}

void pushBack(struct Vector* vector, size_t value){
    if(vector->_data == NULL){
        printf("Vector has not been created yet\n");
        return;
    }
    if(vector->_size>=vector->_capacity){
        size_t new_capacity = vector->_capacity * 2;
        int* new_data = realloc(vector->_data,new_capacity * sizeof(int));
        vector->_capacity = new_capacity;
        vector->_data = new_data;
    }
    vector->_data[vector->_size] = value;
    vector->_size++;
}

void displayVector(const struct Vector vector){
    if(vector._size == 0){
        printf("Vector has not elements to be displayed\n");
        return;
    }
    printf("The elements are: ");
    for(size_t i = 0; i<vector._size; i++){
        printf("%d ",vector._data[i]);
    }
}
