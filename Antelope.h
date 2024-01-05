#pragma once
#include "Animal.h"
#include "Organism.h"

class Antelope : public Animal {
public:
	Antelope(int strength = 4, int initiative = 4, int age = 0, char graphicRepresentation = 'A');
	Organism* action(World& world) override;
protected:
	CollisionResult collision(Organism& otherOrganism, World& world);
	Animal* clone() override;
};