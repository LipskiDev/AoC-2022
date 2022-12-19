#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

#define TOTAL_SPACE 70000000
#define SPACE_NEEDED 30000000

struct Directory
{
    int size;
    Directory *parentDirectory;
    std::map<std::string, Directory *> directories;
    std::map<std::string, int> files;
};

// Solid name, dont ask
void calculateTotalSumOfAllDirectoriesWithAtMost100000(Directory *root, int &totalSize)
{
    for (std::map<std::string, Directory *>::iterator it = root->directories.begin(); it != root->directories.end(); it++)
    {
        if (it->second->size < 100000)
            totalSize += it->second->size;
        if (it->second->directories.size() > 0)
            calculateTotalSumOfAllDirectoriesWithAtMost100000(it->second, totalSize);
    }
}

void findSmallestDirectory(Directory *root, int smallestSizePossible, int &smallest)
{
    int smallestRightNow = smallest;

    for (std::map<std::string, Directory *>::iterator it = root->directories.begin(); it != root->directories.end(); it++)
    {
        if (it->second->size > smallestSizePossible)
        {
            if (smallest == 0 || smallestRightNow > it->second->size)
            {
                smallest = it->second->size;
            }
        }

        if (it->second->directories.size() > 0)
            findSmallestDirectory(it->second, smallestSizePossible, smallest);
    }
}

void first_star()
{

    std::ifstream command_history;
    command_history.open("aoc/resources/day07/command_history.txt");

    if (!command_history)
    {
        return;
    }

    // Generate root directory
    Directory *root = new (Directory);
    root->size = 0;
    root->parentDirectory = NULL;
    Directory *currentDirectory = root;

    std::string line;
    getline(command_history, line);

    // Create filesystem
    while (command_history)
    {
        std::getline(command_history, line);

        std::string first, second, third;
        std::stringstream ss(line);

        if (line == "")
        {
            break;
        }
        if (line.at(0) == '$') // User Input
        {
            if (line == "$ ls") // ls command
            {
            }
            else
            { // cd command
                if (line == "$ cd ..")
                {
                    currentDirectory = currentDirectory->parentDirectory;
                }
                else
                {
                    // first = $, second = cd, third = path
                    ss >> first >> second >> third;
                    currentDirectory = currentDirectory->directories.at(third);
                }
            }
        }
        else
        { // Device output
            // case dir: first = dir, second = dirName
            // case file: first = fileSize, second = fileName
            ss >> first >> second;
            if (first == "dir") // case dir
            {
                Directory *toAdd = new Directory();
                toAdd->parentDirectory = currentDirectory;
                toAdd->size = 0;
                currentDirectory->directories.insert({second, toAdd});
            }
            else
            { // case file
                int fileSize = 0;
                fileSize = stoi(first);

                currentDirectory->size += fileSize;
                Directory *parent = currentDirectory->parentDirectory; // used to iterate up to root and add fileSize to all Superdirectories
                do
                {
                    if (parent != NULL)
                    {
                        parent->size += fileSize;
                        parent = parent->parentDirectory;
                    }
                } while (parent != NULL);
            }
        }
    }

    int totalSize = 0;
    // Calculate total size recursively
    calculateTotalSumOfAllDirectoriesWithAtMost100000(root, totalSize);

    std::cout << totalSize << std::endl;

    return;
}

void second_star()
{

    std::ifstream command_history;
    command_history.open("aoc/resources/day07/command_history.txt");

    if (!command_history)
    {
        return;
    }

    // Generate root directory
    Directory *root = new (Directory);
    root->size = 0;
    root->parentDirectory = NULL;
    Directory *currentDirectory = root;

    std::string line;
    getline(command_history, line);

    // Create filesystem
    while (command_history)
    {
        std::getline(command_history, line);

        std::string first, second, third;
        std::stringstream ss(line);

        if (line == "")
        {
            break;
        }
        if (line.at(0) == '$') // User Input
        {
            if (line == "$ ls") // ls command
            {
            }
            else
            { // cd command
                if (line == "$ cd ..")
                {
                    currentDirectory = currentDirectory->parentDirectory;
                }
                else
                {
                    // first = $, second = cd, third = path
                    ss >> first >> second >> third;
                    currentDirectory = currentDirectory->directories.at(third);
                }
            }
        }
        else
        { // Device output
            // case dir: first = dir, second = dirName
            // case file: first = fileSize, second = fileName
            ss >> first >> second;
            if (first == "dir") // case dir
            {
                Directory *toAdd = new Directory();
                toAdd->parentDirectory = currentDirectory;
                toAdd->size = 0;
                currentDirectory->directories.insert({second, toAdd});
            }
            else
            { // case file
                int fileSize = 0;
                fileSize = stoi(first);

                currentDirectory->size += fileSize;
                Directory *parent = currentDirectory->parentDirectory; // used to iterate up to root and add fileSize to all Superdirectories
                do
                {
                    if (parent != NULL)
                    {
                        parent->size += fileSize;
                        parent = parent->parentDirectory;
                    }
                } while (parent != NULL);
            }
        }
    }

    int smallest = 0;
    int freeSpace = TOTAL_SPACE - root->size;
    int spaceNeeded = SPACE_NEEDED - freeSpace;
    findSmallestDirectory(root, spaceNeeded, smallest);
    std::cout << smallest << std::endl;

    return;
}

int main()
{
    first_star();
    second_star();

    return 1;
}