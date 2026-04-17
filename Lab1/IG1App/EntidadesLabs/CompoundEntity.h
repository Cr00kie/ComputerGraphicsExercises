#ifndef _H_CompoundEntity_H_
#define _H_CompoundEntity_H_

#include "../Entity.h"
class CompoundEntity :
    public Abs_Entity
{
public:
    ~CompoundEntity();
    void addEntity(Abs_Entity* ae);
    void render(const glm::mat4& modelViewMat) const override;
    void update() override;
    void load() override;
    void unload() override;
private:
    std::vector<Abs_Entity*> gObjects;
};

#endif
