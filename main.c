#include "Structures/vector.h"

int main(){
    Vector* vector = createVector(sizeof(int));
    vector->pushBack(vector, &(int){5});
    destroyVector(vector);
}