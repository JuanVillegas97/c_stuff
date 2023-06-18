#include "vector.h"

struct Vector createVector(){
    struct Vector vector;
    vector._capacity = 4;
    vector._size = 0;
    vector._data = malloc(vector._capacity * sizeof(int));

    if (vector._data == NULL) {
        printf("Failed to allocate memory for vector\n");
        exit(EXIT_FAILURE);
    }

    vector.pop = pop;    
    vector.push = push;
    vector.insert = insert;
    vector.delete = delete;
    vector.display = display;
    return vector;
}

static void moreMemory(struct Vector* vector) {
    size_t new_capacity = vector->_capacity * 2;
    int* new_data = realloc(vector->_data, new_capacity * sizeof(int));

    if (new_data == NULL) {
        printf("Failed to reallocate memory for vector\n");
        exit(EXIT_FAILURE);
    }

    vector->_capacity = new_capacity;
    vector->_data = new_data;
}

int pop(struct Vector* vector){
    if(vector->_data == NULL){
        printf("Vector has not been created yet\n"); 
        exit(EXIT_FAILURE);
    }
    if(vector->_size < 1){
        printf("There are no elements to pop\n");
        exit(EXIT_FAILURE);
    }
    vector->_size--;
    return vector->_data[vector->_size -1]; 
}

void push(struct Vector* vector, size_t value){
    if(vector->_data == NULL){
        printf("Vector has not been created yet\n"); 
        exit(EXIT_FAILURE);
    }
    
    if(vector->_size>=vector->_capacity) moreMemory(vector);

    vector->_data[vector->_size] = value;
    vector->_size++;
}

void display(const struct Vector vector){
    if(vector._size == 0){
        printf("Vector has not elements to be displayed\n"); 
        exit(EXIT_FAILURE);
    }
    printf("The elements are: ");
    for(size_t i = 0; i<vector._size; i++)
        printf("%d ",vector._data[i]);
    printf("\n");
}

void insert(struct Vector* vector, const size_t index, const size_t value){
    if(vector->_data == NULL){
        printf("Vector has not been intialized yet\n");
        exit(EXIT_FAILURE);
    }

    if(index < 0 || index > vector->_size){
        printf("Invalid index; must be between the limits"); 
        exit(EXIT_FAILURE);
    }

    if (vector->_size >= vector->_capacity) {
        moreMemory(vector);
    }

    for(size_t i = vector->_size; index<i; i--)
        vector->_data[i] = vector->_data[i-1];
    vector->_data[index] = value;
    
    vector->_size++;
}

int delete(struct Vector* vector, const size_t index){
    if(vector->_data == NULL){
        printf("Vector has not been intialized yet\n");
        exit(EXIT_FAILURE);
    }

    if(index <  0 && index > vector->_size){
        printf("Invalid index; must be between the limits");
        exit(EXIT_FAILURE);
    }

    int deleted_element = vector->_data[index];
    
    for(size_t i = index; i<vector->_size-1; i++)
        vector->_data[i] = vector->_data[i+1];
    
    vector->_size--;
    return deleted_element;
}