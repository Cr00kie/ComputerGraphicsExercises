#include "Scene4.h"
#include "../EntidadesLabs/Ground.h"
#include "../EntidadesLabs/BoxOutline.h"

void Scene4::init()
{
	Scene::init();

	Ground* ground = new Ground(300, "baldosaC.png");
	//gObjects.push_back(ground);


	BoxOutline* box = new BoxOutline(100, "container.jpg", "papelE.png");
	gObjects.push_back(box);
}
