#include "Structures/vector.h"

int main(){
    Vector* vector = createVector();
    vector->initialize(vector);
    vector->populate(vector);
    vector->display(vector);
    vector->push(vector,5);
    vector->display(vector);

    vector->kill(vector);
}