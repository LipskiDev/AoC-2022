#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <deque>
#include <sstream>
#include <set>

void first_star()
{

    std::ifstream datastream_buffer;
    datastream_buffer.open("aoc/resources/day06/datastream_buffer.txt");

    if (!datastream_buffer)
    {
        return;
    }

    std::deque<char> packet;
    std::set<char> helper;
    int index = 0;

    std::string buffer;
    getline(datastream_buffer, buffer);

    // For each character in given input
    for (char c : buffer)
    {
        // Remove longest lasting member of deque
        if (packet.size() == 4)
        {
            packet.pop_back();
        }

        packet.push_front(c);

        // Add all Elements of deque to map
        for (char ch : packet)
        {
            helper.insert(ch);
        }
        // Check if deque consisted of 4 diffrent characters
        if (helper.size() == 4)
        {
            ++index;
            break;
        }

        helper.clear();

        ++index;
    }

    std::cout << index << std::endl;

    return;
}

void second_star()
{
    std::ifstream datastream_buffer;
    datastream_buffer.open("aoc/resources/day06/datastream_buffer.txt");

    if (!datastream_buffer)
    {
        return;
    }

    std::deque<char> packet;
    std::set<char> helper;
    int index = 0;

    std::string buffer;
    getline(datastream_buffer, buffer);

    // For each character in given input
    for (char c : buffer)
    {
        // Remove longest lasting member of deque
        if (packet.size() == 14)
        {
            packet.pop_back();
        }

        packet.push_front(c);

        // Add all Elements of deque to map
        for (char ch : packet)
        {
            helper.insert(ch);
        }
        // Check if deque consisted of 4 diffrent characters
        if (helper.size() == 14)
        {
            ++index;
            break;
        }

        helper.clear();

        ++index;
    }

    std::cout << index << std::endl;

    return;
}

int main()
{
    first_star();
    second_star();

    return 1;
}