#include "Structures/vector.h"

int main(){
    // Testing creating a vector
    struct Vector vector = createVector();

    // Testing push
    for(int i = 0; i<5; i++)
        vector.push(&vector,i);
    vector.display(vector);

    // Testing insert
    vector.insert(&vector,2,5);
    vector.display(vector);

    // Testing pop
    vector.pop(&vector);
    vector.display(vector);

    // Testing delete
    vector.delete(&vector,2);
    vector.display(vector);

    // Testing binary search (Elements must be sorted)
    int index = vector.binarySearch(vector,4);
    printf("The index is %d\n", index);

    // Testing get 
    int key = vector.get(vector,1);
    printf("The key is %d\n", key);

    // Testing set
    vector.set(&vector, 0, 5);
    vector.display(vector);

    // Testing sum
    int sum = vector.sum(vector);
    printf("sum is: %d\n", sum);

    // Testing avg
    float avg = vector.avg(vector);
    printf("avg is: %f\n", avg);

    // Testing max
    int max = vector.max(vector);
    printf("max is: %d\n",max);

    // Testing min
    int min = vector.min(vector);
    printf("min is: %d\n",min);

    // Testing reverse
    vector.display(vector);
    vector.reverse(&vector);
    vector.display(vector);

    //Testing leftShift
    vector.leftShift(&vector);
    vector.display(vector);

    // Just performing things
    vector.set(&vector, 0, 0);
    vector.set(&vector, 2, 2); 
    vector.display(vector);
    
    // Testing isSorted
    int bool = vector.isSorted(vector);
    printf("is sorted: %d",bool);
}


