#pragma once
#include "Organism.h"
#include "World.h"


class Plant :public Organism {
public:
	Organism* action(World& world) ;
protected:
	virtual Plant* clone() = 0;
	bool isAnimal();
};
