#pragma once
#include "IElement.h"
class IElement;
class IItem;
class Player;
class IEnemy : 
    public IElement
{
public:
    virtual ~IEnemy() {}
    virtual bool iteraction(Player& player) = 0;
    virtual void move() = 0;
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual typeElement getType() = 0;
    virtual void changeHealth(int value) = 0;
    virtual int getDamage() = 0;
    virtual void write(std::ostream& out) = 0;
};

