#include "Photo.h"

#include "../IG1App.h"
#include <glm/gtc/matrix_transform.hpp>

Photo::Photo(GLdouble length, GLfloat alpha)
					// Ponemos una textura random para que no lance error
	: EntityWithTexture("\0", alpha), mLength(length)
{
	mMesh = Mesh::generateRectangleTexCor(length, length, 1, 1);

	mTexture->loadColorBuffer(IG1App::s_ig1app.viewPort().width(), IG1App::s_ig1app.viewPort().height());
}

void Photo::update()
{
	mTexture->loadColorBuffer(IG1App::s_ig1app.viewPort().width(), IG1App::s_ig1app.viewPort().height());
}
