#ifndef PROXYPHOTO_COMPONENT_H
#define PROXYPHOTO_COMPONENT_H

#include "IPhoto.h"

#include <fruit/fruit.h>

fruit::Component<IPhotoFactory> getProxyPhotoComponent();

#endif