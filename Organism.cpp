#include <string>
#include <iostream>
#include <cstring>

#include "Events.h"
#include "World.h"
#include "Gotoxy.h"
#include "Organism.h"

using namespace std;

const int Width = 25;
const int Height = 25;

CollisionResult Organism::collision(Organism& otherOrganism)
{
    if (type == otherOrganism.type)
    {
        reportEvent("[Collision] " + type + " had collision with " + otherOrganism.type + " and because are the same species, a new animal is created.");

        // Breeding is not implemented. I only want 3 points.
        return CollisionResult::NothingHappen;
    }

    if (getStrength() > otherOrganism.getStrength())
    {
        return CollisionResult::IEatYou;
    }
    else if (getStrength() < otherOrganism.getStrength())
    {
        return CollisionResult::YouEatMe;
    }

    if (getAge() > otherOrganism.getAge())
    {
        return CollisionResult::IEatYou;
    }
    else if (getAge() < otherOrganism.getAge())
    {
        return CollisionResult::YouEatMe;
    }

    return CollisionResult::NothingHappen;
}

void Organism::draw(int offsetX, int offsetY)
{
    gotoxy(x + offsetX, y + offsetY);
    std::cout << graphicRepresentation;
}

int Organism::getInitiative()
{
    return initiative;
}

int Organism::getStrength()
{
    return strength;
}

int Organism::getAge()
{
    return age;
}

void Organism::increaseAge()
{
    ++age;
}

int Organism::getX()
{
    return x;
}

int Organism::getY()
{
    return y;
}

void Organism::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}
