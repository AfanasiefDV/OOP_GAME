#pragma once
#include "IEnemy.h"
#include "Player.h"
#include "Field.h"
class Field;
class Player;
class IEnemy;

class VerticalEnemy :
    public IEnemy
{
public:
    VerticalEnemy() = default;
    VerticalEnemy(int x, int y, Field& field, int health = 3, int damage = -1);
    ~VerticalEnemy() = default;
    bool iteraction(Player& player) override;
    void move() override;
    int getX() override;
    int getY() override;
    typeElement getType() override;
    void changeHealth(int value) override;
    int getDamage() override;
    void write(std::ostream& out) override;
    friend std::ostream& operator<<(std::ostream& out, const VerticalEnemy& enemy);
private:
    int side = -1;
    int x, y;
    Field& field;
    int damage = -1;
    int health = 3;
};

