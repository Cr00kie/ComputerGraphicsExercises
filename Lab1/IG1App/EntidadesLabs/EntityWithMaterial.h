#ifndef ENTITYWITHMATERIAL_H
#define ENTITYWITHMATERIAL_H
#include "../Entity.h"
#include "../Material.h"

class EntityWithMaterial : public Abs_Entity
{
public:
	EntityWithMaterial();
	void setMaterial(const Material& m) { mMaterial = m; };
	void render(const glm::mat4& modelViewMat) const override;
	static void toggleShowNormals();

protected:
	Material mMaterial;

private:
	static bool sShowNormals;
};

#endif