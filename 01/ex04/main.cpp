/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdolho <rabdolho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 10:09:36 by rabdolho          #+#    #+#             */
/*   Updated: 2026/10/12 14:38:21 by rabdolho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string replace(std::string s1, std::string s2 , std::string line)
{
    if (s1 == "") return (line);
    std::string::size_type indexFound;
    std::string::size_type position = 0;
    while((indexFound = line.find(s1, position)) != std::string::npos )
    {
        line = line.substr(0, indexFound) + s2 + line.substr(indexFound + s1.size());
        position  =  indexFound + s2.size();
    }
    return line;
}

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
    std::string line;
    std::string newLine;

    std::ifstream inputFile(fileName.c_str());
    if (!inputFile.is_open())
    {
        std::cout << "Somthing went wrong in opening the file" << std::endl;
        return (1);
    }
    std::ofstream outputFile;
    std::string replaceFileName = fileName + ".replace";
    outputFile.open(replaceFileName.c_str());
    if (!outputFile.is_open())
    {
        std::cout << "Somthing went wrong in creating a replacement file" << std::endl;
        return (1);
    }
    std::ostringstream streamContent;
    streamContent << inputFile.rdbuf();
    if (streamContent.bad() || (streamContent.fail() && !streamContent.eof()))
    {
        std::cout << "Error reading from the file." << std::endl;
        return (1);
    }
    line = streamContent.str();
    newLine = replace(s1, s2, line);
    outputFile << newLine;
    if (!outputFile)
    {
        std::cout << "Error writing the content to the replace file." << std::endl;
        return (1);
    }
    inputFile.close();
    outputFile.close();
    if (outputFile.fail() || inputFile.fail())
    {
        std::cout << "Error closing files." << std::endl;
        return (1);
    }
    return (0);
}