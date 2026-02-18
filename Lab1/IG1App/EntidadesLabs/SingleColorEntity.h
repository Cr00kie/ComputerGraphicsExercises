#ifndef _H_SingleColorEntity_H_
#define _H_SingleColorEntity_H_

#include "../Entity.h"
class SingleColorEntity :
    public Abs_Entity
{
public:
	explicit SingleColorEntity(glm::vec4);
	void render(const glm::mat4& modelViewMat) const override;

private:
	glm::vec4 mColor;

};

#endif	