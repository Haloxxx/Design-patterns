#include <string>
#include <fruit/fruit.h>
#include "ICoordinates.h"


fruit::Component<ICoordinatesFactory> getGMaps_coordinatesComponent();

class GMaps_coordinates : public ICoordinates{
    public:
        double dlugosc;
        double szerokosc;

        INJECT(GMaps_coordinates()) = default;

        int setCoordinates(std::string kordy) override;
        void printCoordinates() override;

};