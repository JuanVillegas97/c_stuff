#include <stdio.h>
#include <stdlib.h>

// Structure to represent an array
struct Array {
    int* A;                     // Pointer to the array
    int size;                   // Size of the array
    int length;                 // Length of the array (number of elements)
    void (*create)(struct Array*, int);     // Function pointer to create an array
    void (*populate)(struct Array*);        // Function pointer to populate the array
    void (*display)(const struct Array*);   // Function pointer to display the array
    void (*deallocate)(struct Array*);      // Function pointer to deallocate the array
};

// Function to create an array with a given size
void create(struct Array* arr, int size) {
    arr->size = size;
    arr->A = malloc(arr->size * sizeof(*arr->A));   // Allocate memory for the array
    if (arr->A == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

// Function to populate the array with elements
void populate(struct Array* arr) {
    printf("Enter the number of elements: ");
    scanf("%d", &(arr->length));
    if (arr->length < 0 || arr->length > arr->size) {
        printf("Invalid length. Length must be between 0 and %d.\n", arr->size);
        return;
    }

    for (int i = 0; i < arr->length; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &(arr->A[i]));
    }
}

// Function to display the elements of the array
void display(const struct Array* arr) {
    if (arr->length == 0) {
        printf("Array has no elements to display\n");
        return;
    }

    for (int i = 0; i < arr->length; i++) {
        printf(" %d", arr->A[i]);
    }
    printf("\n");
}

// Function to deallocate the array memory
void deallocate(struct Array* arr) {
    free(arr->A);
    printf("Array deallocated\n");
}

// Function to instantiate the function pointers of the Array structure
void instantiate(struct Array* arr) {
    arr->create = create;
    arr->populate = populate;
    arr->display = display;
    arr->deallocate = deallocate;
}

// Main function
int main() {
    struct Array arr;
    instantiate(&arr);  // Instantiate the function pointers of the Array structure

    arr.create(&arr, 10);   // Create an array with size 10
    arr.populate(&arr);     // Populate the array with elements
    arr.display(&arr);      // Display the elements of the array
    arr.deallocate(&arr);   // Deallocate the array memory

    return 0;
}
