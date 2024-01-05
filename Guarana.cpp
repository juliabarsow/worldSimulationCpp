#include "Guarana.h"
#include "Events.h"

Guarana::Guarana(int strength, int initiative, int age, char graphicRepresentation)
{
    this->strength = strength;
    this->initiative = initiative;
    this->x = -1;
    this->y = -1;
    this->age = age;
    this->graphicRepresentation = graphicRepresentation;
    this->type = "Guarana";
}

Plant* Guarana::clone() {
    return new Guarana;
}

CollisionResult Guarana::collision(Organism& otherOrganism, World& world)
{
    if (type == otherOrganism.type)
    {
        reportEvent("[Collision] " + type + " had collision with " + otherOrganism.type + " and because are the same species, nothing happen.");

        // Breeding is not implemented. I only want 3 points.
        return CollisionResult::NothingHappen;
    }

    if (getStrength() > otherOrganism.getStrength())
    {
        return CollisionResult::IEatYou;
    }
    else if (getStrength() < otherOrganism.getStrength())
    {
        otherOrganism.strength += 3;
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