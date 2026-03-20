#include "Scene.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <array>
#include <stdexcept>

using namespace glm;

void
Scene::init()
{
	setGL(); // OpenGL settings

	// allocate memory and load resources
	// Lights
	// Textures

	// Graphics objects (entities) of the scene
	gObjects.push_back(new RGBAxes(400.0));
}

Scene::~Scene()
{
	destroy();
	resetGL();
}

void
Scene::destroy()
{ // release memory and resources

	for (Abs_Entity* el : gObjects)
		delete el;

	for (Abs_Entity* obj : gTranslucidObjects)
		delete obj;

	gObjects.clear();
	gTranslucidObjects.clear();
}

void
Scene::load()
{
	for (Abs_Entity* obj : gObjects)
		obj->load();

	for (Abs_Entity* obj : gTranslucidObjects)
		obj->load();
}

void
Scene::unload()
{
	for (Abs_Entity* obj : gObjects)
		obj->unload();
	
	for (Abs_Entity* obj : gTranslucidObjects)
		obj->unload();
}

void
Scene::setGL()
{
	// OpenGL basic setting
	// Cambio color de fondo (APARTADO 1)
	glClearColor(0.6, 0.7, 0.8, 1.0); // background color (alpha=1 -> opaque)
	glEnable(GL_DEPTH_TEST);          // enable Depth test
}
void
Scene::resetGL()
{
	glClearColor(.0, .0, .0, .0); // background color (alpha=1 -> opaque)
	glDisable(GL_DEPTH_TEST);     // disable Depth test
}

void
Scene::render(Camera const& cam) const
{
	cam.upload();

	for (Abs_Entity* el : gObjects)
		el->render(cam.viewMat());

	glEnable(GL_BLEND);
	glDepthMask(GL_FALSE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	for (Abs_Entity* el : gTranslucidObjects)
		el->render(cam.viewMat());

	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);
}

void Scene::update() {
	for (Abs_Entity* el : gObjects)
		el->update();

	for (Abs_Entity* el : gTranslucidObjects)
		el->update();
}

Texture* Scene::getTexture(const std::string& name, GLubyte alpha)
{
	// Check whether the texture is already loaded
	// Usamos auto para evitar escribir el tipo del iterador
	auto it = gTextures.find(name);

	if (it == gTextures.end()) {
		std::unique_ptr<Texture> texture = std::make_unique<Texture>();
		try
		{
			// Load the texture from file (under the texture root)
			texture->load("../assets/images/" + name, alpha);
		}
		// Si no se encuentra capturamos el error, pero no paramos, se quedará una textura negra
		catch(std::logic_error){}

		it = gTextures.insert({ name, std::move(texture) }).first;
	}

	return it->second.get();
}
