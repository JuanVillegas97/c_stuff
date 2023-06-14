#include "vector.h"

Vector* createVector(size_t element_size){
    Vector* vector = (Vector*)malloc(sizeof(Vector));
    if(vector == NULL){
        fprintf(stderr,"Failed to allocate memory for the vector\n");
        exit(EXIT_FAILURE);
    }
    vector->_element_size = element_size;
    vector->_data = NULL;
    vector->_capacity = 0;
    vector->_size = 0;
    return vector;
}

void destroyVector(Vector* vector){
    free(vector->_data);
    free(vector);
}

void pushBack(Vector* vector, const void* value){
    if(vector->_size > vector->_capacity){
        size_t new_capacity = (vector->_capacity == 0) ? 1 : vector->_capacity * 2;
        void* new_data = realloc(vector->_data, new_capacity * vector->_element_size * new_capacity);
        if(new_data == NULL){
            fprintf(stderr,"Failed to allocate memory for the vector\n");
            exit(EXIT_FAILURE);
        }
        vector->_data = new_data;
        vector->_capacity = new_capacity;
        void* destination = (char*)vector->_data + (vector->_size * vector->_element_size);
        memcpy(destination, value, vector->_element_size);
        vector->_size++;
    }
}