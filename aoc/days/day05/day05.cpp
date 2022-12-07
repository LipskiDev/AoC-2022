#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <deque>
#include <sstream>

void first_star()
{
    std::array<std::deque<char>, 9> stacks;

    // Setup Array of Deques to use as Stacks
    for (int i = 0; i < 9; i++)
    {
        std::deque<char> newDeque;
        stacks[i] = newDeque;
    }

    std::ifstream rearrangement_procedure;
    rearrangement_procedure.open("aoc/resources/day05/rearrangement_procedure.txt");

    if (!rearrangement_procedure)
    {
        return;
    }

    std::string line;
    int index;
    char crate;

    getline(rearrangement_procedure, line);
    // Setup initial Stack-Setup
    while (line.compare(" 1   2   3   4   5   6   7   8   9 ") != 0) // Dont want the numbers to be added to the stacks
    {
        for (int stack = 0; stack < 9; stack++)
        {
            index = 4 * stack + 1;
            crate = line.at(index);
            if (crate != ' ')
            {
                stacks[stack].push_back(crate);
            }
        }
        getline(rearrangement_procedure, line);
    }
    getline(rearrangement_procedure, line);

    std::stringstream ss;
    std::string trash;
    int amount, from, to;

    // Process rearragnement procedure
    while (rearrangement_procedure)
    {

        getline(rearrangement_procedure, line);

        if (line == "")
        {
            break;
        }

        ss << line;
        ss >> trash >> amount >> trash >> from >> trash >> to;

        ss.clear();

        char crateTemp;
        // Move from to
        for (int i = 0; i < amount; i++)
        {
            crateTemp = stacks[from - 1].front();
            stacks[from - 1].pop_front();
            stacks[to - 1].push_front(crateTemp);
        }
    }

    for (int i = 0; i < 9; i++)
    {
        std::cout << stacks[i].front();
    }

    std::cout << std::endl;

    return;
}

void second_star()
{
    std::array<std::deque<char>, 9> stacks;

    // Setup Array of Deques to use as Stacks
    for (int i = 0; i < 9; i++)
    {
        std::deque<char> newDeque;
        stacks[i] = newDeque;
    }

    std::ifstream rearrangement_procedure;
    rearrangement_procedure.open("aoc/resources/day05/rearrangement_procedure.txt");

    if (!rearrangement_procedure)
    {
        return;
    }

    std::string line;
    int index;
    char crate;

    getline(rearrangement_procedure, line);
    // Setup initial Stack-Setup
    while (line.compare(" 1   2   3   4   5   6   7   8   9 ") != 0) // Dont want the numbers to be added to the stacks
    {
        for (int stack = 0; stack < 9; stack++)
        {
            index = 4 * stack + 1;
            crate = line.at(index);
            if (crate != ' ')
            {
                stacks[stack].push_back(crate);
            }
        }
        getline(rearrangement_procedure, line);
    }
    getline(rearrangement_procedure, line);

    std::stringstream ss;
    std::string trash;
    int amount, from, to;
    std::deque<char> helper;

    // Process rearragnement procedure
    while (rearrangement_procedure)
    {

        getline(rearrangement_procedure, line);

        if (line == "")
        {
            break;
        }

        ss << line;
        ss >> trash >> amount >> trash >> from >> trash >> to;

        ss.clear();

        char crateTemp;
        // Move from to
        for (int i = 0; i < amount; i++)
        {
            crateTemp = stacks[from - 1].front();
            helper.push_front(crateTemp);
            stacks[from - 1].pop_front();
        }

        for (int i = 0; i < amount; i++)
        {
            crateTemp = helper.front();
            helper.pop_front();
            stacks[to - 1].push_front(crateTemp);
        }
    }

    for (int i = 0; i < 9; i++)
    {
        std::cout << stacks[i].front();
    }

    std::cout << std::endl;

    return;
}

int main()
{
    first_star();
    second_star();

    return 1;
}