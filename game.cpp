#include "./game.h"

Game::Game() {
  this->isRunning = false;
}

bool Game::IsRunning() const {
  return this->isRunning;
}

void Game::Initialize(){
  this->board = new Board();
  //this->graphics = new Graphics();
  this->minimax = new Minimax();
  //graphics->Initialize(width, height);
  Start();
  isRunning = true;
  return;
}

void Game::Start(){
  this->currentPlayer = HUMAN;
  this->currentMove = 'X';
  this->row = ROW;
  this->column = COLUMN;
  gameState = START;
  board->Initialize();
}

void Game::ProcessInput(){
  //if (!graphics->ProcessInput(board, gameState, currentPlayer, isRunning, row, column)){
   // isRunning = false;
  //}
  if (board->GetBoardState() == RESET){
    Game::Start();
  }
}

void Game::ProcessAI(){
  if (currentPlayer == PC && gameState == PLAYING){
    minimax->GetBestMove(board, row, column);
  }
}

void Game::Update(){
  // set move on board
  if (board->Update(currentMove, row, column)){
    Game::TogglePlayer();
  }
  gameState = board->GetBoardState();
}

void Game::Render(){
  //graphics->Render(board, gameState);
}

void Game::TogglePlayer(){
  if (currentPlayer == HUMAN){
    currentPlayer = PC;
    currentMove = 'O';
  } else {
    currentPlayer = HUMAN;
    currentMove = 'X';
  }
}

unsigned int Game::GetGameState(){
  return board->GetBoardState();
}

void Game::Destroy(){
  //graphics->Destroy();
  delete board;
  //delete graphics;
  delete minimax;
}
