#ifndef IPhoto_H
#define IPhoto_H

#include <string>
#include <fruit/fruit.h>

class IPhoto
{
    public:

        virtual ~IPhoto(){};
        std::unique_ptr<IPhoto> pic;
        std::string name{};
        virtual int setPic(std::string path) = 0;
        virtual void showPic() = 0;
        virtual void showMiniature() = 0;
};

using IPhotoFactory = std::function<std::unique_ptr<IPhoto>()>;

#endif
