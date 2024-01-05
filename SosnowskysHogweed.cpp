#include "SosnowskysHogweed.h"
#include "Events.h"
#include "Organism.h"

SosnowskysHogweed::SosnowskysHogweed(int strength, int initiative, int age, char graphicRepresentation)
{
    this->strength = strength;
    this->initiative = initiative;
    this->x = -1;
    this->y = -1;
    this->age = age;
    this->graphicRepresentation = graphicRepresentation;
    this->type = "SosnowskysHogweed";
}

Plant* SosnowskysHogweed::clone() {
    return new SosnowskysHogweed;
}

Organism* SosnowskysHogweed::action(World& world)
{
    int previousX = x;
    int previousY = y;

    bool shouldSpread = std::rand() % 10 == 0;
    if (shouldSpread) {
        int direction = rand() % 4;

        switch (direction) {
        case 0: // up
            if (this->y >= 1 && world.getOrganismAt(x, y - 1) == nullptr) {
                world.placeOrganism(clone(), x, y - 1);
            }
            break;
        case 1: // down
            if (this->y < Height - 1 && world.getOrganismAt(x, y + 1) == nullptr) {
                world.placeOrganism(clone(), x, y + 1);
            }
            break;
        case 2: // left
            if (this->x >= 1 && world.getOrganismAt(x - 1, y) == nullptr) {
                world.placeOrganism(clone(), x - 1, y);
            }
            break;
        case 3: // right
            if (this->x < Width - 1 && world.getOrganismAt(x + 1, y) == nullptr) {
                world.placeOrganism(clone(), x + 1, y);
            }
            break;
        }
    } 

    if (x + 1 < Width - 1&& x-1>1 && y-1>1 && y+1 < Height-1) {
        Organism* other = world.getOrganismAt(x + 1, y);

        if (world.getOrganismAt(x + 1, y) != nullptr && other->isAnimal() == true)
        {
            reportEvent("[Collision] " + type + " had collision with " + other->type + " and killed it.");
            //delete other;
            //return CollisionResult::IEatYou;
            world.kill(other);
            return other;
        }
        other = world.getOrganismAt(x - 1, y);
        if (world.getOrganismAt(x - 1, y) != nullptr && other->isAnimal() == true)
        {
            reportEvent("[Collision] " + type + " had collision with " + other->type + " and killed it.");
            //delete other;
            world.kill(other);
            return other;
        }
        other = world.getOrganismAt(x, y + 1);
        if (world.getOrganismAt(x, y + 1) != nullptr && other->isAnimal() == true)
        {
            reportEvent("[Collision] " + type + " had collision with " + other->type + " and killed it.");
            //delete other;
            world.kill(other);
            return other;
        }
        other = world.getOrganismAt(x, y - 1);
        if (world.getOrganismAt(x, y - 1) != nullptr && other->isAnimal() == true)
        {
            reportEvent("[Collision] " + type + " had collision with " + other->type + " and killed it.");
            // delete other;
            world.kill(other);
            return other;
        }
    }

    return nullptr;

}

CollisionResult SosnowskysHogweed::collision(Organism& otherOrganism, World& world)
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
        delete &otherOrganism;
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
