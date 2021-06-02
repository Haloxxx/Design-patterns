#include "ICoordinatesComponent.h"

#include "GMaps_coordinates.h"

fruit::Component<ICoordinatesFactory> getICoordinatesComponent() {
    return getGMaps_coordinatesComponent();
}