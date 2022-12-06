#include <iostream>
#include <fstream>
#include <string>

bool between(int left, int right, int x)
{
    if (left <= x && x <= right)
    {
        return true;
    }
    return false;
}

void first_star()
{

    std::ifstream section_assignments;
    section_assignments.open("aoc/resources/day04/section_assignments.txt");

    if (!section_assignments)
    {
        return;
    }

    std::string sections;
    std::string firstSection, secondSection;
    std::string firstDelimiter = ",";
    std::string secondDelimiter = "-";

    int firstMin, firstMax, secondMin, secondMax;

    int count = 0;
    int count2 = 0;

    while (section_assignments)
    {

        getline(section_assignments, sections);

        if (sections == "")
        {
            break;
        }

        firstSection = sections.substr(0, sections.find(firstDelimiter));
        secondSection = sections.substr(sections.find(firstDelimiter) + 1, sections.length());

        firstMin = stoi(firstSection.substr(0, firstSection.find(secondDelimiter)));
        firstMax = stoi(firstSection.substr(firstSection.find(secondDelimiter) + 1, firstSection.length()));

        secondMin = stoi(secondSection.substr(0, secondSection.find(secondDelimiter)));
        secondMax = stoi(secondSection.substr(secondSection.find(secondDelimiter) + 1, secondSection.length()));

        if (firstMin <= secondMin && firstMax >= secondMax)
        {
            ++count;
        }
        else if (firstMin >= secondMin && firstMax <= secondMax)
        {
            ++count;
        }
    }
    std::cout << count << std::endl;
    return;
}

void second_star()
{

    std::ifstream section_assignments;
    section_assignments.open("aoc/resources/day04/section_assignments.txt");

    if (!section_assignments)
    {
        return;
    }

    std::string sections;
    std::string firstSection, secondSection;
    std::string firstDelimiter = ",";
    std::string secondDelimiter = "-";

    int firstMin, firstMax, secondMin, secondMax;

    int count = 0;

    while (section_assignments)
    {

        getline(section_assignments, sections);

        if (sections == "")
        {
            break;
        }

        firstSection = sections.substr(0, sections.find(firstDelimiter));
        secondSection = sections.substr(sections.find(firstDelimiter) + 1, sections.length());

        firstMin = stoi(firstSection.substr(0, firstSection.find(secondDelimiter)));
        firstMax = stoi(firstSection.substr(firstSection.find(secondDelimiter) + 1, firstSection.length()));

        secondMin = stoi(secondSection.substr(0, secondSection.find(secondDelimiter)));
        secondMax = stoi(secondSection.substr(secondSection.find(secondDelimiter) + 1, secondSection.length()));

        if (between(firstMin, firstMax, secondMin) || between(firstMin, firstMax, secondMax) || between(secondMin, secondMax, firstMin) || between(secondMin, secondMax, firstMax))
        {
            ++count;
        }
    }
    std::cout << count << std::endl;
    return;
}

int main()
{
    first_star();
    second_star();

    return 1;
}