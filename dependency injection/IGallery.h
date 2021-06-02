#ifndef IGallery_H
#define IGallery_H

#include "IPhoto.h"
#include <vector>
#include <string>

class IGallery
{
    public:
        virtual ~IGallery(){};
        std::vector<std::shared_ptr<IPhoto>> photos{};

        virtual int setPathToPics(std::string path) = 0;
        virtual std::string getPathToPics() = 0;
        virtual void showPic(int i) = 0;

        virtual int getSize() = 0;

        virtual int loadImages() = 0;
};

using IGalleryFactory = std::function<std::unique_ptr<IGallery>()>;

#endif