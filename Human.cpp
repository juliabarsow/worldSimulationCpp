
#include <conio.h>
#include <iostream>

#include "Events.h"
#include "Human.h"
#include "GetInput.h"
#include "Gotoxy.h"
using namespace std;

Human::Human(int strength, int initiative, int age, char graphicRepresentation)
{
    this->strength = strength;
    this->initiative = initiative;
    this->x = -1;
    this->y = -1;
    this->age = age;
    this->graphicRepresentation = graphicRepresentation;
    this->type = "Human";
}
Animal* Human::clone() {
    return new Human;
}

Organism* Human::Superpower(World& world) {
    gotoxy(1, 1);
    cout << "Ability unlocked";
    if (this->x + 1 < Width) {
        Organism* other = world.getOrganismAt(x + 1, y);
        if (world.getOrganismAt(x + 1, y) != nullptr)
        {
            reportEvent("[Collision] " + type + " had collision with " + other->type + " and killed it.");

            world.kill(other);
            return other;
        }
    }
    if (this->x - 1 > 0) {
        Organism* other = world.getOrganismAt(x - 1, y);
        if (world.getOrganismAt(x - 1, y) != nullptr)
        {
            reportEvent("[Collision] " + type + " had collision with " + other->type + " and killed it.");
            //delete other;
            world.kill(other);
            return other;
        }
    }
    if (this->y + 1 < Height) {
        Organism* other = world.getOrganismAt(x, y + 1);
        if (world.getOrganismAt(x, y + 1) != nullptr)
        {
            reportEvent("[Collision] " + type + " had collision with " + other->type + " and killed it.");
            //delete other;
            world.kill(other);
            return other;
        }
    }
    if (this->y - 1 > 0) {
        Organism* other = world.getOrganismAt(x, y - 1);
        if (world.getOrganismAt(x, y - 1) != nullptr)
        {
            reportEvent("[Collision] " + type + " had collision with " + other->type + " and killed it.");
            // delete other;
            world.kill(other);
            return other;
        }
    }
}

Organism* Human::action(World& world) {
    int previousX = x;
    int previousY = y;

    do {
        Move nextMove = getInput();
        if (nextMove == Move::Up && y >= 1) {
            y--;
           
        }
        if (nextMove == Move::Down && y < Height - 1) {
            y++;
       
        }
        if (nextMove == Move::Left && x >= 1) {
            x--;
           
        }
        if (nextMove == Move::Right && x < Width - 1) {
            x++;
            
        }
        if (nextMove == Move::Ability) {
            int i = 0;
            while (i<=5) {
                Superpower(world);
                i++;
            }
        }
            
        
    } while (previousX == x && previousY == y);


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
        reportEvent("[Collision] " + type + " had collision with " + previousOrganismOnThatField->type + " and was killed.");

        x = previousX;
        y = previousY;

        world.kill(this);
        return this;
    }

    // Shouldn't be ever reached.
    return nullptr;

}
