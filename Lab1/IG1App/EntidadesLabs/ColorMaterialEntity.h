#pragma once
#include "SingleColorEntity.h"
class ColorMaterialEntity :
    public SingleColorEntity
{
public:
    ColorMaterialEntity(glm::vec4 col = {0,0,0,1});
};

