#include "IGallery.h"
#include "ICoordinates.h"
#include "IGalleryComponent.h"
#include "ICoordinatesComponent.h"

class Drzewo
{
    public:
        std::string nazwa{};
        std::string rok_posadzenia{};
        std::unique_ptr<IGallery> galeria{}; 
        std::unique_ptr<ICoordinates> pozycja{};

        Drzewo(std::string name,std::string year, std::string path, std::string coordinates);
};