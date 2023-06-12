#include "Structures/vector.h"

int main(){
    Vector* vector = createVector();
    
    vector->push(vector,5);
    vector->display(vector);

    vector->kill(vector);
}