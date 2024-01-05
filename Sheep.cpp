#include "Sheep.h"

Sheep::Sheep(int strength, int initiative, int age, char graphicRepresentation) {
    this->strength = strength;
    this->initiative = initiative;
    this->x = -1;
    this->y = -1;
    this->age = age;
    this->graphicRepresentation = graphicRepresentation;
    this->type = "Sheep";
}

Animal* Sheep::clone() {
    return new Sheep;
}
