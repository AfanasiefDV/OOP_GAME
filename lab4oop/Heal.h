#pragma once
#include "IItem.h"
#include "Player.h"
class Player;
class Heal :
    public IItem
{
public:
    Heal() = default;
    Heal(int x, int y, int Value = 3);
    ~Heal() = default;
    bool iteraction(Player& player) override;
    int getX() override;
    int getY() override;
    typeElement getType() override;
    void changeVal() override;
    void write(std::ostream& out) override;
    friend std::ostream& operator<<(std::ostream& out, const Heal& heal);
private:
    int x, y;
    int Value = 3;
};

