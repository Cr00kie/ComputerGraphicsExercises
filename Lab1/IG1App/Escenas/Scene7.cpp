#include "Scene7.h"
#include "../EntidadesLabs/Sphere.h"
#include "../EntidadesLabs/Cone.h"
#include "../EntidadesLabs/Disk.h"
#include "../EntidadesLabs/SphereWithTexture.h"

void Scene7::init()
{
	Scene::init();

	/*Sphere* sphere = new Sphere(50,12,12, {0,1,0,1});
	gObjects.push_back(sphere);*/

	/*Cone* cone = new Cone(100, 100, 50, 12, 12, {0,1,0,1});
	gObjects.push_back(cone);*/
	
	/*Disk* disk = new Disk(100, 50, 12, 12, { 0,1,0,1 });
	gObjects.push_back(disk);*/

	SphereWithTexture* sph = new SphereWithTexture(50, 12, 12, "container.jpg");
	gObjects.push_back(sph);
}
