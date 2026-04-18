#ifndef SCENE8_H
#define SCENE8_H
#include "../Scene.h"

class Droid;
class CompoundEntity;

class Scene8 : public Scene
{
public:
	Scene8() = default;
	void init() override;

	void rotate() override;
	void orbit() override;
protected:
	void setGL() override;

private:
	Droid* mDroid;
	CompoundEntity* mOrbitNode;
};

#endif