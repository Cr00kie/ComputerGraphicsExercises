#include "Scene9.h"

#include "../EntidadesLabs/Sphere.h"
#include "../EntidadesLabs/Cone.h"
#include "../EntidadesLabs/Disk.h"
#include "../EntidadesLabs/CompoundEntity.h"
#include "glm/gtc/matrix_transform.hpp"

void Scene9::init()
{
	Scene::init();

	// Lo meto todo en una Compound entity por limpieza. Me parece correcto
	CompoundEntity* snowMan = new CompoundEntity;

	// Creamos el cuerpo
	GLdouble bodySize = 100;
	GLdouble headSize = bodySize * 0.75;
	Sphere* body = new Sphere(bodySize, 40, 40, { 1,1,1,1 });
	snowMan->addEntity(body);

	// Creamos la cabeza
	Sphere* head = new Sphere(headSize, 40, 40, { 1,1,1,1 });
	head->setModelMat(glm::translate(glm::mat4(1), { 0, bodySize + headSize/2, 0})); // Lo pongo medio metido para que se vea mas real
	snowMan->addEntity(head);

	// Creamos la nariz y la colocamos en la cabeza
	Cone* nose = new Cone(bodySize * 0.7, 0, bodySize * 0.15, 5, 12, { 1, 0.404, 0, 1 });
	nose->setModelMat(glm::translate(glm::mat4(1), { 0, bodySize + headSize/2, headSize}) * glm::rotate(glm::mat4(1), glm::radians(-90.f), {1,0,0}));
	snowMan->addEntity(nose);

	// Creamos el ojo izq y der
	Cone* leftEye = new Cone(headSize * 0.2, 0, headSize * 0.2, 5, 12, { 0.341, 0.71, 0.604, 1 });
	leftEye->setModelMat(glm::translate(glm::mat4(1), { -headSize/4, bodySize + headSize/2 + headSize/4, headSize}) * glm::rotate(glm::mat4(1), glm::radians(-90.f), {1,0,0}));
	snowMan->addEntity(leftEye);
	Cone* rightEye = new Cone(headSize * 0.2, 0, headSize * 0.2, 5, 12, { 0.341, 0.71, 0.604, 1 });
	rightEye->setModelMat(glm::translate(glm::mat4(1), { headSize / 4, bodySize + headSize/2 + headSize/4, headSize}) * glm::rotate(glm::mat4(1), glm::radians(-90.f), {1,0,0}));
	snowMan->addEntity(rightEye);

	// Creamos el gorro
	Disk* hatDisk = new Disk(bodySize, headSize*0.9, 20, 40, { 0.341, 0.71, 0.604, 1 });
	hatDisk->setModelMat(glm::translate(glm::mat4(1), { 0, bodySize + headSize, 0 }));
	snowMan->addEntity(hatDisk);

	Cone* hatCyl = new Cone(headSize / 2, headSize, headSize, 5, 20, { 0.169, 0.812, 0.627,1 });
	hatCyl->setModelMat(glm::translate(glm::mat4(1), { 0, bodySize + headSize + headSize/4, 0 }));
	snowMan->addEntity(hatCyl);

	Disk* hatTop = new Disk(headSize, 0, 20, 40, { 1, 0.71, 0.71, 1 });
	hatTop->setModelMat(glm::translate(glm::mat4(1), { 0, bodySize + headSize + headSize / 2, 0 }));
	snowMan->addEntity(hatTop);

	gObjects.push_back(snowMan);
}
