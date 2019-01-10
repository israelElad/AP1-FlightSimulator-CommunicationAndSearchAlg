#include "Cell.h"

int Cell::getI() {
    return i;
}

int Cell::getJ() {
    return j;
}

Cell::Cell(int i, int j) {
    this->i = i;
    this->j = j;
}
