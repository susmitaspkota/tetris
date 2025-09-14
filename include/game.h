#pragma once

#include "grid.h"
#include "blocks.cpp"
#include <vector>

class Game
{
private:
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared);
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void MoveBlockRight();
    void MoveBlockLeft();
    Sound rotatesound;
    Sound clearsound;

public:
    Game();
    ~Game();
    Grid grid;
    void Draw();
    void MoveBlockDown();
    void HandleInput();
    bool gameOver;
    int score;
    Music music;
};