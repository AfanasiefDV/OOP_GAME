#pragma once
#include <memory>
#include "IObject.h"
class Player;
class IEnemy;
class IItem;
enum typeElement {
    player,
    verticalEnemy,
    horizontalEnemy,
    boss,
    coin,
    heal,
    weapon
};
class IElement : public IObject {
public:
    virtual ~IElement(){}
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual void write(std::ostream& out) = 0;
    virtual typeElement getType() = 0;
};