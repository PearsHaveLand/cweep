#ifndef GAME
#define GAME

#include "board.h"
#include <curses.h>
using namespace std;

// Keybindings
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 27

class CGame
{
public:
  CGame(unsigned int uiHeight = DEFAULT_HEIGHT,
    unsigned int uiWidth = DEFAULT_WIDTH,
    unsigned int uiBombs = DEFAULT_NUM_BOMBS);

  ~CGame();

  void RunGame();

private:

  // moveCursor()
  // Checks if the requested space is valid
  // If valid, moves the cursor to the coordinates provided as parameters
  void moveCursor(unsigned int y, unsigned int x);

  void handleMove();


  void refreshDisplay();

  void displayBoard();

// Member variables
  CBoard *m_board;
  unsigned int m_uiCursorY;
  unsigned int m_uiCursorX;
};

#endif
