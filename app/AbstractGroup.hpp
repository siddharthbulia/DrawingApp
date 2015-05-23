#pragma once

#include "IDrawable.hpp"
#include "ITransformable.hpp"
#include <vector>

class VisualEntity;

class AbstractGroup : public IDrawable, public ITransformable
{
public:
    AbstractGroup();
    virtual ~AbstractGroup();

    virtual int add(VisualEntity *val) = 0;
    virtual void remove(int index);
    virtual void remove(VisualEntity *val);

    std::vector<VisualEntity*>::iterator find(VisualEntity *val);
    VisualEntity* get(int index) const;
    void destroy(int index);
    int getSize() const;
    QRect getBoundary() override;

    void setPosition(QPoint pos) override;
    QPoint getPosition() override;

protected:
    std::vector<VisualEntity*> m_children;
};
