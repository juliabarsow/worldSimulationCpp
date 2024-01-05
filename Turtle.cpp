#include <cstdlib>

#include "Events.h"
#include "Turtle.h"

Turtle::Turtle(int strength, int initiative, int age, char graphicRepresentation)
{
    this->strength = strength;
    this->initiative = initiative;
    this->x = -1;
    this->y = -1;
    this->age = age;
    this->graphicRepresentation = graphicRepresentation;
    this->type = "Turtle";
}

Animal* Turtle::clone() {
    return new Turtle;
}

Organism* Turtle::action(World& world)
{
    bool shouldMove = std::rand() % 4 == 0; // Have 25% to move each turn.
    if (shouldMove)
    {
        return Animal::action(world);
    }

    return nullptr;
}

CollisionResult Turtle::collision(Organism& otherOrganism)
{
    if (otherOrganism.getStrength() < 5)
    {
        reportEvent("[Collision] " + otherOrganism.type + " had collision with " + type + ", tried to eat it, but it's too weak.");
        return CollisionResult::NothingHappen;
    }

    return Organism::collision(otherOrganism);
}
