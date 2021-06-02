#ifndef StandardGallery_H
#define StandardGallery_H

#include <fruit/fruit.h>
#include <filesystem>
//
#include <iostream>
#include "IGallery.h"
#include "ProxyPhotoComponent.h"

namespace fs = std::filesystem;

fruit::Component<IGalleryFactory> getStandardGalleryComponent();

class StandardGallery : public IGallery{
    public:
        
        std::string pathToPics;

        INJECT(StandardGallery()) = default;

        int setPathToPics(std::string path) override;
        std::string getPathToPics() override;

        void showPic(int i) override;

        int getSize() override;

        int loadImages() override;
};

#endif