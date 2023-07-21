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

    vector.binarySearch = binarySearch;
    vector.pop = pop;    
    vector.push = push;
    vector.insert = insert;
    vector.delete = delete;
    vector.display = display;
    vector.get = get;
    vector.set = set;
    vector.sum = sum;
    vector.avg = avg;
    vector.max = max;
    vector.min = min;
    vector.reverse = reverse;
    vector.leftShift = leftShift;
    vector.isSorted = isSorted;

    return vector;
}

int isSorted(struct Vector vector){
    if(vector._size<1){
        printf("Not enough size to perform leftShift method");
        return -1;
    }
    for(int i=0; i<vector._size-1; i++){
        if(vector._data[i]>vector._data[i+1]) return 0;
    }
    return 1;
}

void leftShift(struct Vector* vector){
    if(vector->_size<2){
        printf("Not enough size to perform leftShift method");
        return;
    }
    
    int temp = vector->_data[0];
    for(int i=0; i<vector->_size-1; i++){
        vector->_data[i] = vector->_data[i+1];
    }
    vector->_data[vector->_size-1] = temp;
}

void reverse(struct Vector* vector){
    if(vector->_size<2){
        printf("Not enough size to perform reverse method");
        return;
    }
    for(int i = 0, j=vector->_size - 1; i<j; i++, j--){
        int swap = vector->_data[i];
        vector->_data[i] = vector->_data[j];
        vector->_data[j] = swap;
    }
}

int min(const struct Vector vector){
    if(vector._size>0){
        int min = vector._data[0];
        for(int i = 0; i<vector._size; i++){
            if(min>vector._data[i]){
                min = vector._data[i];
            }
        }
        return min;
    }
    return -1;
}


int max(const struct Vector vector){
    if(vector._size>0){
        int max = vector._data[0];
        for(int i = 0; i<vector._size; i++){
            if(max<vector._data[i]){
                max = vector._data[i];
            }
        }
        return max;
    }
    return -1;
}

float avg(const struct Vector vector){
    if(vector._size>0){
        float sum = vector.sum(vector);
        return (float)(sum/vector._size);
    }
    return -1;
}

int sum(const struct Vector vector){
    if(vector._size>0){
        int sum = 0;
        for(int i = 0; i<vector._size; i++){
            sum += vector._data[i];
        }
        return sum;
    }
    return -1;
}

void set(struct Vector* vector, const int index,const int key){
    if(index<0 && index>=vector->_size){
        printf("Failed to set number\n");
        exit(EXIT_FAILURE); 
    }
    vector->_data[index] = key;
}

int get(const struct Vector vector, const int index){
    if(index>=0 && index<vector._size){
        return vector._data[index];
    }
    return -1;
}

int binarySearch(const struct Vector vector, int const key){
    int low = 0;
    int high = vector._size-1;
    while (low<=high){
        int mid = (high + low)/2;
        if(key==vector._data[mid]){
            return mid;
        }else if(key<vector._data[mid]){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}



static void moreMemory(struct Vector* vector) {
    int new_capacity = vector->_capacity * 2;
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

void push(struct Vector* vector, int value){
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
    for(int i = 0; i<vector._size; i++)
        printf("%d ",vector._data[i]);
    printf("\n");
}

void insert(struct Vector* vector, const int index, const int value){
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

    for(int i = vector->_size; index<i; i--)
        vector->_data[i] = vector->_data[i-1];
    vector->_data[index] = value;
    
    vector->_size++;
}

int delete(struct Vector* vector, const int index){
    if(vector->_data == NULL){
        printf("Vector has not been intialized yet\n");
        exit(EXIT_FAILURE);
    }

    if(index <  0 && index > vector->_size){
        printf("Invalid index; must be between the limits");
        exit(EXIT_FAILURE);
    }

    int deleted_element = vector->_data[index];
    
    for(int i = index; i<vector->_size-1; i++)
        vector->_data[i] = vector->_data[i+1];
    
    vector->_size--;
    return deleted_element;
}