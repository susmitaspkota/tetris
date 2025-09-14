#pragma once

#include <vector>
#include <raylib.h>

class Grid
{
public:
    int numRows;
    int numCols;
    Grid();
    void Initialize();
    void Print();
    int grid[20][10];
    void DrawGrid(

    );
    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);
    int ClearFullRows();

private:
    int cellSize;
    std::vector<Color> colors;
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);
};