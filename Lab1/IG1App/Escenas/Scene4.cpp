#include "Scene4.h"
#include "../EntidadesLabs/Ground.h"
#include "../EntidadesLabs/BoxOutline.h"
#include "../EntidadesLabs/Star3D.h"
#include "../EntidadesLabs/GlassParapet.h"
#include "../EntidadesLabs/Photo.h"
#include "../EntidadesLabs/Grass.h"

#include <glm/gtc/matrix_transform.hpp>

void Scene4::init()
{
	Scene::init();

	// Creamos el suelo
	Ground* ground = new Ground(300, "baldosaC.png");
	gObjects.push_back(ground);

	// Creamos la caja
	GLdouble boxSize = 70;
	BoxOutline* box = new BoxOutline(boxSize, "container.jpg", "papelE.png");
	box->setModelMat(glm::translate(glm::mat4(1), glm::vec3(-80, boxSize/2, -80)) * box->modelMat());
	gObjects.push_back(box);

	// Creamos la estrella dentro de la caja
	Star3D* star = new Star3D(25, 8, 25, "rueda.png");
	star->setModelMat(glm::translate(glm::mat4(1), glm::vec3(-80, 25, -80)) * star->modelMat());
	gObjects.push_back(star);

	// Creamos los bordes transparentes
	GlassParapet* glassParapet = new GlassParapet(300, "windowC.png", 150);
	glassParapet->setModelMat(glm::scale(glm::mat4(1.f), glm::vec3(1.f, 0.3f, 1.f)) * glassParapet->modelMat());
	gTranslucidObjects.push_back(glassParapet);

	// Creamos la foto
	Photo* photo = new Photo(80, 255);
	photo->setModelMat(glm::translate(glm::mat4(1), glm::vec3(0, 1, 0)) * 
							glm::rotate(glm::mat4(1.f), glm::radians(-90.f),
						glm::vec3(1, 0, 0)) * photo->modelMat());
	gObjects.push_back(photo);

	// Creamos la hierba
	Grass* grass = new Grass(40, 40, "grass.png", 255);
	grass->setModelMat(glm::translate(glm::mat4(1), glm::vec3(80, 20, 80)) * grass->modelMat());
	gObjects.push_back(grass);
}
