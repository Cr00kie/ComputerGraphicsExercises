#include "Scene2.h"
#include "../EntidadesLabs/RGBTriangle.h"
#include "../EntidadesLabs/RGBRectangle.h"
#include "../EntidadesLabs/RegularPoligon.h"
#include "glm/gtc/matrix_transform.hpp"


void Scene2::init()
{
	setGL();

	gObjects.push_back(new RGBAxes(400.0));


	gObjects.push_back(new RGBRectangle(200, 200));

	const GLdouble rad = glm::sqrt(10000 * 2);
	gObjects.push_back(new RegularPoligon(40, rad, { 1.0, 0.0, 1.0, 1.0 }));

	RGBTriangle* triangle = new RGBTriangle(100);
	// Colocamos el triangulo en la posicion pedida en el apartado 11
	triangle->setModelMat(glm::translate(triangle->modelMat(), { rad, 0, 0 }));
	gObjects.push_back(triangle);
}
