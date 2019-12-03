#include "game.h"
CGame::CGame(unsigned int uiSize, unsigned int uiBombs) :
  m_uiCursorY(0),
  m_uiCursorX(0)
{
  m_board = new CBoard(uiSize, uiBombs);

  // initialize curses
	initscr();
	cbreak();
	noecho();
}
CGame::~CGame()
{
  delete m_board;

  // finish curses
  endwin();
}
void CGame::DisplayBoard()
{

}

// moveCursor()
// Checks if the requested space is valid
// If valid, moves the cursor to the coordinates provided as parameters
void CGame::moveCursor(unsigned int y, unsigned int x)
{
  if (m_board->IsInBounds(y, x))
  {
    m_uiCursorX = x;
    m_uiCursorY = y;
  }
}
