#pragma once
#include "Field.h"
#include <memory>
class Field;
class Cell;
class IteratorField {
public:
    IteratorField(const Field& field);
    void operator++();
    void operator++(int k);
    void next();
    bool isDone();
    void First();
    Cell operator*();
private:
    size_t i, j;
    const Field& field;
};