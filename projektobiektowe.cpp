#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include "Gotoxy.h"
#include "Events.h"
#include "World.h"

// Animals
#include "Fox.h"
#include "Sheep.h"
#include "Turtle.h"
#include "Wolf.h"
#include "Human.h"
#include "Antelope.h"
// Plants
#include "Guarana.h"
#include "Grass.h"
#include "SowThistle.h"
#include "SosnowskysHogweed.h"
#include "Belladonna.h"
using namespace std;

int main() {
    SetConsoleTitle(L"Julia, Barsow, 193490");


    srand(static_cast<unsigned int>(time(NULL)));

    World world;

    world.placeOrganism(new Fox, 0, 0);
    world.placeOrganism(new Fox, 10, 0);
    world.placeOrganism(new Fox, 10, 21);
    world.placeOrganism(new Turtle, 1, 0);
    world.placeOrganism(new Turtle, 1, 10);
    world.placeOrganism(new Wolf, 1, 1);
    world.placeOrganism(new Wolf, 15, 4);
    world.placeOrganism(new Human, 4, 1);
    world.placeOrganism(new Antelope, 3, 1);
    world.placeOrganism(new Antelope, 15, 11);
    world.placeOrganism(new Grass, 5, 1);
    world.placeOrganism(new Grass, 6, 20);
    world.placeOrganism(new Belladonna, 9, 1);
    world.placeOrganism(new SosnowskysHogweed, 9, 5);
    world.placeOrganism(new SowThistle, 20, 5);
    world.placeOrganism(new Guarana, 20, 20);
    world.placeOrganism(new Sheep, 20, 22);
    world.placeOrganism(new Sheep, 1, 20);
    world.placeOrganism(new Sheep, 3, 20);

    while (true)
    {
        system("cls");
        world.drawWorld();
        gotoxy(1, 0);
        cout << "A - special ability";
        printEvents();
        //world.endGame();
        world.makeTurn();
    }

    system("pause");

    return 0;
}
