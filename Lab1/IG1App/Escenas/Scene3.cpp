#include "Scene3.h"
#include "../EntidadesLabs/Cube.h"
#include "../EntidadesLabs/RGBCube.h"
#include "glm/gtc/matrix_transform.hpp"

void Scene3::init()
{
	Scene::init();

	RGBCube* cube = new RGBCube(400);
	gObjects.push_back(cube);
	cube->setModelMat(glm::translate(cube->modelMat(), { 200, 200, -200 }));
}
