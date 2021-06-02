#include "PhotoComponent.h"

#include "StandardPhoto.h"

fruit::Component<IPhotoFactory> getPhotoComponent() {
    return getStandardPhotoComponent();
}