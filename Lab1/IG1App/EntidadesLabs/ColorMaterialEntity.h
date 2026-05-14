#ifndef COLOR_MATERIAL_ENTITY_H
#define COLOR_MATERIAL_ENTITY_H

#include "EntityWithMaterial.h"

class ColorMaterialEntity : public EntityWithMaterial
{
public:
    ColorMaterialEntity(glm::vec4 col = {0,0,0,1});
};

#endif