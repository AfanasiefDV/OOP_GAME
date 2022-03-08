#pragma once
#include "IItem.h"
#include "Player.h"
class Player;
class Coin :
    public IItem
{
public:
    Coin() = default;
    Coin(int x, int y, int Value = 2);
    ~Coin() = default;
    bool iteraction(Player& player) override;
    int getX() override;
    int getY() override;
    typeElement getType() override;
    void changeVal() override;
    void write(std::ostream& out) override;
    friend std::ostream& operator<<(std::ostream& out, const Coin& coin);
private:
    int x, y;
    int Value = 2;
};

