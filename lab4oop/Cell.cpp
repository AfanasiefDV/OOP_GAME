#include "Cell.h"

Cell::Cell(std::shared_ptr<IElement> element, bool is_passible, types_cell cell_type) :element(element), is_passible(is_passible), cell_type(cell_type) {
    if (this->cell_type == start || this->cell_type == finish) {
        this->is_passible = true;
    }
}
Cell::Cell(bool is_passible, types_cell cell_type) : is_passible(is_passible), cell_type(cell_type) {
    if (this->cell_type == start || this->cell_type == finish) {
        this->is_passible = true;
    }
}
types_cell Cell::getCellType() {
    return this->cell_type;
}
void Cell::SetCellType(types_cell newType) {
    this->cell_type = newType;
    if (this->cell_type == start || this->cell_type == finish) {
        this->is_passible = true;
    }
}
bool Cell::IsPassible() {
    return this->is_passible;
}
void Cell::setElement(std::shared_ptr<IElement> element_) {
    this->element = element_;
}
std::shared_ptr<IElement> Cell::getElement() {
    return this->element;
}
void Cell::SetPassability(bool p) {
    this->is_passible = p;
    if (this->cell_type == start || this->cell_type == finish) {
        this->is_passible = true;
    }
}
std::ostream& operator<<(std::ostream& out, const Cell& cell) {
    switch (cell.cell_type) {
    case types_cell::finish:
        out << 'f';
        break;
    case types_cell::start:
        out << 's';
        break;
    case types_cell::thing:
        out << '_';
        break;
    case types_cell::wall:
        out << '#';
        break;
    }
    return out;
}





/*if (cell.element != nullptr) {
            switch (cell.element->getType())
            {
            case typeElement::player:
                out << "@";
                break;
            case typeElement::horizontalEnemy:
                out << "-";
                break;
            case typeElement::verticalEnemy:
                out << "|";
                break;
            case typeElement::boss:
                out << "\\";
                break;
            case typeElement::coin:
                out << "$";
                break;
            case typeElement::heal:
                out << "+";
                break;
            case typeElement::weapon:
                out << "!";
                break;
            }
        }
        else{*/