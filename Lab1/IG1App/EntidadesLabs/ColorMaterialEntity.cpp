#include "ColorMaterialEntity.h"

ColorMaterialEntity::ColorMaterialEntity(glm::vec4 col)
	: SingleColorEntity(col)
{
	mShader = Shader::get("simple_light");
}
