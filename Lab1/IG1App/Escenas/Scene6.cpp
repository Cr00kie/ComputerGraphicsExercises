#include "Scene6.h"
#include "../EntidadesLabs/IndexedBox.h"

void Scene6::init()
{
	Scene::init();

	IndexedBox* box = new IndexedBox(100, {0,1,0,1});
	gObjects.push_back(box);
}
