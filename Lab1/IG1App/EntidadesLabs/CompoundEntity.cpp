#include "CompoundEntity.h"

CompoundEntity::~CompoundEntity()
{
	for (Abs_Entity* el : gObjects)
		delete el;

	gObjects.clear();
}

void CompoundEntity::render(const glm::mat4& modelViewMat) const
{
	// Aplicamos la transformación del objeto padre a los objetos hijos
	glm::mat4 aMat = modelViewMat * mModelMat;
	for (Abs_Entity* el : gObjects) el->render(aMat);
}

void CompoundEntity::update()
{
	for (Abs_Entity* el : gObjects) el->update();
}

void CompoundEntity::load()
{
	for (Abs_Entity* el : gObjects) el->load();
}

void CompoundEntity::unload()
{
	for (Abs_Entity* el : gObjects) el->unload();
}

void CompoundEntity::addEntity(Abs_Entity* ae)
{
	gObjects.push_back(ae);
}
