#include "GMaps_coordinates.h"
#include <iostream>


int GMaps_coordinates::setCoordinates(std::string kordy)
{
            dlugosc = stod(kordy.substr(0, kordy.find(",")));
            szerokosc = stod(kordy.substr(kordy.find(",")+std::string(";").length(),kordy.length()));

            return 0;
}

void GMaps_coordinates::printCoordinates()
{
    std::cout<<"Długość: "<<dlugosc<<" szerokość: "<<szerokosc<<'\n';
}


fruit::Component<ICoordinatesFactory> getGMaps_coordinatesComponent() {
    return fruit::createComponent()
        .bind<ICoordinates, GMaps_coordinates>();
}
