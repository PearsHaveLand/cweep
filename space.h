#ifndef CSPACE
#define CSPACE

#define CONCEALED_SPACE '-'
#define BOMB '!'

class CSpace
{
public:
	CSpace();
	bool CheckSpace();
	bool Dump();
  void SetBomb(bool bBomb);
  bool GetBomb() {return m_bHasBomb;}
  char Dump();
private:
	bool m_bHasBomb;
	bool m_bIsChecked;
};

#endif
