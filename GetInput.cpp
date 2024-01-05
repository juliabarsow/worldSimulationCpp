#include <conio.h>

#include "GetInput.h"

Move getInput()
{
    while (true)
    {
        char first = _getch();
        if (first == char(224))
        {
            char second = _getch();
            switch (second)
            {
            case 72:
                return Move::Up;

            case 80:
                return Move::Down;

            case 75:
                return Move::Left;

            case 77:
                return Move::Right;

            }
        }
        if (first == char(97)) {
            return Move::Ability;
        }
    }
}