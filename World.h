#pragma once

#include <vector>

#include "Organism.h"

extern const int Width;
extern const int Height;

class World {
public:

    World();
    ~World();

    void makeTurn();
    void drawWorld();
    void endGame();

    void placeOrganism(Organism* organism, int x, int y);
    void kill(Organism* organism);

    Organism* getOrganismAt(int x, int y);
    void moveOrganism(int fromX, int fromY, int toX, int toY);


private:
    void increaseAgeOfOrganisms();

    std::vector<Organism*> world;
};
