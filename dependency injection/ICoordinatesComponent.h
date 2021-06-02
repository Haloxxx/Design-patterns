#ifndef COORDINATES_COMPONENT_H
#define COORDINATES_COMPONENT_H

#include "ICoordinates.h"

#include <fruit/fruit.h>

fruit::Component<ICoordinatesFactory> getICoordinatesComponent();

#endif