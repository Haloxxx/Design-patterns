#include "StandardGallery.h"


int StandardGallery::setPathToPics(std::string path)
{
    pathToPics = path;

    //std::cout<<"galeria\n";

    loadImages();

    return 0;
}

std::string StandardGallery::getPathToPics()
{
    return pathToPics;
}

int StandardGallery::loadImages()
{
    int i = 0;

    fruit::Injector<IPhotoFactory> injector(getProxyPhotoComponent);
    IPhotoFactory iphotoFactory(injector);

    for(auto& p: fs::directory_iterator(pathToPics))
    {
        
        std::unique_ptr<IPhoto> pic = iphotoFactory();
        
        pic->setPic(p.path());
        
        photos.push_back(std::move(pic));
    
    }
    return 0;
}

void StandardGallery::showPic(int i)
{
    photos[i]->showPic();
}

int StandardGallery::getSize()
{
    return photos.size();
}

fruit::Component<IGalleryFactory> getStandardGalleryComponent() {
    return fruit::createComponent()
        .bind<IGallery, StandardGallery>();
}