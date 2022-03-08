#pragma once
#include "Cell.h"
#include "IteratorField.h"
#include "Game.h"
#include "Boss.h"
#include "Coin.h"
#include "Heal.h"
#include "Weapon.h"
#include "IObject.h"
#include <memory>
#include <ostream>
class Cell;
class IteratorField;
class Field : public IObject {
public:
    Field() = default;
    ~Field() = default;
    Field(size_t x_, size_t y_);
    Field(const Field& f); //конструктор копирования
    Field(Field&& f); //контруктор пермещения
    Field& operator=(const Field& f);//оператор присваивания копированием
    Field& operator=(Field&& f);//оператор присваивания перемещением
    IteratorField getIter();
    int getX();
    int getY();
    Cell& getCell(int x, int y);
    bool isFreeCell(int x, int y);
    void write(std::ostream& out) override;
    friend std::ostream& operator<< (std::ostream& out, const Field& f);
private:
    friend class IteratorField;
    friend class Player;
    //template <typename T>
    //friend class Game;
    friend class VerticalEnemy;
    friend class HorizontalEnemy;
    friend class Boss;
    std::unique_ptr<std::unique_ptr<Cell[]>[]> field;
    size_t x, y;
};