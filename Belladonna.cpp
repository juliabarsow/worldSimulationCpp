#include "Belladonna.h"
#include "Events.h"

Belladonna::Belladonna(int strength, int initiative, int age, char graphicRepresentation)
{
    this->strength = strength;
    this->initiative = initiative;
    this->x = -1;
    this->y = -1;
    this->age = age;
    this->graphicRepresentation = graphicRepresentation;
    this->type = "Belladonna";
}


Plant* Belladonna::clone() {
    return new Belladonna;
}

CollisionResult Belladonna::collision(Organism& otherOrganism, World& world)
{
    if (type == otherOrganism.type)
    {
        reportEvent("[Collision] " + type + " had collision with " + otherOrganism.type + " and because are the same species, nothing happen.");

        // Breeding is not implemented. I only want 3 points.
        return CollisionResult::NothingHappen;
    }

    if (getStrength() > otherOrganism.getStrength())
    {
        reportEvent("[Collision] " + type + " had collision with " + otherOrganism.type + " and killed it.");
        return CollisionResult::IEatYou;
        world.kill(&otherOrganism);
        //return otherOrganism;
    }
    else if (getStrength() < otherOrganism.getStrength())
    {
        
        reportEvent("[Collision] " + type + " had collision with " + otherOrganism.type + " and was eaten, but kills the animal who ate it.");
        return CollisionResult::YouEatMe;
        world.kill(&otherOrganism);
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