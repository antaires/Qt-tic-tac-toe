#ifndef GAME_H
#define GAME_H

// #include "./graphics.h"
#include "./minimax.h"
#include "./board.h"

class Game {
  private:
    bool isRunning;
    unsigned int currentPlayer;
    unsigned int currentMove;
    unsigned int row;
    unsigned int column;
    void TogglePlayer();

  public:
    Game();
    unsigned int gameState;
    bool IsRunning() const;
    Board *board;
    //Graphics* graphics;
    Minimax* minimax;

    void Start();
    void Initialize();
    void ProcessInput();
    void ProcessAI();
    void Update();
    void Render();
    void Destroy();
    unsigned int GetGameState();
};

#endif
