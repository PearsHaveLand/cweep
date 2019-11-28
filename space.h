#ifndef CSPACE
#define CSPACE

#define CONCEALED '-'
#define BOMB '!'

class CSpace
{
public:
	CSpace();
	bool CheckSpace();
	void SetBomb(bool bBomb);
  bool GetBomb() {return m_bHasBomb;}
  char Dump();
  bool GetIsChecked();
private:
	bool m_bHasBomb;
	bool m_bIsChecked;
};

#endif
