#include "Antelope.h"
#include "Events.h"
#include <cstdlib>

Antelope::Antelope(int strength, int initiative, int age, char graphicRepresentation)
{
    this->strength = strength;
    this->initiative = initiative;
    this->x = -1;
    this->y = -1;
    this->age = age;
    this->graphicRepresentation = graphicRepresentation;
    this->type = "Antelope";
}

Animal* Antelope::clone() {
    return new Antelope;
}

Organism* Antelope::action(World& world) {
    int previousX = x;
    int previousY = y;

    // While animals doesn't move...
    while (previousX == x && previousY == y) {
        int direction = rand() % 4;

        switch (direction) {
        case 0: // up
            if (this->y >= 2) {
                y -= 2;
                
              
            }
            break;
        case 1: // down
            if (this->y < Height - 2) {
                y += 2;
           
            }
            break;
        case 2: // left
            if (this->x >= 2) {
                x -= 2;
           
            }
            break;
        case 3: // right
            if (this->x < Width - 2) {
                x += 2;
               
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

CollisionResult Antelope::collision(Organism& otherOrganism, World& world)
{
    int previousX = x;
    int previousY = y;

    bool shouldEscape = std::rand() % 2 == 0;
    if (shouldEscape == true)
    {
        if (this->x + 1 < Width) {
            world.moveOrganism(previousX, previousY, x, y);
        }
        if (this->x - 1 > 0) {
            world.moveOrganism(previousX, previousY, x, y);
        }
        if (this->y + 1 < Height) {
            world.moveOrganism(previousX, previousY, x, y);
        }
        if (this->y - 1 > 0) {
            world.moveOrganism(previousX, previousY, x, y);
        }
        reportEvent("[Collision] " + otherOrganism.type + " had collision with " + type + ", tried to eat it, but Antelope managed to escape.");
        return CollisionResult::NothingHappen;
    }

    return Organism::collision(otherOrganism);
}