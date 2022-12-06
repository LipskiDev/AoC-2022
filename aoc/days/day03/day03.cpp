#include <iostream>
#include <fstream>
#include <string>
#include <set>

int charToPriority(char c)
{
    if (c >= 97 && c <= 122)
    {
        // std::cout << c << " " << c - 96 << std::endl;
        return c - 96;
    }
    else if (c >= 65 && c <= 90)
    {
        // std::cout << c << " " << c - 38 << std::endl;
        return c - 38;
    }

    return 0;
}

void first_star()
{
    // std::cout << "hi" << std::endl;

    std::ifstream content_list;
    content_list.open("aoc/resources/day03/content_list.txt");

    if (!content_list)
    {
        return;
    }

    std::string items, firstRucksack, secondRucksack;
    std::set<char> contents;
    int prioritySum = 0;

    while (content_list)
    {
        getline(content_list, items);
        firstRucksack = items.substr(0, items.length() / 2);
        secondRucksack = items.substr(items.length() / 2, items.length() / 2);

        // std::cout << items << std::endl << firstRucksack << secondRucksack << std::endl;

        for (char c : firstRucksack)
        {
            contents.insert(c);
        }

        for (char d : secondRucksack)
        {
            if (contents.count(d))
            {
                std::cout << d << " " << charToPriority(d) << " " << contents.count(d) << std::endl;
                prioritySum += charToPriority(d);
                contents.clear();
                continue;
            }
        }
    }

    std::cout << prioritySum << std::endl;

    return;
}

void second_star()
{
    // std::cout << "hi" << std::endl;

    std::ifstream content_list;
    content_list.open("aoc/resources/day03/content_list.txt");

    if (!content_list)
    {
        return;
    }

    std::string firstRucksack, secondRucksack, thirdRucksack;
    std::set<char> contents;
    std::multiset<char> badges;
    int prioritySum = 0;

    while (content_list)
    {
        getline(content_list, firstRucksack);
        getline(content_list, secondRucksack);
        getline(content_list, thirdRucksack);
        contents.clear();

        // std::cout << items << std::endl << firstRucksack << secondRucksack << std::endl;

        for (char c : firstRucksack)
        {
            contents.insert(c);
        }

        for (char c : contents)
        {
            std::cout << c;
            badges.insert(c);
        }

        std::cout << std::endl;

        contents.clear();
        for (char c : secondRucksack)
        {
            contents.insert(c);
        }

        for (char c : contents)
        {
            badges.insert(c);
        }

        contents.clear();
        for (char c : thirdRucksack)
        {
            contents.insert(c);
        }

        for (char c : contents)
        {
            badges.insert(c);
        }

        contents.clear();
        for (char c : badges)
        {
            // std::cout << c << std::endl;
            if (badges.count(c) == 3)
            {
                prioritySum += charToPriority(c);
                badges.clear();
                continue;
            }
        }
    }

    std::cout << prioritySum << std::endl;

    return;
}

int main()
{
    first_star();
    second_star();

    return 1;
}