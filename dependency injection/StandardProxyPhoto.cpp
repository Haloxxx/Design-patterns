#include "StandardProxyPhoto.h"
//
#include <iostream>


int StandardProxyPhoto::setPic(std::string path)
{
    name = path;
    return 0;
}

void StandardProxyPhoto::showPic()
{
    if (pic == nullptr){

        fruit::Injector<IPhotoFactory> injector(getPhotoComponent);
        IPhotoFactory photoFactory(injector);
    
        pic = photoFactory();
    }
    
    pic->setPic(name);
    pic->showPic();
}

void StandardProxyPhoto::showMiniature()
{

}

fruit::Component<IPhotoFactory> getStandardProxyPhotoComponent() {
    return fruit::createComponent()
        .bind<IPhoto, StandardProxyPhoto>();
}