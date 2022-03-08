#pragma once
#include "IEnemy.h"
#include "Player.h"
#include "Field.h"
class Field;
class Player;
class IEnemy;
class Boss :
    public IEnemy
{
public:
    Boss() = default;
    Boss(int x, int y, Field& field, int health = 5, int damage = -1);
    ~Boss(){}
    bool iteraction(Player& player) override;
    void move() override;
    int getX() override;
    int getY() override;
    typeElement getType() override;
    void changeHealth(int value) override;
    int getDamage() override;
    void write(std::ostream& out) override;
    friend std::ostream& operator<<(std::ostream& out, const Boss& boss);
private:
    int x, y;
    int side = -1;
    Field& field;
    int damage = -1;
    int health = 5;
};

