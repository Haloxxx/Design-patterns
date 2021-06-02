#ifndef GALLERY_COMPONENT_H
#define GALLERY_COMPONENT_H

#include "IGallery.h"

#include <fruit/fruit.h>

fruit::Component<IGalleryFactory> getIGalleryComponent();

#endif