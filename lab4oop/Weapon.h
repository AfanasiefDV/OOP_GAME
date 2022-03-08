#pragma once
#include "IItem.h"
#include "Player.h"
class Player;
class Weapon :
    public IItem
{
public:
    Weapon() = default;
    Weapon(int x, int y, int Value = -1);
    ~Weapon()=default;
    bool iteraction(Player& player) override;
    int getX() override;
    int getY() override;
    typeElement getType() override;
    void changeVal() override;
    void write(std::ostream& out) override;
    friend std::ostream& operator<<(std::ostream& out, const Weapon& weapon);
private:
    int x, y;
    int Value = -1;
};

