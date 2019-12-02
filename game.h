#ifndef GAME
#define GAME

class CGame
{
public:
  CGame();
  ~CGame();
  DisplayBoard();
private:
  void moveCursor(unsigned int y, unsigned int x);

  CBoard m_board;
  unsigned int m_uiCursorY;
  unsigned int m_uiCursorX;
};

#endif
