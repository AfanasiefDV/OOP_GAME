#include "IteratorField.h"

IteratorField::IteratorField(const Field& field) :field(field), i(0), j(0) {}
void IteratorField::next() {
    if (j < (field.x - 1)) {
        j++;
    }
    else {
        j = 0;
        i++;
    }
}
void IteratorField::operator++() {
    this->next();
}
void IteratorField::operator++(int k) {
    this->next();
}
bool IteratorField::isDone() {
    if (i == (field.y) && j == 0) {
        return true;
    }
    return false;
}
void IteratorField::First() {
    this->i = 0;
    this->j = 0;
}
Cell IteratorField::operator*() {
    return this->field.field[i][j];
}