#include "Wolf.h"

Wolf::Wolf(int strength, int initiative, int age, char graphicRepresentation) {
    this->strength = strength;
    this->initiative = initiative;
    this->x = -1;
    this->y = -1;
    this->age = age;
    this->graphicRepresentation = graphicRepresentation;
    this->type = "Wolf";
}

Animal* Wolf::clone() {
    return new Wolf;
}
