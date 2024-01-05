#pragma once
#include "Plant.h"
#include "Organism.h"

class Belladonna : public Plant {

public:
    Belladonna(int strength = 99, int initiative = 0, int age = 0, char graphicRepresentation = 'B');
    //Organism* action(World& world) override;
    //DOROB KOLIZJE
    
protected:
    Plant* clone() override;
    CollisionResult collision(Organism& otherOrganism, World& world);
};