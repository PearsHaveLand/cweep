#ifndef CSPACE
#define CSPACE

#define CONCEALED '-'
#define BOMB '!'


#include <curses.h>

class CSpace
{
public:
	CSpace();
	bool CheckSpace();
	void SetBomb(bool bBomb);
  bool GetBomb() {return m_bHasBomb;}
  char Dump();
  bool GetIsChecked();
  char GetDisplay() {return m_cDisplay;}
  void SetDisplay(char newDisplay) {m_cDisplay = newDisplay;}
private:
	bool m_bHasBomb;
	bool m_bIsChecked;
  char m_cDisplay;
};

#endif
