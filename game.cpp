#include "game.h"
CGame::CGame(unsigned int uiHeight, unsigned int uiWidth, unsigned int uiBombs) :
  m_uiCursorY(0),
  m_uiCursorX(0),
  m_bFinished(false),
  m_bNeedRefresh(true)
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
  int iInput;

  // initialize curses
  initscr();
  cbreak();
  noecho();

  m_gameWindow = newwin(m_board->GetHeight()+1, m_board->GetWidth()+1, 0, 0);
  box(m_gameWindow, 0 , 0);
	mvwin(m_gameWindow, 0,0);
  
	// Begin game loop
  while (!m_bFinished)
  {
    if (m_bNeedRefresh)
    {
      refreshDisplay();
		} 

    // Get user input
    iInput = wgetch(m_gameWindow);
    handleInput(iInput);
  }

  delwin(m_gameWindow);
  endwin();
}

void CGame::handleInput(int input)
{
  int x, y;
  getyx(m_gameWindow, y, x);

  // Handle user input
  switch (input)
  {
  case KEY_ESC:
    m_bFinished = true;
    break;
  case KEY_W:
    wmove(m_gameWindow, y-1, x);
    break;
  case KEY_A:
   	wmove(m_gameWindow, y, x-1);
    break;
  case KEY_S:
    wmove(m_gameWindow, y+1, x);
    break;
  case KEY_D:
    wmove(m_gameWindow, y, x+1);
    break;
  }

	m_bNeedRefresh = true;
}

void CGame::refreshDisplay()
{
  //clear();
  erase();
	displayBoard();
  box(m_gameWindow, 0, 0);
  wrefresh(m_gameWindow);
  refresh();
  mvwin(m_gameWindow, 0,0);
  m_bNeedRefresh = false;
}

void CGame::displayBoard()
{
  char **boardDisplay = m_board->GetDisplay();
  int x, y;
	
	// Save previous cursor location, because we need to move it
	// to re-print the board
	getyx(m_gameWindow, y, x);
	wmove(m_gameWindow, 0, 0);

	for (unsigned int i = 0; i < m_board->GetHeight(); i++)
  {
    if (i == m_board->GetHeight()-1)
		{
			wprintw(m_gameWindow, "%s", boardDisplay[i]);
		}
		else
		{
			wprintw(m_gameWindow, "%s\n", boardDisplay[i]);
		}
	}

	wmove(m_gameWindow, y, x);
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
