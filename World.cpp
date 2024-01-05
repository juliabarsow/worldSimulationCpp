#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <conio.h>

#include <Windows.h>
#include "Gotoxy.h"
#include "World.h"
#include "Events.h"

using namespace std;

World::World() :
    world(Width* Height)
{

}

World::~World()
{
    for (const auto& organism : world)
    {
        delete organism;
    }
}

bool shouldFirstPerformActionBeforeSecond(Organism* first, Organism* second)
{
    // Returns true if first should be before second.
    if (first->getInitiative() > second->getInitiative())
    {
        return true;
    }
    else if (first->getInitiative() < second->getInitiative())
    {
        return false;
    }

    if (first->getAge() > second->getAge())
    {
        return true;
    }

    return false;
}

void World::makeTurn()
{
    std::vector<Organism*> allOrganisms;
    for (auto& organism : world) {
        if (organism != nullptr) {
            allOrganisms.push_back(organism);
        }
    }

    // Sort all organisms in order in which they should perform actions.
    std::sort(allOrganisms.begin(), allOrganisms.end(), shouldFirstPerformActionBeforeSecond);

    std::vector<Organism*> eatenOrganisms;
    for (auto& organism : allOrganisms)
    {
        // If organism is alive, it wasn't eaten.
        if (std::find(eatenOrganisms.begin(), eatenOrganisms.end(), organism) == eatenOrganisms.end())
        {
            Organism* eatenOrganism = organism->action(*this);
            if (eatenOrganism != nullptr)
            {
                eatenOrganisms.push_back(eatenOrganism);
            }
        }
    }

    for (const auto& eatenOrganism : eatenOrganisms)
    {
        std::erase(allOrganisms, eatenOrganism);
    }

    increaseAgeOfOrganisms();
}

void World::drawWorld() {
    const int offsetX = 2;
    const int offsetY = 3;

    for (int x = -1; x <= Width; x++) {
        for (int y = -1; y <= Height; y++) {
            if (x == -1 || x == Width
                || y == -1 || y == Height) {
                gotoxy(offsetX + x, offsetY + y);
                std::cout << "*";
            }
        }
    }

    for (const auto& organism : world) {
        if (organism != nullptr) {
            organism->draw(offsetX, offsetY);
        }
    }
}

void World::placeOrganism(Organism* organism, int x, int y)
{
    
        if (x<0 || y<0 || x>Width || y>Height) {
            reportError("invalid placement of organism");
            return;
        }

        Organism* actualOrganismOnThatField = getOrganismAt(x, y);
        if (actualOrganismOnThatField != nullptr) {
            reportError("on that field was already another organism");
            delete organism;
            return;
        }

        organism->setPosition(x, y);
        world[Width * y + x] = organism;
    
}

void World::kill(Organism* organism)
{
    world[Width * organism->getY() + organism->getX()] = nullptr;
    delete organism;
}

Organism* World::getOrganismAt(int x, int y)
{
    return world[Width * y + x];
}

void World::moveOrganism(int fromX, int fromY, int toX, int toY)
{
    world[Width * toY + toX] = getOrganismAt(fromX, fromY);
    world[Width * fromY + fromX] = nullptr;
}

void World::increaseAgeOfOrganisms()
{
    for (const auto& organism : world) {
        if (organism != nullptr) {
            organism->increaseAge();
        }
    }
}

void World::endGame() {
    int count = 0;
    for (int i = 0; i < Width; i++) {
        for (int j = 0; j < Height; j++) {
            if (world[i,j] != nullptr){
                count++;
               // system("cls");
               // gotoxy(2, 2);
               // cout << "Game over";
            }
        }
    }
    if (count == Width * Height) {
        system("cls");
        gotoxy(2, 2);
        cout << "Game over";
    }
}