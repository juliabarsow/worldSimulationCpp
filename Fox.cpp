#include "Events.h"
#include "Fox.h"

Fox::Fox(int strength, int initiative, int age, char graphicRepresentation)
{
    this->strength = strength;
    this->initiative = initiative;
    this->x = -1;
    this->y = -1;
    this->age = age;
    this->graphicRepresentation = graphicRepresentation;
    this->type = "Fox";
}

Animal* Fox::clone() {
    return new Fox;
}

Organism* Fox::action(World& world)
{
    int previousX = x;
    int previousY = y;

    std::vector<int> possibleDirections;
    // up
    if (this->y >= 1) {
        Organism* organismOnThatField = world.getOrganismAt(x, y - 1);
        if (organismOnThatField == nullptr)
        {
            possibleDirections.push_back(0);
        }
        else if (organismOnThatField->getStrength() <= strength)
        {
            possibleDirections.push_back(0);
        }
    }

    // down
    if (this->y < Height - 1) {
        Organism* organismOnThatField = world.getOrganismAt(x, y + 1);
        if (organismOnThatField == nullptr)
        {
            possibleDirections.push_back(1);
        }
        else if (organismOnThatField->getStrength() <= strength)
        {
            possibleDirections.push_back(1);
        }
    }

    // left
    if (this->x >= 1) {
        Organism* organismOnThatField = world.getOrganismAt(x - 1, y);
        if (organismOnThatField == nullptr)
        {
            possibleDirections.push_back(2);
        }
        else if (organismOnThatField->getStrength() <= strength)
        {
            possibleDirections.push_back(2);
        }
    }

    // right
    if (this->x < Width - 1) {
        Organism* organismOnThatField = world.getOrganismAt(x + 1, y);
        if (organismOnThatField == nullptr)
        {
            possibleDirections.push_back(3);
        }
        else if (organismOnThatField->getStrength() <= strength)
        {
            possibleDirections.push_back(3);
        }
    }

    if (possibleDirections.empty())
    {
        reportEvent("[Move] " + type + " wanted to move but had no available field.");
        return nullptr;
    }

    // While animals doesn't move...
    int direction = possibleDirections[rand() % possibleDirections.size()];

    switch (direction) {
    case 0: // up
        y--;
        break;
    case 1: // down
        y++;
        break;
    case 2: // left
        x--;
        break;
    case 3: // right
        x++;
        break;
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
