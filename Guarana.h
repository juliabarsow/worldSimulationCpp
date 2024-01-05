#pragma once
#include "Plant.h"
#include "Organism.h"

class Guarana : public Plant {

public:
    Guarana(int strength = 0, int initiative = 0, int age = 0, char graphicRepresentation = '!');
    //Organism* action(World& world) override;
    
protected:
    Plant* clone() override;
	CollisionResult collision(Organism& otherOrganism, World& world); 
};
