#include "IndexedBox.h"
#include "../IndexMesh.h"

IndexedBox::IndexedBox(GLdouble l, glm::vec4 col) :
	ColorMaterialEntity(col)
{
	mMesh = IndexMesh::generateIndexedBox(l);
}
