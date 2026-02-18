#include "Mesh.h"

using namespace std;
using namespace glm;

// Placeholder for the pending index of a GPU object
constexpr GLuint NONE = numeric_limits<GLuint>::max();

Mesh::Mesh()
 : mVAO(NONE)
 , mVBO(NONE)
 , mCBO(NONE)
{
}

Mesh::~Mesh()
{
	unload();
}

void
Mesh::draw() const
{
	glDrawArrays(
	  mPrimitive,
	  0,
	  size()); // primitive graphic, first index and number of elements to be rendered
}

void
Mesh::load()
{
	assert(mVBO == NONE); // not already loaded

	if (vVertices.size() > 0) { // transfer data
		glGenBuffers(1, &mVBO);
		glGenVertexArrays(1, &mVAO);

		glBindVertexArray(mVAO);
		glBindBuffer(GL_ARRAY_BUFFER, mVBO);
		glBufferData(GL_ARRAY_BUFFER, vVertices.size() * sizeof(vec3), vVertices.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vec3), nullptr);
		glEnableVertexAttribArray(0);

		if (vColors.size() > 0) {             // upload colors
			glGenBuffers(1, &mCBO);

			glBindBuffer(GL_ARRAY_BUFFER, mCBO);
			glBufferData(GL_ARRAY_BUFFER, vColors.size() * sizeof(vec4), vColors.data(), GL_STATIC_DRAW);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(vec4), nullptr);
			glEnableVertexAttribArray(1);
		}
	}
}

void
Mesh::unload()
{
	if (mVAO != NONE) {
		glDeleteVertexArrays(1, &mVAO);
		glDeleteBuffers(1, &mVBO);
		mVAO = NONE;
		mVBO = NONE;

		if (mCBO != NONE) {
			glDeleteBuffers(1, &mCBO);
			mCBO = NONE;
		}
	}
}

void
Mesh::render() const
{
	assert(mVAO != NONE);

	glBindVertexArray(mVAO);
	draw();
}

Mesh*
Mesh::createRGBAxes(GLdouble l)
{
	Mesh* mesh = new Mesh();

	mesh->mPrimitive = GL_LINES;

	mesh->mNumVertices = 6;
	mesh->vVertices.reserve(mesh->mNumVertices);

	// X axis vertices
	mesh->vVertices.emplace_back(0.0, 0.0, 0.0);
	mesh->vVertices.emplace_back(l, 0.0, 0.0);
	// Y axis vertices
	mesh->vVertices.emplace_back(0, 0.0, 0.0);
	mesh->vVertices.emplace_back(0.0, l, 0.0);
	// Z axis vertices
	mesh->vVertices.emplace_back(0.0, 0.0, 0.0);
	mesh->vVertices.emplace_back(0.0, 0.0, l);

	mesh->vColors.reserve(mesh->mNumVertices);
	// X axis color: red  (Alpha = 1 : fully opaque)
	mesh->vColors.emplace_back(1.0, 0.0, 0.0, 1.0);
	mesh->vColors.emplace_back(1.0, 0.0, 0.0, 1.0);
	// Y axis color: green
	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);
	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);
	// Z axis color: blue
	mesh->vColors.emplace_back(0.0, 0.0, 1.0, 1.0);
	mesh->vColors.emplace_back(0.0, 0.0, 1.0, 1.0);

	return mesh;
}

// crea un polígono regular 
Mesh* Mesh::generateRegularPolygon(GLuint num, GLdouble r)
{
	Mesh* mesh = new Mesh();


	mesh->mPrimitive = GL_LINE_LOOP;
	mesh->mNumVertices = num;
	mesh->vVertices.reserve(mesh->mNumVertices);

	const float angleDelta = glm::radians(360.0f/num);
	constexpr float offSet = glm::radians(90.0f);
	// Creamos los vertices
	for (int i = 0; i < num; i++) {
		float angle = offSet + angleDelta * i;
		mesh->vVertices.emplace_back(r * glm::cos(angle), r * glm::sin(angle), 0);
	}

	return mesh;
}

Mesh* Mesh::generateRBGTriangle(GLdouble r)
{
	Mesh* mesh = Mesh::generateRegularPolygon(3, r);

	// Ponemos bien la primitiva
	mesh->mPrimitive = GL_TRIANGLES;

	mesh->vColors.reserve(mesh->mNumVertices);
	// Rojo
	mesh->vColors.emplace_back(1.0, 0.0, 0.0, 1.0);
	// Verde
	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);
	// Azul
	mesh->vColors.emplace_back(0.0, 0.0, 1.0, 1.0);

	return mesh;
}

Mesh* Mesh::generateRectangle(GLdouble w, GLdouble h)
{
	Mesh* mesh = new Mesh();

	mesh->mPrimitive = GL_TRIANGLE_STRIP;

	mesh->mNumVertices = 4;
	mesh->vVertices.reserve(mesh->mNumVertices);

	mesh->vVertices.emplace_back(-w / 2,  h / 2, 0.0);
	mesh->vVertices.emplace_back(-w / 2, -h / 2, 0.0);
	mesh->vVertices.emplace_back( w / 2,  h / 2, 0.0);
	mesh->vVertices.emplace_back( w / 2, -h / 2, 0.0);

	return mesh;
}

Mesh* Mesh::generateRGBRectangle(GLdouble w, GLdouble h)
{
	Mesh* mesh = generateRectangle(w, h);

	mesh->vColors.reserve(mesh->mNumVertices);
	mesh->vColors.emplace_back(1.0, 0.0, 0.0, 1.0);
	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);
	mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);
	mesh->vColors.emplace_back(0.0, 0.0, 1.0, 1.0);

	return mesh;
}

Mesh* Mesh::generateCube(GLdouble length)
{
	Mesh* mesh = new Mesh();

	mesh->mPrimitive = GL_TRIANGLES;
	mesh->mNumVertices = 36;
	mesh->vVertices.reserve(mesh->mNumVertices);

	//	6 - - - - - - - - - 5
	//	 | \             | \
	//	 |   - - - - - - - - -
	//	 |   |0          |   |1
	//	 |   |           |   |
	//	 |   |           |   |
	//	 |   |           |   |
	//	 |   |           |4  |
	//	7 - -| - - - - - -   |
	//	   \ |2            \ |3
	//	     - - - - - - - - -
	//
	//		 y |
	//		   |
	//	   z - -
	//			\ x

	// Cara +X
	mesh->vVertices.emplace_back(length / 2, -length / 2, -length / 2); // 3
	mesh->vVertices.emplace_back(length / 2, length / 2, length / 2); // 0
	mesh->vVertices.emplace_back(length / 2, -length / 2, length / 2); // 2

	mesh->vVertices.emplace_back(length / 2, length / 2, -length / 2); // 1
	mesh->vVertices.emplace_back(length / 2, length / 2, length / 2); // 0
	mesh->vVertices.emplace_back(length / 2, -length / 2, -length / 2); // 3

	// Cara +Z
	mesh->vVertices.emplace_back(length / 2, -length / 2, length / 2); // 2
	mesh->vVertices.emplace_back(-length / 2, length / 2, length / 2); // 6
	mesh->vVertices.emplace_back(-length / 2, -length / 2, length / 2); // 7

	mesh->vVertices.emplace_back(length / 2, length / 2, length / 2); // 0
	mesh->vVertices.emplace_back(-length / 2, length / 2, length / 2); // 6
	mesh->vVertices.emplace_back(length / 2, -length / 2, length / 2); // 2

	// Cara -X
	mesh->vVertices.emplace_back(-length / 2, -length / 2, length / 2); // 7
	mesh->vVertices.emplace_back(-length / 2, length / 2, -length / 2); // 5
	mesh->vVertices.emplace_back(-length / 2, -length / 2, -length / 2); // 4

	mesh->vVertices.emplace_back(-length / 2, length / 2, length / 2); // 6
	mesh->vVertices.emplace_back(-length / 2, length / 2, -length / 2); // 5
	mesh->vVertices.emplace_back(-length / 2, -length / 2, length / 2); // 7

	// Cara -Z
	mesh->vVertices.emplace_back(-length / 2, -length / 2, -length / 2); // 4
	mesh->vVertices.emplace_back(length / 2, length / 2, -length / 2); // 1
	mesh->vVertices.emplace_back(length / 2, -length / 2, -length / 2); // 3

	mesh->vVertices.emplace_back(-length / 2, length / 2, -length / 2); // 5
	mesh->vVertices.emplace_back(length / 2, length / 2, -length / 2); // 1
	mesh->vVertices.emplace_back(-length / 2, -length / 2, -length / 2); // 4

	// Cara +Y
	mesh->vVertices.emplace_back(length / 2, length / 2, -length / 2); // 1
	mesh->vVertices.emplace_back(-length / 2, length / 2, length / 2); // 6
	mesh->vVertices.emplace_back(length / 2, length / 2, length / 2); // 0

	mesh->vVertices.emplace_back(-length / 2, length / 2, -length / 2); // 5
	mesh->vVertices.emplace_back(-length / 2, length / 2, length / 2); // 6
	mesh->vVertices.emplace_back(length / 2, length / 2, -length / 2); // 1

	// Cara -Y
	mesh->vVertices.emplace_back(-length / 2, -length / 2, length / 2); // 7
	mesh->vVertices.emplace_back(length / 2, -length / 2, -length / 2); // 3
	mesh->vVertices.emplace_back(length / 2, -length / 2, length / 2); // 2

	mesh->vVertices.emplace_back(-length / 2, -length / 2, -length / 2); // 4
	mesh->vVertices.emplace_back(length / 2, -length / 2, -length / 2); // 3
	mesh->vVertices.emplace_back(-length / 2, -length / 2, length / 2); // 7

	return mesh;
}

Mesh* Mesh::generateRGBCubeTriangles(GLdouble length)
{
	Mesh* mesh = generateCube(length);

	mesh->vColors.reserve(mesh->mNumVertices);

	for (int i = 0; i < mesh->mNumVertices; ++i) {
		if (i / 6 == 0 || i / 6 == 2) {
			mesh->vColors.emplace_back(0.0, 1.0, 0.0, 1.0);
		}
		else if (i / 6 == 4 || i / 6 == 5) {
			mesh->vColors.emplace_back(0.0, 0.0, 1.0, 1.0);
		}
		else 
			mesh->vColors.emplace_back(1.0, 0.0, 0.0, 1.0);
	}

	return mesh;
}
