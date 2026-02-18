#ifndef _H_EntityWithTexture_H_
#define _H_EntityWithTexture_H_

#include "../Entity.h"
#include "../Texture.h"
class EntityWithTexture :
    public Abs_Entity
{
public:
    EntityWithTexture();
    inline void setTexture(Texture* t) { mTexture = t; }
    inline void setModulate(bool modulate) { mModulate = modulate; }
protected:
    Texture* mTexture = nullptr;
    bool mModulate = false;

    void render(const glm::mat4& modelViewMat) const override;
};

#endif