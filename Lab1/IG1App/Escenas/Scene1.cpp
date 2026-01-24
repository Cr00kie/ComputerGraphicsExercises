#include "Scene1.h"
#include "../EntidadesLabs/RegularPoligon.h"

void Scene1::init()
{
	setGL();

	gObjects.push_back(new RGBAxes(400.0));
	// Hexagono Magenta
	gObjects.push_back(new RegularPoligon(6, 300, {1,0,1,1}));
	// Circunferencia Amarilla
	gObjects.push_back(new RegularPoligon(40, 300, { 1,1,0,1 }));
}
