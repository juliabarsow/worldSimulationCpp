#pragma once

#include <string>

class World;

enum class CollisionResult
{
    YouEatMe,
    IEatYou,
    NothingHappen,
};

class Organism {
public:

    void draw(int offsetX, int offsetY);  // method which draws or returns symbolic or graphical representation of the organism.

    int getInitiative();
    int getStrength();
    int getAge();
    void increaseAge();

    int getX();
    int getY();
    void setPosition(int x, int y);

    // Returns eaten organism. If nothing were eaten returns nullptr.
    virtual Organism* action(World& world) = 0; // basic behavior of organism should be implemented in this method,

    virtual ~Organism() = default;
    bool isAnimal();

    virtual CollisionResult collision(Organism& otherOrganism); // behavior of organism in case of collision with other organism,

    int strength;
    int initiative;
    int x;
    int y;
    int age;
    char graphicRepresentation;
    std::string type = "Unknown";
};
