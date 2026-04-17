#ifndef SCENE8_H
#define SCENE8_H
#include "../Scene.h"

class Scene8 : public Scene
{
public:
	Scene8() = default;
	void init() override;

protected:
	void setGL() override;
};

#endif