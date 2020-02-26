#ifndef BOARD_H
#define BOARD_H

#include "./constants.h"
#include <iostream>

class Board {
private:
  char board[ROW][COLUMN];
  unsigned int moveCount;
  char winner;
  void UpdateBoardState();

public:
  Board();
  unsigned int boardState;
  void Initialize();
  bool Update(char piece, unsigned int row, unsigned int column);
  void Playing();
  bool GameOver();
  void SetEmpty(unsigned int row, unsigned int column);
  unsigned int GetBoardState();
  char GetCell(unsigned int row, unsigned int column);
  void Reset();
};

#endif
