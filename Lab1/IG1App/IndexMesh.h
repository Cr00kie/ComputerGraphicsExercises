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

	void draw() const override;

	void load() override;

	void unload() override;

	void buildNormalVectors();

protected:
	std::vector<GLuint> vIndexes;
	GLuint mIBO;
};

#endif