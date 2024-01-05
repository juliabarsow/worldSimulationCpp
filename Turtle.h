#pragma once


#include "Animal.h"
#include "Organism.h"

class Turtle : public Animal {
public:

	Turtle(int strength = 2, int initiative = 1, int age = 0, char graphicRepresentation = 'T');
	Organism* action(World& world) override;

protected:
	
	CollisionResult collision(Organism& otherOrganism) override;
	Animal* clone();
};
