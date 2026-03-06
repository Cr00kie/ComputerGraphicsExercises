#include "Scene4.h"
#include "../EntidadesLabs/Ground.h"
#include "../EntidadesLabs/BoxOutline.h"
#include "../EntidadesLabs/Star3D.h"
#include "../EntidadesLabs/GlassParapet.h"
#include "../EntidadesLabs/Photo.h"

#include <glm/gtc/matrix_transform.hpp>

void Scene4::init()
{
	Scene::init();

	Ground* ground = new Ground(300, "baldosaC.png");
	gObjects.push_back(ground);


	//BoxOutline* box = new BoxOutline(100, "container.jpg", "papelE.png");
	//gObjects.push_back(box);

	//Star3D* star = new Star3D(100, 8, 100, "rueda.png");
	//gObjects.push_back(star);

	//GlassParapet* glassParapet = new GlassParapet(100, "windowC.png", 150);
	//gTranslucidObjects.push_back(glassParapet);

	Photo* photo = new Photo(100, "windowC.png", 255);
	photo->setModelMat(glm::translate(glm::mat4(1), glm::vec3(0, 1, 0)) * photo->modelMat());
	gObjects.push_back(photo);
}
