#include <iostream>
#include <fstream>
#include <string>

int getPointForShape(char opponent, char outcome)
{
    int shape = opponent - 65;

    if (outcome == 'X')
    {
        shape = ((shape - 1) % 3 + 3) % 3;
    }
    else if (outcome == 'Z')
    {
        shape = ((shape + 1) % 3 + 3) % 3;
    }
    else if (outcome == 'Y')
    {
        shape = shape;
    }

    shape = shape + 88;

    char myShape = (char)shape;

    switch (myShape)
    {
    case 'X': // Rock
        return 1;
        break;
    case 'Y': // Paper
        return 2;
        break;
    case 'Z': // Scissors
        return 3;
        break;

    default:
        return 0;
        break;
    }
}

int getPointsForOutcome(char outcome)
{

    if (outcome == 'Y')
    {
        return 3;
    }

    if (outcome == 'X')
    {
        return 0;
    }

    return 6;
}

int main()
{

    std::ifstream strategy_guide;
    strategy_guide.open("aoc/resources/day02/strategy_guide.txt");

    if (!strategy_guide)
        return 0;

    int points = 0;
    char outcome, opponent;

    std::string round;
    while (strategy_guide)
    {
        getline(strategy_guide, round);
        if (round.compare("") == 0)
            break;
        opponent = round.at(0);
        outcome = round.at(2);

        points = points + getPointForShape(opponent, outcome) + getPointsForOutcome(outcome);
    }

    return 1;
}