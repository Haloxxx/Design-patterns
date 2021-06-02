#ifndef StandardPhoto_H
#define StandardPhoto_H

#include <fruit/fruit.h>
#include "IPhoto.h"
#include "Simple_window.hpp"
#include "Graph.hpp"

fruit::Component<IPhotoFactory> getStandardPhotoComponent();

class StandardPhoto : public IPhoto
{
    public:

        INJECT(StandardPhoto()) = default;
        //~StandardPhoto(){};

        int setPic(std::string path) override;
        void showPic() override;
        void showMiniature() override;
};



#endif