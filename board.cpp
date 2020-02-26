#include "./board.h"

Board::Board(){}

void Board::Initialize(){
  for (unsigned int i = 0; i < ROW; ++i){
    for(unsigned int j = 0; j < COLUMN; ++j){
      this->board[i][j] = 'E';
    }
  }
  moveCount = 0;
  winner = 'E';
  boardState = START;
}

bool Board::Update(char piece, unsigned int row, unsigned int column){
  if (row > (ROW - 1) || column > (COLUMN - 1)){
    return false;
  }
  if (this->board[row][column] == 'E'){
    this->board[row][column] = piece;
    moveCount++;
    this->UpdateBoardState();
    return true;
  }
  return false;
}

void Board::UpdateBoardState(){
  if (boardState != PLAYING){
    return;
  }
  for(unsigned int i = 0; i < ROW; ++i){
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]){
      winner = board[i][0];
    } else if (board[0][i] == board[1][i] && board[1][i] == board[2][i]){
      winner = board[0][i];
    }
  }

  if (winner == 'E' && ((board[0][0] == board[1][1] && board[1][1] == board[2][2])
      || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))){
    winner = board[1][1];
  }

  switch(winner){
    case 'X':
      boardState = X_WIN;
      break;
    case 'O':
      boardState = O_WIN;
      break;
    default:
      boardState = PLAYING;
  }

  if (boardState == PLAYING && moveCount == ROW * COLUMN){
    boardState = DRAW;
    return;
  }
}

unsigned int Board::GetBoardState(){
  return boardState;
}

char Board::GetCell(unsigned int row,unsigned int column){
  return this->board[row][column];
}

void Board::SetEmpty(unsigned int row, unsigned int column){
  this->board[row][column] = 'E';
}

bool Board::GameOver(){
  if (boardState == X_WIN || boardState == O_WIN || boardState == DRAW){
    return true;
  }
  return false;
}

void Board::Playing(){
  boardState = PLAYING;
}

void Board::Reset(){
  boardState = RESET;
}
