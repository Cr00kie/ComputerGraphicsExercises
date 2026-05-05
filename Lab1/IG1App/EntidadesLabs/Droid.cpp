#include "Droid.h"
#include "SphereWithTexture.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Cone.h"
#include "Disk.h"
#include "../Scene.h"
#include "../Light.h"

Droid::Droid(Scene* parentScene, GLdouble bodyRadius)
{
	GLdouble headHeight = bodyRadius * 0.5f;
	GLdouble eyeRadius = headHeight * 0.25f;
	GLdouble eyeLength = headHeight;

	// Cuerpo
	droidSphere = new SphereWithTexture(bodyRadius, 20, 20, "container.jpg");
	addEntity(droidSphere);

	CompoundEntity* head = new CompoundEntity();
	// Cabeza
	Cone* cone = new Cone(headHeight, bodyRadius, headHeight, 20, 20, {1.0, 1.0, 0.0, 1.0});
	cone->setModelMat(glm::translate(glm::mat4(1), glm::vec3(0, bodyRadius + headHeight * 0.5f, 0)));
	head->addEntity(cone);

	// Ojos
	Cone* leftEye = new Cone(eyeLength, eyeRadius, eyeRadius, 10, 10, {0.0, 1.0, 0.0, 1.0});
	glm::mat4 eyeRotation = glm::rotate(glm::mat4(1), glm::radians(90.f), glm::vec3(1, 0, 0));
	glm::mat4 leftEyeTranslation = glm::translate(glm::mat4(1), glm::vec3(eyeRadius, bodyRadius + headHeight / 2, bodyRadius));
	leftEye->setModelMat(leftEyeTranslation * eyeRotation);
	head->addEntity(leftEye);

	Cone* rightEye = new Cone(eyeLength, eyeRadius, eyeRadius, 10, 10, { 0.0, 1.0, 0.0, 1.0 });
	glm::mat4 rightEyeTranslation = glm::translate(glm::mat4(1), glm::vec3(-eyeRadius, bodyRadius + headHeight / 2, bodyRadius));
	rightEye->setModelMat(rightEyeTranslation * eyeRotation);
	head->addEntity(rightEye);

	// Tapas
	Disk* tapaInferior = new Disk(0, bodyRadius, 1, 20, { 1.0, 1.0, 0.0, 1.0 });
	tapaInferior->setModelMat(glm::translate(modelMat(), glm::vec3(0, bodyRadius, 0))* glm::rotate(glm::mat4(1), glm::radians(180.f), glm::vec3(0, 0, 1)));
	head->addEntity(tapaInferior);

	Disk* tapaSuperior = new Disk(0, headHeight, 1, 20, { 1.0, 1.0, 0.0, 1.0 });
	tapaSuperior->setModelMat(glm::translate(glm::mat4(1), glm::vec3(0, bodyRadius+headHeight, 0)));
	head->addEntity(tapaSuperior);

	addEntity(head);

	// Luces
	spotLight = new SpotLight({0, 0, 0}, 1);

	spotLight->setAmb({ 0.25, 0.25, 0.25 });
	spotLight->setDiff({ 0.6, 0.6, 0.6 });
	spotLight->setSpec({ 0.0, 0.2, 0.0 });

	parentScene->addLight(spotLight);
}

void Droid::render(const glm::mat4& modelViewMat) const
{
	CompoundEntity::render(modelViewMat);
	spotLight->upload(*Shader::get("light"), modelViewMat * mModelMat);
}

void Droid::rotateSphere(float amount)
{
	droidSphere->setModelMat(glm::rotate(glm::mat4(1.f), amount, glm::vec3(1.f, 0.f, 0.f)) * droidSphere->modelMat());
}
