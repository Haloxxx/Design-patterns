#include "ProxyPhotoComponent.h"

#include "StandardProxyPhoto.h"

fruit::Component<IPhotoFactory> getProxyPhotoComponent() {
    return getStandardProxyPhotoComponent();
}