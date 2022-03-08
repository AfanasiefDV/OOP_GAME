#pragma once
#include "IElement.h"
#include "IEnemy.h"
#include "Field.h"
class IElement;
class IEnemy;
class Field;
class Player : public IElement
{
public:
    Player(int x, int y, Field& field, int health = 10, int damage = -1, int coin = 0);
    Player() = default;
    ~Player()=default;
    void iteraction(IEnemy& enemy);
    void iteraction(IItem& item);
    void move(int& x, int& y);
    int getX() override;
    int getY() override;
    typeElement getType() override;
    void write(std::ostream& out) override;
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
    void changeHealth(int value);
    void changeDamage(int value);
    void changeCoins(int value);
    int getHealth();
    int getDamage();
    int getCoins();
private:
    int x, y;
    Field& field;
    int health = 10;
    int damage = -1;
    unsigned int coins = 0;
};
