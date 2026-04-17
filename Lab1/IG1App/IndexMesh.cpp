#include "IndexMesh.h"

using namespace std;
using namespace glm;

// Placeholder for the pending index of a GPU object
constexpr GLuint NONE = numeric_limits<GLuint>::max();

IndexMesh::IndexMesh() : Mesh()
, mIBO(NONE)
{
}

IndexMesh* IndexMesh::generateByRevolution(const std::vector<glm::vec2>& profile, GLuint nSamples, GLfloat angleMax)
{
	IndexMesh* mesh = new IndexMesh;
	mesh->mPrimitive = GL_TRIANGLES;

	int tamPerfil = profile.size();
	mesh->vVertices.reserve(nSamples * tamPerfil);
	mesh->vTexCoords.reserve(mesh->mNumVertices);

	// Genera los vértices de las muestras
	GLdouble theta1 = angleMax / nSamples;
	for (int i = 0; i <= nSamples; ++i) { // muestra i-ésima

		GLdouble c = cos(i * theta1), s = sin(i * theta1);
		
		// rota el perfil
		for (int j = 0; j < tamPerfil; ++j)
		{
			// Creamos los vertices de cada anillo
			mesh->vVertices.emplace_back(profile[j].x * c, profile[j].y, -profile[j].x * s);

			// Añadimos las coordenadas de textura
			mesh->vTexCoords.emplace_back(float(i) / nSamples, 1 - (float(j) / tamPerfil));
		}
	}

	int i = 0;
	for (; i < nSamples - 1; ++i) // caras i a i + 1
		for (int j = 0; j < tamPerfil - 1; ++j) { // una cara
			if (profile[j].x != 0.0) // triángulo inferior
				for (auto [s, t] : { pair{i, j}, {i, j + 1}, {i + 1, j} })
					mesh->vIndexes.push_back(s * tamPerfil + t);
			if (profile[j + 1].x != 0.0) // triángulo superior
				for (auto [s, t] : { pair{i, j + 1}, {i + 1, j + 1}, {i + 1, j} })
					mesh->vIndexes.push_back(s * tamPerfil + t);
		}

	// Creamos la ultima cara uniendo con la primera o no 
	// (solo si la intención es dar exactamente una vuelta, asumimos que la intención es dar una vuelta si el ángulo máximo es cercano a 2*pi)
	int lastSampleIndex = angleMax - std::numbers::pi * 2 < 0.0001 ? 0 : i+1;
	for (int j = 0; j < tamPerfil - 1; ++j)
	{ // una cara
		if (profile[j].x != 0.0) // triángulo inferior
			for (auto [s, t] : { pair{i, j}, {i, j + 1}, {lastSampleIndex, j} })
				mesh->vIndexes.push_back(s * tamPerfil + t);
		if (profile[j + 1].x != 0.0) // triángulo superior
			for (auto [s, t] : { pair{i, j + 1}, {lastSampleIndex, j + 1}, {lastSampleIndex, j} })
				mesh->vIndexes.push_back(s * tamPerfil + t);
	}


	mesh->mNumVertices = mesh->vVertices.size();

	mesh->buildNormalVectors();

	return mesh;
}

IndexMesh* IndexMesh::generateIndexedBox8(GLdouble length)
{
	IndexMesh* mesh = new IndexMesh;
	mesh->mPrimitive = GL_TRIANGLES;
	mesh->mNumVertices = 8;

	GLdouble l = length / 2;

	mesh->vVertices = {
		{ l,  l, -l}, 
		{ l, -l, -l}, 
		{-l,  l, -l}, 
		{-l, -l, -l},
		{-l,  l,  l}, 
		{-l, -l,  l}, 
		{ l,  l,  l}, 
		{ l, -l,  l}
	};

	mesh->vIndexes = {
		0, 1, 2,  2, 1, 3,  // Back
		4, 5, 6,  6, 5, 7,  // Front
		2, 3, 4,  4, 3, 5,  // Left
		6, 7, 0,  0, 7, 1,  // Right
		2, 4, 0,  0, 4, 6,  // Top
		5, 3, 1,  1, 7, 5   // Bottom
	};

	mesh->buildNormalVectors();

	return mesh;
}

IndexMesh* IndexMesh::generateIndexedBox(GLdouble l)
{
	IndexMesh* mesh = new IndexMesh;
	mesh->mPrimitive = GL_TRIANGLES;
	mesh->mNumVertices = 24;

	//	4 - - - - - - - - - 2
	//	 | \             | \
	//	 |   - - - - - - - - -
	//	 |   |6          |   |0
	//	 |   |           |   |
	//	 |   |           |   |
	//	 |   |           |   |
	//	 |   |           |3  |
	//	5 - -| - - - - - -   |
	//	   \ |7            \ |1
	//	     - - - - - - - - -
	//
	//		 y |
	//		   |
	//	   z - -
	//			\ x

	mesh->vVertices = {
		{ l,  l, -l}, // 0x - 0
		{ l,  l, -l}, // 0y - 1
		{ l,  l, -l}, // 0z - 2

		{ l, -l, -l}, // 1x - 3
		{ l, -l, -l}, // 1y - 4
		{ l, -l, -l}, // 1z - 5

		{-l,  l, -l}, // 2x - 6
		{-l,  l, -l}, // 2y - 7
		{-l,  l, -l}, // 2z - 8

		{-l, -l, -l}, // 3x - 9
		{-l, -l, -l}, // 3y - 10
		{-l, -l, -l}, // 3z - 11

		{-l,  l,  l}, // 4x - 12
		{-l,  l,  l}, // 4y - 13
		{-l,  l,  l}, // 4z - 14

		{-l, -l,  l}, // 5x - 15
		{-l, -l,  l}, // 5y - 16
		{-l, -l,  l}, // 5z - 17

		{ l,  l,  l}, // 6x - 18
		{ l,  l,  l}, // 6y - 19
		{ l,  l,  l}, // 6z - 20

		{ l, -l,  l}, // 7x - 21
		{ l, -l,  l}, // 7y - 22
		{ l, -l,  l}  // 7z - 23
	};

	mesh->vIndexes = {
		 2,  5,  8,   5, 11,  8,  // Back
		14, 17, 20,  20, 17, 23,  // Front
		 6,  9, 12,  12,  9, 15,  // Left
		18,  21, 0,  21,  3,  0,  // Right
		 7, 13,  1,   1, 13, 19,  // Top
		16, 10,  4,   4, 22, 16   // Bottom
	};

	mesh->buildNormalVectors();

	return mesh;
}

IndexMesh* IndexMesh::generateSphere(GLdouble radius, GLuint nParallel, GLuint nMeridians)
{
	std::vector<glm::vec2> vProfile(nParallel + 1);

	const float angleDelta = glm::radians(180.f / (float)nParallel);
	constexpr float offSet = glm::radians(90.f);
	// Creamos los vertices
	for (int i = 0; i < nParallel; i++)
	{
		float angle = offSet + angleDelta * i;
		vProfile[i] = { radius * glm::cos(angle), radius * glm::sin(angle) };
	}

	vProfile[nParallel] = { 0, -radius };

	return IndexMesh::generateByRevolution(vProfile, nMeridians);
}

void IndexMesh::draw() const
{
	glDrawElements(
		mPrimitive,
		// primitiva (GL_TRIANGLES, etc.)
		vIndexes.size(), // número de índices
		GL_UNSIGNED_INT, // tipo de los índices
		nullptr
		// offset en el VBO de índices
	);
}

void IndexMesh::load() {
	Mesh::load(); glBindVertexArray(mVAO);
	glGenBuffers(1, &mIBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		vIndexes.size() * sizeof(GLuint),
		vIndexes.data(), GL_STATIC_DRAW);
	glBindVertexArray(0);
}

void IndexMesh::unload()
{
	Mesh::unload();

	if (mVAO != NONE) {
		if (mIBO != NONE) {
			glDeleteBuffers(1, &mIBO);
			mIBO = NONE;
		}
	}
}

void IndexMesh::buildNormalVectors()
{
	// Construir el vector de normales del mismo tamaño que el de vértices e Inicializar las normales a 0
	vNormals.resize(vVertices.size(), glm::vec3(0.f));

	// Recorrer los triángulos
	for (int k = 0; k < vIndexes.size(); k += 3){
		vec3 normal = normalize(cross(vVertices[vIndexes[k+1]]  - vVertices[vIndexes[k]], vVertices[vIndexes[k+2]] - vVertices[vIndexes[k]]));

		vNormals[vIndexes[k]] += normal;
		vNormals[vIndexes[k+1]] += normal;
		vNormals[vIndexes[k+2]] += normal;
	}

	// Normalizar los vectores normales
	for (glm::vec3& n : vNormals) n = normalize(n);
}
