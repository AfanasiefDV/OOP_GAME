#include "Field.h"
#include <iostream>
Field::Field(size_t x_, size_t y_) : x(x_), y(y_), field(std::make_unique<std::unique_ptr<Cell[]>[]>(y_)) {
    for (int i = 0; i < this->y; ++i) {
        field[i] = std::make_unique<Cell[]>(x);
        for (int j = 0; j < this->x; ++j) {
            if (i == 0 || j == 0 || i == (this->y - 1) || j == (this->x - 1)) {
                this->field[i][j].SetPassability(false);
                this->field[i][j].SetCellType(types_cell::wall);
            }
            else {
                this->field[i][j].SetPassability(true);
                this->field[i][j].SetCellType(types_cell::thing);
            }
        }
    }
    this->field[1][1].SetCellType(types_cell::start);
    this->field[this->y - 2][this->x - 2].SetCellType(types_cell::finish);
}
Field::Field(const Field& f) : x(f.x), y(f.y), field(std::make_unique<std::unique_ptr<Cell[]>[]>(f.y)) {
    for (int i = 0; i < this->y; ++i) {
        field[i] = std::make_unique<Cell[]>(x);
        for (int j = 0; j < this->x; ++j) {
            this->field[i][j].SetCellType(f.field[i][j].getCellType());
            this->field[i][j].SetPassability(f.field[i][j].IsPassible());
            if (f.field[i][j].getElement() != nullptr) {
                this->field[i][j].setElement(f.field[i][j].getElement());
            }
        }
    }
}
Field::Field(Field&& f) {
    std::swap(this->x, f.x);
    std::swap(this->y, f.y);
    this->field = std::move(f.field);
}
Field& Field::operator=(const Field& f) {
    if (&f == this) {
        return *this;
    }
    this->x = f.x;
    this->y = f.y;
    this->field = std::make_unique<std::unique_ptr<Cell[]>[]>(y);
    for (int i = 0; i < this->y; ++i) {
        field[i] = std::make_unique<Cell[]>(x);
        for (int j = 0; j < this->x; ++j) {
            this->field[i][j].SetCellType(f.field[i][j].getCellType());
            this->field[i][j].SetPassability(f.field[i][j].IsPassible());
            if (f.field[i][j].getElement() != nullptr) {
                this->field[i][j].setElement(f.field[i][j].getElement());
            }
        }
    }
    return *this;
}
Field& Field::operator=(Field&& f) {
    if (&f == this) {
        return *this;
    }
    std::swap(this->x, f.x);
    std::swap(this->y, f.y);
    this->field = std::move(f.field);
    return *this;
}
void Field::write(std::ostream& out) {
    out << *this;
}

std::ostream& operator<<(std::ostream& out, const Field& field) {
    IteratorField iter(field);
    for (int k = 0; !iter.isDone(); k++) {
        if (k % (field.x) == 0 && k != 0) {
            out << '\n';
        }
        out << *(iter);
        iter++;
    }
    out << '\n';
    return out;
}
IteratorField Field::getIter() {
    return IteratorField(*this);
}
int Field::getX() {
    return this->x;
}
int Field::getY() {
    return this->y;
}
Cell& Field::getCell(int x, int y) {
    return this->field[y][x];
}
bool Field::isFreeCell(int x, int y) {
    if (x > 0 && y > 0 && x < this->x && y < this->y) {
        if (this->field[y][x].getCellType() == types_cell::thing && this->field[x][y].getElement() == nullptr) {
            return true;
        }
    }
    return false;
}