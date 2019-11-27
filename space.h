#ifndef CSPACE
#define CSPACE

#define CONCEALED_SPACE 218
#define BOMB '!'

class CSpace
{
public:
	CSpace(bool bHasBomb);
	bool CheckSpace();
	void SetDisplay(char cDisplay);
private:
	bool m_bHasBomb;
	char m_cDisplay;
	bool m_bIsChecked;
};

#endif
