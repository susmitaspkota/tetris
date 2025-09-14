#pragma once
#include <vector>
#include <map>
#include "color.h"
#include "position.h"

class Block
{
public:
    Block();
    int id;
    std::vector<Position> GetCellPositions();
    std::map<int, std::vector<Position>> cells;
    void DrawBlock(int offsetX, int offsetY);
    void Move(int rows, int columns);
    void Rotate();
    void UndoRotation();

private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};