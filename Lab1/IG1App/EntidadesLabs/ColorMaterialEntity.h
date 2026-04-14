#pragma once
#include "SingleColorEntity.h"
class ColorMaterialEntity :
    public SingleColorEntity
{
private:
    static bool sShowNormals;
public:
    ColorMaterialEntity(glm::vec4 col = {0,0,0,1});
    static void toggleShowNormals();
    void render(const glm::mat4& modelViewMat) const override;

};