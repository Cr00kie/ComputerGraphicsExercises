#include "Scene.h"

#include "Light.h"

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
	
	// Create default scene light
	mDefaultLight = new DirLight(0);
	mDefaultLight->setAmb({ 0.25, 0.25, 0.25 });
	mDefaultLight->setDiff({ 0.6, 0.6, 0.6 });
	mDefaultLight->setSpec({ 0.0, 0.2, 0.0 });
	gLights.push_back(mDefaultLight);
}

Scene::~Scene()
{
	destroy();
	resetGL();
}

void
Scene::destroy()
{ // release memory and resources

	for(Light* light : gLights)
		delete light;

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

	// Llamamos aqui a setGL para cambiar el color de fondo
	setGL();
}

void
Scene::unload()
{
	for(Light* light : gLights)
		light->unload(*Shader::get("light"));

	for (Abs_Entity* obj : gObjects)
		obj->unload();
	
	for (Abs_Entity* obj : gTranslucidObjects)
		obj->unload();
}

void Scene::addLight(Light* light)
{
	gLights.push_back(light);
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
	uploadLights(cam);

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

void Scene::uploadLights(const Camera& cam) const
{
	for (Light* light : gLights)
		light->upload(*Shader::get("light"), cam.viewMat());
}

void Scene::update() {
	for (Abs_Entity* el : gObjects)
		el->update();

	for (Abs_Entity* el : gTranslucidObjects)
		el->update();
}

bool Scene::handleKey(unsigned int key)
{
	if (key == 'r')
	{
		mDefaultLight->setEnabled(!mDefaultLight->enabled());
		return true;
	}

	return false;
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
