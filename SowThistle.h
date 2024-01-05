#pragma once
#include "Plant.h"
#include "Organism.h"

class SowThistle : public Plant {

public:
    SowThistle(int strength = 0, int initiative = 0, int age = 0, char graphicRepresentation = '+');
protected:
    Plant* clone() override;
};
