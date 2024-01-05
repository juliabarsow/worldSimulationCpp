#pragma once
#include "Plant.h"
#include "Organism.h"

class Grass : public Plant {

public:
    Grass(int strength = 0, int initiative = 0, int age = 0, char graphicRepresentation = 'G');
protected:
    Plant* clone() override;
};