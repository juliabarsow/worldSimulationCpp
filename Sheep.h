#pragma once

#include "Animal.h"

class Sheep : public Animal {
public:
    Sheep(int strength = 4, int initiative = 4, int age = 0, char graphicRepresentation = 'S');
protected:
    Animal* clone();
};
