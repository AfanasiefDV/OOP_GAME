#pragma once
#include <ostream>
#include <memory>
#include "IElement.h"
#include "Player.h"
#include "VerticalEnemy.h"
#include "HorizontalEnemy.h"
enum types_cell {
    thing,
    wall,
    start,
    finish
};


class Cell {
public:
    Cell() = default;
    Cell(std::shared_ptr<IElement> element, bool is_passible, types_cell cell_type);
    Cell(bool is_passible, types_cell cell_type);
    types_cell getCellType();
    void SetCellType(types_cell newType);
    bool IsPassible();
    void setElement(std::shared_ptr<IElement> element_);
    std::shared_ptr<IElement> getElement();
    void SetPassability(bool p);
    friend std::ostream& operator<<(std::ostream& out, const Cell& cell);
private:
    std::shared_ptr<IElement> element = nullptr;
    bool is_passible;
    types_cell cell_type;
};

