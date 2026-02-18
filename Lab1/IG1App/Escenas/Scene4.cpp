#include "Scene4.h"
#include "../EntidadesLabs/Ground.h"

void Scene4::init()
{
	Scene::init();

	Texture* groundTex = new Texture();
	groundTex->load("../assets/images/baldosaC.png");
	gTextures.push_back(groundTex);

	Ground* ground = new Ground(300);
	ground->setTexture(groundTex);
	gObjects.push_back(ground);
}
