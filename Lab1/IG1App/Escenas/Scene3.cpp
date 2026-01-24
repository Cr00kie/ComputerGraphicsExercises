#include "Scene3.h"
#include "../EntidadesLabs/Cube.h"
#include "../EntidadesLabs/RGBCube.h"

void Scene3::init()
{
	setGL();

	gObjects.push_back(new RGBAxes(400.0));
	gObjects.push_back(new RGBCube(400));
}
