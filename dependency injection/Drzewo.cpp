#include "Drzewo.h"

Drzewo::Drzewo(std::string name,std::string year, std::string path, std::string coordinates)
{
    nazwa = name;
    year = rok_posadzenia;

    fruit::Injector<IGalleryFactory> GalleryInjector(getIGalleryComponent);
    IGalleryFactory igalleryFactory(GalleryInjector);
    galeria = igalleryFactory();
    galeria->setPathToPics(path);


    fruit::Injector<ICoordinatesFactory> CoordinatesInjector(getICoordinatesComponent);
    ICoordinatesFactory icoordinatesFactory(CoordinatesInjector);
    pozycja = icoordinatesFactory();
    pozycja->setCoordinates(coordinates);

}