#include "Scene4.h"
#include "../EntidadesLabs/Ground.h"
#include "../EntidadesLabs/BoxOutline.h"
#include "../EntidadesLabs/Star3D.h"
#include "../EntidadesLabs/GlassParapet.h"

void Scene4::init()
{
	Scene::init();

	//Ground* ground = new Ground(300, "baldosaC.png");
	//gObjects.push_back(ground);


	//BoxOutline* box = new BoxOutline(100, "container.jpg", "papelE.png");
	//gObjects.push_back(box);

	Star3D* star = new Star3D(100, 8, 100, "rueda.png");
	gObjects.push_back(star);

	GlassParapet* glassParapet = new GlassParapet(100, "windowC.png", 150);
	gTranslucidObjects.push_back(glassParapet);
}
