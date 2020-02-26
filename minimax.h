#ifndef MINIMAX_H
#define MINIMAX_H

#include "./board.h"

class Minimax {
  private:
    int currentMove;
    void Evaluate(Board* board, int depth);
    void MinimaxCalc(Board* cloneBoard, int depth, bool isMaximizingPlayer, int& value);
    void Clone(Board* original, Board* clone);

  public:
    Minimax();
    void GetBestMove(Board* board, unsigned int& row, unsigned int& column);
};

#endif
