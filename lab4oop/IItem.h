#pragma once
#include "IElement.h"
class IElement;
class IItem:public IElement
{
public:
    virtual ~IItem() {};
    virtual bool iteraction(Player& player) = 0;
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual typeElement getType() = 0;
    virtual void changeVal() = 0;
    virtual void write(std::ostream& out) = 0;
};

