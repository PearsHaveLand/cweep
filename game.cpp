#include "game.h"
CGame::CGame(unsigned int uiHeight, unsigned int uiWidth, unsigned int uiBombs) :
  m_uiCursorY(0),
  m_uiCursorX(0)
{
  m_board = new CBoard(uiHeight, uiWidth, uiBombs);
}
CGame::~CGame()
{
  delete m_board;

  // finish curses
  endwin();
}

void CGame::RunGame()
{
  bool bFinished = false;
  int iInput;

  // initialize curses
  initscr();
  cbreak();
  noecho();

  while (!bFinished)
  {
    // Do stuff
    iInput = getch();
    switch (iInput)
    {
    case KEY_ESC:
      bFinished = true;
    }
  }

  endwin();
}

void CGame::refreshDisplay()
{
  refresh();
}

/*
void CGame::displayBoard()
{
  unsigned int uiWidth = m_board->GetWidth();
  unsigned int uiHeight = m_board->GetHeight();

  for (unsigned int i = 0; i < uiHeight; i++)
  {
    for (unsigned int j = 0; j < uiWidth; j++)
    {
      // if concealed, display CONCEALED
      // if not concealed, display number of adjacent bombs
    }
  }
}
*/

/*
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
*/
