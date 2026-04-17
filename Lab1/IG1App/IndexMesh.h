#ifndef _H_IndexMesh_H_
#define _H_IndexMesh_H_

#include "Mesh.h"

#include <numbers>

class IndexMesh : public Mesh
{
public:
	IndexMesh();

	static IndexMesh* generateByRevolution(
		const std::vector<glm::vec2>& profile, GLuint nSamples,
		GLfloat angleMax = 2 * std::numbers::pi);

	static IndexMesh* generateIndexedBox8(GLdouble l);
	static IndexMesh* generateIndexedBox(GLdouble l);
	static IndexMesh* generateSphere(GLdouble radius,
		GLuint nParallel, GLuint nMeridians);

	void draw() const override;

	void load() override;

	void unload() override;

	void buildNormalVectors();

protected:
	std::vector<GLuint> vIndexes;
	GLuint mIBO;
};

#endif