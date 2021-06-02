#ifndef StandardProxyPhoto_H
#define StandardProxyPhoto_H

#include "IPhoto.h"
#include "PhotoComponent.h"
#include <string>
#include <fruit/fruit.h>

fruit::Component<IPhotoFactory> getStandardProxyPhotoComponent();

class StandardProxyPhoto : public IPhoto
{
    public:
        

        INJECT(StandardProxyPhoto()) = default;

        int setPic(std::string path) override;
        void showPic() override;
        void showMiniature() override;
};


#endif
