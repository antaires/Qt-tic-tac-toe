#include "./minimax.h"

/* Takes in a board object and return the best move for the PC
  player using the minimax algorithm. This variation
  preferences moves that lead to quick wins or slow losses */

Minimax::Minimax(){}

void Minimax::GetBestMove(Board* board, unsigned int& row, unsigned int& column){
  // works through each move and scores based on HUMAN or PC winner or DRAW
  unsigned int bestMoveRow = 0;
  unsigned int bestMoveCol = 0;
  int bestMoveValue = 10000;
  Board* cloneBoard = new Board();
  Minimax::Clone(board, cloneBoard);
  currentMove = -1;

  // get each empty square
  for(unsigned int i = 0; i < ROW; ++i){
    for(unsigned int j = 0; j < COLUMN; ++j){
      if (cloneBoard->GetCell(i, j) == 'E'){
        cloneBoard->Update('O', i, j);
        Minimax::MinimaxCalc(cloneBoard, 0, true, currentMove);
        // undo move
        cloneBoard->SetEmpty(i, j);
        // if MINIMIZER
        if (currentMove < bestMoveValue){
          bestMoveValue = currentMove;
          bestMoveRow = i;
          bestMoveCol = j;
        }
      }
    }
  }
  row = bestMoveRow;
  column = bestMoveCol;
  delete cloneBoard;
}

void Minimax::Evaluate(Board* cloneBoard, int depth){
  // determines point value of initial move based on game outcome
  // depth is number of moves made prior to game end state
  switch (cloneBoard->GetBoardState()){
    case X_WIN:
      // winner is maximizer (HUMAN)
      this->currentMove = (WINPOINTS - depth);
    case O_WIN:
      // winner is minimizer (PC)
      this->currentMove = (LOSEPOINTS + depth);
    default:
      this->currentMove = 0;
  }
}

void Minimax::MinimaxCalc(Board* cloneBoard, int depth, bool isMaximizingPlayer, int& returnValue){
  // Minimax: https://en.wikipedia.org/wiki/Minimax
  unsigned int state = cloneBoard->GetBoardState();
  if (state == X_WIN || state == O_WIN || state == DRAW){
    Minimax::Evaluate(cloneBoard, depth);
    return;
  }

  int bestValue = 0;
  Board* clone = new Board();
  Minimax::Clone(cloneBoard, clone);

  if (isMaximizingPlayer){
    // maximizer
    bestValue = -10000;
    for(unsigned int i = 0; i < ROW; ++i){
      for(unsigned int j = 0; j < COLUMN; ++j){
        if (clone->GetCell(i, j) == 'E'){
          clone->Playing();
          clone->Update('X', i, j);
          int value;
          Minimax::MinimaxCalc(clone, depth+1, false, value);
          bestValue = bestValue > value ? bestValue : value;
          clone->SetEmpty(i, j);
        }
      }
    }
    delete clone;
    returnValue = bestValue;
    return;
  } else {
    // minimizer
    int bestValue = 10000;
    for(unsigned int i = 0; i < ROW; ++i){
      for(unsigned int j = 0; j < COLUMN; ++j){
        if (clone->GetCell(i, j) == 'E'){
          clone->Update('O', i, j);
          int value;
          Minimax::MinimaxCalc(clone, depth+1, true, value);
          bestValue = bestValue < value ? bestValue : value;
          clone->SetEmpty(i, j);
        }
      }
    }
  }
  delete clone;
  returnValue = bestValue;
  return;
}

void Minimax::Clone(Board* original, Board* clone){
  clone->Initialize();
  for(unsigned int i = 0; i < ROW; ++i){
    for(unsigned int j = 0; j < COLUMN; ++j){
      clone->Update(original->GetCell(i, j), i, j);
    }
  }
}
