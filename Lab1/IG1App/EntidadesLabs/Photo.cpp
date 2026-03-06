#include "Photo.h"

#include "../IG1App.h"
#include <glm/gtc/matrix_transform.hpp>

Photo::Photo(GLdouble length, const std::string& imageName, GLfloat alpha)
	: EntityWithTexture(imageName, alpha), mLength(length)
{
	mMesh = Mesh::generateRectangleTexCor(length, length, 1, 1);
	// TODO: en teor'ia esto est'a mal pq en el constructor no se mueven las entidades, pero es lo que dice el enunciado
	setModelMat(glm::rotate(glm::mat4(1.f), glm::radians(-90.f), glm::vec3(1, 0, 0)));
}

void Photo::update()
{
	mTexture->loadColorBuffer(IG1App::s_ig1app.viewPort().width(), IG1App::s_ig1app.viewPort().height());
}
