#ifndef GAME
#define GAME

#include "board.h"
// Keybindings
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 27
#define KEY_SPACE 32

class CGame
{
public:
  CGame(unsigned int uiHeight = DEFAULT_HEIGHT,
    unsigned int uiWidth = DEFAULT_WIDTH,
    unsigned int uiBombs = DEFAULT_NUM_BOMBS);

  ~CGame();

  void RunGame();

private:

  void handleInput(int input);

  void refreshDisplay();

  void displayBoard();

	bool inRange(unsigned int y, unsigned int x);

	void handleGameEnd();

// Member variables
  CBoard *m_board;
  WINDOW *m_gameWindow, *m_borderWindow;
  unsigned int m_uiCursorY;
  unsigned int m_uiCursorX;
  bool m_bFinished;
  bool m_bChangeBoard;
};

#endif
