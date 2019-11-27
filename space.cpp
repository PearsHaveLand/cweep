#include "space.h"

// Constructor
// Bomb distribution is determined in CBoard
// All spaces' displays begin as concealed, until the user reveals them
CSpace::CSpace(bool bHasBomb)
{
	m_bHasBomb = bHasBomb;
	m_cDisplay = CONCEALED_SPACE;
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

// SetDisplay
// assigns the display to the provided argument
void CSpace::SetDisplay(char cDisplay)
{
	m_cDisplay = cDisplay;
}
