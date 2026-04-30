#ifndef SCENE8_H
#define SCENE8_H
#include "../Scene.h"

class Droid;
class CompoundEntity;
class PosLight;
class SpotLight;

class Scene8 : public Scene
{
public:
	Scene8() = default;
	void init() override;

	void handleKey(unsigned int key) override;

	void rotate();
	void orbit();
protected:
	void setGL() override;

private:
	Droid* mDroid;
	CompoundEntity* mOrbitNode;
	PosLight* mPosLightT;
	SpotLight* mSpotLightY;
};

#endif