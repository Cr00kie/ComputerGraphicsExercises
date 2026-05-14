#ifndef _H_Droid_H_
#define _H_Droid_H_
#include "CompoundEntity.h"

class SpotLight;
class SphereWithTexture;
class Scene;

class Droid : public CompoundEntity
{
public:
	// Recibimos la escena para añadir la luz del droide a la escena. Si no, la luz no se desactivará al cambiar de escena.
	// No lo hemos hecho con más entidades por si acaso está mal.
	Droid(Scene* parentScene, GLdouble bodyRadius);
	void render(const glm::mat4& modelViewMat) const override;
	void rotateSphere(float amount);
	void toggleLight();

private:
	SpotLight* spotLight;
	SphereWithTexture* droidSphere;
};

#endif