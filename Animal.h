#pragma once

#include "Organism.h"
#include "World.h"

class Animal : public Organism {

public:
    Organism* action(World& world) override;
protected:
    virtual Animal* clone() = 0;
};
