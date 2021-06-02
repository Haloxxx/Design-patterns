#ifndef PHOTO_COMPONENT_H
#define PHOTO_COMPONENT_H

#include "IPhoto.h"

#include <fruit/fruit.h>

fruit::Component<IPhotoFactory> getPhotoComponent();

#endif