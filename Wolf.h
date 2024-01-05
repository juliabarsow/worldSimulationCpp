#pragma once

#include "Animal.h"

class Wolf : public Animal {
public:
    Wolf(int strength = 9, int initiative = 5, int age = 0, char graphicRepresentation = 'W');
protected:
    Animal* clone();
};
