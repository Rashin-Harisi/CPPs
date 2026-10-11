#include <iostream>
#include <fstream>
#include <string>

void replace(std::string filename, std::string s1, std::string s2 , std::string line){}

std::string fileNameCreate(std::string str){}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage :./replace filename s1 s2" << std::endl;
        return (1);
    }
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string fileName = argv[1];

    std::ifstream inputFile(fileName);
    std::string line;
    std::ofstream outputFile;
    std::string replaceFileName = fileNameCreate(fileName);
    outputFile.open(replaceFileName);
    if (!outputFile.is_open())
    {
        std::cout << "Somthing went wrong in creating a replacement file" << std::endl;
        return (1);
    }
    while (std::getline(inputFile, line))
    {
        replace(replaceFileName, s1, s2, line);
    }

    return (0);
}