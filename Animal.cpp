#include <cstdlib>
#include <ctime>

#include "Animal.h"
#include "Events.h"
#include "Gotoxy.h"
#include "Organism.h"

extern const int Width;
extern const int Height;


Organism* Animal::action(World& world) {
    int previousX = x;
    int previousY = y;

    // While animals doesn't move...
    while (previousX == x && previousY == y) {
        int direction = rand() % 4;

        switch (direction) {
        case 0: // up
            if (this->y >= 1) {
                y--;
            }
            break;
        case 1: // down
            if (this->y < Height - 1) {
                y++;
            }
            break;
        case 2: // left
            if (this->x >= 1) {
                x--;
            }
            break;
        case 3: // right
            if (this->x < Width - 1) {
                x++;
            }
            break;
        }
    }

    // Here move is performed, but we need to check if collision happen.
    Organism* previousOrganismOnThatField = world.getOrganismAt(x, y);
    if (previousOrganismOnThatField == nullptr)
    {
        world.moveOrganism(previousX, previousY, x, y);
        return nullptr;
    }

    // Some organism were on that field, so collision happen.
    CollisionResult collisionResult = previousOrganismOnThatField->collision(*this);
    switch (collisionResult)
    {
    case CollisionResult::NothingHappen:
        x = previousX;
        y = previousY;

        if (x+1 <Width && world.getOrganismAt(x + 1, y) == nullptr)
        {
            world.placeOrganism(clone(), x+1, y);
        }
        else if (x-1 > 0 && world.getOrganismAt(x - 1, y) == nullptr )
        {
            world.placeOrganism(clone(), x-1, y );
        }
        else if (y+1<Height && world.getOrganismAt(x, y + 1) == nullptr)
        {
            world.placeOrganism(clone(), x, y + 1);
        }
        else if (y-1 > 0 && world.getOrganismAt(x, y - 1) == nullptr )
        {
            world.placeOrganism(clone(), x, y - 1);
        }

        return nullptr;

    case CollisionResult::YouEatMe:
        reportEvent("[Collision] " + type + " had collision with " + previousOrganismOnThatField->type + " and ate it.");

        world.kill(previousOrganismOnThatField);
        world.moveOrganism(previousX, previousY, x, y);
        return previousOrganismOnThatField;

    case CollisionResult::IEatYou:
        reportEvent("[Collision] " + type + " had collision with " + previousOrganismOnThatField->type + " and was eaten.");

        x = previousX;
        y = previousY;

        world.kill(this);
        return this;
    }

    // Shouldn't be ever reached.
    return nullptr;
}
