#ifndef CSPACE
#define CSPACE

#define CONCEALED_SPACE 218
#define BOMB '!'

class CSpace
{
public:
	CSpace();
	bool CheckSpace();
	void SetDisplay(char cDisplay);
  void SetBomb(bool bBomb);
  bool GetBomb() {return m_bHasBomb;}
  char Dump();
private:
	bool m_bHasBomb;
	char m_cDisplay;
	bool m_bIsChecked;
};

#endif
