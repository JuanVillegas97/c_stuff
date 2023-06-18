#include "Structures/vector.h"

int main(){
    struct Vector vector = createVector();
    // Testing push()
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
}