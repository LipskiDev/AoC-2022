#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <deque>

int main()
{
    std::ifstream calories_list;
    calories_list.open("aoc/resources/day01/calories_list.txt");

    if (!calories_list)
        return 0;

    std::string currentLine;
    int lineAsInt;
    std::deque<int> maxs = {-1, -1, -1};
    int maxIndex = -1;
    int counter = 0;
    int index = 0;

    while (calories_list)
    {
        std::getline(calories_list, currentLine);
        if (currentLine.compare("") == 0)
        {
            if (counter > maxs.front())
            {
                maxs.push_front(counter);
                maxs.pop_back();
            }
            else if (counter > maxs.back())
            {
                int pop = maxs.back();
                maxs.pop_back();
                if (counter > maxs.back())
                {
                    pop = maxs.back();
                    maxs.pop_back();
                    maxs.push_back(counter);
                    maxs.push_back(pop);
                }
                else
                {
                    maxs.push_back(counter);
                }
            }

            counter = 0;
            ++index;
            continue;
        }

        lineAsInt = stoi(currentLine);

        counter = counter + lineAsInt;
    }
    int max = 0;
    while (maxs.size() != 0)
    {
        max = max + maxs.front();
        maxs.pop_front();
    }
    std::cout << max << " " << maxIndex << std::endl;

    return 1;
}