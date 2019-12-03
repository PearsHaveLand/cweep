#ifndef GAME
#define GAME

#include "board.h"
#include <curses.h>
using namespace std;

class CGame
{
public:
  CGame(unsigned int uiSize = DEFAULT_BOARD_SIZE, unsigned int uiBombs = DEFAULT_NUM_BOMBS);
  ~CGame();
  void DisplayBoard();
private:
  // moveCursor()
  // Checks if the requested space is valid
  // If valid, moves the cursor to the coordinates provided as parameters
  void moveCursor(unsigned int y, unsigned int x);

  void handleMove();
  CBoard *m_board;
  unsigned int m_uiCursorY;
  unsigned int m_uiCursorX;
};

#endif
