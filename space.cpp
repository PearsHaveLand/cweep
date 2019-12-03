#include "space.h"

// Constructor
// Bomb distribution is determined in CBoard
// All spaces begin as unchecked
// Bomb is potentially given later
CSpace::CSpace() :
  m_bHasBomb(false),
  m_bIsChecked(false),
  m_cDisplay(CONCEALED)
{
}

// CheckSPace
// returns true if space has not been checked
// returns false if space has already been checked
bool CSpace::CheckSpace()
{
	bool retval = !m_bIsChecked;
	if (m_bIsChecked)
		m_bIsChecked = false;

	return retval;
}

bool CSpace::GetIsChecked()
{
  return m_bIsChecked;
}

void CSpace::SetBomb(bool bBomb)
{
  m_bHasBomb = bBomb;
}

// Dump()
// Used for debugging, to be removed later
// Returns char representation of space contents
char CSpace::Dump()
{
  char retVal;
  if (m_bHasBomb)
    retVal = BOMB;
  else
    retVal = CONCEALED;

  return retVal;
}
