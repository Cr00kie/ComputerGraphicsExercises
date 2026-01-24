#include "RegularPoligon.h"

RegularPoligon::RegularPoligon(GLuint num, GLdouble rad, glm::vec4 col = { 0,0,0,1 })
	: SingleColorEntity(col)
{
	mMesh = Mesh::generateRegularPolygon(num, rad);
}
