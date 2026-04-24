#ifndef COLOR_MATERIAL_ENTITY_H
#define COLOR_MATERIAL_ENTITY_H

#include "EntityWithMaterial.h"

class ColorMaterialEntity : public EntityWithMaterial
{
private:
    static bool sShowNormals;

public:
    ColorMaterialEntity(glm::vec4 col = {0,0,0,1});
    static void toggleShowNormals();
    void render(const glm::mat4& modelViewMat) const override;

};

#endif