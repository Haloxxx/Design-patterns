#include "StandardPhoto.h"


int StandardPhoto::setPic(std::string path)
{
    name = path;
    return 0;
}

void StandardPhoto::showMiniature()
{

}

void StandardPhoto::showPic()
{
    using namespace Graph_lib;
    
    Point tl(100,100);
    Simple_window win(tl,800,1000,"Canvas");
    Image photo {Point{0,200},name};
    photo.set_mask(Point{150,0},200,200);

    win.attach(photo);
    win.wait_for_button();

}

fruit::Component<IPhotoFactory> getStandardPhotoComponent() {
    return fruit::createComponent()
        .bind<IPhoto, StandardPhoto>();
}