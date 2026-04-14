#include "Scene5.h"
#include "../EntidadesLabs/Torus.h"

void Scene5::init()
{
	Scene::init();

	Torus* torus = new Torus(50,25,40,40,{0,1,0,1});
	gObjects.push_back(torus);
}
