#include <fruit/fruit.h>
#include <fstream>
#include <array>
#include "Drzewo.h"
#include <iostream>

std::vector<std::unique_ptr<Drzewo>> read_file(std::string path)
{
    std::vector<std::unique_ptr<Drzewo>> result{};
    std::ifstream File(path);
    std::string line{};
    std::string temp{};

    while (getline(File, line))
    {
        temp = line;   
        std::array<std::string,4> params; 
        
        for (int i = 0; i < 4; ++i)
        {
            params[i] = temp.substr(0, temp.find(";"));
            temp = temp.substr(temp.find(";") + std::string(";").length());
        }

        result.push_back(std::unique_ptr<Drzewo>(new Drzewo(params[0],params[1],params[2],params[3])));
    }

    File.close();

    return result;
}



int main()
{
    
    std::vector<std::unique_ptr<Drzewo>> drzewa = read_file("baza.txt");

    
    drzewa[0]->galeria->showPic(0);
    
    drzewa[0]->pozycja->printCoordinates();

    return 0;
}