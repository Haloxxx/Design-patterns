#include "IGalleryComponent.h"

#include "StandardGallery.h"

fruit::Component<IGalleryFactory> getIGalleryComponent() {
    return getStandardGalleryComponent();
}