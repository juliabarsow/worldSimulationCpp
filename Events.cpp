#include "Gotoxy.h"

#include <cmath>
#include <iostream>
#include <vector>

std::vector<std::string> events;

void printEvents()
{
	int x = 40;
	int y = 2;
	const int maxEvents = 20;

	int lastEventToPrint = static_cast<int>(events.size());
	int firstEventToPrint = max(0, lastEventToPrint - maxEvents);

	gotoxy(x, y++);
	std::cout << "Last events" << std::endl;
	gotoxy(x, y++);
	std::cout << "==================================================";

	for (int eventIndex = firstEventToPrint; eventIndex < lastEventToPrint; ++eventIndex)
	{
		gotoxy(x, y++);
		std::cout << events[eventIndex] << std::endl;
	}
}

void reportError(std::string description)
{
	events.push_back("Error: " + description);
}

void reportEvent(std::string description)
{
	events.push_back(description);
}
