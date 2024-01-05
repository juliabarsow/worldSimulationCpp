#pragma once

#include "Animal.h"
#include "Organism.h"

class Fox : public Animal {
public:
	Fox(int strength = 3, int initiative = 7, int age = 0, char graphicRepresentation = 'F');
	Organism* action(World& world) override;
protected:
	Animal* clone();
};

