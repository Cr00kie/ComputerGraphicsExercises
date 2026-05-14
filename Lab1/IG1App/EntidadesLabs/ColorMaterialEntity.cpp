#include "ColorMaterialEntity.h"

bool ColorMaterialEntity::sShowNormals = false;

ColorMaterialEntity::ColorMaterialEntity(glm::vec4 col)
	: EntityWithMaterial()
{
	mMaterial.setAmb(col);
	mMaterial.setDiff(col);
	mMaterial.setSpec(col);
}
