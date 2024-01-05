#pragma once
#include "Plant.h"
#include "Organism.h"

class SosnowskysHogweed : public Plant {

public:
    SosnowskysHogweed(int strength = 10, int initiative = 0, int age = 0, char graphicRepresentation = 'X');
    Organism* action(World& world) override;
    
protected:
    Plant* clone() override;
    CollisionResult collision(Organism& otherOrganism, World& world);
};