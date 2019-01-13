#ifndef PROJECT2_CELL_H
#define PROJECT2_CELL_H


class Cell {
    int i;
    int j;
public:
    Cell(int i, int j);
    int getI();
    int getJ();
    bool operator==(Cell otherCell);
};


#endif //PROJECT2_CELL_H
