#pragma once
#include "Animal.h"
#include "Organism.h"
#include "Gotoxy.h"

class Human : public Animal {
public:
    Human(int strength = 5, int initiative = 4, int age = 0, char graphicRepresentation = 'H');
    Organism* action(World& world) override;
    Organism* Superpower(World& world);
protected:
    Animal* clone();

};
