#include "Scene2.h"
#include "../EntidadesLabs/RGBTriangle.h"
#include "../EntidadesLabs/RGBRectangle.h"
#include "../EntidadesLabs/RegularPoligon.h"
#include "glm/gtc/matrix_transform.hpp"


void Scene2::init()
{
	Scene::init();

	constexpr GLdouble rectangleLength = 200;
	constexpr GLdouble halfRectLength = rectangleLength / 2;
	gObjects.push_back(new RGBRectangle(rectangleLength, rectangleLength));

	const GLdouble rad = glm::sqrt(halfRectLength * halfRectLength * 2);
	gObjects.push_back(new RegularPoligon(40, rad, { 1.0, 0.0, 1.0, 1.0 }));

	RGBTriangle* triangle = new RGBTriangle(100);
	// Colocamos el triangulo en la posicion pedida en el apartado 11
	triangle->setModelMat(glm::translate(triangle->modelMat(), { rad, 0, 0 }));
	gObjects.push_back(triangle);
}
