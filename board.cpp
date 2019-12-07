#include "board.h"

// Constructor
// Creates new board with dimensions uiSize x uiSize
// Randomly plants <uiBombs> bombs into the board
// Dynamically creates CSpaces, which are deleted in the destructor
CBoard::CBoard(unsigned int uiHeight, unsigned int uiWidth, unsigned int uiBombs) :
  m_uiBombs(uiBombs),
  m_uiHeight(uiHeight),
  m_uiWidth(uiWidth),
	m_uiSafeSpaces(uiHeight*uiWidth - uiBombs),
	m_uiRevealedSpaces(0)
{
  // First, initialize arrays of rows
  m_spaces = new CSpace*[m_uiHeight];
  m_display = new char*[m_uiHeight];

  // Then, initialize each row of spaces
  for (unsigned int i = 0; i < m_uiHeight; i++)
  {
    m_spaces[i] = new CSpace[m_uiWidth];
    m_display[i] = new char[m_uiWidth+1];
  }

  // Place bombs in board
  populateBoard();
}

// populateBoard()
// Generates the board based on provided parameters
// Generates bomb locations
// Places bombs in their given locations
void CBoard::populateBoard()
{
  unsigned int uiRandx, // Randomized coordinates for bombs
    uiRandy,            // Randomized coordinates for bombs
    uiPlacedBombs = 0;      // Current number of bombs placed on board

  // Seed random number generator
  srand(time(NULL));

  // Generate random bomb locations
  while (uiPlacedBombs < m_uiBombs)
  {
    // Generate random coordinates
    uiRandy = rand() % m_uiHeight;
    uiRandx = rand() % m_uiWidth;

    // If no bomb in space
    if (!m_spaces[uiRandy][uiRandx].GetBomb())
    {
      // Bomb is placed in space
      uiPlacedBombs++;
      m_spaces[uiRandy][uiRandx].SetBomb(true);
    }
  }

  // Populate display
  for (unsigned int i = 0; i < m_uiHeight; i++)
  {
    m_display[i][m_uiWidth] = '\0';

    // Populate row with displays
    for (unsigned int j = 0; j < m_uiWidth; j++)
    {
      m_display[i][j] = m_spaces[i][j].GetDisplay();
    }
  }
}

// Destructor
// Deletes m_spaces and m_display
CBoard::~CBoard()
{
	DeleteBoard();
}

// Dump()
// Returns board in the form of null-terminated char*s
// Used for debugging, will be removed later
char** CBoard::Dump()
{
  char **csDisplay = new char*[m_uiHeight];

  // Initialize rows
  for (unsigned int i = 0; i < m_uiHeight; i++)
  {
    // Needs the +1 for null terminator
    csDisplay[i] = new char[m_uiWidth+1];
    csDisplay[i][m_uiWidth] = '\0';

    // Populate row with displays
    for (unsigned int j = 0; j < m_uiWidth; j++)
    {
      csDisplay[i][j] = m_spaces[i][j].Dump();
    }
  }

  return csDisplay;
}

// IsSpaceChecked()
// Peeks the space at the given coordinates
// If the space has been "checked", return true
// False if the space has not been checked
bool CBoard::IsSpaceChecked(unsigned int y, unsigned int x)
{
  return m_spaces[y][x].GetIsChecked();
}

// GetSpaceBomb()
// Checks if the current space has a bomb
// Returns true if bomb is present
// Returns false if not
bool CBoard::GetSpaceBomb(unsigned int y, unsigned int x)
{
  return m_spaces[y][x].GetBomb();
}

// IsInBounds()
// Checks if the given coordinates are in bounds in the board
// Returns true if a valid board position
// false if not
bool CBoard::IsInBounds(unsigned int y, unsigned int x)
{
  bool retVal;
  if (y < m_uiHeight && x < m_uiWidth)
    retVal = true;
  else
    retVal = false;

  return retVal;
}

bool CBoard::CheckSpace(unsigned int y, unsigned int x)
{
  unsigned int uiCount = 0;
  bool bHasBomb = false;
  bool bHasAdjacentBomb = false;
  unsigned int checkY, checkX;

  // Check if space is in bounds
  if (IsInBounds(y, x))
  {
    bHasBomb = m_spaces[y][x].GetBomb();
    m_spaces[y][x].CheckSpace();
  	m_uiRevealedSpaces++;
	}
  else
    return bHasBomb;

  // Just return if bomb is found in space
  if (bHasBomb)
  {
    m_display[y][x] = '!';
    return bHasBomb;
  }

  // Check if space has adjacent bombs
  for (int i = -1; i <= 1; i++)
  {
    checkY = y+i;
    for (int j = -1; j <= 1; j++)
    {
      checkX = x+j;
      if (IsInBounds(checkY, checkX) && !(i == 0 && j == 0))
      {
        if (m_spaces[checkY][checkX].GetBomb())
        {
          bHasAdjacentBomb = true;
          uiCount++;
        }
      }
    }
  }

  if (bHasAdjacentBomb)
  {
    m_display[y][x] = uiCount+48;
    return bHasBomb;
  }

  // Recursively check all adjacent spaces
  for (int i = -1; i <= 1; i++)
  {
    checkY = y+i;
    for (int j = -1; j <= 1; j++)
    {
      checkX = x+j;
      if (IsInBounds(checkY, checkX) && !(i == 0 && j == 0))
      {
        if (!IsSpaceChecked(checkY, checkX))
          CheckSpace(checkY, checkX);
      }
    }
  }

 	m_display[y][x] = ' ';
  return bHasBomb;
}

bool CBoard::IsCleared()
{
	// When all safe spaces have been revealed, the board is clear
	bool retVal = (m_uiSafeSpaces == m_uiRevealedSpaces);
	return retVal;
}

// DeleteBoard()
// Used to deallocate memory associated with the board and display
// Required for game logic, for restarting the minesweeper game mid-session
void CBoard::DeleteBoard()
{
  if (m_spaces)
  {

    // First, delete each row
    for (unsigned int i = 0; i < m_uiHeight; i++)
    {
      if (m_spaces[i])
        delete [] m_spaces[i];
    }

    // Then, delete the whole board
    delete [] m_spaces;
  }
	if (m_display)
	{  
		// First, delete each row
    for (unsigned int i = 0; i < m_uiHeight; i++)
    {
      if (m_display[i])
        delete [] m_display[i];
    }

		// Then delete outer array
    delete [] m_display;
	}
}
