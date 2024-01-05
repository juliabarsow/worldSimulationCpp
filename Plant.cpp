#include <cstdlib> 
#include <string>

#include "Organism.h"
#include "Gotoxy.h"
#include "Plant.h"
#include "Events.h"


extern const int Width;
extern const int Height;

bool Organism::isAnimal() {
    if (this->type == "Sheep" || this->type == "Wolf" || this->type == "Human" || this->type == "Antelope" || this->type == "Turtle" || this->type == "Fox") {
        return true;
    }
}

Organism* Plant::action(World& world) {
    int previousX = x;
    int previousY = y;

    bool shouldSpread = std::rand() % 10==0;
    if (shouldSpread ) {
        int direction = rand() % 4;

        switch (direction) {
        case 0: // up
            if (this->y >= 1 && world.getOrganismAt(x,y-1) == nullptr) {
                world.placeOrganism(clone(), x, y-1);
            }
            break;
        case 1: // down
            if (this->y < Height - 1 && world.getOrganismAt(x, y + 1) == nullptr) {
                world.placeOrganism(clone(), x, y+1);
            }
            break;
        case 2: // left
            if (this->x >= 1 && world.getOrganismAt(x-1, y ) == nullptr) {
                world.placeOrganism(clone(), x-1, y);
            }
            break;
        case 3: // right
            if (this->x < Width - 1 && world.getOrganismAt(x+1, y ) == nullptr) {
                world.placeOrganism(clone(), x+1, y);
            }
            break;
        }
    }

    return nullptr;
}